//
//  OperatorFunctionId.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/OperatorFunctionId.hxx"

namespace laolx {
namespace parser {

TPNode
OverloadableOperator::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(OverloadableOperator);

OverloadableOperator::Node::Node(const TPNode& node) {
    //todo
}

ostream&
OverloadableOperator::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

TPNode
OperatorFunctionId::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(OperatorFunctionId);

OperatorFunctionId::Node::Node(const TPNode& node) {
    //todo
}

ostream&
OperatorFunctionId::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
