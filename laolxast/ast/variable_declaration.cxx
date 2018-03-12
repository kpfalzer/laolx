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
 * File:   variable_declaration.cxx
 * Author: kpfalzer
 *
 * Created on Mon Oct  9 14:17:22 2017
 */
#include "ast/variable_declaration.hxx"

TPCVariableDeclaration VariableDeclaration::parse(Parser& parser) {
    auto start = parser.getMark();
    auto mutability = Mutability::parse(parser);
    auto isStatic = false;
    if (Token::K_STATIC == parser.peek()->code) {
        parser.accept();
        isStatic = true;
    }
    TPCSimpleTypeSpecifier typeSpec = nullptr;
    TPCVarOrAttrName varOrAttrName = nullptr;
    simpleTypeVarName(parser, typeSpec, varOrAttrName);
    if (varOrAttrName) {
        TPCInitializerClause initClause = nullptr;
        start = parser.getMark();
        if (Token::S_EQ == parser.peek()->code) {
            initClause = InitializerClause::parse(parser.advance());
            if (!initClause) {
                parser.setMark(start);
            }
        }
        return new VariableDeclaration(mutability, isStatic, typeSpec, varOrAttrName, initClause);
    }
    parser.setMark(start);
    return nullptr;
}

VariableDeclaration::VariableDeclaration(
        TPCMutability mutability,
        bool isStatic,
        TPCSimpleTypeSpecifier typeSpec,
        TPCVarOrAttrName varName,
        TPCInitializerClause initClause) 
: mutability(mutability),
isStatic(isStatic),
typeSpec(typeSpec),
varName(varName),
initClause(initClause) {
}

VariableDeclaration::~VariableDeclaration() {
    delete mutability;
    delete typeSpec;
    delete varName;
    delete initClause;
}
