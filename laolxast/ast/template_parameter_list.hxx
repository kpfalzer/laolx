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
 * File:   template_parameter_list.hxx
 * Author: kwpfalzer
 *
 * Created on Wed Oct 18 20:17:32 2017
 */
#ifndef TEMPLATE_PARAMETER_LIST_HXX
#define TEMPLATE_PARAMETER_LIST_HXX

#include "ast/common.hxx"
#include "ast/template_parameter.hxx"

class TemplateParameterList;
typedef std::shared_ptr<TemplateParameterList> TRcTemplateParameterList;

class TemplateParameterList : public virtual AstNode {
public:
    typedef std::shared_ptr<laolx::Array<TRcTemplateParameter>> TRcTemplateParameters;

    static TRcTemplateParameterList parse(Parser& parser);

    explicit TemplateParameterList(const TRcTemplateParameters& parameters)
    : parameters(parameters) {
    }

    const TRcTemplateParameters parameters;

    virtual ~TemplateParameterList();
};

#endif /* TEMPLATE_PARAMETER_LIST_HXX */
