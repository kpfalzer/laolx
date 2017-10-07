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

#include <functional>
#include <stdexcept>
#include <array>
#include "laolx/istream.hxx"
#include "laolx/list.hxx"
#include "laolx/regex.hxx"
#include "parser/token.hxx"

class Lexer {
public:
    typedef Location::linenum_type linenum_type;
    typedef Location::colnum_type colnum_type;
    
    explicit Lexer(laolx::LineReader& input);

    /**
     * Get next token.
     * @return next token;
     */
    TRcToken accept();
    
    bool isEOF();
    
    virtual ~Lexer();

    const static laolx::String XEOF;
    const char EOLN = '\n';

    class Exception : public std::runtime_error {
    public:

        explicit Exception(const Location& loc, const std::string& reason);
    };
    
private:
    void error(const std::string& reason) const;

    static bool isKeyword(const laolx::String& matched, Token::Code& code) {
        return Token::isKeyword(matched, code);
    }

    bool isKeyword() {
        return isKeyword(m_text, m_keyword);
    }

    bool isEmpty() const {
        return m_line.empty() && m_input.isEOF();
    }

    /**
     * Set state indicating match of n recent characters.
     *
     * @param n number of characters matched.
     */
    void setMatch(colnum_type n);

    /**
     * Advance current line position.
     *
     * @param n char positions to advance.
     */
    void advancePos(colnum_type n = 0);

    /**
     * Get next token.
     *
     * @return next token.
     */
    TRcToken next();

    TRcToken getToken(Token::Code code);

    Location getLocation() const;

    TRcToken identOrKeyword();

    // An empty/null function.
    static const std::function<void(void) > stNullUnterminated;

    TRcToken whileOnLine(
            const std::function<bool(char) >& cond,
            const std::function<TRcToken(void) >& create,
            int colAdj = 0,
            bool allowEsc = false,
            const std::function<void(void) >& unterminated = stNullUnterminated);

    /**
     * Match line comment (and skip over EOLN, if present).
     *
     * @return line comment (without EOLN).
     */
    TRcToken lineComment();

    TRcToken blockComment();

    TRcToken quoted(char quote = '"');

    TRcToken regexp();

    TRcToken symbolOrOther();

    bool testNextChar(const std::function<bool(char) >& pred);

    TRcToken getNumber();

    TRcToken regexMatcher(laolx::Regex& patt, const std::function<TRcToken(void)>& creator);

    TRcToken getSymbolStartingWith(char ch);
    
    TRcToken attrDeclOrOther();

    template<std::size_t N>
    bool contains(const std::array<char, N>& set) const {
        for (auto c : set) {
            if (std::string::npos != m_text.find(c)) {
                return true;
            }
        }
        return false;
    }

    /**
     * Read next line (and append newline).
     *
     * @param force force read line.
     */
    void readLine(bool force = false);

    TRcToken whiteSpace();

    bool matchTo(char ch);

    /**
     * Match current position with to.
     *
     * @param to match to.
     * @param setMatch true if adjust positions upon match.
     * @return true if match; else false.
     */
    bool matchTo(const laolx::String& to, bool setMatch = true);

    static bool isIdentAny(char c);

    static bool isIdentBegin(char c);

    static bool isAlpha(char c);

    static bool isDigit(char c);

private:
    laolx::LineReader& m_input;
    linenum_type m_currLineNumber, m_startLineNumber;
    colnum_type m_currColNumber, m_startColNumber;
    laolx::String m_line; //current line
    laolx::String m_text; //match text
    TRcToken m_token;
    Token::Code m_keyword;

    static const bool stInited;
    static bool init();
};

#endif /* LEXER_HXX */
