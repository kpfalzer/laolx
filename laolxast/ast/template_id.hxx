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
 * File:   template_id.hxx
 * Author: kwpfalzer
 *
 * Created on Tue Nov 14 13:36:48 2017
 */
#ifndef TEMPLATE_ID_HXX
#define TEMPLATE_ID_HXX

#include <array>
#include "ast/common.hxx"
#include "ast/simple_template_id.hxx"
#include "ast/operator_function_id.hxx"
#include "ast/template_argument_list.hxx"

class TemplateId;
typedef const TemplateId* TPCTemplateId;

class TemplateId : public virtual AstNode {
public:
    static TPCTemplateId parse(Parser& parser);

    explicit TemplateId(TPCSimpleTemplateId simpl);
    explicit TemplateId(TPCOperatorFunctionId func, TPCTemplateArgumentList args);

    const std::array<TPCAstNode, 2> nodes;
    
    virtual ~TemplateId();
};

#endif /* TEMPLATE_ID_HXX */
