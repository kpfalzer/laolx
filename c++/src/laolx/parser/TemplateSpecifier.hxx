//
//  TemplateSpecifier.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_TemplateSpecifier_hxx
#define laolx_parser_TemplateSpecifier_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class TemplateSpecifier : public _Acceptor {
public:
    explicit TemplateSpecifier()
    {}
    
    virtual ~TemplateSpecifier()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class TemplateSpecifier;

		explicit Node(const TPNode& node);
    };
    
    static const TemplateSpecifier& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<TemplateSpecifier::Node> TPTemplateSpecifierNode;
DEF_TO_XXXNODE(TemplateSpecifier)

}
}

#endif /* laolx_parser_TemplateSpecifier_stmt_hxx */
