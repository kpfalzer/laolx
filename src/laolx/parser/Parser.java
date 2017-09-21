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

import java.io.FileNotFoundException;
import java.io.Reader;
import java.util.LinkedList;
import java.util.Objects;
import static laolx.parser.Token.Code.WS;
import laolx.parser.ast.Comment;
import laolx.parser.ast.XFile;

/**
 * Parse a single file.
 *
 * @author kwpfalzer
 */
public class Parser implements CommentCollector {

    public Parser(String filename) throws FileNotFoundException {
        lexer = new Lexer(filename);
    }

    public Parser(Reader rdr) {
        lexer = new Lexer(rdr);
    }

    /**
     * Parse file.
     *
     * @return true on success, false if errors.
     */
    public boolean parse() {
        xfile = XFile.matches(this);
        return Objects.nonNull(xfile);
    }

    /**
     * Try to match set of tokens with lookahead.
     *
     * @param codes set of token codes to match.
     * @return true if lookahead matches (else false).
     */
    public boolean hasMatch(Token.Code... codes) {
        Token lookahead[] = lexer.peekn(codes.length - 1);
        for (int i = 0; i < codes.length; i++) {
            if (codes[i] != lookahead[i].code) {
                return false;
            }
        }
        return true;
    }

    public Token la0() {
        return lexer.peek();
    }

    public Token.Code la0Code() {
        return la0().code;
    }
    
    public Token accept() {
        return lexer.accept();
    }

    public boolean skipOverWhitespace() {
        if (WS == la0().code) {
            accept();
            return true;
        }
        return false;
    }

    /**
     * Skip over whitespace and comments.
     * Accumulate comments and also mark if we crossed onto another line;
     * i.e., EOLN detection.
     * @return true if we detected EOLN.
     */
    public boolean skipOverWsCommentsEOLN() {
        final int startingLine = lexer.getLineNumber();
        for (boolean stay = true; stay;) {
            switch (la0Code()) {
                case WS:
                    accept();
                    break;
                case LINE_COMMENT: case BLOCK_COMMENT:
                    add(new Comment(accept()));
                    break;
                default:
                    stay = false;
            }
        }
        detectedEOLN = (lexer.getLineNumber() > startingLine);
        return detectedEOLN;
    }
    
    private final Lexer lexer;
    private XFile xfile;
    private final LinkedList<Comment> comments = new LinkedList<>();
    private boolean detectedEOLN = false;

    @Override
    public void add(Comment comment) {
        comments.add(comment);
    }
}
