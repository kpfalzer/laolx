//
//  PrimaryExpression.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/PrimaryExpression.hxx"
#include "laolx/parser/Token.hxx"
#include "laolx/parser/Literal.hxx"
#include "laolx/parser/Expression.hxx"
#include "laolx/parser/IdExpression.hxx"
#include "laolx/parser/LambdaExpression.hxx"

namespace laolx {
namespace parser {

/**
 PrimaryExpression:
    Literal
 |      K_THIS
 |      S_LPAREN Expression S_RPAREN
 |      IdExpression
 |      LambdaExpression
 */
TPNode
PrimaryExpression::_accept(Consumer& consumer) const {
    static const Sequence S3({&S_LPAREN, &Expression::THE_ONE, &S_RPAREN});
    static const Alternatives GRAM({&Literal::THE_ONE, &K_THIS, &S3, &IdExpression::THE_ONE, &LambdaExpression::THE_ONE});
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(PrimaryExpression);

PrimaryExpression::Node::Node(const TPNode& node) {
    //todo
}

ostream&
PrimaryExpression::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
