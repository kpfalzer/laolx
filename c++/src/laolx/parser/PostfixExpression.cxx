//
//  PostfixExpression.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/PostfixExpression.hxx"
#include "laolx/parser/IdExpression.hxx"
#include "laolx/parser/ExpressionList.hxx"
#include "laolx/parser/Token.hxx"
#include "laolx/parser/Expression.hxx"
#include "laolx/parser/PrimaryExpression.hxx"
#include "laolx/parser/SimpleTypeSpecifier.hxx"

namespace laolx {
namespace parser {

/**
 PostfixExpression: PostfixExpressionY PostfixExpressionX?
 */
TPNode
PostfixExpression::_accept(Consumer& consumer) const {
    static const Repetition XSTAR(X::THE_ONE, Repetition::eZeroOrMore);
    static const Sequence Y_XSTAR({&Y::THE_ONE, &XSTAR});
    TPNode node = Y_XSTAR.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(PostfixExpression);

PostfixExpression::Node::Node(const TPNode& node) {
    //todo
}

ostream&
PostfixExpression::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

/**
 PostfixExpressionX
    S_LBRACK Expression S_RBRACK
 |      S_LPAREN ExpressionList? S_RPAREN
 |      DOT IdExpression
 |      (S_PLUS2 | S_MINUS2) 
 */
TPNode
PostfixExpression::X::_accept(Consumer& consumer) const {
    static const Sequence S1({&S_LBRACK, &Expression::THE_ONE, &S_RBRACK});
    static const Repetition EL_OPT(ExpressionList::THE_ONE, Repetition::eOptional);
    static const Sequence S2({&S_LPAREN, &EL_OPT, &S_RPAREN});
    static const Sequence S3({&S_DOT, &IdExpression::THE_ONE});
    static const Alternatives S4({&S_PLUS2, &S_MINUS2});
    static const Alternatives GRAM({&S1,&S2,&S3,&S4});
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const PostfixExpression::X& PostfixExpression::X::THE_ONE = PostfixExpression::X();

PostfixExpression::X::Node::Node(const TPNode& node) {
    //todo
}

ostream&
PostfixExpression::X::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

/**
 PostfixExpressionY:
    PrimaryExpression
 |      SimpleTypeSpecifier S_LPAREN ExpressionList? S_RPAREN
 |      SimpleTypeSpecifier
 */
TPNode
PostfixExpression::Y::_accept(Consumer& consumer) const {
    static const Repetition EL_OPT(ExpressionList::THE_ONE, Repetition::eOptional);
    static const Sequence S2({&SimpleTypeSpecifier::THE_ONE, &S_LPAREN, &EL_OPT, &S_RPAREN});
    static const Alternatives GRAM({&PrimaryExpression::THE_ONE, &S2, &SimpleTypeSpecifier::THE_ONE});
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const PostfixExpression::Y& PostfixExpression::Y::THE_ONE = PostfixExpression::Y();

PostfixExpression::Y::Node::Node(const TPNode& node) {
    //todo
}

ostream&
PostfixExpression::Y::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
