//
//  Name.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/Name.hxx"
#include "laolx/parser/Token.hxx"
#include "laolx/parser/Template.hxx"

namespace laolx {
namespace parser {

/**
 Name: IDENT | SimpleTemplateId
 */
TPNode
Name::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(Name);

Name::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
Name::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

}
}
