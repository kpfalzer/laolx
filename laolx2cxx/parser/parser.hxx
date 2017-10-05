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

/* 
 * File:   parser.hxx
 * Author: kwpfalzer
 *
 * Created on September 30, 2017, 4:39 PM
 */

#ifndef PARSER_HXX
#define PARSER_HXX

#include <initializer_list>
#include "laolx/map.hxx"
#include "parser/lexer.hxx"

class Parser {
public:
    typedef long int index_type;

    explicit Parser(const laolx::String& filename);

    explicit Parser(laolx::LineReader& input);

    bool hasMore() const {
        return m_pos < m_tokens.length();
    }

    bool isEmpty() const {
        return !hasMore();
    }

    const TRcToken& peek(index_type offset = 0) const;

    /**
     * Accept (position) n tokens and return value at n-1.
     * @param n number of tokens to advance.
     * @return current token at [n-1].
     */
    TRcToken accept(index_type n = 1);

    index_type getMark() const {
        return m_pos;
    }

    void setMark(index_type mark) {
        m_pos = mark;
    }

    /**
     * Check for proper end of statement.
     * @param skipOverSemi skip S_SEMI if next token.
     * @return if next token is eof(), on next line or is S_SEMI.
     */
    bool isEndOfStatement(bool skipOverSemi = true);

    bool accept(laolx::Array<TRcToken>& tokens, std::initializer_list<Token::Code> codes);

    virtual ~Parser();

private:
    void initialize(laolx::LineReader& input);

    // Track tokens, comments separately.
    laolx::Array<TRcToken> m_tokens, m_comments;

    index_type m_pos;
};

#endif /* PARSER_HXX */

