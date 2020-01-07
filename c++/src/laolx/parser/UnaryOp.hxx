//
//  UnaryOp.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_UnaryOp_hxx
#define laolx_parser_UnaryOp_hxx

#include "laolx/parser/laolx.hxx"
#include "laolx/parser/Token.hxx"

namespace laolx {
namespace parser {

class UnaryOp : public _Acceptor {
public:
    explicit UnaryOp()
    {}
    
    virtual ~UnaryOp()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        const TokenNode& asToken() const {
            return toTokenNode(at(0)).asT();
        }
        
        operator const TokenNode&() const {
            return asToken();
        }
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class UnaryOp;

		explicit Node(const TPNode& node);
    };
    
    static const UnaryOp& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<UnaryOp::Node> TPUnaryOpNode;
DEF_TO_XXXNODE(UnaryOp)

}
}

#endif /* laolx_parser_UnaryOp_hxx */
