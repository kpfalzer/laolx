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
import org.junit.jupiter.api.Test;

import java.util.LinkedList;
import java.util.List;
import java.util.Vector;

import static apfev2.runtime.Util.isNonNull;
import static org.junit.jupiter.api.Assertions.*;

class TokensTest {
    @Test
    void test() {
        {
            Acceptor acceptor[] = new Acceptor[]{
                    Tokens.K_CLASS.acceptor,
                    Tokens.K_CLASS.acceptor
            };
            assertTrue(acceptor[0].equals(acceptor[1]));
        }

        String DATA =
                "class foobar {}//line comment\n";

        CharBuffer cbuf = new CharBuffer(DATA.toCharArray());

        {
            Acceptor acceptors[] = new Acceptor[]{
                    Tokens.K_CLASS.acceptor,
                    Tokens.IDENT.acceptor,
                    Tokens.S_LCURLY.acceptor,
                    Tokens.S_RCURLY.acceptor
            };
            List<Accepted> accepted = new LinkedList();
            for (Acceptor acceptor : acceptors) {
                accepted.add(acceptor.accept(cbuf));
            }
            long n = accepted.stream().filter(a -> isNonNull(a)).count();
            assertTrue(acceptors.length == n);
        }

    }
}