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

import apfev2.parser.WithSpacing;
import apfev2.runtime.*;
import apfev2.runtime.CharSequence;

import static apfev2.runtime.Util.isNonNull;
import static apfev2.runtime.Util.isNull;

/**
 * integer: [0-9][0-9_]*
 * hex: 0x[0-9a-fA-F][0-9_a-fA-F]*
 * float: [0-9][0-9_]*\.integer([eE][\-\+]?integer)?
 * sized: [0-9][0-9_]*'[bBhHoOdD][0-9a-fA-F][0-9a-fA-F_]*
 */
public class Number implements Acceptor {
    @Override
    public Accepted accept(CharBuffer charBuffer) {
        if (charBuffer.isEOF() || charBuffer.isEOLN()) {
            return null;
        }
        final CharBuffer.Mark mark = charBuffer.getMark();
        char peek = 0;
        final Location start = charBuffer.getLocation();
        EType type = null;
        Accepted accepted = INTEGER.accept(charBuffer), trailing = null;
        if (isNonNull(accepted)) {
            type = EType.eInteger;
            peek = charBuffer.peek();
            if ('.' == peek) {
                trailing = FLOAT.accept(charBuffer);
                if (isNonNull(trailing)) {
                    type = EType.eFloat;
                }
            } else if ('\'' == peek) {
                trailing = SIZED.accept(charBuffer);
                if (isNonNull(trailing)) {
                    type = EType.eSized;
                }
            } else {
                ;//do nothing
            }
        } else {
            accepted = HEX.accept(charBuffer);
            if (isNonNull(accepted)) {
                type = EType.eHex;
            }
        }
        if (isNull(type)) {
            charBuffer.setMark(mark);
            return null;
        }
        return new MyAccepted(start, type, accepted, trailing);
    }

    public static final Acceptor THE_ONE = new WithSpacing<>(new Number());

    public static class MyAccepted extends Accepted {

        private MyAccepted(Location loc, EType type, Accepted... accepted) {
            super(loc);
            this.type = type;
            this.value = accepted[0].toString() + Util.toString(accepted[1]);
        }

        public final EType type;
        public final String value;

    }

    public enum EType {
        eInteger, eHex, eFloat, eSized
    }

    private static final String DIGITS = "0123456789";

    private static final Acceptor INTEGER = new Sequence(
            new CharClass(DIGITS),
            new Repetition(new CharClass(DIGITS + "_"), Repetition.EType.eZeroOrMore)
    );

    private static final String HEX_DIGITS = DIGITS + "abcdefABCDEF";

    private static final Acceptor HEX_TAIL = new Sequence(
            new CharClass(HEX_DIGITS),
            new Repetition(new CharClass(HEX_DIGITS + "_"), Repetition.EType.eZeroOrMore)
    );
    private static final Acceptor HEX = new Sequence(
            new CharSequence("0x"),
            HEX_TAIL
    );

    private static final Acceptor FLOAT = new Sequence(
            new CharSequence("."),
            INTEGER,
            new Repetition(
                    new Sequence(
                            new CharClass("eE"),
                            new Repetition(
                                    new CharClass("-+"), Repetition.EType.eZeroOrOne
                            ),
                            INTEGER
                    ),
                    Repetition.EType.eZeroOrOne
            )

    );

    private static final Acceptor SIZED = new Sequence(
            new CharSequence("'"),
            new CharClass("bBoOhHdD"),
            HEX_TAIL
    );

}
