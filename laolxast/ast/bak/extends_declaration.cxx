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
 * File:   extends_declaration.cxx
 * Author: kwpfalzer
 *
 * Created on Fri Oct  6 19:30:04 2017
 */
#include "ast/extends_declaration.hxx"

//ExtendsDeclaration: K_EXTENDS BaseName (COMMA BaseName)*

TRcExtendsDeclaration ExtendsDeclaration::parse(Parser& parser, Token::Code code) {
    TRcExtendsDeclaration result(nullptr);
    if (code != parser.peek()->code) {
        return result;
    }
    auto start = parser.getMark();
    laolx::Array<TRcBaseName> names;
    parser.accept(); //K_EXTENDS|IMPLEMENTS
    while (true) {
        TRcBaseName baseName = BaseName::parse(parser);
        if (!baseName) {
            break;
        }
        names << baseName;
        if (Token::S_COMMA != parser.accept()->code) {
            break;
        }
    }
    if (names.isEmpty()) {
        parser.setMark(start);
    } else {
        result = std::make_shared<ExtendsDeclaration>(names.compact());
    }
    return result;
}

ExtendsDeclaration::ExtendsDeclaration(const laolx::Array<TRcBaseName>& names)
: m_names(names) {

}

ExtendsDeclaration::~ExtendsDeclaration() {
}
