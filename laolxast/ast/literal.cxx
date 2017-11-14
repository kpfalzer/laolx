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
 * File:   literal.cxx
 * Author: kwpfalzer
 *
 * Created on Mon Nov 13 18:33:19 2017
 */
#include "ast/literal.hxx"
#include "ast/string.hxx"
#include "ast/symbols.hxx"
#include "ast/bool.hxx"
#include "ast/words.hxx"

TPCLiteral Literal::parse(Parser& parser) {
    auto start = parser.getMark();
    const auto code = parser.peek()->code;
    switch (code) {
        case Token::SYMBOL:
        case Token::INT:
        case Token::FLOAT:
        case Token::REGEXP:
        case Token::K_NIL:
            return new Literal(parser.accept());
        default:
            ; //do nothing
    }
    TPCAstNode node;
    node = String::parse(parser);
    if (!node) {
        node = Words::parse(parser);
        if (!node) {
            node = Symbols::parse(parser);
            if (!node) {
                node = Bool::parse(parser);
            }
        }
    }
    if (node) {
        return new Literal(node);
    }
    parser.setMark(start);
    return nullptr;
}

Literal::Literal(TPCAstNode node) : node(node) {
}

Literal::Literal(const TRcToken& tok)
: node(new Token(*tok)) {
}

Literal::~Literal() {
    delete node;
}
