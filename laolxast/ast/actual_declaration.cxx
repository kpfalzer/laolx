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
 * File:   actual_declaration.cxx
 * Author: kpfalzer
 *
 * Created on Mon Oct  9 14:14:07 2017
 */
#include "ast/actual_declaration.hxx"
#include "ast/class_declaration.hxx"
#include "ast/interface_declaration.hxx"
#include "ast/variable_declaration.hxx"
#include "ast/typedef_declaration.hxx"
#include "ast/method_declaration.hxx"
#include "ast/namespace_declaration.hxx"

TRcActualDeclaration ActualDeclaration::parse(Parser& parser) {
    TRcActualDeclaration result(nullptr);
    {
        const auto decl = ClassDeclaration::parse(parser);
        if (decl) {
            return std::make_shared<ActualDeclaration>(std::static_pointer_cast<AstNode>(decl));
        }
    }
    {
        const auto decl = InterfaceDeclaration::parse(parser);
        if (decl) {
            return std::make_shared<ActualDeclaration>(std::static_pointer_cast<AstNode>(decl));
        }
    }
    {
        const auto decl = VariableDeclaration::parse(parser);
        if (decl) {
            return std::make_shared<ActualDeclaration>(std::static_pointer_cast<AstNode>(decl));
        }
    }
    {
        const auto decl = TypedefDeclaration::parse(parser);
        if (decl) {
            return std::make_shared<ActualDeclaration>(std::static_pointer_cast<AstNode>(decl));
        }
    }
    {
        const auto decl = MethodDeclaration::parse(parser);
        if (decl) {
            return std::make_shared<ActualDeclaration>(std::static_pointer_cast<AstNode>(decl));
        }
    }
    {
        const auto decl = NamespaceDeclaration::parse(parser);
        if (decl) {
            return std::make_shared<ActualDeclaration>(std::static_pointer_cast<AstNode>(decl));
        }
    }
    return result;
}

ActualDeclaration::ActualDeclaration(const TRcAstNode& node) 
: m_declaration(node) {
}

ActualDeclaration::~ActualDeclaration() {
}
