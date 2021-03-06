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

WITH_NODE_DEFINE(UnaryOp);

UnaryOp::Node::Node(const TPNode& node)
:   AlternativeNode(node)
{}

ostream&
UnaryOp::Node::operator<<(ostream& os) const {
    return AlternativeNode::operator<<(os);
}

}
}
