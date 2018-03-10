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
 * File:   lambda_expression.hxx
 * Author: kwpfalzer
 *
 * Created on Mon Nov 13 18:34:06 2017
 */
#ifndef LAMBDA_EXPRESSION_HXX
#define LAMBDA_EXPRESSION_HXX

#include "ast/common.hxx"
#include "ast/name.hxx"
#include "ast/method_parameters_declaration.hxx"
#include "ast/return_specifier.hxx"
#include "ast/method_body.hxx"


class LambdaExpression : public virtual AstNode {
public:
    static TPCLambdaExpression parse(Parser& parser);

    explicit LambdaExpression(
            TPCName name,
            TPCMethodParametersDeclaration params,
            TPCReturnSpecifier returnx,
            TPCMethodBody body
            );

    virtual ~LambdaExpression();

    const TPCName name;
    const TPCMethodParametersDeclaration params;
    const TPCReturnSpecifier returnx;
    const TPCMethodBody body;
};

#endif /* LAMBDA_EXPRESSION_HXX */
