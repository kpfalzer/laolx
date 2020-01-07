//
//  UnaryExpression.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/UnaryExpression.hxx"
#include "laolx/parser/Token.hxx"

namespace laolx {
namespace parser {

using apfev3::Alternatives;
using apfev3::Sequence;

/**
 UnaryExpression: UnaryOp? PostfixExpression
 */
TPNode
UnaryExpression::_accept(Consumer& consumer) const {
    const Mark start = consumer.mark();
    TPNode op = UnaryOp::THE_ONE.accept(consumer);
    TPNode expr = PostfixExpression::THE_ONE.accept(consumer);
    if (expr.isNull()) consumer.rewind(start);
    return (expr.isValid()) ? new Node(op, expr) : nullptr;
}

WITH_NODE_DEFINE(UnaryExpression);

UnaryExpression::Node::Node(const TPNode& _op, const TPNode& _expr)
: op(_op.isValid() ? toUnaryOpNode(_op) : nullptr),
  expr(toPostfixExpressionNode(_expr)) {
    if (op.isValid()) push_back(_op);
    push_back(_expr);
}

ostream&
UnaryExpression::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

}
}
