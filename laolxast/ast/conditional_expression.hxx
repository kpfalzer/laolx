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
 * File:   conditional_expression.hxx
 * Author: kwpfalzer
 *
 * Created on Mon Nov 20 14:14:07 2017
 */
#ifndef CONDITIONAL_EXPRESSION_HXX
#define CONDITIONAL_EXPRESSION_HXX

#include <array>
#include "ast/common.hxx"
#include "ast/expression_ele.hxx"
#include "ast/expression.hxx"

class ConditionalExpression;
typedef const ConditionalExpression* TPCConditionalExpression;

class ConditionalExpression : public virtual AstNode {
public:
    static TPCConditionalExpression parse(Parser& parser);

    explicit ConditionalExpression(TPCExpressionEle expr);
    explicit ConditionalExpression(
            TPCExpressionEle expr,
            TPCExpression ifTrue,
            TPCExpression ifFalse);

    const TPCExpressionEle expr;
    const TPCExpression ifTrue, ifFalse;

    virtual ~ConditionalExpression();
};

#endif /* CONDITIONAL_EXPRESSION_HXX */
