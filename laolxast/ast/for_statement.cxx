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
 * File:   for_statement.cxx
 * Author: kwpfalzer
 *
 * Created on Tue Nov 14 19:16:47 2017
 */
#include "ast/for_statement.hxx"

TPCForStatement ForStatement::parse(Parser& parser) {
    auto start = parser.getMark();
    if (Token::K_FOR == parser.accept()->code) {
        if (Token::S_LPAREN == parser.accept()->code) {
            auto ident = parser.accept();
            if (Token::IDENT == ident->code) {
                if (Token::S_COLON == parser.accept()->code) {
                    auto expr = Expression::parse(parser);
                    if (expr) {
                        if (Token::S_RPAREN == parser.accept()->code) {
                            auto stmt = Statement::parse(parser);
                            if (stmt) {
                                return new ForStatement(ident, expr, stmt);
                            }
                        }
                    }
                }
            }
        }
    }
    parser.setMark(start);
    return nullptr;
}

ForStatement::ForStatement(
        const TRcToken& ident,
        TPCExpression expr,
        TPCStatement stmt)
: ident(ident), expr(expr), stmt(stmt) {
}

ForStatement::~ForStatement() {
    delete expr;
    delete stmt;
}