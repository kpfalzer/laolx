//
//  Name.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/Name.hxx"

namespace laolx {
namespace parser {

TPNode
Name::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const Name& Name::THE_ONE = Name();

Name::Node::Node(const TPNode& node) {
    //todo
}

ostream&
Name::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
