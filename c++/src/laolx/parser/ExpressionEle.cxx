//
//  ExpressionEle.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/ExpressionEle.hxx"

namespace laolx {
namespace parser {

TPNode
ExpressionEle::_accept(Consumer& consumer) const {
	//todo
    TPNode node = nullptr;
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const ExpressionEle& ExpressionEle::THE_ONE = ExpressionEle();

ExpressionEle::Node::Node(const TPNode& node) {
    //todo
}

ostream&
ExpressionEle::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
