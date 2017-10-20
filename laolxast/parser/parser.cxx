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
#include <cstdio>
#include <iostream>
#include "parser/parser.hxx"

Parser::Parser(const laolx::String& filename) {
    laolx::FileInputStream fis(filename);
    initialize(fis);
    fis.close();
}

Parser::Parser(laolx::LineReader& input) {
    initialize(input);
}

void Parser::initialize(laolx::LineReader& input) {
    m_pos = 0;
    m_errorCount = 0;
    Lexer lexer(input);
    TRcToken token;
    Token::Code code;
    do {
        token = lexer.accept();
        code = token->code;
        assert(Token::INVALID != code);
        if ((Token::WS != code) && (Token::EOLN != code)) {
            if (!token->isComment()) {
                m_tokens << token;
            } else {
                m_comments << token;
            }
        }
    } while (! token->isEOF());
    assert(token->isEOF());
    m_tokens << token; //add XEOF
    m_tokens.compact();
    m_comments.compact();
}

const TRcToken& Parser::peek(index_type offset) const {
    assert(!isEmpty());
    return m_tokens[m_pos + offset];
}

TRcToken Parser::accept(index_type n) {
    const TRcToken& curr = peek(n - 1);
    m_pos += n;
    return curr;
}

Parser& Parser::advance(index_type n) {
    accept(n);
    return *this;
}

bool Parser::accept(laolx::Array<TRcToken>& tokens, std::initializer_list<Token::Code> codes) {
    assert(tokens.size() == codes.size());
    index_type start = getMark(), i = 0;
    for (auto code : codes) {
        if (isEmpty()) {
            break;
        }
        if (peek()->code == code) {
            tokens[i++] = accept();
        }
    }
    if (i >= tokens.length()) {
        return true;
    }
    setMark(start);
    return false;
}

bool Parser::isEndOfStatement(bool skipOverSemi) {
    if (peek()->isEOF()) {
        return true;
    }
    auto code = peek()->code;
    auto prevLineNum = peek(-1)->location.linenum;
    auto nextLineNum = peek()->location.linenum;
    if (nextLineNum != prevLineNum) {
        assert(nextLineNum > prevLineNum);
        return true;
    }
    if (Token::S_SEMI == code) {
        if (skipOverSemi) {
            accept();
        }
        return true;
    }
    return false;
}

bool Parser::expectEndOfStatement() {
    static const std::string FMT = "Expected end-of-statement: ';', EOLN or EOF.  Found '%s'.";
    const bool ok = isEndOfStatement();
    if (!ok) {
        error(FMT, peek());
    }
    return ok;
}

void Parser::error(const std::string& message, const TRcToken& token) {
    const std::string location = token->location.toString();
    const std::string format = "%s: " + message;
    const std::string text = token->text;
    std::vector<char> buf(format.size() + location.size() + text.size() + 8);
    std::snprintf(&buf[0], buf.size(), format.c_str(), location.c_str(), text.c_str());
    std::cerr << "Error: " << buf.data() << std::endl;
    m_errorCount++;
}

Parser::~Parser() {

}


