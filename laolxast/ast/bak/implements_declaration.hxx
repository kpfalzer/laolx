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
 * File:   implements_declaration.hxx
 * Author: kwpfalzer
 *
 * Created on Fri Oct  6 19:30:04 2017
 */
#ifndef IMPLEMENTS_DECLARATION_HXX
#define IMPLEMENTS_DECLARATION_HXX

#include "ast/common.hxx"
#include "ast/extends_declaration.hxx"

class ImplementsDeclaration;
typedef std::shared_ptr<ImplementsDeclaration> TRcImplementsDeclaration;

class ImplementsDeclaration : public virtual AstNode, public ExtendsDeclaration {
public:
    static TRcImplementsDeclaration parse(Parser& parser);

    explicit ImplementsDeclaration(const laolx::Array<TRcBaseName>& names, bool isConst);

    virtual ~ImplementsDeclaration();
};

#endif /* IMPLEMENTS_DECLARATION_HXX */
