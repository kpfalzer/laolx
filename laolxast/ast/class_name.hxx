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
 * File:   class_name.hxx
 * Author: kwpfalzer
 *
 * Created on Tue Nov 14 14:08:49 2017
 */
#ifndef CLASS_NAME_HXX
#define CLASS_NAME_HXX

#include "ast/common.hxx"
#include "ast/simple_template_id.hxx"

class ClassName;
typedef const ClassName* TPCClassName;

class ClassName : public virtual AstNode {
public:
    static TPCClassName parse(Parser& parser);

    explicit ClassName(const TRcToken& ident);
    explicit ClassName(TPCSimpleTemplateId simplId);
    
    const TPCAstNode node;

    virtual ~ClassName();
};

#endif /* CLASS_NAME_HXX */
