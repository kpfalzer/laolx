//
//  LambdaExpression.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_LambdaExpression_hxx
#define laolx_parser_LambdaExpression_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class LambdaExpression : public _Acceptor {
public:
    explicit LambdaExpression()
    {}
    
    virtual ~LambdaExpression()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
    private:
        friend class LambdaExpression;

		explicit Node(const TPNode& node);
    };
    
    static const LambdaExpression& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<LambdaExpression::Node> TPLambdaExpressionNode;
DEF_TO_XXXNODE(LambdaExpression)

}
}

#endif /* laolx_parser_LambdaExpression_hxx */
