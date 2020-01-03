//
//  NestedNameSpecifier.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_NestedNameSpecifier_hxx
#define laolx_parser_NestedNameSpecifier_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class NestedNameSpecifier : public _Acceptor {
public:
    explicit NestedNameSpecifier()
    {}
    
    virtual ~NestedNameSpecifier()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
    private:
        friend class NestedNameSpecifier;

		explicit Node(const TPNode& node);
    };
    
    static const NestedNameSpecifier& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<NestedNameSpecifier::Node> TPNestedNameSpecifierNode;
DEF_TO_XXXNODE(NestedNameSpecifier)

}
}

#endif /* laolx_parser_NestedNameSpecifier_hxx */
