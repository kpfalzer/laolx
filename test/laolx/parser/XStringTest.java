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
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

class XStringTest {

    @Test
    void accept() {
        final String S1 = "a string";
        final String S2 = "\"" + S1 + "\"";
        final String S3 = "single quoted";
        final String S4 = "'" + S3 + "'";
        final String S5 = "curlyq quoted";
        final String S6 = "%s{" + S5 + "}";
        final String DATA =
                S2 + "\n"
                + "//line comment\n"
                + "  /*block\n"
                + "comment*/"
                + S4
                + S6 + "\n"
                + "  \t\n//line comment\n\n"
                + "\"unterminated stringxxxx"
                ;

        final CharBuffer cbuf = new CharBuffer(DATA.toCharArray());
        Accepted accepted;

        accepted = XString.getTheOne().accept(cbuf);
        assertTrue(isNonNull(accepted));
        {
            WithSpacing.MyAccepted x = downcast(accepted);
            assertTrue(x.hasSpacing());
            assertTrue(S2.equals(x.baseAccepted.toString()));
            XString.MyAccepted y = downcast(x.baseAccepted);
            assertTrue(S1.equals(y.string));
            assertTrue(y.type == XString.MyAccepted.EType.eDouble);
        }

        accepted = XString.getTheOne().accept(cbuf);
        assertTrue(isNonNull(accepted));
        {
            WithSpacing.MyAccepted x = downcast(accepted);
            assertFalse(x.hasSpacing());
            assertTrue(S4.equals(x.baseAccepted.toString()));
            XString.MyAccepted y = downcast(x.baseAccepted);
            assertTrue(S3.equals(y.string));
            assertTrue(y.type == XString.MyAccepted.EType.eSingle);
        }

        accepted = XString.getTheOne().accept(cbuf);
        assertTrue(isNonNull(accepted));
        {
            WithSpacing.MyAccepted x = downcast(accepted);
            assertTrue(x.hasSpacing());
            assertTrue(S6.equals(x.baseAccepted.toString()));
            XString.MyAccepted y = downcast(x.baseAccepted);
            assertTrue(S5.equals(y.string));
            assertTrue(y.type == XString.MyAccepted.EType.eCurlied);
        }

        try {
            accepted = XString.getTheOne().accept(cbuf);
        }
        catch (Exception ex) {
            String s = ex.toString();
            System.out.printf("Caught error: %s\n", s);
            assertTrue(s.contains("found <EOF> while expecting: '\"'"));
        }
        assertTrue(cbuf.isEOF());
    }

}