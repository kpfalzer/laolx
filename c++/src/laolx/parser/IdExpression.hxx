//
//  IdExpression.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_IdExpression_hxx
#define laolx_parser_IdExpression_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class IdExpression : public _Acceptor {
public:
    explicit IdExpression()
    {}
    
    virtual ~IdExpression()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class IdExpression;

		explicit Node(const TPNode& node);
    };
    
    static const IdExpression& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<IdExpression::Node> TPIdExpressionNode;
DEF_TO_XXXNODE(IdExpression)

}
}

#endif /* laolx_parser_IdExpression_hxx */
