/*
 * The MIT License
 *
 * Copyright 2017 kpfalzer.
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
 * File:   lexer.hxx
 * Author: kpfalzer
 *
 * Created on September 28, 2017, 12:34 PM
 */

#ifndef LEXER_HXX
#define LEXER_HXX

#include "laolx/istream.hxx"
#include "token.hxx"
#include "token.hxx"

class Lexer {
public:
    explicit Lexer(const std::string& filename);

    explicit Lexer(laolx::LineReader& input);

    virtual ~Lexer();
    
    const static std::string EOLN;

private:

    static bool isKeyword(const std::string& matched) {
        return Token::isKeyword(matched);
    }

    bool isKeyword() const {
        return isKeyword(m_line);
    }

    bool isEmpty() const {
        return m_line.empty() && m_input.isEOF();
    }
    
    /**
     * Set state indicating match of n recent characters.
     *
     * @param n number of characters matched.
     */
    void setMatch(int n);

    /**
     * Advance current line position.
     *
     * @param n char positions to advance.
     */
    void advancePos(int n = 0);

    /**
     * Read next line (and append newline).
     *
     * @param force force read line.
     */
    void readLine(bool force = false);

    static bool isIdentAny(char c);

    static bool isIdentBegin(char c);

    static bool isAlpha(char c);

    static bool isDigit(char c);

private:
    laolx::LineReader& m_input;
    Location::linenum_type m_currLineNumber, m_startLineNumber;
    Location::colnum_type m_currColNumber, m_startColNumber;
    std::string m_line; //current line
    std::string m_text; //match text
    static const bool stInited;
    static bool init();
};

#endif /* LEXER_HXX */

