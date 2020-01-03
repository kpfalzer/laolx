//
//  Bool.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_Bool_stmt_hxx
#define laolx_parser_Bool_stmt_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class Bool : public _Acceptor {
public:
    explicit Bool()
    {}
    
    virtual ~Bool()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
        bool isTrue() {
            return __isTrue;
        }
        
    private:
        friend class Bool;

		explicit Node(const TPNode& node);
        
        bool __isTrue;
    };
    
    static const Bool& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Bool::Node> TPBoolNode;
DEF_TO_XXXNODE(Bool)

}
}

#endif /* laolx_parser_Bool_stmt_hxx */
