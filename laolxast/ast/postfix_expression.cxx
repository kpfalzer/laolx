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
 * File:   postfix_expression.cxx
 * Author: kwpfalzer
 *
 * Created on Mon Nov 13 11:03:15 2017
 */
#include <array>
#include "ast/postfix_expression.hxx"
#include "ast/primary_expression.hxx"
#include "ast/simple_type_specifier.hxx"
#include "ast/expression_list.hxx"
#include "ast/braced_init_list.hxx"
#include "ast/expression.hxx"
#include "ast/id_expression.hxx"

//PostfixExpressionY:
//  (alt1)  PrimaryExpression
//| (alt2)  SimpleTypeSpecifier S_LPAREN ExpressionList? S_RPAREN
//| (alt3)  SimpleTypeSpecifier BracedInitList

class PostfixExpression::Y {
public:

    static PostfixExpression::TPCY parse(Parser& parser) {
        auto start = parser.getMark();
        {
            auto stype = SimpleTypeSpecifier::parse(parser);
            if (stype) {
                if (Token::S_LPAREN == parser.accept()->code) {
                    auto elist = ExpressionList::parse(parser);
                    if (Token::S_RPAREN == parser.accept()->code) {
                        return new Y(stype, elist);
                    }
                }
            }
        }
        parser.setMark(start);
        {
            auto pexpr = PrimaryExpression::parse(parser);
            if (pexpr) {
                return new Y(pexpr);
            }
        }
        {
            auto stype = SimpleTypeSpecifier::parse(parser);
            if (stype) {
                auto init = BracedInitList::parse(parser);
                if (init) {
                    return new Y(stype, init);
                }
            }
        }
        parser.setMark(start);
        return nullptr;
    }

    enum EType {
        eAlt1, eAlt2, eAlt3
    };

    explicit Y(TPCPrimaryExpression expr)
    : type(eAlt1), nodes({expr, nullptr}) {
    }

    explicit Y(TPCSimpleTypeSpecifier spec, TPCExpressionList exprs)
    : type(eAlt2), nodes({spec, exprs}) {
    }

    explicit Y(TPCSimpleTypeSpecifier spec, TPCBracedInitList init)
    : type(eAlt3), nodes({spec, init}) {
    }

    const EType type;
    const std::array<TPCAstNode, 2> nodes;

    virtual ~Y() {
        //default: destroys each element
    }
};

//PostfixExpressionX
//  (alt1)  S_LBRACK Expression S_RBRACK PostfixExpressionX?
//| (alt2)  S_LBRACK BracedInitList? S_RBRACK PostfixExpressionX?
//| (alt3)  S_LPAREN ExpressionList? S_RPAREN PostfixExpressionX?
//| (alt4)  DOT (K_NEW | IdExpression) PostfixExpressionX?
//| (alt5)  S_ANDDOT IdExpression PostfixExpressionX?
//|        (S_PLUS2 | S_MINUS2) PostfixExpressionX?

class PostfixExpression::X {
public:

    enum EType {
        eAlt1, eAlt2, eAlt3, eAlt4, eAlt5, ePreIncr, ePreDecr, eNew
    };

    static PostfixExpression::TPCX parse(Parser& parser) {
        auto start = parser.getMark();
        {
            if (Token::S_LBRACK == parser.accept()->code) {
                auto expr = Expression::parse(parser);
                if (expr && (Token::S_RBRACK == parser.accept()->code)) {
                    auto pfe = PostfixExpression::X::parse(parser);
                    return new X(expr, pfe);
                }
            }
        }
        parser.setMark(start);
        {
            if (Token::S_LBRACK == parser.accept()->code) {
                auto init = BracedInitList::parse(parser);
                if (Token::S_RBRACK == parser.accept()->code) {
                    auto pfe = PostfixExpression::X::parse(parser);
                    return new X(init, pfe);
                }
            }
        }
        parser.setMark(start);
        {
            if (Token::S_LPAREN == parser.accept()->code) {
                auto elist = ExpressionList::parse(parser);
                if (Token::S_RPAREN == parser.accept()->code) {
                    auto pfe = PostfixExpression::X::parse(parser);
                    return new X(elist, pfe);
                }
            }
        }
        parser.setMark(start);
        if ((Token::S_DOT == parser.peek()->code) && (Token::K_NEW == parser.peek(1)->code)) {
            auto tok = parser.peek(1);
            auto pfe = PostfixExpression::X::parse(parser.advance(2));
            return new X(tok, pfe);
        }
        {
            auto tok = parser.accept()->code;
            if (Token::S_DOT == tok || Token::S_ANDDOT == tok) {
                auto expr = IdExpression::parse(parser);
                if (expr) {
                    auto pfe = PostfixExpression::X::parse(parser);
                    return new X(expr, pfe, Token::S_ANDDOT == tok);
                }
            }
        }
        parser.setMark(start);
        {
            auto tok = parser.accept();
            if (Token::S_PLUS2 == tok->code || Token::S_MINUS2 == tok->code) {
                auto pfe = PostfixExpression::X::parse(parser);
                return new X(tok, pfe);
            }
        }
        parser.setMark(start);
        return nullptr;
    }

    explicit X(TPCExpression expr, TPCX post)
    : type(eAlt1),
    node(expr),
    x(post) {
    }

    explicit X(TPCBracedInitList init, TPCX post)
    : type(eAlt2),
    node(init),
    x(post) {
    }

    explicit X(TPCExpressionList elist, TPCX post)
    : type(eAlt3),
    node(elist),
    x(post) {
    }

    explicit X(TPCIdExpression expr, TPCX post, bool isAndDot)
    : type(isAndDot ? eAlt5 : eAlt4),
    node(expr),
    x(post) {
    }

    explicit X(const TRcToken& op, TPCX post)
    : type((Token::S_PLUS2 == op->code)
    ? ePreIncr
    : ((Token::K_NEW == op->code) ? eNew : ePreDecr)),
    node(new Token(*op)),
    x(post) {
    }

    const EType type;
    TPCAstNode node;

    // All alternatives have this (optionally)
    PostfixExpression::TPCX x;

    virtual ~X() {
        delete x;
        delete node;
    }
};

TPCPostfixExpression PostfixExpression::parse(Parser& parser) {
    auto start = parser.getMark();
    auto y = Y::parse(parser);
    if (y) {
        auto x = X::parse(parser);
        return new PostfixExpression(y, x);
    }
    parser.setMark(start);
    return nullptr;
}

PostfixExpression::PostfixExpression(TPCY y, TPCX x)
: y(y), x(x) {
}

PostfixExpression::~PostfixExpression() {
    delete x;
    delete y;
}


