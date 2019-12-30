//
//  UnaryOp.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/UnaryOp.hxx"

namespace laolx {
namespace parser {

using apfev3::Alternatives;

TPNode
UnaryOp::_accept(Consumer& consumer) const {
    static const Alternatives OPS({&S_PLUS, &S_MINUS, &S_EXCLAMATION, &S_TILDE,
        &S_PLUS2, &S_MINUS2});
    TPNode node = OPS.accept(consumer);
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const UnaryOp& UnaryOp::THE_ONE = UnaryOp();

UnaryOp::Node::Node(const TPNode& node) {
    push_back(node);
}

ostream&
UnaryOp::Node::operator<<(ostream& os) const {
    os << asToken();
    return os;
}

}
}
