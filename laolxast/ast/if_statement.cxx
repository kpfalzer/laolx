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
 * File:   if_statement.cxx
 * Author: kwpfalzer
 *
 * Created on Tue Nov 14 19:16:47 2017
 */
#include "ast/if_statement.hxx"

TPCIfStatement IfStatement::parse(Parser& parser) {
    auto start = parser.getMark();
    if (Token::K_IF == parser.accept()->code) {
        auto ifCond = Condition::parse(parser);
        if (ifCond) {
            auto ifStmt = Statement::parse(parser);
            if (ifStmt) {
                TCondStmt ifClause = {ifCond, ifStmt};
                start = parser.getMark();
                TCondStmts elsifClauses;
                while (Token::K_ELSIF == parser.peek()->code) {
                    auto cond = Condition::parse(parser.advance());
                    if (cond) {
                        auto stmt = Statement::parse(parser);
                        if (stmt) {
                            elsifClauses << TCondStmt({cond, stmt});
                            start = parser.getMark();
                        }
                    } else {
                        break;
                    }
                }
                parser.setMark(start);
                TPCStatement stmt = nullptr;
                if (Token::K_ELSE == parser.peek()->code) {
                    stmt = Statement::parse(parser.advance());
                    if (!stmt) {
                        parser.setMark(start);
                    }
                }
                return new IfStatement(ifClause, elsifClauses, stmt);
            }
        }
    }
    parser.setMark(start);
    return nullptr;
}

IfStatement::IfStatement(
        const TCondStmt& ifClause,
        const TCondStmts& elsifClauses,
        TPCStatement elseClause)
: ifClause(ifClause),
elsifClauses(elsifClauses),
elseClause(elseClause) {
}

IfStatement::~IfStatement() {
    delete elseClause;
}
