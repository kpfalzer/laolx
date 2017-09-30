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
#include "lexer.hxx"

const laolx::String Lexer::XEOF = "<eof>";

const bool Lexer::stInited = Lexer::init();
const std::function<void(void) > stNullUnterminated = []() {
};

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

void Lexer::setMatch(int n) {
    m_startColNumber = m_currColNumber;
    m_startLineNumber = m_currLineNumber;
    m_text = m_line.substr(m_currColNumber, n);
    advancePos(n);
}

void Lexer::advancePos(int n) {
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

Location Lexer::getLocation() {
    return Location(m_input.getFilename(), m_startLineNumber, m_startColNumber);
}

TRcToken Lexer::getToken(Token::Code code) {
    return std::make_shared<Token>(getLocation(), code, m_text);
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

bool Lexer::matchTo(const laolx::String& to, bool setMatch) {
    const colnum_type n = to.length();
    if (m_line.substr(m_currColNumber, n) != to) {
        return false;
    }
    if (setMatch) {
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

TRcToken Lexer::blockComment() {
    std::stringbuf buf(m_text);
    colnum_type end;
    while (true) { //todo: corner case: EOF
        end = m_line.indexOf(END_BLOCK_COMMENT, col);
        if (0 > end) {
            buf.append(line.substring(col));
            advancePos(line.length() - col); //force nextLine
        } else {
            end += END_BLOCK_COMMENT.length();
            buf.append(line.substring(col, end));
            advancePos(end - col);
            break; //while
        }
        if (isEmpty()) {
            throw new Exception("Unterminated block comment");
        }
    }
    text = buf.toString();
    advancePos();
    return getToken(Token.Code.BLOCK_COMMENT);
}

TRcToken Lexer::next() {
    if (isEmpty()) {
        if (m_tokens.isEmpty() || (Token::XEOF == m_tokens.last()->code)) {
            m_text = XEOF;
            return getToken(Token::XEOF);
        }
        return m_tokens.last();
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
}
/*
        
        
        
        if (matchTo("/*")) {
            return blockComment();
        }
        if (('"' == ch) || ('\'' == ch)) {
            return quoted(ch);
        }
        if (matchTo("%r{", false)) {
            return regexp();
        }
        if (isDigit(ch)
                || (('-' == ch || '+' == ch)
                && testNextChar((Character t) -> isDigit(t)))) {
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
 */



