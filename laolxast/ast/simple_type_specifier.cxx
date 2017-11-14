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
 * File:   simple_type_specifier.cxx
 * Author: kwpfalzer
 *
 * Created on Mon Oct 23 17:41:53 2017
 */
#include "ast/simple_type_specifier.hxx"

TPCSimpleTypeSpecifier SimpleTypeSpecifier::parse(Parser& parser) {
    auto start = parser.getMark();
    auto const code = parser.peek()->code;
    switch (code) {
        case Token::K_INT:
        case Token::K_FLOAT:
        case Token::K_STRING:
            return new SimpleTypeSpecifier(parser.accept());
        default:
            ;//do nothing
    }
    auto spec = NestedNameSpecifier::parse(parser);
    auto type = TypeName::parse(parser);
    if (type) {
        return new SimpleTypeSpecifier(spec, type);
    }
    parser.setMark(start);
    return nullptr;
}

SimpleTypeSpecifier::SimpleTypeSpecifier(const TRcToken& token) 
: nodes({new Token(*token), nullptr}) {
}

SimpleTypeSpecifier::SimpleTypeSpecifier(TPCNestedNameSpecifier spec, TPCTypeName type) 
: nodes({spec, type}) {
}

SimpleTypeSpecifier::~SimpleTypeSpecifier() {}
