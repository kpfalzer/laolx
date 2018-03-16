/*
 * The MIT License
 *
 * Copyright 2017 kwpfalzer.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <cassert>
#include <sstream>
#include <type_traits>
#include "laolx/regex.hxx"
#include "laolx/array.hxx"
#include "parser/lexer.hxx"

const laolx::String Lexer::XEOF = "<eof>";

const bool Lexer::stInited = Lexer::init();
const std::function<void(void) > Lexer::stNullUnterminated = []() {
};

Lexer::Lexer(laolx::LineReader& input)
: m_input(input), m_currColNumber(0), m_currLineNumber(0) {
    readLine();
}

TRcToken Lexer::accept() {
    TRcToken token;
    if (!m_token) {
        next();
    }
    token = m_token;
    if (!isEOF()) {
        m_token.reset();
    }
    return token;
}

bool Lexer::isEOF() {
    if (!m_token) {
        next();
    }
    return m_token->isEOF();
}

Lexer::~Lexer() {
}

Lexer::Exception::Exception(const Location& loc, const std::string& reason)
: std::runtime_error(loc.toString() + ": " + reason) {

}

bool Lexer::init() {
    static_assert('0' < '9' && 'a' < 'z' && 'A' < 'Z', "Failed char assumption.");
    return true;
}

bool Lexer::isIdentAny(char c) {
    return isIdentBegin(c) || isDigit(c);
}

bool Lexer::isIdentBegin(char c) {
    return isAlpha(c) || ('_' == c);
}

bool Lexer::isAlpha(char c) {
    return (('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z'));
}

bool Lexer::isDigit(char c) {
    return ('0' <= c) && (c <= '9');
}

void Lexer::setMatch(colnum_type n) {
    m_startColNumber = m_currColNumber;
    m_startLineNumber = m_currLineNumber;
    m_text = m_line.substr(m_currColNumber, n);
    advancePos(n);
}

void Lexer::advancePos(colnum_type n) {
    m_currColNumber += n;
    if (m_currColNumber < m_line.length()) {
        return;
    }
    assert(m_currColNumber == m_line.length()); //just past last valid char and no more
    readLine();
}

void Lexer::readLine(bool force) {
    assert(force || isEmpty() || (m_currColNumber >= m_line.length()));
    m_line = m_input.getLine();
    if (!isEmpty()) {
        m_currLineNumber += 1;
        m_currColNumber = 0;
    }
}

Location Lexer::getLocation() const {
    return Location(m_input.getFilename(), m_startLineNumber, m_startColNumber + 1);
}

void Lexer::error(const std::string& reason) const {
    throw Lexer::Exception(getLocation(), reason);
}

TRcToken Lexer::getToken(Token::Code code) {
    m_token = std::make_shared<Token>(getLocation(), code, m_text);
    return m_token;
}

TRcToken Lexer::identOrKeyword() {
    return whileOnLine(
            [](auto ch) {
                return !isIdentAny(ch);
            },
    [this]() {
        return getToken(isKeyword() ? m_keyword : Token::IDENT);
    }
    );
}

TRcToken Lexer::whiteSpace() {
    return whileOnLine(
            [](auto ch) {
                return (' ' != ch) && ('\t' != ch);
            },
    [this]() {
        return getToken(Token::WS);
    }
    );
}

TRcToken Lexer::whileOnLine(
        const std::function<bool(char) >& cond,
        const std::function<TRcToken(void) >& create,
        int colAdj,
        bool allowEsc,
        const std::function<void(void) >& unterminated) {
    m_startColNumber = m_currColNumber++;
    m_startLineNumber = m_currLineNumber;
    char ch;
    for (; m_currColNumber < m_line.length(); m_currColNumber++) {
        ch = m_line.at(m_currColNumber);
        if (allowEsc) {
            if (ch == '\\') {
                m_currColNumber++;
            } else if (cond(ch)) {
                break;
            }
        } else if (cond(ch)) {
            break;
        }
    }
    if (m_currColNumber >= m_line.length()) {
        unterminated();
    }
    m_currColNumber += colAdj;
    m_text = m_line.slice(m_startColNumber, m_currColNumber);
    advancePos();
    return create();
}

bool Lexer::matchTo(char ch) {
    if (m_line.at(m_currColNumber) != ch) {
        return false;
    }
    setMatch(1);
    return true;
}

bool Lexer::matchTo(const laolx::String& to, bool doSetMatch) {
    const colnum_type n = to.length();
    if (m_line.substr(m_currColNumber, n) != to) {
        return false;
    }
    if (doSetMatch) {
        setMatch(n);
    }
    return true;
}

TRcToken Lexer::lineComment() {
    colnum_type lastPos = m_line.length();
    //don't grab EOLN with text: but skip over it all the same.
    lastPos -= (EOLN == m_line.back()) ? 1 : 0;
    m_text = m_line.slice(m_startColNumber, lastPos);
    m_currColNumber = m_line.length();
    advancePos();
    return getToken(Token::LINE_COMMENT);
}

static const laolx::String END_BLOCK_COMMENT = "*/";

static void append(std::stringbuf& buf, const std::string& s) {
    buf.sputn(s.c_str(), s.length());
}

