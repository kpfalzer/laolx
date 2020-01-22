//
//  @CLASS@.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/@CLASS@.hxx"

namespace laolx {
namespace parser {

TPNode
@CLASS@::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(@CLASS@);

@CLASS@::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
@CLASS@::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

}
}
