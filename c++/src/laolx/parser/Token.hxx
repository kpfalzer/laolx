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

class Sized : public _Acceptor {
public:
    explicit Sized()
    {}
    
    virtual ~Sized()
    {}
    
    class Node : public _Terminal {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
    private:
        friend class Sized;

		explicit Node(const TPNode& size, char base, const TPNode& val);
    };
    
    static const Sized& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Sized::Node> TPSizedNode;
DEF_TO_XXXNODE(Sized)

class Bool : public _Acceptor {
public:
    explicit Bool()
    {}
    
    virtual ~Bool()
    {}
    
    class Node : public _Terminal {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
        bool isTrue() {
            return __isTrue;
        }
        
    private:
        friend class Bool;

		explicit Node(const TPNode& node);
        
        bool __isTrue;
    };
    
    static const Bool& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Bool::Node> TPBoolNode;
DEF_TO_XXXNODE(Bool)

class Regexp : public _Acceptor {
public:
    explicit Regexp()
    {}
    
    virtual ~Regexp()
    {}
    
    class Node : public _Terminal {
    public:
        virtual ~Node()
        {}
        
    private:
        friend class Regexp;

		explicit Node(const TPNode& node)
        : _Terminal(node)
        {}
    };
    
    static const Regexp& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Regexp::Node> TPRegexpNode;
DEF_TO_XXXNODE(Regexp)

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

class Symbol : public _Acceptor {
public:
    explicit Symbol()
    {}
    
    virtual ~Symbol()
    {}
    
    class Node : public _Terminal {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
    private:
        friend class Symbol;

        explicit Node(const TPNode& node);
    };
    
    static const Symbol& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Symbol::Node> TPSymbolNode;
DEF_TO_XXXNODE(Symbol)

class Token : public _Acceptor {
public:
    
    class Node : public _Terminal {
    public:
        enum EType {
            eS_AND,
            eS_AND2,
            eS_COLON,
            eS_COMMA,
            eS_DOT,
            eS_EXCLAMATION,
            eS_LT,
            eS_LBRACK,
            eS_LCURLY,
            eS_LPAREN,
            eS_GT,
            eS_MINUS,
            eS_MINUS2,
            eS_OR,
            eS_PLUS,
            eS_PLUS2,
            eS_RBRACK,
            eS_RCURLY,
            eS_RPAREN,
            eS_SEMICOLON,
            eS_SYMBOLS,
            eS_TILDE,
            eS_WORDS,
            //
            //keywords
            eK_BOOL,
            eK_CHAR,
            eK_FALSE,
            eK_FLOAT,
            eK_FROM,
            eK_IMPORT,
            eK_INT,
            eK_NIL,
            eK_STRING,
            eK_SYMBOL,
            eK_THIS,
            eK_TRUE,
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
    S_COLON,
    S_COMMA,
    S_DOT,
    S_LT,
    S_GT,
    S_LBRACK,
    S_LCURLY,
    S_LPAREN,
    S_MINUS,
    S_MINUS2,
    S_OR,
    S_PLUS,
    S_PLUS2,
    S_RBRACK,
    S_RCURLY,
    S_RPAREN,
    S_SYMBOLS,
    S_TILDE,
    S_EXCLAMATION,
    S_SEMICOLON,
    S_WORDS,
    //
    // keywords
    //
    K_BOOL,
    K_CHAR,
    K_FALSE,
    K_FLOAT,
    K_FROM,
    K_IMPORT,
    K_INT,
    K_NIL,
    K_STRING,
    K_SYMBOL,
    K_THIS,
    K_TRUE
;

typedef Token::Node              TokenNode;
typedef PTRcObjPtr<Token::Node>  TPTokenNode;
typedef PTRcObjPtr<Ident::Node>  TPIdentNode;

DEF_TO_XXXNODE(Token)
DEF_TO_XXXNODE(Ident)

}
}

#endif /* laolx_parser_token_hxx */
