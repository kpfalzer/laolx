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
 * File:   typedef_declaration.hxx
 * Author: kpfalzer
 *
 * Created on Mon Oct  9 14:17:22 2017
 */
#ifndef TYPEDEF_DECLARATION_HXX
#define TYPEDEF_DECLARATION_HXX

#include "ast/common.hxx"
#include "ast/simple_type_specifier.hxx"

class TypedefDeclaration;
typedef const TypedefDeclaration* TPCTypedefDeclaration;

class TypedefDeclaration : public virtual AstNode {
public:
    static TPCTypedefDeclaration parse(Parser& parser);

    explicit TypedefDeclaration(TPCSimpleTypeSpecifier actualType, const TRcToken name)
    : actualType(actualType), name(name) {
    }

    const TPCSimpleTypeSpecifier actualType;
    const TRcToken name;

    virtual ~TypedefDeclaration();
};

#endif /* TYPEDEF_DECLARATION_HXX */
