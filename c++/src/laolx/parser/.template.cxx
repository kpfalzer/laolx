//
//  @CLASS@.cxx
//  
//
//  Created by Karl W Pfalzer
//

#include "laolx/parser/@CLASS@.hxx"

namespace laolx {
namespace parser {

TPNode
@CLASS@::_accept(Consumer& consumer) const {
	//todo
    return (node.isValid()) ? new Node(node) : nullptr;
}

/*static*/ const @CLASS@& @CLASS@::THE_ONE = @CLASS@();

@CLASS@::Node::Node(const TPNode& node) {
    //todo
}

ostream&
@CLASS@::Node::operator<<(ostream& os) const {
	//todo
    return os;
}

}
}
