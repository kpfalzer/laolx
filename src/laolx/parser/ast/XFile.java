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
import static laolx.parser.Token.Code.EOF;
import static laolx.parser.Token.Code.K_INCLUDE;

/**
 *
 * @author kwpfalzer
 */
public class XFile implements AstNode {

    public static XFile match(Parser parser) {
        XFile contents = new XFile();
        while (K_INCLUDE == parser.la0Code()) {
            contents.includes.add(IncludeStatement.match(parser));
        }
        Statement stmt;
        Declaration decl;
        while (true) {
            stmt = Statement.match(parser);
            if (Objects.nonNull(stmt)) {
                contents.stmtsAndDecls.add(stmt);
            }
            decl = Declaration.match(parser);
            if (Objects.nonNull(decl)) {
                contents.stmtsAndDecls.add(decl);
            } else if (Objects.isNull(stmt)) {
                break;
            }
        }
        if (EOF != parser.la0Code()) {
            parser.error();
        }
        return contents;
    }

    private final LinkedList<IncludeStatement> includes = new LinkedList<>();
    private final LinkedList<AstNode> stmtsAndDecls = new LinkedList<>();
}
