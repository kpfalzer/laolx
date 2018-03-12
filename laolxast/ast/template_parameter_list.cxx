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
 * File:   template_parameter_list.cxx
 * Author: kpfalzer
 *
 * Created on Fri Nov 17 12:48:41 2017
 */
#include "ast/template_parameter_list.hxx"
#include "ast/template_parameter.hxx"

TPCTemplateParameterList TemplateParameterList::parse(Parser& parser) {
    /*
     TemplateParameterList:
     S_LT TemplateParameter (COMMA TemplateParameter)* S_GT
     */
    if (Token::S_LT != parser.peek()->code) {
        return nullptr;
    }
    const auto start = parser.getMark();
    const auto params = oneOrMore<TemplateParameter>(parser.advance(1), Token::S_COMMA);
    if (params && (Token::S_GT == parser.accept()->code)) {
        return new TemplateParameterList(params);
    }
    parser.setMark(start);
    return nullptr;
}

TemplateParameterList::TemplateParameterList(const laolx::Array<TPCTemplateParameter>* params) 
: parameters(params) {

}

TemplateParameterList::~TemplateParameterList() {
    delete parameters;
}
