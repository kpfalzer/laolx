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

import static apfev2.runtime.Util.downcast;
import static apfev2.runtime.Util.isNonNull;
import static apfev2.runtime.Util.isNull;
import static laolx.parser.Util.nullAsEmpty;

/**
 * Accept /.../i or %r{...}i
 */
public class RegExp implements Acceptor {
    @Override
    public Accepted accept(CharBuffer charBuffer) {
        if (charBuffer.isEOF() || charBuffer.isEOLN()) {
            return null;
        }
        char close = 0, peek = 0;
        StringBuilder buf = null;
        final Location start = charBuffer.getLocation();
        while (true) {
            peek = charBuffer.peekAndCheckUnexpected(close);
            if (isNull(buf)) {
                if ('/' == peek) {
                    close = peek;
                } else if (charBuffer.match("%r{")) {
                    charBuffer.accept(1);
                    close = '}';
                } else {
                    return null;
                }
                charBuffer.accept(); //accept prefix match
                buf = new StringBuilder();
            } else if (close != peek) {
                buf.append(charBuffer.accept());
                if ('\\' == peek) { //check what we just accepted
                    buf.append(charBuffer.acceptUnlessUnexpected(close));
                }
            } else {
                charBuffer.accept();
                final CharClass.MyAccepted modifier = downcast(MODIFIER.accept(charBuffer));
                return new RegExp.MyAccepted(start, buf.toString(), close, modifier);
            }
        }
    }

    private static final CharClass MODIFIER = new CharClass("i");

    public static class MyAccepted extends Accepted {
        public enum EType {
            eSlash, eCurlied
        }

        private MyAccepted(Location loc, String str, char close, CharClass.MyAccepted modifier) {
            super(loc);
            this.regexp = str;
            this.modifiers = isNonNull(modifier) ? modifier.toString() : null;
            this.type = ('/' == close)
                    ? EType.eSlash
                    : EType.eCurlied;
        }

        @Override
        public String toString() {
            final String delim[] = getDelim(type);
            return delim[0] + regexp + delim[1] + nullAsEmpty(modifiers);
        }

        private static String[] getDelim(EType type) {
            if (EType.eSlash == type) {
                return new String[]{"/", "/"};
            }
            return new String[]{"%r{", "}"};
        }

        public final String regexp;
        public final String modifiers;
        public final EType type;

    }

    private static Acceptor THE_ONE;

    public static Acceptor getTheOne() {
        if (isNull(THE_ONE)) {
            THE_ONE = new WithSpacing<>(new RegExp());
        }
        return THE_ONE;
    }
}
