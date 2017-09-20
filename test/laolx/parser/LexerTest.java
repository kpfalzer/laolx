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

import java.io.StringReader;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author kwpfalzer
 */
public class LexerTest {

    public LexerTest() {
        //force Token load
        Token.initialize();
        dut = new Lexer(new StringReader(TEXT));
    }

    private final static String TEXT
            = /* 1*/ "class foobar\n"
            /* 2*/ + "bar:sym1 :     if\n"
            /* 3*/ + "when //a line comment\n"
            /* 4*/ + "until /***block   \n"
            /* 5*/ + "if when case switch *\n"
            /* 6*/ + "... * */ interface\n"
            /* 7*/ + "'single quote(\\')' and \"double\\\" \"\n"
            /* 8*/ + "an >> \"unterminated string\n"
            /* 9*/ + "regexp %r{:\\w+\\$}\n"
            /*10*/ + "1234+-456.678*89.0e-09\n";
    private final Lexer dut;

    @Test
    public void test() {
        Token tok = dut.peek();
        assertTrue(Token.Code.K_CLASS == tok.code);
        assertTrue(Token.Code.K_CLASS == dut.accept().code);
        assertFalse(dut.isEOF());
        assertTrue(Token.Code.WS == dut.peek(0).code);
        assertTrue(Token.Code.IDENT == dut.peek(1).code);
        assertTrue(Token.Code.EOLN == dut.peek(2).code);
        tok = dut.accept(2);
        assertTrue(Token.Code.EOLN == tok.code);
        {
            /* 2*/
            Token[] toks = dut.peekn(8);
            assertTrue(toks[1].code == Token.Code.S_COLON);
            assertTrue(toks[2].code == Token.Code.IDENT);
            dut.accept(toks.length - 1);
        }
        {
            /* 3*/
            Token[] toks = dut.peekn(3);
            dut.accept(toks.length - 1);
        }
        {
            /* 4,5,6*/
            Token[] toks = dut.peekn(6);
            assertTrue(toks[2].code == Token.Code.BLOCK_COMMENT);
            assertTrue(toks[4].code == Token.Code.K_INTERFACE);
            dut.accept(toks.length - 1);
        }
        {
            /* 7*/
            Token[] toks = dut.peekn(6);
            dut.accept(toks.length - 1);
        }
        {
            /* 8*/
            boolean caughtException = false;
            try {
                Token[] toks = dut.peekn(5);
                dut.accept(toks.length - 1);
            } catch (RuntimeException ex) {
                System.err.println(ex);
                caughtException = true;
            }
            assertTrue(caughtException);
            dut.advanceToNextLine();
        }
        {
            /* 9*/
            Token[] toks = dut.peekn(4);
            assertTrue(toks[2].code == Token.Code.REGEXP);
            dut.accept(toks.length - 1);
        }
        {
            /*10*/
            Token[] toks = dut.peekn(6);
            dut.accept(toks.length - 1);
        }
    }

}
