//
//  PostfixExpression.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/PostfixExpression.hxx"

namespace laolx {
namespace parser {

TPNode
PostfixExpression::_accept(Consumer& consumer) const {
	//todo
    TPNode node = nullptr;
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const PostfixExpression& PostfixExpression::THE_ONE = PostfixExpression();

PostfixExpression::Node::Node(const TPNode& node) {
    //todo
}

ostream&
PostfixExpression::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

TPNode
PostfixExpression::X::_accept(Consumer& consumer) const {
	//todo
    TPNode node = nullptr;
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const PostfixExpression::X& PostfixExpression::X::THE_ONE = PostfixExpression::X();

PostfixExpression::X::Node::Node(const TPNode& node) {
    //todo
}

ostream&
PostfixExpression::X::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

TPNode
PostfixExpression::Y::_accept(Consumer& consumer) const {
	//todo
    TPNode node = nullptr;
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const PostfixExpression::Y& PostfixExpression::Y::THE_ONE = PostfixExpression::Y();

PostfixExpression::Y::Node::Node(const TPNode& node) {
    //todo
}

ostream&
PostfixExpression::Y::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
