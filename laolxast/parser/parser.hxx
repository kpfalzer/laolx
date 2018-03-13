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

    bool isEOF() const {
        return peek()->isEOF();
    }

    const TRcToken& peek(index_type offset = 0) const;

    /**
     * Accept (position) n tokens and return value at n-1.
     * @param n number of tokens to advance.
     * @return current token at [n-1].
     */
    TRcToken accept(index_type n = 1);

    /**
     * Advance (position) n tokens and return parser.
     * @param n number of tokens to advance.
     * @return this parser.
     */
    Parser& advance(index_type n = 1);

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

    /**
     * Check for isEndOfStatement() and generate error if not found.
     * @return isEndOfStatement() result (error was generated if false).
     */
    bool expectEndOfStatement();

    /**
     * Check for isEOF() and return true if so.
     * Else, geenrate error at current token and return false.
     */
    bool expectEOF();
    
    /**
     * Generate error message using text and location from token.
     * @param message message/format specifier with %s for text (from token).
     * @param token extract text and location for message.
     */
    void error(const std::string& message, const TRcToken& token);

    /**
     * Attempt to accept consecutive codes.
     * @param tokens collect match tokens into (this pre-allocated) array.
     * @param codes consecutive Token::Code to match.
     * @return true on match/accept; else false.
     * Note: tokens is invalid/indeterminate unless return true.
     */
    bool accept(laolx::Array<TRcToken>& tokens, std::initializer_list<Token::Code> codes);

    /**
     * Attempt to accept code.  Return true if next token is code (and accept).
     * @param code code to accept.
     * @return treu if code accepted; else false.
     */
    bool accept(Token::Code code);

    auto errorCount() const {
        return m_errorCount;
    }

    bool hasError() const {
        return (0 < errorCount());
    }

    virtual ~Parser();

private:
    void initialize(laolx::LineReader& input);

    // Track tokens, comments separately.
    laolx::Array<TRcToken> m_tokens, m_comments;

    index_type m_pos;
    unsigned long int m_errorCount;
};

#endif /* PARSER_HXX */

