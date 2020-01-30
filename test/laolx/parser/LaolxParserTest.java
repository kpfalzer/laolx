/*
 *
 *  * The MIT License
 *  *
 *  * Copyright 2018 kpfalzer.
 *  *
 *  * Permission is hereby granted, free of charge, to any person obtaining a copy
 *  * of this software and associated documentation files (the "Software"), to deal
 *  * in the Software without restriction, including without limitation the rights
 *  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  * copies of the Software, and to permit persons to whom the Software is
 *  * furnished to do so, subject to the following conditions:
 *  *
 *  * The above copyright notice and this permission notice shall be included in
 *  * all copies or substantial portions of the Software.
 *  *
 *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  * THE SOFTWARE.
 *
 *
 */

package laolx.parser;

// import ANTLR's runtime libraries

import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;
import org.junit.jupiter.api.Test;

import java.util.function.Function;

import static org.junit.jupiter.api.Assertions.*;

class LaolxParserTest {

    @org.junit.jupiter.api.Test
    void number() {
        final String DATA[] = new String[]{
                "10_234 //comment",
                "0x1_2dead_bEEF ",
                "5'b11_000 ",
                "123.456 ",
                "1.0e-4 ",
                "8'hFF00 "
        };

        runTest(DATA, LaolxParser::number);
    }

    @org.junit.jupiter.api.Test
    void simpleTypeSpecifier() {
        final String DATA[] = new String[]{
                "int",
                "float",
                "string",
                "some_type",
                "nmsp1::nmsp2::T1 ",
                "globnmsp::T2 ",
                "List<float, CEXPR> ",
                "Map<K: string, T: List<float, CEXPR>>",
                //not valid type: "%r{[a-zA-Z_]?regexp$}",
                "%t{T1 v, int x, float z}",
                "Tuple<T1: int, T2: float> [][]",
                "function{(a,b)->float}"
        };

        runTest(DATA, LaolxParser::simpleTypeSpec);
    }

    @org.junit.jupiter.api.Test
    void simpleDecl() {
        final String DATA[] = new String[]{
                "function{(a,b)->float} v, const float *x",
                "a,*b,t[] d",
                "var t1 c, const *f"
        };

        runTest(DATA, LaolxParser::simpleDecl);
    }

    @org.junit.jupiter.api.Test
    void expression() {
        final String DATA[] = new String[]{
                "a+b-456.7",
                "a+b.?foo(\"abc\")"
        };

        runTest(DATA, LaolxParser::expression);
    }

    static void runTest(String[] data, Function<LaolxParser, ParseTree> rule) {
        for (String s : data) {
            // create a CharStream that reads from standard input
            CharStream input = CharStreams.fromString(s);
            // create a lexer that feeds off of input CharStream
            LaolxLexer lexer = new LaolxLexer(input);
            // create a buffer of tokens pulled from the lexer
            CommonTokenStream tokens = new CommonTokenStream(lexer);
            // create a parser that feeds off the tokens buffer
            LaolxParser parser = new LaolxParser(tokens);
            ParseTree tree = rule.apply(parser); // begin parsing at init rule
            System.out.println(tree.toStringTree(parser)); // print LISP-style tree
        }
    }
}