//
//  Number.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/Number.hxx"
#include "laolx/parser/Token.hxx"

namespace laolx {
namespace parser {

TPNode
Number::_accept(Consumer& consumer) const {
    static const Repetition SIGN_OPT(Sign::THE_ONE, Repetition::eOptional);
    static const Sequence INT({&SIGN_OPT, &Int::THE_ONE});
    static const Sequence FLOAT({&SIGN_OPT, &Float::THE_ONE});
    static const Sequence SIZED({&SIGN_OPT, &Sized::THE_ONE});
    static const Alternatives GRAM({
        &INT,
        &FLOAT,
        &SIZED
    });
    // node (if valid) is AlternativeNode
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(Number);

Number::Node::Node(const TPNode& node)
: AlternativeNode(toAlternativeNode(node).asT())
{}

ostream&
Number::Node::operator<<(ostream& os) const {
    return os << *actual();
}

}
}
