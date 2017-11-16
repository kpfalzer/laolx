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
 * File:   case_statement.cxx
 * Author: kwpfalzer
 *
 * Created on Tue Nov 14 19:16:47 2017
 */
#include "ast/case_statement.hxx"

TPCCaseStatement CaseStatement::parse(Parser& parser) {
    auto start = parser.getMark();
    if (Token::K_CASE == parser.accept()->code) {
        auto condition = Condition::parse(parser);
        if (condition) {
            if (Token::S_LCURLY == parser.accept()->code) {
                TWhens whens;
                auto isOK = true;
                auto mark = parser.getMark();
                while (isOK && (Token::K_WHEN == parser.peek()->code)) {
                    TWhen when;
                    while (isOK) {
                        auto expr = Expression::parse(parser.advance());
                        if (expr) {
                            when.first << expr;
                            mark = parser.getMark();
                            if (Token::S_COMMA != parser.peek()->code) {
                                break;
                            }
                        } else {
                            isOK = false;
                        }
                    }
                    if (isOK) {
                        auto stmt = Statement::parse(parser);
                        if (stmt) {
                            when.second = stmt;
                            whens << when;
                        } else {
                            isOK = false;
                        }
                    }
                }
                if (isOK && !whens.isEmpty()) {
                    TPCStatement elseStmt = nullptr;
                    if (Token::K_ELSE == parser.peek()->code) {
                        elseStmt = Statement::parse(parser.advance());
                        if (!elseStmt) {
                            isOK = false;
                        }
                    }
                    if (isOK && (Token::S_RCURLY == parser.accept()->code)) {
                        return new CaseStatement(condition, whens, elseStmt);
                    }
                }
            }
        }
    }
    parser.setMark(start);
    return nullptr;
}

CaseStatement::CaseStatement(
        TPCCondition condition,
        const TWhens& whens,
        TPCStatement elseStmt)
: condition(condition),
whens(whens),
elseStmt(elseStmt) {
}

CaseStatement::~CaseStatement() {
    delete condition;
    delete elseStmt;
}
