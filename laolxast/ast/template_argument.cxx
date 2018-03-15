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
 * File:   template_argument.cxx
 * Author: kwpfalzer
 *
 * Created on Tue Nov 14 15:43:26 2017
 */
#include "ast/template_argument.hxx"
#include "ast/constant_expression.hxx"
#include "ast/simple_type_specifier.hxx"

TPCTemplateArgument TemplateArgument::parse(Parser& parser) {
    const auto start = parser.getMark();
    TRcToken bindId = Token::INVALID_TOKEN;
    if ((Token::IDENT == parser.peek()->code)
            && (Token::S_COLON == parser.peek(1)->code)) {
        bindId = parser.peek();
        parser.advance(2);
    }
    TPCAstNode node = ConstantExpression::parse(parser);
    if (!node) {
        node = SimpleTypeSpecifier::parse(parser);
    }
    if (node) {
        return (bindId->isValid())
                ? new TemplateArgument(bindId, node)
                : new TemplateArgument(node)
                ;
    }
    parser.setMark(start);
    return nullptr;
}

TemplateArgument::~TemplateArgument() {
    delete node;
}
