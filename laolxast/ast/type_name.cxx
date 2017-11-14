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
 * File:   type_name.cxx
 * Author: kwpfalzer
 *
 * Created on Tue Nov 14 13:24:10 2017
 */
#include "ast/type_name.hxx"
#include "ast/class_name.hxx"
#include "ast/typedef_name.hxx"

TPCTypeName TypeName::parse(Parser& parser) {
    auto start = parser.getMark();
    TPCAstNode node = ClassName::parse(parser);
    if (!node) {
        node = TypedefName::parse(parser);
    }
    if (node) {
        return new TypeName(node);
    }
    parser.setMark(start);
    return nullptr;
}

TypeName::~TypeName() {
    delete node;
}
