//
//  Expression.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/Expression.hxx"

namespace laolx {
namespace parser {

TPNode
Expression::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(Expression);

Expression::Node::Node(const TPNode& node) {
    //todo
}

ostream&
Expression::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
