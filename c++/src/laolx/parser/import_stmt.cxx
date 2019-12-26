//
//  import_stmt.cxx
//  
//
//  Created by Karl W Pfalzer on 12/11/19.
//

#include "xyzzy/refcnt.hxx"
#include "laolx/parser/token.hxx"
#include "laolx/parser/import_stmt.hxx"

using apfev3::Sequence;
using apfev3::Repetition;
using apfev3::TPNodeVector;

namespace laolx {
namespace parser {

TPNode
ImportSpecifier::_accept(Consumer& consumer) const {
    static const Sequence S1({&S_DOT, &Ident::THE_ONE});
    static const Repetition R1(S1, Repetition::eZeroOrMore);
    static const Sequence S2({&Ident::THE_ONE, &R1});
    TPNode node = S2.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const ImportSpecifier& ImportSpecifier::THE_ONE = ImportSpecifier();

ImportSpecifier::Node::Node(const TPNode& node) {
    initFromOneOrMore(node);
}

ostream&
ImportSpecifier::Node::operator<<(ostream& os) const {
    size_t i = 0;
    this->for_each([&](const TPNode& node){
        if (0 < i++) os << '.';
        os << toTerminal(node)->text;
    });
    return os;
}

TPNode
ImportSpecifierList::_accept(Consumer& consumer) const {
    static const Sequence S1({&S_COMMA, &ImportSpecifier::THE_ONE});
    static const Repetition R1(S1, Repetition::eZeroOrMore);
    static const Sequence S2({&ImportSpecifier::THE_ONE, &R1});
    TPNode node = S2.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}
 
/*static*/ const ImportSpecifierList& ImportSpecifierList::THE_ONE = ImportSpecifierList();

ImportSpecifierList::Node::Node(const TPNode& node) {
    initFromOneOrMore(node);
}

ostream&
ImportSpecifierList::Node::operator<<(ostream& os) const {
    size_t i = 0;
    this->for_each([&](const TPNode& node){
        if (0 < i++) os << ',';
        os << *node;
    });
    return os;
}

TPNode
ImportStmt::_accept(Consumer &consumer) const {
    const Mark start = consumer.mark();
    {
        static const Sequence S1({&K_IMPORT, &ImportSpecifierList::THE_ONE, &S_SEMICOLON});
        TPNode all = S1.accept(consumer);
        if (all.isValid()) {
            return new Node(all, toNodeVector(all)->at(1));
        }
    }
    {
        static const Sequence S1({
            &K_FROM, &ImportSpecifier::THE_ONE,
            &K_IMPORT, &ImportSpecifierList::THE_ONE,
            &S_SEMICOLON
        });
        TPNode all = S1.accept(consumer);
        if (all.isValid()) {
            TPNodeVector vec = toNodeVector(all);
            return new Node(all, vec->at(1), vec->at(3));
        }
    }
    consumer.rewind(start);
    return nullptr;
}

/*static*/ const ImportStmt& ImportStmt::THE_ONE = ImportStmt();

ImportStmt::Node::Node(const TPNode& all, const TPNode& imports)
: Node(all, nullptr, imports) {
}

ImportStmt::Node::Node(const TPNode& all, const TPNode& from, const TPNode& imports)
:   NodeVector(all),
    __from(toImportSpecifierNode(from)),
    __imports(toImportSpecifierListNode(imports)) {
}

ostream&
ImportStmt::Node::Node::operator<<(ostream& os) const {
    return NodeVector::operator<<(os);
}

}
}
