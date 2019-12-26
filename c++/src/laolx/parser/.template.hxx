//
//  @CLASS@.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_@CLASS@_stmt_hxx
#define laolx_parser_@CLASS@_stmt_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class @CLASS@ : public _Acceptor {
public:
    explicit @CLASS@()
    {}
    
    virtual ~@CLASS@()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
    private:
        friend class @CLASS@;

		Node(const TPNode& node);
    };
    
    static const @CLASS@& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<@CLASS@::Node> TP@CLASS@Node;
DEF_TO_XXXNODE(@CLASS@)

}
}

#endif /* laolx_parser_@CLASS@_stmt_hxx */
