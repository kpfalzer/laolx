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

import apfev2.runtime.Accepted;
import apfev2.runtime.Acceptor;
import apfev2.runtime.CharBuffer;
import apfev2.runtime.Location;

import static apfev2.runtime.Util.isNull;

/**
 * Accept "..." or '...' or %s{...}
 */
public class XString implements Acceptor {
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
                if ('"' == peek || '\'' == peek) {
                    close = peek;
                } else if (charBuffer.match("%s{")) {
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
                return new MyAccepted(start, buf.toString(), close);
            }
        }
    }

    public static class MyAccepted extends Accepted {
        public enum Type {
            eSingle, eDouble, eCurlied
        }

        private MyAccepted(Location loc, String str, char close) {
            super(loc);
            this.string = str;
            this.type = ('"' == close)
                    ? Type.eDouble
                    : (('}' == close)
                    ? Type.eCurlied
                    : Type.eSingle);
        }

        @Override
        public String toString() {
            final String delim[] = getDelim(type);
            return delim[0] + string + delim[1];
        }

        private static String[] getDelim(Type type) {
            if (Type.eSingle == type) {
                return new String[]{"'", "'"};
            }
            if (Type.eDouble == type) {
                return new String[]{"\"", "\'"};
            }
            return new String[]{"%s{", "}"};
        }

        public final String string;
        public final Type type;

    }

}
