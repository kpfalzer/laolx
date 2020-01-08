//
//  Literal.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/Literal.hxx"
#include "laolx/parser/String.hxx"
#include "laolx/parser/Words.hxx"

namespace laolx {
namespace parser {

/**
Literal:
	SYMBOL
|	Sign? INT
|	Sign? FLOAT
|        Sign? SIZED
|	String
|	REGEXP
|	Words
|	Symbols
|	K_NIL
|	Bool
*/
TPNode
Literal::_accept(Consumer& consumer) const {
    static const Repetition SIGN_OPT(Sign::THE_ONE, Repetition::eOptional);
    static const Sequence INT({&SIGN_OPT, &Int::THE_ONE});
    static const Sequence FLOAT({&SIGN_OPT, &Float::THE_ONE});
    static const Sequence SIZED({&SIGN_OPT, &Sized::THE_ONE});
    static const Alternatives GRAM({
       &Symbol::THE_ONE,
        &INT,
        &FLOAT,
        &SIZED,
        &String::THE_ONE,
        &Regexp::THE_ONE,
        &Words::THE_ONE,
        &Symbols::THE_ONE,
        &K_NIL,
        &Bool::THE_ONE
    });
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(Literal);

Literal::Node::Node(const TPNode& node) {
    //todo
}

ostream&
Literal::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
