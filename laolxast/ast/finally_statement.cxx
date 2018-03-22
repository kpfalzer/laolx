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
 * File:   finally_statement.cxx
 * Author: kwpfalzer
 *
 * Created on Thu Mar 22 11:21:19 2018
 */
#include "ast/finally_statement.hxx"
#include "ast/statement.hxx"

TPCFinallyStatement FinallyStatement::parse(Parser& parser) {
    if (Token::K_TRY != parser.peek()->code) {
        return nullptr;
    }
    const auto start = parser.getMark();
    auto statement = Statement::parse(parser.advance());
    if (statement) {
        return new FinallyStatement(statement);
    }
    parser.setMark(start);
    return nullptr;
}

FinallyStatement::FinallyStatement(TPCStatement statement)
: statement(statement) {

}

FinallyStatement::~FinallyStatement() {
    delete statement;
}


