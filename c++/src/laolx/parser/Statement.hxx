//
//  Statement.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_Statement_hxx
#define laolx_parser_Statement_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class Statement : public _Acceptor {
public:
    explicit Statement()
    {}
    
    virtual ~Statement()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
        NODE_TYPE_DECLARE;
        
    private:
        friend class Statement;

		explicit Node(const TPNode& node);
    };
    
    static const Statement& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Statement::Node> TPStatementNode;
DEF_TO_XXXNODE(Statement)

}
}

#endif /* laolx_parser_Statement_hxx */
