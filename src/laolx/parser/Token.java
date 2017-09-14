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
package laolx.parser;

/**
 * A token.
 *
 * @author kwpfalzer
 */
public class Token {
    public Token(Location location, Code code, String text) {
        this.location = location;
        this.code = code;
        this.text = text;
    }
    
    public final Location location;
    public final Code code;
    public final String text;
    
    /**
     * Token codes.
     */
    public static enum Code {
        EOF,
        EOLN,
        WS, //whitespace (not including EOF or EOLN)
        LINE_COMMENT,
        BLOCK_COMMENT,
        IDENT,
        DQSTRING, //double-quoted string
        SQSTRING, //single-quoted string
        SYMBOL, //e.g. :foobar
        //
        // K_xxx are keywords
        K_CLASS,
        K_INTERFACE,
        K_EXTENDS,
        K_IMPLEMENTS,
        K_DEFAULT,
        K_STATIC,
        K_FOR,
        K_WHILE,
        K_UNTIL,
        K_CASE,
        K_WHEN,
        K_IF,
        K_ELSE,
        K_ELSIF,
        K_THROW,
        K_CATCH,
        K_PUBLIC,
        K_PROTECTED,
        K_PRIVATE,
        K_NIL,
        K_INT,
        K_FLOAT,
        K_STRING,
        //
        // S_xxx are symbols
        S_TIDLE, //~
        S_EXCLAMATION, //!
        S_AT, //@
        S_POUND, //#
        S_DOLLAR, //$
        S_PCNT, //%
        S_CARET, //^
        S_AND, //&
        S_AND2, //&&
        S_STAR, //*
        S_STAR2, //**
        S_LPAREN, //(
        S_RPAREN, //)
        S_MINUS, //-
        S_PLUS, //+
        S_PLUS2, //++
        S_EQ, //=
        S_PLUSEQ, //+=
        S_MINUSEQ, //-=
        S_LCURLY, //{
        S_RCURLY, //}
        S_LBRACK, //[
        S_RBRACK, //]
        S_OR, //|
        S_OR2, //||
        S_BSLASH, //\
        S_COLON, //:
        S_COLON2, //::
        S_SEMI, //;
        S_DQOUTE, //"
        S_SQUOTE, //'
        S_LT, //<
        S_LT2, //<<
        S_GT, //>
        S_GT2, //>>
        S_COMMA, //,
        S_DOT, //.
        S_QMARK, //?
        S_DIV, // /
        S_BACKTIC, //`
    }
}
