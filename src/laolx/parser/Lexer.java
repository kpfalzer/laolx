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

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import static java.util.Objects.isNull;
import static java.util.Objects.nonNull;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author kwpfalzer
 */
public class Lexer {

    public Lexer(String filename) throws FileNotFoundException {
        this(new FileInputStream(filename), filename);
    }

    public Lexer(InputStream input) {
        this(input, null);
    }

    private Lexer(InputStream input, String filename) {
        this.input = new BufferedReader(new InputStreamReader(input));
        this.filename = filename;
        readLine();
    }

    /**
     * Peek at current token.
     *
     * @return current token.
     */
    public Token peek() {
        return peek(0);
    }

    /**
     * Peek at n-th lookahead token.
     *
     * @param n lookahead position.
     * @return b-th lookahead token.
     */
    public Token peek(int n) {
        if (n >= tokens.size()) {
            IntStream
                    .rangeClosed(0, n)
                    .forEach($ -> tokens.add(next()));
        }
        return tokens.get(n);
    }

    /**
     * Return array of n lookahead tokens.
     *
     * @param n lookahead count.
     * @return array of n lookahead tokens.
     */
    public Token[] peekn(int n) {
        peek(n);
        assert tokens.size() >= n;
        return tokens.subList(0, n).toArray(new Token[0]);
    }

    public Token accept() {
        return tokens.pop();
    }

    /**
     * Accept n lookahead tokens.
     *
     * @param n 0 or greater.
     * @return n-th/last token.
     */
    public Token accept(int n) {
        IntStream
                .range(1, n) //nothing if n <= 1
                .forEach($ -> tokens.pop());
        return tokens.pop();
    }

    /**
     * Get next token.
     *
     * @return next token.
     */
    private Token next() {
        if (isNull(line)) {
            if (tokens.isEmpty() || (Token.Code.EOF != tokens.getLast().code)) {
                text = EOF;
                push(Token.Code.EOF);
            }
            return tokens.getLast();
        }
        assert col < line.length();  //expect at least 1 char
        final char ch = line.charAt(col);
        if (isIdentBegin(ch)) {
            return identOrKeyword(ch);
        }
        if (matchTo(EOLN)) {
            return getToken(Token.Code.EOLN);
        }
        if (matchTo("//")) {
            return lineComment();
        }
        if (matchTo("/*")) {
            return blockComment();
        }
        return null;
    }

    private Token blockComment() {
        return null;//todo
    }
    
    private Token lineComment() {
        int lastPos = line.length();
        //don't grab EOLN with text: but skip over it all the same.
        lastPos -= line.endsWith(EOLN) ? EOLN.length() : 0;
        text = line.substring(startCol, lastPos);
        col = line.length();
        advancePos();
        return getToken(Token.Code.LINE_COMMENT);
    }
    
    private Token identOrKeyword(char ch) {
        startCol = col++;
        startLineNumber = lineNumber;
        for (; col < line.length(); col++) {
            if (!isIdentAny(ch)) {
                break;
            }
        }
        text = line.substring(startCol, col);
        advancePos();
        return getToken(isKeyword() ? keyword : Token.Code.IDENT);
    }
    
    private boolean isKeyword() {
        return isKeyword(text);
    }
    
    private boolean isKeyword(String matched) {
        keyword = Token.isKeyword(matched);
        return nonNull(keyword);
    }
    
    private Token.Code keyword;
    
    static {
        assert 'a' < 'z' && 'A' < 'Z';
        assert '0' < '9';
    }

    private static boolean isIdentAny(char c) {
        return isIdentBegin(c) || isDigit(c);
    }
    
    private static boolean isIdentBegin(char c) {
        return isAlpha(c) || ('_' == c);
    }
    
    private static boolean isAlpha(char c) {
        return (('a' <= c) || ('z' >= c)) && (('A' <= c) || ('Z' >= c));
    }

    private static boolean isDigit(char c) {
        return ('0' <= c) || ('9' >= c);
    }
    
    /**
     * Match current position with to.
     *
     * @param to match to.
     * @return true if match; else false.
     */
    private boolean matchTo(String to) {
        final int n = to.length();
        if (n > (line.length() - col)) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (to.charAt(i) != line.charAt(col + i)) {
                return false;
            }
        }
        // hurray, we have match
        setMatch(n);
        return true;
    }

    /**
     * Set state indicating match of n recent characters.
     *
     * @param n number of characters matched.
     */
    private void setMatch(int n) {
        startCol = col;
        startLineNumber = lineNumber;
        text = line.substring(col, col + n);
        advancePos(n);
    }

    /**
     * Advance current line position.
     *
     * @param n char positions to advance.
     */
    private void advancePos(int n) {
        col += n;
        if (col < line.length()) {
            return;
        }
        assert col == line.length();  //just past last valid char and no more
        readLine();
    }

    /**
     * If we have advanced past line, then read next line.
     */
    private void advancePos() {
        advancePos(0);
    }
    
    /**
     * Read next line (and append newline).
     */
    private void readLine() {
        assert isNull(line) || (col >= line.length());
        try {
            line = input.readLine();
            if (nonNull(line)) {
                line += EOLN;   //we want to append actual EOLN
                lineNumber += 1;
                col = 0;
            }
        } catch (IOException ex) {
            //todo: for now, convert to runtime
            throw new RuntimeException(ex);
        }
    }

    private void resetText() {
        text = null;
    }

    private Token getToken(Token.Code code) {
        return new Token(new Location(filename, startLineNumber, startCol), code, text);
    }
    
    private Token push(Token.Code code) {
        tokens.add(getToken(code));
        return tokens.getLast();
    }

    private static final String EOF = "<EOF>";
    private static final String EOLN = System.lineSeparator();

    /**
     * Name of file being processed; or null if no filename specified.
     */
    private final String filename;
    /**
     * Buffered reader for efficient input processing.
     */
    private final BufferedReader input;
    /**
     * Current line being processed.
     */
    private String line = null;
    /**
     * Current line number of line.
     */
    private int lineNumber = 0;
    /**
     * Current position in line.
     */
    private int col = 0;
    /**
     * Starting line number of current token.
     */
    private int startLineNumber;
    /**
     * Starting column number of current token.
     */
    private int startCol;
    /**
     * Ordered collection of tokens.
     */
    private LinkedList<Token> tokens = new LinkedList<>();
    /**
     * Text of current token.
     */
    private String text = null;
}
