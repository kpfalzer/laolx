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

import java.io.StringReader;
import laolx.parser.Parser;
import static laolx.parser.Token.Code.K_CLASS;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author kwpfalzer
 */
public class IncludeStatementTest {
    
    private static final String TEXT
            = "  include 'pkg1', \n"
            + " 'pkg2', 'pkg3' include 'pkg4',\n"
            + " 'pkg5' \n"
            + ", 'pkg6'\n"
            + "class foo {}//todo";
    
    @Test
    public void testMatches() {
        Parser parser = new Parser(new StringReader(TEXT));
        IncludeStatement stmt = IncludeStatement.match(parser);
        assertNotNull(stmt);
        stmt = IncludeStatement.match(parser);
        assertNotNull(stmt);
        assertTrue(K_CLASS == parser.la0Code());
    }
    
}
