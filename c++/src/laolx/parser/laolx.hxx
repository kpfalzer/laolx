//
//  common.hxx
//  
//  Created by Karl W Pfalzer on 12/11/19.
//

#ifndef laolx_parser_laolx_hxx
#define laolx_parser_laolx_hxx

#include <iostream>
#include "xyzzy/refcnt.hxx"
#include "apfev3/acceptor.hxx"

namespace laolx {
namespace parser {

using xyzzy::PTRcObjPtr;
using xyzzy::downcast;

using std::ostream;
using std::endl;
using apfev3::TPNode;
using apfev3::NodeVector;
using apfev3::_Terminal;
using apfev3::_NonTerminal;
using apfev3::_Acceptor;
using apfev3::Consumer;
using apfev3::Location;
using apfev3::Mark;
using apfev3::toTerminal;
using apfev3::toNonTerminal;
using apfev3::toNodeVector;


#define DEF_TO_XXXNODE(_type) \
inline TP##_type##Node to##_type##Node(const TPNode& node) {        \
        return xyzzy::downcast<apfev3::_Node, _type::Node>(node);   \
    }

}
}

#endif /* laolx_parser_laolx_hxx */
