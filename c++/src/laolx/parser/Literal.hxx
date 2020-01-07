//
//  Literal.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_Literal_hxx
#define laolx_parser_Literal_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class Literal : public _Acceptor {
public:
    explicit Literal()
    {}
    
    virtual ~Literal()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class Literal;

		explicit Node(const TPNode& node);
    };
    
    static const Literal& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Literal::Node> TPLiteralNode;
DEF_TO_XXXNODE(Literal)

}
}

#endif /* laolx_parser_Literal_hxx */
