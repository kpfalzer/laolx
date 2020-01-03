//
//  Name.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_Name_hxx
#define laolx_parser_Name_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class Name : public _Acceptor {
public:
    explicit Name()
    {}
    
    virtual ~Name()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
    private:
        friend class Name;

		explicit Node(const TPNode& node);
    };
    
    static const Name& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Name::Node> TPNameNode;
DEF_TO_XXXNODE(Name)

}
}

#endif /* laolx_parser_Name_hxx */
