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
import java.io.Reader;
import java.util.LinkedList;
import java.util.stream.IntStream;
import static java.util.Objects.isNull;
import static java.util.Objects.nonNull;
import java.util.function.Predicate;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

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

    public Lexer(Reader rdr) {
        this(rdr, null);
    }

    private Lexer(InputStream input, String filename) {
        this(new InputStreamReader(input), filename);
    }

    private Lexer(Reader rdr, String filename) {
        this.input = new BufferedReader(rdr);
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
     * @return n-th lookahead token.
     */
    public Token peek(int n) {
        while (tokens.size() <= n) {
            push(next());
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
        assert tokens.size() > n;
        return tokens.subList(0, n).toArray(new Token[0]);
    }

    public Token accept() {
        return accept(0);
    }

    /**
     * Accept n lookahead tokens.
     *
     * @param n 0 or greater.
     * @return n-th/last token.
     */
    public Token accept(int n) {
        peek(n);
        while (0 < n--) {
            tokens.pop();
        }
        return tokens.pop();
    }

    /**
     * For use during error recovery: skip to beginning of next line; and reset
     * all existing tokens.
     */
    public void advanceToNextLine() {
        tokens.clear();
        readLine(true);
    }

    /**
     * Get next token.
     *
     * @return next token.
     */
    private Token next() {
        if (isEmpty()) {
            if (tokens.isEmpty() || (Token.Code.EOF != tokens.getLast().code)) {
                text = EOF;
                return getToken(Token.Code.EOF);
            }
            return tokens.getLast();
        }
        assert col < line.length();  //expect at least 1 char
        final char ch = line.charAt(col);
        if (isIdentBegin(ch)) {
            return identOrKeyword();
        }
        if ((' ' == ch) || ('\t' == ch)) {
            return whiteSpace();
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
        if (('"' == ch) || ('\'' == ch)) {
            return quoted(ch);
        }
        if (matchTo("%r{", false)) {
            return regexp();
        }
        if (isDigit(ch)
                || (('-' == ch || '+' == ch)
                && testNextChar((Character t) -> isDigit(t)))) {
            return getNumber();
        }
        return getSymbolStartingWith(ch);
    }

    private static final Pattern NUMBER_REX = Pattern.compile("^[\\-\\+]?\\d+(\\.\\d+)?([eE][\\-\\+]?\\d+)?");

    private Token getNumber() {
        startLineNumber = lineNumber;
        startCol = col;
        Matcher matcher = NUMBER_REX.matcher(line.substring(col));
        assert matcher.find();
        col += matcher.end();
        text = line.substring(startCol, col);
        advancePos();
        return getToken(contains(FLOATER) ? Token.Code.FLOAT : Token.Code.INT);
    }

    private static final char[] FLOATER = new char[]{'.', 'e', 'E'};

    private boolean contains(char[] set) {
        for (char ch : set) {
            if (0 <= text.indexOf(ch)) {
                return true;
            }
        }
        return false;
    }

    private boolean charIn(char[] set, char ch) {
        for (char c : set) {
            if (c == ch) {
                return true;
            }
        }
        return false;
    }

    private boolean testNextChar(Predicate<Character> test) {
        return (col < line.length() - 1) ? test.test(line.charAt(col + 1)) : false;
    }

    private Token getSymbolStartingWith(char ch) {
        assert Token.SYMBOLS.containsKey(ch);
        for (Token.Code sym : Token.SYMBOLS.get(ch)) {
            if (matchTo(sym.text)) {
                return getToken(sym);
            }
        }
        assert false; //never
        return null;
    }

    private Token whiteSpace() {
        return whileOnLine(
                (char ch1) -> ((' ' != ch1) && ('\t' != ch1)),
                () -> getToken(Token.Code.WS)
        );
    }

    private Token quoted(char quote) {
        return whileOnLine(
                (char ch) -> (quote == ch),
                () -> getToken(('"' == quote) ? Token.Code.DQSTRING : Token.Code.SQSTRING),
                1,
                true,
                () -> {
                    throw new Exception("Unterminated string");
                }
        );
    }

    private Token regexp() {
        col += 2;   //past %r of %r{
        return whileOnLine(
                (char ch) -> ('}' == ch),
                () -> getToken(Token.Code.REGEXP),
                1,
                true,
                () -> {
                    throw new Exception("Unterminated regexp");
                }
        );
    }

    private Token identOrKeyword() {
        return whileOnLine(
                (char ch1) -> !isIdentAny(ch1),
                () -> getToken(isKeyword() ? keyword : Token.Code.IDENT)
        );
    }

    private interface BreakPredicate {

        boolean cond(char ch);
    }

    private interface CreateToken {

        Token create();
    }

    private interface Unterminated {

        void onCondition();
    }

    private Token whileOnLine(BreakPredicate breaker, CreateToken creator, int colAdj, boolean allowEsc, Unterminated unterminated) {
        startCol = col++;
        startLineNumber = lineNumber;
        char ch;
        for (; col < line.length(); col++) {
            ch = line.charAt(col);
            if (allowEsc) {
                if (ch == '\\') {
                    col++;
                } else if (breaker.cond(ch)) {
                    break;
                }
            } else if (breaker.cond(ch)) {
                break;
            }
        }
        if (nonNull(unterminated) && (col >= line.length())) {
            unterminated.onCondition();
        }
        col += colAdj;
        text = line.substring(startCol, col);
        advancePos();
        return creator.create();
    }

    private Token whileOnLine(BreakPredicate breaker, CreateToken creator) {
        return whileOnLine(breaker, creator, 0, false, null);
    }

    private static final String END_BLOCK_COMMENT = "*/";

    private Token blockComment() {
        StringBuilder buf = new StringBuilder(text);
        int end;
        while (true) { //todo: corner case: EOF
            end = line.indexOf(END_BLOCK_COMMENT, col);
            if (0 > end) {
                buf.append(line.substring(col));
                advancePos(line.length() - col);  //force nextLine
            } else {
                end += END_BLOCK_COMMENT.length();
                buf.append(line.substring(col, end));
                advancePos(end - col);
                break; //while
            }
            if (isEmpty()) {
                throw new Exception("Unterminated block comment");
            }
        }
        text = buf.toString();
        advancePos();
        return getToken(Token.Code.BLOCK_COMMENT);
    }

    public boolean isEOF() {
        if (tokens.isEmpty()) {
            push(next());
        }
        return (Token.Code.EOF == tokens.getFirst().code);
    }

    /**
     * Check if input stream is empty. NOTE: Public API uses isEmpty().
     *
     * @return true on empty stream.
     */
    private boolean isEmpty() {
        return isNull(line);
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
        return (('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z'));
    }

    private static boolean isDigit(char c) {
        return ('0' <= c) && (c <= '9');
    }

    /**
     * Match current position with to.
     *
     * @param to match to.
     * @param setMatch true if adjust positions upon match.
     * @return true if match; else false.
     */
    private boolean matchTo(String to, boolean setMatch) {
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
        if (setMatch) {
            setMatch(n);
        }
        return true;
    }

    private boolean matchTo(String to) {
        return matchTo(to, true);
    }

    private boolean matchTo(char ch) {
        if (line.charAt(col) != ch) {
            return false;
        }
        setMatch(1);
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
     *
     * @param force force read line.
     */
    private void readLine(boolean force) {
        assert force || isEmpty() || (col >= line.length());
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

    private void readLine() {
        readLine(false);
    }

    private void resetText() {
        text = null;
    }

    private Token getToken(Token.Code code) {
        return new Token(getLocation(), code, text);
    }

    private Location getLocation() {
        return new Location(filename, startLineNumber, startCol + 1);
    }

    private Token push(Token token) {
        tokens.add(token);
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

    public class Exception extends RuntimeException {

        public Exception(String reason) {
            //todo: since we're inner class: add location.
            super(getLocation() + ": " + reason);
        }
    }
}
