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
 * File:   member_variable_declaration.cxx
 * Author: kwpfalzer
 *
 * Created on Tue Nov 14 18:33:41 2017
 */
#include "ast/member_variable_declaration.hxx"

TPCMemberVariableDeclaration MemberVariableDeclaration::parse(Parser& parser) {
    auto start = parser.getMark();
    // Access? Mutability? K_STATIC? --- in any order
    TPCAccess access = nullptr;
    TPCMutability mutability = nullptr;
    bool isStatic = false;
    // since we'll allow any order: try 3 times
    for (int iter = 0; iter < 3; iter++) {
        if (!access) {
            access = Access::parse(parser);
        }
        if (!mutability) {
            mutability = Mutability::parse(parser);
        }
        if (!isStatic && (Token::K_STATIC == parser.peek()->code)) {
            parser.accept();
            isStatic = true;
        }
    }
    TPCSimpleTypeSpecifier typeSpec = nullptr;
    TPCVarOrAttrName varOrAttrName = nullptr;
    simpleTypeVarName(parser, typeSpec, varOrAttrName);
    if (varOrAttrName) {
        TPCInitializerClause init = nullptr;
        start = parser.getMark();
        if (Token::S_EQ == parser.peek()->code) {
            init = InitializerClause::parse(parser.advance());
            if (!init) {
                parser.setMark(start);
            }
        }
        parser.expectEndOfStatement();
        return new MemberVariableDeclaration(
                access, mutability, isStatic,
                typeSpec, varOrAttrName, init);
    }
    parser.setMark(start);
    return nullptr;
}

MemberVariableDeclaration::MemberVariableDeclaration(
        TPCAccess access,
        TPCMutability mutability,
        bool isStatic,
        TPCSimpleTypeSpecifier typeSpec,
        TPCVarOrAttrName varOrAttrName,
        TPCInitializerClause initClause)
: access(access), mutability(mutability), isStatic(isStatic),
typeSpec(typeSpec), varOrAttrName(varOrAttrName), initClause(initClause) {
}

MemberVariableDeclaration::~MemberVariableDeclaration() {
    delete access;
    delete mutability;
    delete typeSpec;
    delete varOrAttrName;
    delete initClause;
}
