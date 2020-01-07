//
//  PrimaryExpression.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_PrimaryExpression_hxx
#define laolx_parser_PrimaryExpression_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class PrimaryExpression : public _Acceptor {
public:
    explicit PrimaryExpression()
    {}
    
    virtual ~PrimaryExpression()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class PrimaryExpression;

		explicit Node(const TPNode& node);
    };
    
    static const PrimaryExpression& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<PrimaryExpression::Node> TPPrimaryExpressionNode;
DEF_TO_XXXNODE(PrimaryExpression)

}
}

#endif /* laolx_parser_PrimaryExpression_hxx */
