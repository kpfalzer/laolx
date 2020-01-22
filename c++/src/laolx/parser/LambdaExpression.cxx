//
//  LambdaExpression.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/LambdaExpression.hxx"
#include "laolx/parser/Token.hxx"
#include "laolx/parser/MethodParameter.hxx"
#include "laolx/parser/ReturnSpecifier.hxx"
#include "laolx/parser/Statement.hxx"

namespace laolx {
namespace parser {

/**
 //lambda looks like ruby closure
 LambdaExpression:
     S_LCURLY
         S_OR MethodParametersDeclaration S_OR
         ReturnSpecifier?
         Statement*
         S_RCURLY
 */
TPNode
LambdaExpression::_accept(Consumer& consumer) const {
    static const Repetition RET_OPT(ReturnSpecifier::THE_ONE, Repetition::eOptional);
    static const Repetition STMTS(Statement::THE_ONE, Repetition::eZeroOrMore);
    static const Sequence GRAM({&S_LCURLY,
        &S_OR, &MethodParametersDeclaration::THE_ONE, &S_OR,
        &RET_OPT,
        &STMTS,
        &S_LCURLY
    });
	TPNode node = GRAM.accept(consumer); //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(LambdaExpression);

LambdaExpression::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
LambdaExpression::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

}
}
