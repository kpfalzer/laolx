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

/*static*/ const ReturnSpecifier& ReturnSpecifier::THE_ONE = ReturnSpecifier();

ReturnSpecifier::Node::Node(const TPNode& node) {
    //todo
}

ostream&
ReturnSpecifier::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}