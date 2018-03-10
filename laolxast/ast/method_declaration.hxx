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
 * File:   method_declaration.hxx
 * Author: kpfalzer
 *
 * Created on Mon Oct  9 14:17:22 2017
 */
#ifndef METHOD_DECLARATION_HXX
#define METHOD_DECLARATION_HXX

#include <utility>
#include "ast/common.hxx"
#include "ast/access.hxx"
#include "ast/mutability.hxx"
#include "ast/method_parameters_declaration.hxx"
#include "ast/return_specifier.hxx"
#include "ast/method_body.hxx"


class MethodDeclaration : public virtual AstNode {
public:
    typedef std::pair<TRcToken, TPCAstNode> Type;
    typedef const Type* TPCType;

    static TPCMethodDeclaration parse(Parser& parser);

    explicit MethodDeclaration(
            TPCAccess access,
            TPCMutability mutability,
            TPCType type,
            TPCMethodParametersDeclaration parametersDeclaration,
            TPCReturnSpecifier returnSpecifier,
            TPCMethodBody body,
            bool isStatic = false
            );

    const TPCAccess access;
    const TPCMutability mutability;
    const TPCType type;
    const TPCMethodParametersDeclaration parametersDeclaration;
    const TPCReturnSpecifier returnSpecifier;
    const TPCMethodBody body;
    const bool isStatic;

    virtual ~MethodDeclaration();
};

#endif /* METHOD_DECLARATION_HXX */
