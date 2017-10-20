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
 * File:   var_name.cxx
 * Author: kwpfalzer
 *
 * Created on Thu Oct 19 20:02:39 2017
 */
#include "ast/var_name.hxx"

TRcVarName VarName::parse(Parser& parser) {
    TRcVarName result(nullptr);
    if (parser.peek()->code == Token::IDENT) {
        result = std::make_shared<VarName>(parser.accept());
    }
    return result;
}

VarName::~VarName() {
}

TRcVarOrAttrName VarOrAttrName::parse(Parser& parser) {
    TRcVarOrAttrName result(nullptr);
    {
        auto varName = VarName::parse(parser);
        if (varName) {
            return std::make_shared<VarOrAttrName>(varName);
        }
    }
    switch (parser.peek()->code) {
        case Token::ATTR_DECL: case Token::ATTR_DECL_RO: case Token::ATTR_DECL_RW:
            return std::make_shared<VarOrAttrName>(parser.accept());
        default:
            ; //do nothing
    }
    return result;
}

VarOrAttrName::~VarOrAttrName() {
}