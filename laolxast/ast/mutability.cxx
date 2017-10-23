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
 * File:   mutability.cxx
 * Author: kwpfalzer
 *
 * Created on Thu Oct 19 19:53:52 2017
 */
#include "ast/mutability.hxx"

TPCMutability Mutability::parse(Parser& parser) {
    switch (parser.peek()->code) {
        case Token::K_VAR:
        case Token::K_CONST:
            return new Mutability(parser.accept());
        default:
            ; //do nothing
    }
    return nullptr;
}

bool Mutability::isConst() const {
    return !isVar();
}

bool Mutability::isVar() const {
    return (mutability && (Token::K_VAR == mutability->code));
}

Mutability::~Mutability() {
}
