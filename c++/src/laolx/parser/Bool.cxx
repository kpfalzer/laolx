//
//  Bool.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/Bool.hxx"
#include "laolx/parser/Token.hxx"

namespace laolx {
namespace parser {

using apfev3::toAlternativeNode;

TPNode
Bool::_accept(Consumer& consumer) const {
    static const Alternatives GRAM({&K_FALSE, &K_TRUE});
	TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const Bool& Bool::THE_ONE = Bool();

Bool::Node::Node(const TPNode& node) {
    push_back(node);
    __isTrue = toTokenNode(toAlternativeNode(node)->actual())->type == Token::Node::eK_TRUE;
}

ostream&
Bool::Node::operator<<(ostream& os) const {
	return os << (__isTrue ? "true" : "false");
}

}
}
