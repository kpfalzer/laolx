//
//  BracedInitList.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_BracedInitList_stmt_hxx
#define laolx_parser_BracedInitList_stmt_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class BracedInitList : public _Acceptor {
public:
    explicit BracedInitList()
    {}
    
    virtual ~BracedInitList()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
    private:
        friend class BracedInitList;

		explicit Node(const TPNode& node);
    };
    
    static const BracedInitList& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<BracedInitList::Node> TPBracedInitListNode;
DEF_TO_XXXNODE(BracedInitList)

}
}

#endif /* laolx_parser_BracedInitList_stmt_hxx */
