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
 * File:   token.hxx
 * Author: kpfalzer
 *
 * Created on September 27, 2017, 10:19 AM
 */

#ifndef TOKEN_HXX
#define TOKEN_HXX

#include <memory>
#include <utility>
#include "laolx/map.hxx"
#include "laolx/string.hxx"

class Token;
class Location;

typedef std::shared_ptr<Token> TRcToken;

class Location {
public:
    typedef unsigned long int linenum_type;
    typedef unsigned long int colnum_type;

    explicit Location(const laolx::String& filename, linenum_type linenum, colnum_type colnum)
    : filename(filename), linenum(linenum), colnum(colnum) {
    }

    explicit Location(linenum_type linenum, colnum_type colnum)
    : Location("", linenum, colnum) {
    }

    virtual ~Location() {
    }

    laolx::String toString() const;

    const laolx::String filename;
    const linenum_type linenum;
    const colnum_type colnum;
};

class Token {
public:
    static const laolx::String EMPTY;

    enum Code {
        INVALID,
        XEOF, //not conflict with macro/define EOF
        EOLN,
        WS, //whitespace (not including EOF or EOLN)
        LINE_COMMENT,
        BLOCK_COMMENT,
        IDENT,
        SYMBOL,
        ATTR_DECL, //@-IDENT
        ATTR_DECL_RO, //@IDENT
        ATTR_DECL_RW, //@+IDENT
        DQSTRING, //double-quoted string
        SQSTRING, //single-quoted string
        REGEXP, //%r{...}
        INT,
        FLOAT,
        //
        // K_xxx are keywords
        K_AS,
        K_ASSERT,
        K_CASE,
        K_CATCH,
        K_CLASS,
        K_CONST,
        K_DEF,
        K_DEFAULT,
        K_ELSE,
        K_ELSIF,
        K_EXTERN,
        K_FALSE,
        K_FLOAT,
        K_FOR,
        K_IF,
        K_IMPORT,
        K_INT,
        K_INTERFACE,
        K_NAMESPACE,
        K_NEW,
        K_NIL,
        K_PRIVATE,
        K_PROTECTED,
        K_PUBLIC,
        K_STATIC,
        K_STRING,
        K_SYMBOL,
        K_TEMPLATE,
        K_THIS,
        K_THROW,
        K_TRUE,
        K_UNLESS,
        K_UNTIL,
        K_VAR,
        K_WHEN,
        K_WHILE,
        //
        // S_xxx are symbols
        S_TIDLE,
        S_EXCLAMATION,
        S_AT,
        S_POUND,
        S_DOLLAR,
        S_PCNT,
        S_PCNTEQ,
        S_WORDS, //start list of words
        S_SYMBOLS, //start list of symbols
        S_CARET,
        S_AND,
        S_ANDEQ,
        S_AND2,
        S_AND2EQ,
        S_STAR,
        S_STAREQ,
        S_STAR2,
        S_STAR2EQ,
        S_LPAREN,
        S_RPAREN,
        S_MINUS,
        S_PLUS,
        S_PLUS2,
        S_EQ,
        S_EQGT,
        S_MATCH,
        S_NOTMATCH,
        S_PLUSEQ,
        S_MINUSEQ,
        S_LCURLY,
        S_RCURLY,
        S_LBRACK,
        S_RBRACK,
        S_OR,
        S_OREQ,
        S_OR2,
        S_OR2EQ,
        S_BSLASH,
        S_COLON,
        S_SEMI,
        S_DQOUTE,
        S_SQUOTE,
        S_LT,
        S_LTEQ,
        S_LT2,
        S_LT2EQ,
        S_GT,
        S_GTEQ,
        S_GT2,
        S_GT2EQ,
        S_COMMA,
        S_DOT,
        S_DOT2,
        S_DOT3,
        S_QMARK,
        S_DIV,
        S_BACKTIC
    };

    explicit Token(const Location& location, Code code, const laolx::String& text)
    : location(location), code(code), text(text) {
    }

    bool isComment() const {
        return (BLOCK_COMMENT == code) || (LINE_COMMENT == code);
    }
    
    bool isEOF() const {
        return (XEOF == code);
    }
    
    /**
     * Return true if text matches a keyword.
     * @param text check if keyword.
     * @return true if text matches keyword.
     */
    static bool isKeyword(const laolx::String& text, Code& code);

    const Location location;
    const Code code;
    const laolx::String text;

    virtual ~Token();

private:
    typedef laolx::Map<laolx::String, Code> CodeByString;
    typedef std::pair<laolx::String, Code> SymbolCode;
    typedef laolx::Map<char, laolx::Array<SymbolCode>> SymbolsByChar;
    static const CodeByString stKeywords, stSymbols;
    static SymbolsByChar stSymbolsByChar;
    static bool init(void);
    static bool stInited;
    
    friend class Lexer;
};

#endif /* TOKEN_HXX */

