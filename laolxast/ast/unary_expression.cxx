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
 * File:   unary_expression.cxx
 * Author: kwpfalzer
 *
 * Created on Mon Nov 13 11:03:15 2017
 */
#include "ast/unary_expression.hxx"

TPCUnaryExpression UnaryExpression::parse(Parser& parser) {
    auto start = parser.getMark();
    {
        auto postfix = PostfixExpression::parse(parser);
        if (postfix) {
            return new UnaryExpression(postfix);
        }
    }
    {
        const auto preop = parser.peek();
        const auto code = preop->code;
        if (Token::S_PLUS2 == code || Token::S_MINUS2) {
            auto uexpr = UnaryExpression::parse(parser.advance());
            if (uexpr) {
                return new UnaryExpression(preop, uexpr);
            }
        }
    }
    parser.setMark(start);
    {
        auto uop = UnaryOperator::parse(parser);
        if (uop) {
            auto uexpr = UnaryExpression::parse(parser);
            if (uexpr) {
                return new UnaryExpression(uop, uexpr);
            }
        }
    }
    parser.setMark(start);
    return nullptr;
}

UnaryExpression::UnaryExpression(TPCPostfixExpression expr) 
: type(ePostfix) {
    m_expr.m_postfixExpr = expr;
}

UnaryExpression::UnaryExpression(const TRcToken& preop, TPCUnaryExpression expr) 
: type((Token::S_PLUS2 == preop->code) ? ePreIncr : ePreDecr) {
    m_expr.m_preopExpr = expr;
}

UnaryExpression::UnaryExpression(TPCUnaryOperator uop,  TPCUnaryExpression expr)
: type(eUopExpr) {
    m_expr.m_uop = uop;
    m_expr.m_expr = expr;
}

UnaryExpression::~UnaryExpression() {
    switch (type) {
        case ePreDecr: case ePreIncr:
            delete m_expr.m_preopExpr;
            break;
        case ePostfix:
            delete m_expr.m_postfixExpr;
            break;
        default:
            delete m_expr.m_uop;
            delete m_expr.m_expr;
            break;
    }
}
