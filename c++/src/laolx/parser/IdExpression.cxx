//
//  IdExpression.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/IdExpression.hxx"
#include "laolx/parser/Token.hxx"
#include "laolx/parser/OperatorFunctionId.hxx"
#include "laolx/parser/Template.hxx"
#include "laolx/parser/NestedNameSpecifier.hxx"

namespace laolx {
namespace parser {

/**
 IdExpression:
    UnqualifiedId
 |      QualifiedId
 */
TPNode
IdExpression::_accept(Consumer& consumer) const {
    static const Alternatives GRAM({&UnqualifiedId::THE_ONE, &QualifiedId::THE_ONE});
	TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(IdExpression);

IdExpression::Node::Node(const TPNode& node)
: AlternativeNode(node)
{}

ostream&
IdExpression::Node::operator<<(ostream& os) const {
    return AlternativeNode::operator<<(os);
}

/**
  QualifiedId: NestedNameSpecifier UnqualifiedId
 */
TPNode
QualifiedId::_accept(Consumer& consumer) const {
    static const Sequence GRAM({&NestedNameSpecifier::THE_ONE, &UnqualifiedId::THE_ONE});
	TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(QualifiedId);

QualifiedId::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
QualifiedId::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

/**
 UnqualifiedId:
    IDENT
 |      OperatorFunctionId
 |      TemplateId
 */
TPNode
UnqualifiedId::_accept(Consumer& consumer) const {
    static const Alternatives GRAM({&Ident::THE_ONE, &OperatorFunctionId::THE_ONE, &TemplateId::THE_ONE});
	TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(UnqualifiedId);

UnqualifiedId::Node::Node(const TPNode& node)
: AlternativeNode(node)
{}

ostream&
UnqualifiedId::Node::operator<<(ostream& os) const {
    return AlternativeNode::operator<<(os);
}

}
}
