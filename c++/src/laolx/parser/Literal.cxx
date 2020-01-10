//
//  Literal.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/Literal.hxx"
#include "laolx/parser/String.hxx"
#include "laolx/parser/Words.hxx"
#include "laolx/parser/Number.hxx"
#include "laolx/parser/Collection.hxx"

namespace laolx {
namespace parser {

/**
Literal:
	SYMBOL
|	Number
|	String
|	REGEXP
|	Words
|	Symbols
|	K_NIL
|	Bool
|        Array
|        Vector
|        Map
*/
TPNode
Literal::_accept(Consumer& consumer) const {
    static const Repetition SIGN_OPT(Sign::THE_ONE, Repetition::eOptional);
    static const Sequence INT({&SIGN_OPT, &Int::THE_ONE});
    static const Sequence FLOAT({&SIGN_OPT, &Float::THE_ONE});
    static const Sequence SIZED({&SIGN_OPT, &Sized::THE_ONE});
    static const Alternatives GRAM({
        &Symbol::THE_ONE,
        &Number::THE_ONE,
        &FLOAT,
        &SIZED,
        &String::THE_ONE,
        &Regexp::THE_ONE,
        &Words::THE_ONE,
        &Symbols::THE_ONE,
        &K_NIL,
        &Bool::THE_ONE,
        &Array::THE_ONE,
        &Vector::THE_ONE,
        &Map::THE_ONE
    });
    // node (if valid) is AlternativeNode
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(Literal);

Literal::Node::Node(const TPNode& node)
: AlternativeNode(toAlternativeNode(node).asT())
{}

ostream&
Literal::Node::operator<<(ostream& os) const {
    return os << *actual();
}

}
}
