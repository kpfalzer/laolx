//
//  ExpressionList.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/ExpressionList.hxx"

namespace laolx {
namespace parser {

TPNode
ExpressionList::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(ExpressionList);

ExpressionList::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
ExpressionList::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

}
}
