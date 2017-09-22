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
package laolx.parser.ast;

import laolx.parser.AstNode;
import laolx.parser.Parser;
import laolx.parser.Token;
import static laolx.parser.Token.Code.SQSTRING;
import static laolx.parser.Token.Code.DQSTRING;

/**
 * 
 * @author kwpfalzer
 */
public class XString implements AstNode {
    public static XString match(Parser parser) {
        Token la = parser.la0();
        if (SQSTRING != la.code && DQSTRING != la.code) {
            return null;
        }
        return new XString(parser.accept());
    }
    
    private XString(Token string) {
        this.string = string;
    }
    
    private final Token string;
}
