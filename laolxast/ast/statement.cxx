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
 * File:   statement.cxx
 * Author: kwpfalzer
 *
 * Created on Tue Nov 14 18:34:56 2017
 */
#include "ast/statement.hxx"
#include "ast/expression.hxx"
#include "ast/compound_statement.hxx"
#include "ast/if_statement.hxx"
#include "ast/case_statement.hxx"
#include "ast/jump_statement.hxx"
#include "ast/iteration_statement.hxx"
#include "ast/for_statement.hxx"

TPCStatement Statement::parse(Parser& parser) {
    TPCAstNode node = Expression::parse(parser);
    if (!node) {
        node = CompoundStatement::parse(parser);
        if (!node) {
            node = IfStatement::parse(parser);
            if (!node) {
                node = CaseStatement::parse(parser);
                if (!node) {
                    node = JumpStatement::parse(parser);
                    if (!node) {
                        node = IterationStatement::parse(parser);
                        if (!node) {
                            node = ForStatement::parse(parser);
                        }
                    }
                }
            }
        }
    }
    if (node) {
        parser.expectEndOfStatement();
        return new Statement(node);
    }
    return nullptr;
}

Statement::~Statement() {
    delete node;
}
