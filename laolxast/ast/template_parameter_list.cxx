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
 * Author: kwpfalzer
 *
 * Created on Wed Oct 18 20:17:32 2017
 */
#include "ast/template_parameter_list.hxx"

TRcTemplateParameterList TemplateParameterList::parse(Parser& parser) {
    TRcTemplateParameterList result(nullptr);
    if (parser.peek()->code != Token::S_LT) {
        return result;
    }
    auto start = parser.getMark();
    auto parameters = sequenceOf<TemplateParameter>(parser.advance(), start, Token::S_COMMA);
    if (parser.accept()->code == Token::S_GT) {
        return std::make_shared<TemplateParameterList>(parameters);
    }
    parser.setMark(start);
    return result;
}

TemplateParameterList::~TemplateParameterList() {
}
