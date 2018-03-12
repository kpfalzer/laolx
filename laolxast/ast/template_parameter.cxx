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
 * File:   template_parameter.cxx
 * Author: kpfalzer
 *
 * Created on Fri Nov 17 12:48:41 2017
 */
#include "ast/template_parameter.hxx"
#include "ast/template_argument.hxx"

TPCTemplateParameter TemplateParameter::parse(Parser& parser) {
    //TemplateParameter: IDENT (S_EQ TemplateArgument)?
    if (Token::IDENT != parser.peek()->code) {
        return nullptr;
    }
    const auto ident = parser.accept();
    if (Token::S_EQ != parser.peek()->code) {
        return new TemplateParameter(ident);
    }
    const auto start = parser.getMark();
    const auto initializer = TemplateArgument::parse(parser.advance(1));
    if (initializer) {
        return new TemplateParameter(ident, initializer);
    }
    parser.setMark(start);
    return nullptr;
}

TemplateParameter::TemplateParameter(const TRcToken& ident, const TPCTemplateArgument initializer) 
: ident(ident), initializer(initializer) {

}

TemplateParameter::~TemplateParameter() {
    delete initializer;
}
