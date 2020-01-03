//
//  BracedInitList.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/BracedInitList.hxx"

namespace laolx {
namespace parser {

TPNode
BracedInitList::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const BracedInitList& BracedInitList::THE_ONE = BracedInitList();

BracedInitList::Node::Node(const TPNode& node) {
    //todo
}

ostream&
BracedInitList::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
