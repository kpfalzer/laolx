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
 * File:   variable_declaration.hxx
 * Author: kpfalzer
 *
 * Created on Mon Oct  9 14:17:22 2017
 */
#ifndef VARIABLE_DECLARATION_HXX
#define VARIABLE_DECLARATION_HXX

#include "ast/common.hxx"
#include "ast/mutability.hxx"
#include "ast/simple_type_specifier.hxx"
#include "ast/initializer_clause.hxx"
#include "ast/var_or_attr_name.hxx"

class VariableDeclaration;
typedef const VariableDeclaration* TPCVariableDeclaration;

class VariableDeclaration : public virtual AstNode {
public:
    static TPCVariableDeclaration parse(Parser& parser);

    explicit VariableDeclaration(
            TPCMutability mutability,
            bool isStatic,
            TPCSimpleTypeSpecifier typeSpec,
            TPCVarOrAttrName varName,
            TPCInitializerClause initClause
            );

    const TPCMutability mutability;
    const bool isStatic;
    const TPCSimpleTypeSpecifier typeSpec;
    const TPCVarOrAttrName varName;
    const TPCInitializerClause initClause;

    virtual ~VariableDeclaration();
};

#endif /* VARIABLE_DECLARATION_HXX */
