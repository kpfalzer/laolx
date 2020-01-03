//
//  Statement.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/Statement.hxx"

namespace laolx {
namespace parser {

TPNode
Statement::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const Statement& Statement::THE_ONE = Statement();

Statement::Node::Node(const TPNode& node) {
    //todo
}

ostream&
Statement::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
