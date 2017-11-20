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
 * File:   base_type_specifier.cxx
 * Author: kpfalzer
 *
 * Created on Fri Nov 17 12:52:23 2017
 */
#include "ast/base_type_specifier.hxx"

TPCBaseTypeSpecifier BaseTypeSpecifier::parse(Parser& parser) {
    auto start = parser.getMark();
    auto prefix = NestedNameSpecifier::parse(parser);
    auto name = BaseName::parse(parser);
    if (name) {
        return new BaseTypeSpecifier(prefix, name);
    }
    parser.setMark(start);
    return nullptr;
}

BaseTypeSpecifier::BaseTypeSpecifier(TPCNestedNameSpecifier prefix, TPCBaseName name) 
: prefix(prefix), name(name) {

}

BaseTypeSpecifier::~BaseTypeSpecifier() {
    delete prefix;
    delete name;
}
