//
//  TemplateSpecifier.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/TemplateSpecifier.hxx"

namespace laolx {
namespace parser {

TPNode
TemplateSpecifier::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(TemplateSpecifier);

TemplateSpecifier::Node::Node(const TPNode& node) {
    //todo
}

ostream&
TemplateSpecifier::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
