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
    Lexer lexer(input);
    TRcToken token;
    Token::Code code;
    do {
        token = lexer.accept();
        code = token->code;
        assert(Token::INVALID != code);
        if (Token::WS != code) {
            if (!token->isComment()) {
                if (Token::EOLN != code) {
                    m_tokens << token;
                } else {
                    m_eolns[token->location.linenum] = token;
                }
            } else {
                m_comments[token->location.linenum] << token;
            }
        }
    } while (Token::XEOF != code);
    m_tokens.compact();
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

Parser::~Parser() {

}


