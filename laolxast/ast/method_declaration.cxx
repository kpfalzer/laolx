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
 * File:   method_declaration.cxx
 * Author: kpfalzer
 *
 * Created on Mon Oct  9 14:17:22 2017
 */
#include "ast/method_declaration.hxx"
#include "ast/name.hxx"
#include "ast/overloadable_operator.hxx"

TPCMethodDeclaration MethodDeclaration::parse(Parser& parser) {
    // Access? Mutability? K_STATIC? --- in any order
    TPCAccess access = nullptr;
    TPCMutability mutability = nullptr;
    TRcToken isStatic = nullptr;
    auto start = parser.getMark();
    // since we'll allow any order: try 3 times
    for (int iter = 0; iter < 3; iter++) {
        if (!access) {
            access = Access::parse(parser);
        }
        if (!mutability) {
            mutability = Mutability::parse(parser);
        }
        if (!isStatic && (Token::K_STATIC == parser.peek()->code)) {
            isStatic = parser.accept();
        }
    }
    TRcToken type = nullptr;
    switch (parser.peek()->code) {
        case Token::K_DEF: case Token::K_OPERATOR:
            type = parser.accept();
            break;
        default:
            parser.setMark(start);
            return nullptr;
    }
    TPCAstNode xtra = nullptr;
    if (type->code == Token::K_DEF) {
        auto methodName = Name::parse(parser);
        if (methodName) {
            xtra = methodName;
        }
    } else {
        auto op = OverloadableOperator::parse(parser);
        if (op) {
            xtra = op;
        }
    }
    if (!xtra) {
        parser.setMark(start);
        return nullptr;
    }
    auto typeNode = new Type(type, xtra);
    auto methodParamDecl = MethodParametersDeclaration::parse(parser);
    auto returnSpecifier = ReturnSpecifier::parse(parser);
    TPCMethodBody methodBody = nullptr;
    if (parser.peek()->code == Token::S_LCURLY) {
        methodBody = MethodBody::parse(parser.advance());
        if (!methodBody || parser.peek()->code != Token::S_RCURLY) {
            parser.setMark(start);
            return nullptr;
        }
        assert(Token::S_RCURLY == parser.accept()->code);
    }
    parser.expectEndOfStatement();
    return new MethodDeclaration(access, mutability, typeNode, methodParamDecl, returnSpecifier, methodBody);
}

MethodDeclaration::MethodDeclaration(
        TPCAccess access,
        TPCMutability mutability,
        TPCType type,
        TPCMethodParametersDeclaration parametersDeclaration,
        TPCReturnSpecifier returnSpecifier,
        TPCMethodBody body,
        bool isStatic)
: access(access),
mutability(mutability),
type(type),
parametersDeclaration(parametersDeclaration),
returnSpecifier(returnSpecifier),
body(body),
isStatic(isStatic) {
}

MethodDeclaration::~MethodDeclaration() {
    delete access;
    delete mutability;
    delete type;
    delete parametersDeclaration;
    delete returnSpecifier;
    delete body;
}
