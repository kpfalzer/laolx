//
//  ExpressionEle.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_ExpressionEle_hxx
#define laolx_parser_ExpressionEle_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class ExpressionEle : public _Acceptor {
public:
    explicit ExpressionEle()
    {}
    
    virtual ~ExpressionEle()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class ExpressionEle;

		explicit Node(const TPNode& node);
    };
    
    static const ExpressionEle& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<ExpressionEle::Node> TPExpressionEleNode;
DEF_TO_XXXNODE(ExpressionEle)

}
}

#endif /* laolx_parser_ExpressionEle_hxx */
