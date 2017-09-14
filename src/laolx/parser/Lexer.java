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
        return IntStream
                .range(0, n)
                .map(Lexer::next)
                .collect(Collectors.toList())
                .toArray(new Token[0]);
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
        char ch = 0;
        while (true) {
            if (isNull(line)) {
                col = 0;
                try {
                    line = input.readLine();
                } catch (IOException ex) {
                    //todo: for now, convert to runtime
                    throw new RuntimeException(ex);
                }
                if (isNull(line)) {
                    final Token lastToken = tokens.peekLast();
                    if (tokens.isEmpty() || (lastToken.code != Token.Code.EOF)) {
                        lineNumber += 1;
                        text = new StringBuilder(EOF);
                        return push(Token.Code.EOF);
                    }
                    assert lastToken.code == Token.Code.EOF;
                    return lastToken;
                }
                lineNumber += 1;
                resetText();
            }
            if (col >= line.length()) {
                text.append(EOLN);
                line = null;
                return push(Token.Code.EOLN);
            }
            ch = line.charAt(col);
            //todo
        }
        return null;
    }

    private void resetText() {
        text.setLength(0);
    }
    
    private Token push(Token.Code code) {
        tokens.add(new Token(new Location(filename, lineNumber, col), code, text.toString()));
        return tokens.getLast();
    }

    private static final String EOF = "<EOF>";
    private static final String EOLN = System.lineSeparator();

    private final String filename;
    private final BufferedReader input;
    private String line = null;
    private int lineNumber = 0, col = 0;
    private LinkedList<Token> tokens = new LinkedList<>();
    private StringBuilder text = new StringBuilder();
}
