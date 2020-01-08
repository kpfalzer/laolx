//
//  Words.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/Words.hxx"
#include "laolx/parser/Token.hxx"

namespace laolx {
namespace parser {

static const Repetition IDENTS(Ident::THE_ONE, Repetition::eZeroOrMore);

TPNode
Words::_accept(Consumer& consumer) const {
    static const Sequence GRAM({&S_WORDS, &IDENTS, &S_RCURLY});
	TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(Words);

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
    static const Sequence GRAM({&S_SYMBOLS, &IDENTS, &S_RCURLY});
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(Symbols);

Symbols::Node::Node(const TPNode& node) {
    //todo
}

ostream&
Symbols::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
