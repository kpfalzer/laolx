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

class NumberTest {

    @Test
    void accept() {
        final String S1 = "10_234";
        final String S2 = "0x1_2dead_bEEF";
        final String S3 = "5'b11_000";
        final String S4 = "123.456";
        final String DATA =
                S1 + "\n"
                        + S2 + "\n"
                        + S3 + "\n"
                        + S4;

        final CharBuffer cbuf = new CharBuffer(DATA.toCharArray());

        expect(cbuf, S1, Number.EType.eInteger);
        expect(cbuf, S2, Number.EType.eHex);

        //assertTrue(cbuf.isEOF());

    }

    private static void expect(CharBuffer cbuf, String gold, Number.EType type) {
        Accepted accepted = Number.THE_ONE.accept(cbuf);
        assertTrue(isNonNull(accepted));
        WithSpacing.MyAccepted x = downcast(accepted);
        assertTrue(x.hasSpacing());
        Number.MyAccepted y = downcast(x.baseAccepted);
        assertTrue(gold.equals(y.value));
        assertTrue(y.type == type);
    }
}