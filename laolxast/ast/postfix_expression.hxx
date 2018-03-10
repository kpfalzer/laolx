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
 * File:   postfix_expression.hxx
 * Author: kwpfalzer
 *
 * Created on Mon Nov 13 11:03:15 2017
 */
#ifndef POSTFIX_EXPRESSION_HXX
#define POSTFIX_EXPRESSION_HXX

#include "ast/common.hxx"


class PostfixExpression : public virtual AstNode {
public:
    static TPCPostfixExpression parse(Parser& parser);

    virtual ~PostfixExpression();
    
private:
    class X;
    class Y;
    typedef const X* TPCX;
    typedef const Y* TPCY;
    
    TPCX x;
    TPCY y;
    
public:
    explicit PostfixExpression(TPCY y, TPCX x);
    
};

#endif /* POSTFIX_EXPRESSION_HXX */
