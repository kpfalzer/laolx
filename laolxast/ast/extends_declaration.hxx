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
 * File:   extends_declaration.hxx
 * Author: kwpfalzer
 *
 * Created on Fri Oct  6 19:30:04 2017
 */
#ifndef EXTENDS_DECLARATION_HXX
#define EXTENDS_DECLARATION_HXX

#include "laolx/array.hxx"
#include "ast/common.hxx"
#include "ast/base_name.hxx"

class ExtendsDeclaration;
typedef std::shared_ptr<ExtendsDeclaration> TRcExtendsDeclaration;

class ExtendsDeclaration : public virtual AstNode {
public:
    static TRcExtendsDeclaration parse(Parser& parser, Token::Code code = Token::K_EXTENDS);

    explicit ExtendsDeclaration(const laolx::Array<TRcBaseName>& names);

    const laolx::Array<TRcBaseName> m_names;
    
    virtual ~ExtendsDeclaration();
};

#endif /* EXTENDS_DECLARATION_HXX */
