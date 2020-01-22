//
//  ReturnSpecifier.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/ReturnSpecifier.hxx"

namespace laolx {
namespace parser {

TPNode
ReturnSpecifier::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(ReturnSpecifier);

ReturnSpecifier::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
ReturnSpecifier::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

}
}
