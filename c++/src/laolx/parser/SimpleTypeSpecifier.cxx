//
//  SimpleTypeSpecifier.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/SimpleTypeSpecifier.hxx"

namespace laolx {
namespace parser {

TPNode
SimpleTypeSpecifier::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const SimpleTypeSpecifier& SimpleTypeSpecifier::THE_ONE = SimpleTypeSpecifier();

SimpleTypeSpecifier::Node::Node(const TPNode& node) {
    //todo
}

ostream&
SimpleTypeSpecifier::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}