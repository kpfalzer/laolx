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
 * File:   binary_op.cxx
 * Author: kwpfalzer
 *
 * Created on Mon Nov 20 14:51:56 2017
 */
#include "ast/binary_op.hxx"

TPCBinaryOp BinaryOp::parse(Parser& parser) {
    switch (parser.peek()->code) {
        case Token::S_PCNT:
        case Token::S_CARET:
        case Token::S_AND:
        case Token::S_AND2:
        case Token::S_STAR:
        case Token::S_STAR2:
        case Token::S_MINUS:
        case Token::S_PLUS:
        case Token::S_EQGT:
        case Token::S_MATCH:
        case Token::S_NOTMATCH:
        case Token::S_OR:
        case Token::S_OR2:
        case Token::S_LT:
        case Token::S_LTEQ:
        case Token::S_LT2:
        case Token::S_GT:
        case Token::S_GTEQ:
        case Token::S_GT2:
        case Token::S_DIV:
            return new BinaryOp(parser.accept());
        default:
            ; //do nothing
    }
    return nullptr;
}

BinaryOp::~BinaryOp() {
}
