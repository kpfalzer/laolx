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
import apfev2.runtime.Accepted;
import apfev2.runtime.CharBuffer;
import org.junit.jupiter.api.Test;

import static apfev2.runtime.Util.downcast;
import static apfev2.runtime.Util.isNonNull;
import static apfev2.runtime.Util.isNull;
import static org.junit.jupiter.api.Assertions.*;

class RegExpTest {

    @Test
    void accept() {
        final String S1 = "a.+bar$";
        final String S2 = "/" + S1 + "/";
        final String S3 = "a_regexp_pattern.*[a-z]";
        final String S4 = "%r{" + S3 + "}i";
        final String DATA =
                S2 + "\n"
                        + "//line comment\n"
                        + "  /*block\n"
                        + "comment*/"
                        + S4
                ;

        final CharBuffer cbuf = new CharBuffer(DATA.toCharArray());
        Accepted accepted;

        accepted = RegExp.getTheOne().accept(cbuf);
        assertTrue(isNonNull(accepted));
        {
            WithSpacing.MyAccepted x = downcast(accepted);
            assertTrue(x.hasSpacing());
            assertTrue(S2.equals(x.baseAccepted.toString()));
            RegExp.MyAccepted y = downcast(x.baseAccepted);
            assertTrue(S1.equals(y.regexp));
            assertTrue(y.type == RegExp.MyAccepted.EType.eSlash);
            assertTrue(isNull(y.modifiers));
        }

        accepted = RegExp.getTheOne().accept(cbuf);
        assertTrue(isNonNull(accepted));
        {
            WithSpacing.MyAccepted x = downcast(accepted);
            assertFalse(x.hasSpacing());
            assertTrue(S4.equals(x.baseAccepted.toString()));
            RegExp.MyAccepted y = downcast(x.baseAccepted);
            assertTrue(S3.equals(y.regexp));
            assertTrue(y.type == RegExp.MyAccepted.EType.eCurlied);
            assertTrue(y.modifiers.equals("i"));
        }

        assertTrue(cbuf.isEOF());
    }

}