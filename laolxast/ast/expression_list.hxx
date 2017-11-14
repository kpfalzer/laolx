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
 * File:   expression_list.hxx
 * Author: kwpfalzer
 *
 * Created on Mon Nov 13 13:28:34 2017
 */
#ifndef EXPRESSION_LIST_HXX
#define EXPRESSION_LIST_HXX

#include "ast/common.hxx"
#include "ast/initializer_list.hxx"

class ExpressionList;
typedef const ExpressionList* TPCExpressionList;

class ExpressionList : public virtual AstNode {
public:
    static TPCExpressionList parse(Parser& parser);

    explicit ExpressionList(TPCInitializerList init)
    : exprList(init) {
    }

    const TPCInitializerList exprList;

    virtual ~ExpressionList();
};

#endif /* EXPRESSION_LIST_HXX */
