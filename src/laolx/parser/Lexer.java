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

    private Token next() {
        if (isNull(line)) {
            if (!tokens.isEmpty() && (Token.Code.EOF != tokens.getLast().code)) {
                text = new StringBuilder(EOF);
                push(Token.Code.EOF);
            }
            return tokens.getLast();
        }
        char ch = 0;
        
        return null;
    }

    /**
     * Match current position with to. 
     * @param to match to.
     * @return true if match; else false.
     */
    private boolean matchTo(String to) {
        //todo
        return false;
    }
    
    private void readLine() {
        assert isNull(line) || (col >= line.length());
        try {
            line = input.readLine();
        } catch (IOException ex) {
            //todo: for now, convert to runtime
            throw new RuntimeException(ex);
        }
        lineNumber += 1;
        col = 0;
        resetText();
    }

    private void resetText() {
        text.setLength(0);
    }

    private Token push(Token.Code code) {
        tokens.add(new Token(new Location(filename, startLineNumber, startCol), code, text.toString()));
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
    private StringBuilder text = new StringBuilder();
}
