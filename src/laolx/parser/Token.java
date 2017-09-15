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

import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.stream.Stream;

/**
 * A token.
 *
 * @author kwpfalzer
 */
public class Token {

    public Token(Location location, Code code, String text) {
        this.location = location;
        this.code = code;
        this.text = text;
    }

    public final Location location;
    public final Code code;
    public final String text;

    /**
     * Check if text matches a keyword.
     * @param text text to check.
     * @return Code of matching keyword or null if not a keyword.
     */
    public static Code isKeyword(String text) {
        return KEYWORDS.get(text);
    }
    
    /**
     * Check is text matches a keyword.
     * @param text text to check.
     * @param ref set to keyword code iff text is a keyword; else do nothing.
     * @return true if text matches keyword (and ref[0] updated); else false;
     */
    public static boolean isKeyword(String text, Code ref[]) {
        final Code kwrd = isKeyword(text);
        if (Objects.nonNull(kwrd)) {
            assert 0 < ref.length;
            ref[0] = kwrd;
        }
        return Objects.nonNull(kwrd);
    }
    
    /**
     * Token codes.
     */
    public static enum Code {
        EOF,
        EOLN,
        WS, //whitespace (not including EOF or EOLN)
        LINE_COMMENT,
        BLOCK_COMMENT,
        IDENT,
        DQSTRING, //double-quoted string
        SQSTRING, //single-quoted string
        SYMBOL, //e.g. :foobar
        //
        // K_xxx are keywords
        K_CLASS("class"),
        K_INTERFACE("interface"),
        K_EXTENDS("extends"),
        K_IMPLEMENTS("implements"),
        K_DEFAULT("default"),
        K_STATIC("static"),
        K_FOR("for"),
        K_WHILE("while"),
        K_UNTIL("until"),
        K_CASE("case"),
        K_WHEN("when"),
        K_IF("if"),
        K_ELSE("else"),
        K_ELSIF("elsif"),
        K_THROW("throw"),
        K_CATCH("catch"),
        K_PUBLIC("public"),
        K_PROTECTED("protected"),
        K_PRIVATE("private"),
        K_NIL("nil"),
        K_INT("int"),
        K_FLOAT("float"),
        K_STRING("string"),
        //
        // S_xxx are symbols
        S_TIDLE("~"),
        S_EXCLAMATION("!"),
        S_AT("@"),
        S_POUND("#"),
        S_DOLLAR("$"),
        S_PCNT("%"),
        S_CARET("^"),
        S_AND("&"),
        S_ANDEQ("&="),
        S_AND2("&&"),
        S_AND2EQ("&&="),
        S_STAR("*"),
        S_STAREQ("*="),
        S_STAR2("**"),
        S_STAR2EQ("**="),
        S_LPAREN("("),
        S_RPAREN(")"),
        S_MINUS("-"),
        S_PLUS("+"),
        S_PLUS2("++"),
        S_EQ("="),
        S_PLUSEQ("+="),
        S_MINUSEQ("-="),
        S_LCURLY("{"),
        S_RCURLY("}"),
        S_LBRACK("["),
        S_RBRACK("]"),
        S_OR("|"),
        S_OREQ("|="),
        S_OR2("||"),
        S_OR2EQ("||="),
        S_BSLASH("\\"),
        S_COLON(":"),
        S_COLON2("::"),
        S_SEMI(";"),
        S_DQOUTE("\""),
        S_SQUOTE("'"),
        S_LT("<"),
        S_LTEQ("<="),
        S_LT2("<<"),
        S_LT2EQ("<<="),
        S_GT(">"),
        S_GTEQ(">="),
        S_GT2(">>"),
        S_GT2EQ(">>="),
        S_COMMA(","),
        S_DOT("."),
        S_QMARK("?"),
        S_DIV("/"),
        S_BACKTIC(",");

        private Code() {
            this(null);
        }

        private Code(String text) {
            this.text = text;
        }

        final String text;
    }

    public static final Map<String, Code> KEYWORDS = new HashMap<>();
    public static final Map<Character, Code[]> SYMBOLS = new HashMap<>();

    static {
        initKeywords();
        initSymbols();
    }

    /**
     * Initialize KEYWORDS to Code by String/keyword.
     */
    private static void initKeywords() {
        Stream.of(Code.class.getEnumConstants())
                .filter(code -> code.toString().startsWith("K_"))
                .forEach((Code code) -> {
                    KEYWORDS.put(code.text, code);
                });
    }

    /**
     * Initialize SYMBOLS to array Code[] by 1st symbol char. Code[] is sorted
     * longest to shortest *by text.length); i.e., to find longest matching.
     */
    private static void initSymbols() {
        Map<Character, List<Code>> codesByChar = new HashMap<>();
        Stream.of(Code.class.getEnumConstants())
                .filter(code -> code.toString().startsWith("S_"))
                .forEach((Code code) -> {
                    final Character first = code.text.charAt(0);
                    if (!codesByChar.containsKey(first)) {
                        codesByChar.put(first, new LinkedList<>());
                    }
                    codesByChar.get(first).add(code);
                });
        codesByChar.entrySet().stream().forEach(e -> {
            Code[] value = e
                    .getValue()
                    .stream()
                    .sorted(CODE_COMPARATOR)
                    .toArray(Code[]::new);
            SYMBOLS.put(e.getKey(), value);
        });
    }

    /**
     * Lambda for descending order (by text.length).
     */
    private static final Comparator<Code> CODE_COMPARATOR = (Code o1, Code o2) -> {
        final int len1 = o1.text.length(), len2 = o2.text.length();
        return (len1 < len2) ? 1 : ((len1 == len2) ? 0 : -1);
    };

}
