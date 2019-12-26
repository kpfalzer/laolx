//
// token.hxx
//  
//
//  Created by Karl W Pfalzer on 12/20/19.
//

#ifndef laolx_parser_token_hxx
#define laolx_parser_token_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class Ident : public _Acceptor {
public:
    class Node : public _Terminal {
        friend class Ident;
        
        explicit Node(const TPNode& node)
        : _Terminal(node)
        {}
    };
    
    virtual ~Ident()
    {}
    
    static const Ident& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

class Token : public _Acceptor {
public:
    
    class Node : public _Terminal {
    public:
        enum EType {
            eS_AND,
            eS_AND2,
            eS_COMMA,
            eS_DOT,
            eS_LT,
            eS_GT,
            eS_SEMICOLON,
            //
            //keywords
            eK_FROM,
            eK_IMPORT
        };
        
        const EType type;
        
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;

    private:
        friend class Token;
        
        explicit Node(const TPNode& node, EType type)
        : _Terminal(node), type(type)
        {}
    };
    
    virtual ~Token()
    {}
    
    explicit Token(const std::string& text, Node::EType type)
    : sequence(text), type(type)
    {}
    
protected:
    TPNode _accept(Consumer& consumer) const;
    
private:
    apfev3::token::CharSequence sequence;
    const Node::EType type;
};

extern const Token
    S_AND,
    S_AND2,
    S_COMMA,
    S_DOT,
    S_LT,
    S_GT,
    S_SEMICOLON,
    //
    // keywords
    //
    K_FROM,
    K_IMPORT
;

typedef PTRcObjPtr<Token::Node>  TPTokenNode;
typedef PTRcObjPtr<Ident::Node>  TPIdentNode;

DEF_TO_XXXNODE(Token)
DEF_TO_XXXNODE(Ident)

}
}

#endif /* laolx_parser_token_hxx */
