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
 * File:   interface_declaration.hxx
 * Author: kwpfalzer
 *
 * Created on Tue Mar 20 15:03:18 2018
 */
#ifndef INTERFACE_DECLARATION_HXX
#define INTERFACE_DECLARATION_HXX

#include "laolx/array.hxx"
#include "ast/common.hxx"

class InterfaceDeclaration : public virtual AstNode {
public:
    typedef laolx::Array<TPCMethodDeclaration> TDecls;

	static TPCInterfaceDeclaration parse(Parser& parser);

	explicit InterfaceDeclaration(
                                  const TRcToken name,
                                  TPCTemplateParameterList templParams,
                                  const TDecls& methodDecls
);

	virtual ~InterfaceDeclaration();
    
    const TRcToken name;
    const TPCTemplateParameterList templParams;
    const TDecls methodDecls;
};

#endif /* INTERFACE_DECLARATION_HXX */
