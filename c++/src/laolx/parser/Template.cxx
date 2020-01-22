//
//  Template.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/Template.hxx"
#include "laolx/parser/Expression.hxx"
#include "laolx/parser/SimpleTypeSpecifier.hxx"
#include "laolx/parser/Token.hxx"

namespace laolx {
namespace parser {

/**
 TemplateSpecifier: S_LT TemplateArgumentList? S_GT
 */
TPNode
TemplateSpecifier::_accept(Consumer& consumer) const {
    static const Repetition TAL(TemplateArgumentList::THE_ONE, Repetition::eOptional);
    static const Sequence GRAM({&S_LT, &TAL, &S_GT});
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(TemplateSpecifier);

TemplateSpecifier::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
TemplateSpecifier::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

/**
 // NOTE: we'll use special templates: VARIANT and LAMBDA as needed.
 TemplateId:
    SimpleTemplateId
 |      OperatorFunctionId TemplateSpecifier
 */
TPNode
TemplateId::_accept(Consumer& consumer) const {
	//todo
	TPNode node = nullptr; //todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(TemplateId);

TemplateId::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
TemplateId::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

/**
 TemplateArgumentList: TemplateArgument (S_COMMA TemplateArgument)*
 */
TPNode
TemplateArgumentList::_accept(Consumer& consumer) const {
    static const Sequence TA1({&S_COMMA, &TemplateArgument::THE_ONE});
    static const Repetition TA2(TA1, Repetition::eZeroOrMore);
    static const Sequence GRAM({&TemplateArgument::THE_ONE, &TA2});
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(TemplateArgumentList);

TemplateArgumentList::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
TemplateArgumentList::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

/**
 // NOTE: While syntax is a bit loose: semantics require all named/bound
 //       or all positional; cannot mix these.
 TemplateArgument:
     (IDENT S_COLON)?
         (    Expression
         |    SimpleTypeSpecifier
         )
 */
TPNode
TemplateArgument::_accept(Consumer& consumer) const {
    static const Sequence P1({&Ident::THE_ONE, &S_COLON});
    static const Repetition P2(P1, Repetition::eOptional);
    static const Alternatives P3({&Expression::THE_ONE, &SimpleTypeSpecifier::THE_ONE});
    static const Sequence GRAM({&P2, &P3});
    TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(TemplateArgument);

TemplateArgument::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
TemplateArgument::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

/**
 SimpleTemplateId: IDENT TemplateSpecifier
 */
TPNode
SimpleTemplateId::_accept(Consumer& consumer) const {
    static const Sequence GRAM({&Ident::THE_ONE, &TemplateSpecifier::THE_ONE});
	TPNode node = GRAM.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

WITH_NODE_DEFINE(SimpleTemplateId);

SimpleTemplateId::Node::Node(const TPNode& node)
: NodeVector(node)
{}

ostream&
SimpleTemplateId::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

}
}
