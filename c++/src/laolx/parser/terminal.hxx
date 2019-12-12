//
//  terminal.hxx
//  
//
//  Created by Karl W Pfalzer on 12/11/19.
//

#ifndef laolx_parser_terminal_hxx
#define laolx_parser_terminal_hxx

#include "laolx/parser/node.hxx"

namespace laolx {
namespace parser {

class _Terminal : public _Node {
public:
    
protected:
    virtual ~_Terminal() = 0;
    
};

typedef PTRcObjPtr<_Terminal> TPTerminal;

}
}

#endif /* laolx_parser_nonterminal_hxx */
