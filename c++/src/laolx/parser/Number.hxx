//
//  Number.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_Number_hxx
#define laolx_parser_Number_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class Number : public _Acceptor {
public:
    explicit Number()
    {}
    
    virtual ~Number()
    {}
    
    class Node : public AlternativeNode {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class Number;

		explicit Node(const TPNode& node);
    };
    
    static const Number& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Number::Node> TPNumberNode;
DEF_TO_XXXNODE(Number)

}
}

#endif /* laolx_parser_Number_stmt_hxx */
