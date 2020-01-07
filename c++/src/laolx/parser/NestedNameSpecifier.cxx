//
//  NestedNameSpecifier.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/NestedNameSpecifier.hxx"

namespace laolx {
namespace parser {

TPNode
NestedNameSpecifier::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(NestedNameSpecifier);

NestedNameSpecifier::Node::Node(const TPNode& node) {
    //todo
}

ostream&
NestedNameSpecifier::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
