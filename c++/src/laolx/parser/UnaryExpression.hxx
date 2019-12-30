//
//  UnaryExpression.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_UnaryExpression_stmt_hxx
#define laolx_parser_UnaryExpression_stmt_hxx

#include "laolx/parser/laolx.hxx"
#include "laolx/parser/PostfixExpression.hxx"
#include "laolx/parser/UnaryOp.hxx"

namespace laolx {
namespace parser {

class UnaryExpression : public _Acceptor {
public:
    explicit UnaryExpression()
    {}
    
    virtual ~UnaryExpression()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
        const TPUnaryOpNode op;
        const TPPostfixExpressionNode expr;
        
    private:
        friend class UnaryExpression;

		explicit Node(const TPNode& op, const TPNode& expr);
    };
    
    static const UnaryExpression& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<UnaryExpression::Node> TPUnaryExpressionNode;
DEF_TO_XXXNODE(UnaryExpression)

}
}

#endif /* laolx_parser_UnaryExpression_stmt_hxx */
