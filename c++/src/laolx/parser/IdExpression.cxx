//
//  IdExpression.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/IdExpression.hxx"

namespace laolx {
namespace parser {

TPNode
IdExpression::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(IdExpression);

IdExpression::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
IdExpression::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

}
}
