//
//  NestedNameSpecifier.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/NestedNameSpecifier.hxx"
#include "laolx/parser/Token.hxx"
#include "laolx/parser/Name.hxx"
#include "laolx/parser/Template.hxx"

namespace laolx {
namespace parser {

/**
 NestedNameSpecifier: NestedNameSpecifierY NestedNameSpecifierX*
 */
LEFT_RECURSION_DEFINE(NestedNameSpecifier);

TPNode
NestedNameSpecifier::_accept(Consumer& consumer) const {
	TPNode node = __GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(NestedNameSpecifier);

NestedNameSpecifier::Node::Node(const TPNode& node) {
    //todo
}

ostream&
NestedNameSpecifier::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

TPNode
DotOp::_accept(Consumer& consumer) const {
    static const Alternatives GRAM({&S_DOT, &S_DOT_QMARK});
	TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(DotOp);

DotOp::Node::Node(const TPNode& node) {
    //todo
}

ostream&
DotOp::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

/**
DotOp: S_DOT | S_DOT_QMARK

NestedNameSpecifierX:
   IDENT DotOp
|      SimpleTemplateId DotOp
*/
TPNode
NestedNameSpecifier::X::_accept(Consumer& consumer) const {
    static const Sequence ALT1({&Ident::THE_ONE, &DotOp::THE_ONE});
    static const Sequence ALT2({&SimpleTemplateId::THE_ONE, &DotOp::THE_ONE});
    static const Alternatives GRAM({&ALT1, &ALT2});
	TPNode node = GRAM.accept(consumer); //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(NestedNameSpecifier::X);

NestedNameSpecifier::X::Node::Node(const TPNode& node) {
    //todo
}

ostream&
NestedNameSpecifier::X::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

/**
NestedNameSpecifierY: Name DotOp
*/
TPNode
NestedNameSpecifier::Y::_accept(Consumer& consumer) const {
    static const Sequence GRAM({&Name::THE_ONE, &DotOp::THE_ONE});
	TPNode node = GRAM.accept(consumer); //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(NestedNameSpecifier::Y);

NestedNameSpecifier::Y::Node::Node(const TPNode& node) {
    //todo
}

ostream&
NestedNameSpecifier::Y::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
