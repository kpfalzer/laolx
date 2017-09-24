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
import static laolx.parser.Token.Code.BLOCK_COMMENT;
import static laolx.parser.Token.Code.EOF;
import static laolx.parser.Token.Code.EOLN;
import static laolx.parser.Token.Code.LINE_COMMENT;
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
        getAllTokens();
    }

    public Parser(Reader rdr) {
        lexer = new Lexer(rdr);
        getAllTokens();
    }

    /**
     * Parse file.
     *
     * @return true on success, false if errors.
     */
    public boolean parse() {
        xfile = XFile.match(this);
        return Objects.nonNull(xfile);
    }

    private void getAllTokens() {
        LinkedList<Token> xtokens = new LinkedList<>();
        Token la;
        Token.Code code;
        while (true) {
            la = lexer.accept();
            code = la.code;
            if (LINE_COMMENT == code || BLOCK_COMMENT == code) {
                add(new Comment(la));
            } else if (EOF == code) {
                xtokens.add(la);
                break;
            } else if (WS != code && EOLN != code) {
                xtokens.add(la);
            }
        }
        this.tokens = xtokens.toArray(new Token[0]);
    }

    private Token[] tokens = null;
    private int tokpos = 0;

    public int getMark() {
        return tokpos;
    }

    public int getMarkThenAccept() {
        int mark = getMark();
        accept();
        return mark;
    }

    public void setMark(int pos) {
        tokpos = pos;
    }

    /**
     * Try to match set of tokens with lookahead.
     *
     * @param codes set of token codes to match.
     * @return true if lookahead matches (else false).
     */
    public boolean hasMatch(Token.Code... codes) {
        for (int i = 0; i < codes.length; i++) {
            if (codes[i] != tokens[tokpos + i].code) {
                return false;
            }
        }
        return true;
    }

    public static boolean hasEOLN(Token from, Token to) {
        return (from.location.line != to.location.line);
    }

    public Token la(int n) {
        return tokens[tokpos + n];
    }

    public Token la0() {
        return la(0);
    }

    public Token.Code la0Code() {
        return la0().code;
    }

    public Token accept() {
        return (la0Code() != EOF) ? tokens[tokpos++] : la0();
    }

    private final Lexer lexer;
    private XFile xfile;
    private final LinkedList<Comment> comments = new LinkedList<>();

    @Override
    public void add(Comment comment) {
        comments.add(comment);
    }
    
    public void error() {
        throw new Exception();
    }
    
    public class Exception extends RuntimeException {

        public Exception() {
            super(la0().location.toString() + ": error at '" + la0().text + "'");
        }
    }
}
