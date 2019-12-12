//
//  string.hxx
//  
//
//  Created by Karl W Pfalzer on 12/11/19.
//

#ifndef laolx_parser_string_hxx
#define laolx_parser_string_hxx

#include "laolx/parser/terminal.hxx"

namespace laolx {
namespace parser {

class String : public _Terminal {
public:
    
    bool parse(Consumer& consumer, TPNodeCollector collector);
    
    virtual ~String()
    {}
    
};

typedef PTRcObjPtr<String>  TPString;

}
}

#endif /* laolx_parser_string_hxx */
