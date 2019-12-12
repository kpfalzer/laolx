//
//  nonterminal.hxx
//  
//
//  Created by Karl W Pfalzer on 12/11/19.
//

#ifndef laolx_parser_nonterminal_hxx
#define laolx_parser_nonterminal_hxx

#include "laolx/parser/node.hxx"

namespace laolx {
namespace parser {

class _NonTerminal : public _Node, public _NodeCollector {
public:
    
protected:
    virtual ~_NonTerminal() = 0;
    
};

typedef PTRcObjPtr<_NonTerminal> TPNonTerminal;

}
}

#endif /* laolx_parser_nonterminal_hxx */
