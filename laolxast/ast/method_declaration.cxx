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

TPCMethodDeclaration MethodDeclaration::parse(Parser& parser) {
    // Access? Mutability? K_STATIC? --- in any order
    TPCAccess access = nullptr;
    TPCMutability mutability = nullptr;
    bool isStatic = false;
    bool accessMutabilityStaticDone = false;
    access = Access::parse(parser);
    if (access) {
        mutability = Mutability::parse(parser);
        if (mutability) {
            accessMutabilityStaticDone = true;
            isStatic = (parser.peek()->code == Token::K_STATIC);
            if (isStatic) {
                parser.accept();
            }
        } else if (parser.peek()->code == Token::K_STATIC) {
            isStatic = true;
            mutability = Mutability::parse(parser.advance());
            accessMutabilityStaticDone = true;
        }
    } else {
        //redux !!!
    }
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
