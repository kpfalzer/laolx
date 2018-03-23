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
 * File:   nested_name_specifier.cxx
 * Author: kwpfalzer
 *
 * Created on Tue Nov 14 13:23:02 2017
 */
#include "ast/nested_name_specifier.hxx"
#include "ast/simple_template_id.hxx"
#include "ast/name.hxx"

class NestedNameSpecifier::X {
public:

    static TPCX parse(Parser& parser) {
        auto start = parser.getMark();
        {
            auto ident = parser.accept();
            if (Token::IDENT == ident->code) {
                if (Token::S_DOT == parser.accept()->code) {
                    auto x = X::parse(parser);
                    return new X(ident, x);
                }
            }
        }
        parser.setMark(start);
        {
            auto sid = SimpleTemplateId::parse(parser);
            if (sid) {
                if (Token::S_DOT == parser.accept()->code) {
                    auto x = X::parse(parser);
                    return new X(sid, x);
                }
            }
        }
        parser.setMark(start);
        return nullptr;
    }

    explicit X(const TRcToken& ident, TPCX x = nullptr)
    : node(new Token(*ident)), x(x) {
    }

    explicit X(TPCSimpleTemplateId simpleTemplId, TPCX x)
    : node(simpleTemplId), x(x) {
    }

    virtual ~X() {
        delete node;
        delete x;
    }

    const TPCAstNode node;
    const TPCX x;
};

class NestedNameSpecifier::Y {
public:

    static TPCY parse(Parser& parser) {
        auto start = parser.getMark();
        {
            auto type = Name::parse(parser);
            if (type) {
                if (Token::S_DOT == parser.accept()->code) {
                    return new Y(type);
                }
            }
        }
        parser.setMark(start);
        return nullptr;
    }

    explicit Y(TPCAstNode node)
    : node(node) {
    }

    virtual ~Y() {
        delete node;
    }

    const TPCAstNode node;
};

TPCNestedNameSpecifier NestedNameSpecifier::parse(Parser& parser) {
    auto start = parser.getMark();
    auto y = Y::parse(parser);
    if (y) {
        auto x = X::parse(parser);
        return new NestedNameSpecifier(y, x);
    }
    parser.setMark(start);
    return nullptr;
}

NestedNameSpecifier::NestedNameSpecifier(TPCY y, TPCX x)
: y(y), x(x) {
}

NestedNameSpecifier::~NestedNameSpecifier() {
}
