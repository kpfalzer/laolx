//
//  Collection.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/Collection.hxx"
#include "laolx/parser/Token.hxx"
#include "laolx/parser/Expression.hxx"
#include "laolx/parser/ExpressionList.hxx"

namespace laolx {
namespace parser {

/**
 Array: S_ARRAY ExpressionList? S_RCURLY
*/
TPNode
Array::_accept(Consumer& consumer) const {
    static const Repetition EL(ExpressionList::THE_ONE, Repetition::eOptional);
    static const Sequence GRAM({&S_ARRAY, &EL, &S_RCURLY});
	TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(Array);

Array::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
Array::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

/**
Vector: S_VECTOR ExpressionList? S_RCURLY
*/
TPNode
Vector::_accept(Consumer& consumer) const {
    static const Repetition EL(ExpressionList::THE_ONE, Repetition::eOptional);
    static const Sequence GRAM({&S_VECTOR, &EL, &S_RCURLY});
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(Vector);

Vector::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
Vector::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

/**
Map: S_MAP MapEntryList? S_RCURLY
*/
TPNode
Map::_accept(Consumer& consumer) const {
    static const Repetition MEL(MapEntryList::THE_ONE, Repetition::eOptional);
    static const Sequence GRAM({&S_MAP, &MEL, &S_RCURLY});
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(Map);

Map::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
Map::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

/**
MapEntry: Ident S_COLON Expression
*/
TPNode
MapEntry::_accept(Consumer& consumer) const {
    static const Sequence GRAM({&Ident::THE_ONE, &S_COLON, &Expression::THE_ONE});
	TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(MapEntry);

MapEntry::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
MapEntry::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

/**
MapEntryList: MapEntry (COMMA MapEntry)*
*/
TPNode
MapEntryList::_accept(Consumer& consumer) const {
    static const Sequence ME1({&S_COMMA, &MapEntry::THE_ONE});
    static const Repetition ME2(ME1, Repetition::eZeroOrMore);
    static const Sequence GRAM({&MapEntry::THE_ONE, &ME2});
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(MapEntryList);

MapEntryList::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
MapEntryList::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

}
}
