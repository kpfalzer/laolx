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
 * File:   class_declaration.hxx
 * Author: kwpfalzer
 *
 * Created on October 4, 2017, 8:55 PM
 */

#ifndef CLASS_DECLARATION_HXX
#define CLASS_DECLARATION_HXX

#include "ast/common.hxx"
#include "ast/type_parameters.hxx"
#include "ast/parameter_declaration_list.hxx"
#include "ast/extends_declaration.hxx"
#include "ast/implements_declaration.hxx"
#include "ast/class_body.hxx"
#include "parameter_declaration.hxx"

class ClassDeclaration;
typedef std::shared_ptr<ClassDeclaration> TRcClassDeclaration;

class ClassDeclaration : public virtual AstNode {
public:
    static TRcClassDeclaration parse(Parser& parser);

    explicit ClassDeclaration(
            const TRcToken& className,
            const TRcTypeParameters& typeParameters,
            const TRcParameterDeclarationList& parameterDeclarationList,
            const TRcExtendsDeclaration& extendsDeclaration,
            const TRcImplementsDeclaration& implementsDeclaration,
            const TRcClassBody& classBody
            );

    const TRcToken m_className;
    const TRcTypeParameters m_typeParameters;
    const TRcParameterDeclarationList m_parameterDeclarationList;
    const TRcExtendsDeclaration m_extendsDeclaration;
    const TRcImplementsDeclaration m_implementsDeclaration;
    const TRcClassBody m_classBody;

    virtual ~ClassDeclaration();

};


#endif /* CLASS_DECLARATION_HXX */
