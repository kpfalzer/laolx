//
//  string.hxx
//  
//
//  Created by Karl W Pfalzer on 12/11/19.
//

#ifndef laolx_parser_string_hxx
#define laolx_parser_string_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class String : public _Acceptor {
public:
    explicit String()
    {}
    
    virtual ~String()
    {}
    
    static const String& THE_ONE;
    
    class Node : public _Terminal {
    public:
        virtual ~Node()
        {}
        
        bool isSquote() const;
        
        bool isDquote() const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class String;
        
        explicit Node(const TPNode& node);
    };
    
protected:
    TPNode _accept(Consumer& consumer) const;
    
};

typedef PTRcObjPtr<String::Node>  TPStringNode;

}
}

#endif /* laolx_parser_string_hxx */
