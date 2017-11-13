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
 * File:   unary_expression.hxx
 * Author: kwpfalzer
 *
 * Created on Mon Nov 13 11:03:15 2017
 */
#ifndef UNARY_EXPRESSION_HXX
#define UNARY_EXPRESSION_HXX

#include "ast/common.hxx"
#include "ast/postfix_expression.hxx"
#include "ast/unary_operator.hxx"

class UnaryExpression;
typedef const UnaryExpression* TPCUnaryExpression;

class UnaryExpression : public virtual AstNode {
public:
    static TPCUnaryExpression parse(Parser& parser);

    enum EType {ePostfix, ePreIncr, ePreDecr, eUopExpr};
    
    explicit UnaryExpression(TPCPostfixExpression expr);
    explicit UnaryExpression(const TRcToken& preop,  TPCUnaryExpression expr);
    explicit UnaryExpression(TPCUnaryOperator uop,  TPCUnaryExpression expr);

    const EType type;
    
    virtual ~UnaryExpression();
    
private:
    union Expr {
        TPCPostfixExpression m_postfixExpr;
        TPCUnaryExpression m_preopExpr;
        struct {
            TPCUnaryOperator m_uop;
            TPCUnaryExpression m_expr;
        };
    };
    
    Expr m_expr;
};

#endif /* UNARY_EXPRESSION_HXX */
