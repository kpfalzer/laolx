//
//  SimpleTypeSpecifier.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/SimpleTypeSpecifier.hxx"
#include "laolx/parser/Token.hxx"
#include "laolx/parser/Name.hxx"
#include "laolx/parser/NestedNameSpecifier.hxx"
#include "laolx/parser/Template.hxx"

namespace laolx {
namespace parser {

/**
 SimpleTypeSpecifier: SimpleTypeSpecifierX ArraySpecifier?

 ArraySpecifier: S_LBRACK S_RBRACK
 */
TPNode
SimpleTypeSpecifier::_accept(Consumer& consumer) const {
    static const Repetition ARY(ArraySpecifier::THE_ONE, Repetition::eOptional);
    static const Sequence GRAM({&X::THE_ONE, &ARY});
	TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(SimpleTypeSpecifier);

SimpleTypeSpecifier::Node::Node(const TPNode& node) {
    //todo
}

ostream&
SimpleTypeSpecifier::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

WITH_NODE_DEFINE(SimpleTypeSpecifier::X);

SimpleTypeSpecifier::X::Node::Node(const TPNode& node) {
    //todo
}

ostream&
SimpleTypeSpecifier::X::Node::operator<<(ostream& os) const {
    //todo
    return os;
}

TPNode
ArraySpecifier::_accept(Consumer& consumer) const {
    static const Sequence GRAM({&S_LBRACK, &S_RBRACK});
	TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(ArraySpecifier);

ArraySpecifier::Node::Node(const TPNode& node) {
    //todo
}

ostream&
ArraySpecifier::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

/**
SimpleTypeSpecifierX:
  NestedNameSpecifier? Name
|    K_INT
|    K_FLOAT
|    K_STRING
|    K_CHAR
|    K_BOOL
|    K_SYMBOL
|    K_VECTOR TemplateSpecifier?
|    K_MAP TemplateSpecifier?
*/
TPNode
SimpleTypeSpecifier::X::_accept(Consumer& consumer) const {
    static const Repetition NNOPT(NestedNameSpecifier::THE_ONE, Repetition::eOptional);
    static const Repetition TSOPT(TemplateSpecifier::THE_ONE, Repetition::eOptional);
    static const Sequence NN({&NNOPT, &Name::THE_ONE});
    static const Sequence VEC({&K_VECTOR, &TSOPT});
    static const Sequence MAP({&K_MAP, &TSOPT});
    static const Alternatives GRAM({
        &NN,
        &K_INT,
        &K_FLOAT,
        &K_STRING,
        &K_CHAR,
        &K_BOOL,
        &K_SYMBOL,
        &VEC,
        &MAP
    });
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

}
}
