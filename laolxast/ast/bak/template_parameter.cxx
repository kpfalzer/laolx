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
 * Author: kwpfalzer
 *
 * Created on Wed Oct 18 20:17:32 2017
 */
#include "ast/template_parameter.hxx"

TRcTemplateParameter TemplateParameter::parse(Parser& parser) {
    TRcTemplateParameter result(nullptr);
    if (parser.peek()->code != Token::IDENT) {
        return result;
    }
    TRcToken name = parser.accept();
    auto start = parser.getMark();
    TRcInitializerClause initializer(nullptr);
    if (parser.accept()->code == Token::S_EQ) {
        initializer = InitializerClause::parse(parser);
        if (!initializer) {
            parser.setMark(start);
        }
    } 
    result = std::make_shared<TemplateParameter>(name, initializer);
    return result;
}

TemplateParameter::TemplateParameter(const TRcToken& name, const TRcInitializerClause& init)
: name(name), initializer(init) {
}

TemplateParameter::~TemplateParameter() {
}
