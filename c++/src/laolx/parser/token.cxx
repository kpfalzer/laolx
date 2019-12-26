//
//  token.cxx
//  
//
//  Created by Karl W Pfalzer on 12/11/19.
//

#include "apfev3/acceptor.hxx"
#include "laolx/parser/token.hxx"

namespace laolx {
namespace parser {

TPNode
Ident::_accept(Consumer& consumer) const {
    TPNode node = apfev3::token::Ident::THE_ONE.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const Ident& Ident::THE_ONE = Ident();

TPNode
Token::_accept(Consumer& consumer) const {
    TPNode node = sequence.accept(consumer);
    if (node.isNull()) return nullptr;
    /*unused*/ apfev3::token::Spacing::THE_ONE.accept(consumer);
    return new Node(node, type);
}

//extern
const Token
    S_AND("&", Token::Node::eS_AND),
    S_AND2("&&", Token::Node::eS_AND2),
    S_COMMA(",", Token::Node::eS_COMMA),
    S_LT("<", Token::Node::eS_LT),
    S_GT(">", Token::Node::eS_GT),
    S_DOT(".", Token::Node::eS_DOT),
    S_SEMICOLON(";", Token::Node::eS_SEMICOLON),
    //
    K_FROM("from", Token::Node::eK_FROM),
    K_IMPORT("import", Token::Node::eK_IMPORT)
;

ostream&
Token::Node::operator<<(ostream& os) const {
    os << text;
    return os;
}

}
}
