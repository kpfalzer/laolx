//
//  MethodParameter.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/MethodParameter.hxx"

namespace laolx {
namespace parser {

TPNode
MethodParameter::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const MethodParameter& MethodParameter::THE_ONE = MethodParameter();

MethodParameter::Node::Node(const TPNode& node) {
    //todo
}

ostream&
MethodParameter::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

TPNode
MethodParameterList::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const MethodParameterList& MethodParameterList::THE_ONE = MethodParameterList();

MethodParameterList::Node::Node(const TPNode& node) {
    //todo
}

ostream&
MethodParameterList::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

TPNode
MethodParametersDeclaration::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const MethodParametersDeclaration& MethodParametersDeclaration::THE_ONE = MethodParametersDeclaration();

MethodParametersDeclaration::Node::Node(const TPNode& node) {
    //todo
}

ostream&
MethodParametersDeclaration::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
