//
//  Literal.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/Literal.hxx"

namespace laolx {
namespace parser {

TPNode
Literal::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const Literal& Literal::THE_ONE = Literal();

Literal::Node::Node(const TPNode& node) {
    //todo
}

ostream&
Literal::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
