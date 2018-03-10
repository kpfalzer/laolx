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
 * File:   method_parameter.hxx
 * Author: kpfalzer
 *
 * Created on Fri Nov 24 18:37:43 2017
 */
#ifndef METHOD_PARAMETER_HXX
#define METHOD_PARAMETER_HXX

#include "ast/common.hxx"
#include "ast/mutability.hxx"
#include "ast/simple_type_specifier.hxx"
#include "ast/initializer_clause.hxx"
#include "ast/var_or_attr_name.hxx"
#include "ast/access.hxx"


class MethodParameter : public virtual AstNode {
public:
    static TPCMethodParameter parse(Parser& parser);

    explicit MethodParameter(
            TPCAccess access,
            TPCMutability mutability,
            TPCSimpleTypeSpecifier typeSpec,
            TPCVarOrAttrName varName,
            TPCInitializerClause initClause
            );

    const TPCAccess access;
    const TPCMutability mutability;
    const TPCSimpleTypeSpecifier typeSpec;
    const TPCVarOrAttrName varName;
    const TPCInitializerClause initClause;

    virtual ~MethodParameter();
};

#endif /* METHOD_PARAMETER_HXX */
