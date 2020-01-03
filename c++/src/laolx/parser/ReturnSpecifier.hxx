//
//  ReturnSpecifier.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_ReturnSpecifier_stmt_hxx
#define laolx_parser_ReturnSpecifier_stmt_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class ReturnSpecifier : public _Acceptor {
public:
    explicit ReturnSpecifier()
    {}
    
    virtual ~ReturnSpecifier()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
    private:
        friend class ReturnSpecifier;

		explicit Node(const TPNode& node);
    };
    
    static const ReturnSpecifier& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<ReturnSpecifier::Node> TPReturnSpecifierNode;
DEF_TO_XXXNODE(ReturnSpecifier)

}
}

#endif /* laolx_parser_ReturnSpecifier_stmt_hxx */
