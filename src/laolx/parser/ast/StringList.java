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

import java.util.LinkedList;
import java.util.Objects;
import laolx.parser.AstNode;
import laolx.parser.Parser;
import static laolx.parser.Token.Code.S_COMMA;

/**
 * 
 * @author kwpfalzer
 */
public class StringList implements AstNode {
    public static StringList matches(Parser parser) {
        StringList stringList = null;
        XString string;
        while (true) {
            string = XString.matches(parser);
            if (Objects.isNull(string)) {
                return stringList;
            }
            if (Objects.isNull(stringList)) {
                stringList = new StringList(string);
            } else {
                stringList.add(string);
            }
            if (S_COMMA != parser.la0Code()) {
                break; //while
            } else {
                parser.accept();
                parser.skipOverWsCommentsEOLN();
            }
        }
        parser.skipOverWsCommentsEOLN();
        return stringList;
    }
    
    private StringList(XString string) {
        stringList = new LinkedList<>();
        stringList.add(string);
    }
    
    private void add(XString string) {
        stringList.add(string);
    }
    
    private final LinkedList<XString> stringList;
}
