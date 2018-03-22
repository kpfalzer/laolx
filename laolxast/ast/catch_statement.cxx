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
 * File:   catch_statement.cxx
 * Author: kwpfalzer
 *
 * Created on Thu Mar 22 11:21:19 2018
 */
#include "ast/catch_statement.hxx"
#include "ast/simple_type_specifier.hxx"
#include "ast/var_or_attr_name.hxx"
#include "ast/statement.hxx"

TPCCatchStatement CatchStatement::parse(Parser& parser) {
    if ((Token::K_CATCH != parser.peek()->code) 
            || (Token::S_LPAREN != parser.peek(1)->code)) {
        return nullptr;
    }
    const auto start = parser.getMark();
    TPCSimpleTypeSpecifier typeSpec = nullptr;
    TPCVarOrAttrName name = nullptr;
    if (simpleTypeVarName(parser.advance(2), typeSpec, name)) {
        if (Token::S_RPAREN == parser.accept()->code) {
            auto statement = Statement::parse(parser);
            if (statement) {
                return new CatchStatement(typeSpec, name, statement);
            }
        }
    }
    parser.setMark(start);
    return nullptr;
}

CatchStatement::CatchStatement(TPCSimpleTypeSpecifier typeSpec, TPCVarOrAttrName name, TPCStatement statement) 
: typeSpec(typeSpec), name(name), statement(statement) {
}

CatchStatement::~CatchStatement() {
    delete typeSpec;
    delete name;
    delete statement;
}
