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
 * File:   expression_ele.hxx
 * Author: kwpfalzer
 *
 * Created on Mon Nov 20 14:37:48 2017
 */
#ifndef EXPRESSION_ELE_HXX
#define EXPRESSION_ELE_HXX

#include "ast/common.hxx"
#include "binary_op.hxx"
#include "unary_expression.hxx"

class ExpressionEle;
typedef const ExpressionEle* TPCExpressionEle;

class ExpressionEle : public virtual AstNode {
public:
    typedef std::pair<TPCBinaryOp, TPCExpressionEle> TEle;

    static TPCExpressionEle parse(Parser& parser);

    explicit ExpressionEle(TPCUnaryExpression expr);
    explicit ExpressionEle(
            TPCUnaryExpression expr,
            const laolx::Array<TEle>& moExprs);

    const TPCUnaryExpression expr;
    const laolx::Array<TEle> moExprs;

    virtual ~ExpressionEle();
};

#endif /* EXPRESSION_ELE_HXX */
