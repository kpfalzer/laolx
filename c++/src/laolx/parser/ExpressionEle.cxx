//
//  ExpressionEle.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/ExpressionEle.hxx"
#include "laolx/parser/Token.hxx"
#include "laolx/parser/UnaryExpression.hxx"

namespace laolx {
namespace parser {

/**
 // NOTE: ExpressionEle is simplified logical-or-expression of c++ grammar
 ExpressionEle: UnaryExpression (BinaryOp ExpressionEle)*

 BinaryOp: //see code directly
 */
TPNode
ExpressionEle::_accept(Consumer& consumer) const {
    static const Sequence S1({&BinaryOp::THE_ONE, &ExpressionEle::THE_ONE});
    static const Repetition R1(S1, Repetition::eZeroOrMore);
    static const Sequence GRAM({&UnaryExpression::THE_ONE, &R1});
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(ExpressionEle);

ExpressionEle::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
ExpressionEle::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

TPNode
BinaryOp::_accept(Consumer& consumer) const {
    static const Alternatives GRAM({
        &S_STAR,
        &S_DIV,
        &S_PCNT,
        &S_PLUS,
        &S_MINUS,
        &S_LT2,
        &S_GT2,
        &S_LT,
        &S_GT,
        &S_LTEQ,
        &S_GTEQ,
        &S_EQ2,
        &S_NOTEQ,
        &S_AND,
        &S_XOR,
        &S_OR,
        &S_AND2,
        &S_OR2
    });
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(BinaryOp);

BinaryOp::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
BinaryOp::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

}
}
