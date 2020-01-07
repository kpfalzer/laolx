//
//  ExpressionList.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_ExpressionList_hxx
#define laolx_parser_ExpressionList_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class ExpressionList : public _Acceptor {
public:
    explicit ExpressionList()
    {}
    
    virtual ~ExpressionList()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class ExpressionList;

		explicit Node(const TPNode& node);
    };
    
    static const ExpressionList& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<ExpressionList::Node> TPExpressionListNode;
DEF_TO_XXXNODE(ExpressionList)

}
}

#endif /* laolx_parser_ExpressionList_hxx */
