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
 * File:   lambda_expression.cxx
 * Author: kwpfalzer
 *
 * Created on Mon Nov 13 18:34:06 2017
 */
#include "ast/lambda_expression.hxx"

TPCLambdaExpression LambdaExpression::parse(Parser& parser) {
    auto start = parser.getMark();
    if (Token::K_DEF == parser.accept()->code) {
        auto name = MethodName::parse(parser);
        if (name) {
            auto mpd = MethodParametersDeclaration::parse(parser);
            auto ret = ReturnSpecifier::parse(parser);
            if (Token::S_LCURLY == parser.accept()->code) {
                auto body = MethodBody::parse(parser);
                if (body) {
                    if (Token::S_RCURLY == parser.accept()->code) {
                        return new LambdaExpression(name, mpd, ret, body);
                    }
                }
            }
        }
    }
    parser.setMark(start);
    return nullptr;
}

LambdaExpression::LambdaExpression(
        TPCMethodName name,
        TPCMethodParametersDeclaration params,
        TPCReturnSpecifier returnx,
        TPCMethodBody body)
: name(name), params(params), returnx(returnx), body(body) {
}

LambdaExpression::~LambdaExpression() {
    delete name;
    delete params;
    delete returnx;
    delete body;
}
