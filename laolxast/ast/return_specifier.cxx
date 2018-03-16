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
 * File:   return_specifier.cxx
 * Author: kwpfalzer
 *
 * Created on Mon Oct 23 17:55:39 2017
 */
#include "ast/return_specifier.hxx"

TPCReturnSpecifier ReturnSpecifier::parse(Parser& parser) {
    if (Token::S_EQGT != parser.peek()->code) {
        return nullptr;
    }
    const auto start = parser.getMark();
    auto specifier = SimpleTypeSpecifier::parse(parser.advance(1));
    if (specifier) {
        return new ReturnSpecifier(specifier);
    }
    parser.setMark(start);
    return nullptr;
}

ReturnSpecifier::~ReturnSpecifier() {
    delete specifier;
}
