//
//  string.cxx
//  
//
//  Created by Karl W Pfalzer on 12/11/19.
//

#include "apfev3/acceptor.hxx"
#include "laolx/parser/String.hxx"

namespace laolx {
namespace parser {

//todo: #{expression} as EVALSTRING, actually parses expression.

TPNode
String::_accept(Consumer& consumer) const {
    TPNode node = apfev3::token::Quoted::THE_ONE.accept(consumer);
    return (node.isValid()) ? new Node(node) : node;
}

bool
String::Node::isSquote() const {
    return '\'' == text[0];
}

bool
String::Node::isDquote() const {
    return '"' == text[0];
}

String::Node::Node(const TPNode& node)
: _Terminal(node)
{}

/*static*/ const String& String::THE_ONE = String();

}
}
