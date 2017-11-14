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
 * File:   nested_name_specifier.hxx
 * Author: kwpfalzer
 *
 * Created on Tue Nov 14 13:23:02 2017
 */
#ifndef NESTED_NAME_SPECIFIER_HXX
#define NESTED_NAME_SPECIFIER_HXX

#include "ast/common.hxx"

class NestedNameSpecifier;
typedef const NestedNameSpecifier* TPCNestedNameSpecifier;

class NestedNameSpecifier : public virtual AstNode {
public:
    static TPCNestedNameSpecifier parse(Parser& parser);

    class X;
    typedef const X* TPCX;
    class Y;
    typedef const Y* TPCY;
    
    explicit NestedNameSpecifier(TPCY y, TPCX x);

    const TPCY y;
    const TPCX x;
    
    virtual ~NestedNameSpecifier();
};

#endif /* NESTED_NAME_SPECIFIER_HXX */
