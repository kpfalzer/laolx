/*
 *
 *  * The MIT License
 *  *
 *  * Copyright 2018 kpfalzer.
 *  *
 *  * Permission is hereby granted, free of charge, to any person obtaining a copy
 *  * of this software and associated documentation files (the "Software"), to deal
 *  * in the Software without restriction, including without limitation the rights
 *  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  * copies of the Software, and to permit persons to whom the Software is
 *  * furnished to do so, subject to the following conditions:
 *  *
 *  * The above copyright notice and this permission notice shall be included in
 *  * all copies or substantial portions of the Software.
 *  *
 *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  * THE SOFTWARE.
 *
 *
 */

package laolx.parser;

import apfev2.parser.Spacing;
import apfev2.parser.WithSpacing;
import apfev2.runtime.Acceptor;
import apfev2.runtime.IdentOrKeyword;
import apfev2.runtime.Token;

import java.util.HashMap;

import static apfev2.runtime.Util.invariant;
import static apfev2.runtime.Util.isNonNull;
import static apfev2.runtime.Util.isNull;

public enum Tokens {
    // These are essentially static vars
    INITIALIZE(),  //call empty contructor to get initialized
    IDENT(null, true), //special constructor for IDENT
    S_SEMI(";"),
    S_LCURLY("{"),
    S_RCURLY("}"),
    K_CLASS("class"),
    K_INT("int"),
    K_FLOAT("float"),
    K_STRING("string"),
    K_CHAR("char"),
    K_SYMBOL("symbol"),
    S_COLON2("::"),
    S_COLON(":"),
    S_LT("<"),
    S_GT(">"),
    S_DOT3("..."),
    S_COMMA(","),
    ;

    private Tokens(String text, boolean isKeyword) {
        this.code = (isNonNull(text)) ? getCode() : IdentOrKeyword.IDENT;
        this.acceptor = getAcceptor(text, isKeyword);
    }

    private Tokens(String text) {
        this(text, Character.isAlphabetic(text.charAt(0)));
    }

    private Tokens() {
        this.code = -1;
        this.acceptor = null;
        initialize();
    }

    public final int code;
    public final Acceptor acceptor;

    // We cannot initialize these here
    private static int CODEI;
    private static HashMap<String, Integer> CODE_BY_KEYWORD;
    private static Acceptor IDENT_OR_KEYWORD;

    private int getCode() {
        return CODEI++;
    }

    private static void initialize() {
        invariant(isNull(CODE_BY_KEYWORD));
        CODEI = IdentOrKeyword.IDENT + 1;
        CODE_BY_KEYWORD = new HashMap<>();
        IDENT_OR_KEYWORD = new WithSpacing<>(new IdentOrKeyword(CODE_BY_KEYWORD));
    }

    private Acceptor getAcceptor(String text, boolean isKeyword) {
        if (isKeyword) {
            if (isNonNull(text)) {
                CODE_BY_KEYWORD.put(text, code);
            }
            return IDENT_OR_KEYWORD;
        }
        return new WithSpacing<>(new Token(code, text));
    }
}
