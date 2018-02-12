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

/* 
 * File:   test1.cxx
 * Author: kwpfalzer
 *
 * Created on October 1, 2017, 3:05 PM
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include <cassert>
#include "parser/parser.hxx"
#include "ast/source_file.hxx"

/*
 * Simple C++ Test Suite
 */

static const std::string TEST = \
        "//line comment\n" \
        "ident include class /*multiline\n" \
        "comment **** /\n" \
        "end here*/\n" \
        ;

void test1() {
    Token::Code code;
    bool isKeyword = Token::isKeyword("import", code);
    assert(isKeyword);
}

void test2() {
    laolx::StringInputStream sis(TEST);
    Parser parser(sis);
}

void test3() {
    static const std::string TEST3 = "import p1.p2 as p2, p3";
    laolx::StringInputStream sis(TEST3);
    Parser parser(sis);
    TPCSourceFile sourceFile = SourceFile::parse(parser);
    assert(sourceFile);
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% parser_test" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (parser_test)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% test1 (parser_test)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (parser_test)" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% test2 (parser_test)" << std::endl;
    
    std::cout << "%TEST_STARTED% test3 (parser_test)" << std::endl;
    test3();
    std::cout << "%TEST_FINISHED% test3 (parser_test)" << std::endl;
    
    std::cout << "%SUITE_FINISHED%" << std::endl;

    return (EXIT_SUCCESS);
}

