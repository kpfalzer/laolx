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
 * File:   template_argument_list.cxx
 * Author: kwpfalzer
 *
 * Created on Tue Nov 14 15:30:41 2017
 */
#include "ast/template_argument_list.hxx"

TPCTemplateArgumentList TemplateArgumentList::parse(Parser& parser) {
    auto arg = TemplateArgument::parse(parser);
    if (!arg) {
        return nullptr;
    }
    TArgs args;
    args << arg;
    auto start = parser.getMark();
    while (Token::S_COMMA == parser.accept()->code) {
        arg = TemplateArgument::parse(parser);
        if (arg) {
            args << arg;
            start = parser.getMark();
        } else {
            break;
        }
    }
    parser.setMark(start);
    return new TemplateArgumentList(args.compact());
}

TemplateArgumentList::TemplateArgumentList(const TArgs& args)
: args(args) {
}

TemplateArgumentList::~TemplateArgumentList() {
}
