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
 * File:   actual_declaration.hxx
 * Author: kwpfalzer
 *
 * Created on October 4, 2017, 8:30 PM
 */

#ifndef ACTUAL_DECLARATION_HXX
#define ACTUAL_DECLARATION_HXX

#include "ast/common.hxx"
#include "ast/string.hxx"

class ActualDeclaration;
typedef std::shared_ptr<ActualDeclaration> TRcActualDeclaration;

class ActualDeclaration : public virtual AstNode {
public:
    static TRcActualDeclaration parse(Parser& parser);

    explicit ActualDeclaration(const TRcString& actual_declaration);

    const TRcString m_actual_declaration;
    
    virtual ~ActualDeclaration();
};


#endif /* ACTUAL_DECLARATION_HXX */

