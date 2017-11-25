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
 * File:   overloadable_operator.cxx
 * Author: kwpfalzer
 *
 * Created on Mon Oct 23 17:55:39 2017
 */
#include "ast/overloadable_operator.hxx"

TPCOverloadableOperator OverloadableOperator::parse(Parser& parser) {
    bool isSetter = false;
    TRcToken op = nullptr;
    if (Token::IDENT == parser.peek()->code) {
        op = parser.accept();
        isSetter = parser.accept(Token::S_EQ);
    } else {
        switch(parser.peek()->code) {
            case Token::S_AND: case Token::S_AND2: case Token::S_AND2EQ:
            case Token::S_ANDEQ: 
            case Token::S_CARET: case Token::S_DIV:
            case Token::S_EQ: case Token::S_EXCLAMATION:
            case Token::S_FUNC_CALL: 
            case Token::S_GT: case Token::S_GT2:
            case Token::S_GT2EQ: case Token::S_GTEQ:
            case Token::S_LT2EQ: case Token::S_LTEQ:
            case Token::S_LT: case Token::S_LT2:
            case Token::S_OR: case Token::S_OR2: case Token::S_OR2EQ:
            case Token::S_OREQ:
            case Token::S_PCNT: case Token::S_PCNTEQ:
            case Token::S_PLUS: case Token::S_PLUSEQ:
            case Token::S_STAR: case Token::S_STAR2:
            case Token::S_STAR2EQ: case Token::S_STAREQ:
            case Token::S_SUBSCRIPT: case Token::S_SUBSCRIPT_EQ:
            case Token::S_TILDE:
                op = parser.accept();
                break;
            default:
                ;//do nothing
        }
    }
    return (op) ? new OverloadableOperator(op, isSetter) : nullptr;
}

OverloadableOperator::~OverloadableOperator() {
}
