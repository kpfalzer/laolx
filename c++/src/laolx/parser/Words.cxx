//
//  Words.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/Words.hxx"

namespace laolx {
namespace parser {

TPNode
Words::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const Words& Words::THE_ONE = Words();

Words::Node::Node(const TPNode& node) {
    //todo
}

ostream&
Words::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

TPNode
Symbols::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const Symbols& Symbols::THE_ONE = Symbols();

Symbols::Node::Node(const TPNode& node) {
    //todo
}

ostream&
Symbols::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

TPNode
Regexp::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const Regexp& Regexp::THE_ONE = Regexp();

Regexp::Node::Node(const TPNode& node) {
    //todo
}

ostream&
Regexp::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
