//
//  Expression.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/Expression.hxx"
#include "laolx/parser/ExpressionEle.hxx"
#include "laolx/parser/Token.hxx"

namespace laolx {
namespace parser {

/**
 Expression: ConditionalExpression
 */
TPNode
Expression::_accept(Consumer& consumer) const {
	TPNode node = ConditionalExpression::THE_ONE.accept(consumer); //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(Expression);

Expression::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
Expression::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

/**
 ConditionalExpression: ExpressionEle (S_QMARK Expression S_COLON Expression)?
 */
TPNode
ConditionalExpression::_accept(Consumer& consumer) const {
    static const Sequence COND({&S_QMARK, &Expression::THE_ONE, &S_COLON, &Expression::THE_ONE});
    static const Repetition OPT_COND(COND, Repetition::eOptional);
    static const Sequence GRAM({&ExpressionEle::THE_ONE, &OPT_COND});
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(ConditionalExpression);

ConditionalExpression::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
ConditionalExpression::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

}
}
