//
//  IdExpression.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/IdExpression.hxx"

namespace laolx {
namespace parser {

TPNode
IdExpression::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const IdExpression& IdExpression::THE_ONE = IdExpression();

IdExpression::Node::Node(const TPNode& node) {
    //todo
}

ostream&
IdExpression::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
