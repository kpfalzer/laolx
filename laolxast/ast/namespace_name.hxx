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
 * File:   namespace_name.hxx
 * Author: kpfalzer
 *
 * Created on Thu Oct 19 14:32:08 2017
 */
#ifndef NAMESPACE_NAME_HXX
#define NAMESPACE_NAME_HXX

#include "ast/common.hxx"

class NamespaceName;
typedef const NamespaceName* TPCNamespaceName;

class NamespaceName : public virtual AstNode {
public:

    explicit NamespaceName(const TRcToken& name) : name(name) {
    }
    
    static TPCNamespaceName parse(Parser& parser);

    explicit NamespaceName();

    const TRcToken name;

    virtual ~NamespaceName();
};

#endif /* NAMESPACE_NAME_HXX */