TRcToken Lexer::blockComment() {
    std::stringbuf buf(m_text);
    size_t end;
    while (true) { //todo: corner case: EOF
        end = m_line.indexOf(END_BLOCK_COMMENT, m_currColNumber);
        if (laolx::String::npos == end) {
            append(buf, m_line.slice(m_currColNumber));
            advancePos(m_line.length() - m_currColNumber); //force nextLine
        } else {
            end += END_BLOCK_COMMENT.length();
            append(buf, m_line.slice(m_currColNumber, end));
            advancePos(end - m_currColNumber);
            break; //while
        }
        if (isEmpty()) {
            error("Unterminated block comment");
        }
    }
    m_text = buf.str();
    advancePos();
    return getToken(Token::BLOCK_COMMENT);
}

TRcToken Lexer::quoted(char quote) {
    return whileOnLine(
            [quote](char ch) {
                return quote == ch;
            },
    [quote, this]() {
        return getToken(('"' == quote)
                ? Token::DQSTRING
                : (('\'' == quote)
                ? Token::SQSTRING
                : Token::EVALSTRING));
    },
    1,
    true,
    [this]() {
        error("Unterminated string");
    }
    );
}

TRcToken Lexer::regexp() {
    m_currColNumber += 2; //past %r of %r{
    return whileOnLine(
            [](char ch) {
                return '}' == ch;
            },
    [this]() {
        return getToken(Token::REGEXP);
    },
    1,
    true,
    [this]() {
        error("Unterminated regexp");
    }
    );
}

bool Lexer::testNextChar(const std::function<bool(char) >& pred) {
    return (m_currColNumber < m_line.length() - 1)
            ? pred(m_line[m_currColNumber + 1])
            : false;
}

static laolx::Regex NUMBER_REX("^[\\-\\+]?\\d+(\\.\\d+)?([eE][\\-\\+]?\\d+)?");
static const std::array<char, 3> FLOATER({'.', 'e', 'E'});

TRcToken Lexer::getNumber() {
    return regexMatcher(
            NUMBER_REX,
            [this]() {
                return getToken(contains(FLOATER) ? Token::FLOAT : Token::INT);
            }
    );
}

TRcToken Lexer::regexMatcher(laolx::Regex& patt, const std::function<TRcToken(void)>& creator) {
    m_startLineNumber = m_currLineNumber;
    m_startColNumber = m_currColNumber;
    bool matches = patt.match(m_line.slice(m_currColNumber));
    assert(matches);
    m_text = patt.getMatch(0);
    m_currColNumber += m_text.length();
    advancePos();
    return creator();
}

static laolx::Regex SYMBOL_REX("^:([a-zA-Z_]\\w*)?");

TRcToken Lexer::symbolOrOther() {
    return regexMatcher(
            SYMBOL_REX,
            [&]() {
                if (1 == m_text.length()) {
                    m_currColNumber--;
                    return getSymbolStartingWith(':');
                }
                return getToken(Token::SYMBOL);
            }
    );
}

TRcToken Lexer::getSymbolStartingWith(char ch) {
    assert(Token::stSymbolsByChar.hasKey(ch));
    const auto debug = Token::stSymbolsByChar[ch];
    for (const auto& symbolCode : Token::stSymbolsByChar[ch]) {
        if (matchTo(symbolCode.first)) {
            return getToken(symbolCode.second);
        }
    }
    assert(false);
}

static laolx::Regex ATTR_REX("^@(\\-|\\+)?([a-zA-Z_]\\w*)?");

TRcToken Lexer::attrDeclOrOther() {
    return regexMatcher(
            ATTR_REX,
            [this]() {
                if (1 == m_text.length()) {
                    m_currColNumber--;
                    return getSymbolStartingWith('@');
                }
                char ch = m_text[1];
                Token::Code code = ('-' == ch)
                        ? Token::ATTR_DECL
                        : (('+' == ch)
                        ? Token::ATTR_DECL_RW
                        : Token::ATTR_DECL_RO);
                return getToken(code);
            }
    );
}

TRcToken Lexer::next() {
    if (isEmpty()) {
        if (!m_token || !m_token->isEOF()) {
            m_text = XEOF;
            return getToken(Token::XEOF);
        }
        return m_token;
    }
    assert(m_currColNumber < m_line.length());
    const char ch = m_line.at(m_currColNumber);
    if (isIdentBegin(ch)) {
        return identOrKeyword();
    }
    if ((' ' == ch) || ('\t' == ch)) {
        return whiteSpace();
    }
    if (matchTo(EOLN)) {
        return getToken(Token::EOLN);
    }
    if (matchTo("//")) {
        return lineComment();
    }
    if (matchTo("/*")) {
        return blockComment();
    }
    if (('"' == ch) || ('\'' == ch) || ('`' == ch)) {
        return quoted(ch);
    }
    if (matchTo("%r{", false)) {
        return regexp();
    }
    if (matchTo("%w{")) {
        return getToken(Token::S_WORDS);
    }
    if (matchTo("%s{")) {
        return getToken(Token::S_SYMBOLS);
    }
    if (isDigit(ch)
            || (('-' == ch || '+' == ch)
            && testNextChar([this](auto c) {
                return isDigit(c);
            })
    )
    ) {
    return getNumber();
}
    if (':' == ch) {
        return symbolOrOther();
    }
    if ('@' == ch) {
        return attrDeclOrOther();
    }
    return getSymbolStartingWith(ch);
}
