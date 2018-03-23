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
 * File:   primary_expression.cxx
 * Author: kwpfalzer
 *
 * Created on Mon Nov 13 13:28:34 2017
 */
#include <cassert>
#include "ast/primary_expression.hxx"

TPCPrimaryExpression PrimaryExpression::parse(Parser& parser) {
    auto start = parser.getMark();
    {
        auto literal = Literal::parse(parser);
        if (literal) {
            return new PrimaryExpression(literal);
        }
    }
    if (Token::K_THIS == parser.peek()->code) {
        return new PrimaryExpression(parser.accept());
    }
    if (Token::S_LPAREN == parser.peek()->code) {
        auto expr = Expression::parse(parser.advance());
        if (expr && (Token::S_RPAREN == parser.accept()->code)) {
            return new PrimaryExpression(expr);
        }
    }
    parser.setMark(start);
    {
        auto idExpr = IdExpression::parse(parser);
        if (idExpr) {
            return new PrimaryExpression(idExpr);
        }
    }
    {
        auto lambda = LambdaExpression::parse(parser);
        if (lambda) {
            return new PrimaryExpression(lambda);
        }
    }
    parser.setMark(start);
    return nullptr;
}

PrimaryExpression::PrimaryExpression(TPCLiteral literal)
: type(eLiteral) {
    node = literal;
}

PrimaryExpression::PrimaryExpression(const TRcToken& thisx)
: type(eThis) {
    assert(Token::K_THIS == thisx->code);
    node = new Token(*thisx);
}

PrimaryExpression::PrimaryExpression(TPCExpression expr)
: type(eExpr) {
    node = expr;
}

PrimaryExpression::PrimaryExpression(TPCIdExpression idExpr)
: type(eIdExpr) {
    node = idExpr;
}

PrimaryExpression::PrimaryExpression(TPCLambdaExpression lambda)
: type(eLambda) {
    node = lambda;
}

PrimaryExpression::~PrimaryExpression() {
    delete node;
}
