//
//  Expression.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_Expression_hxx
#define laolx_parser_Expression_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class Expression : public _Acceptor {
public:
    explicit Expression()
    {}
    
    virtual ~Expression()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class Expression;

		explicit Node(const TPNode& node);
    };
    
    static const Expression& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Expression::Node> TPExpressionNode;
DEF_TO_XXXNODE(Expression)

}
}

#endif /* laolx_parser_Expression_hxx */
