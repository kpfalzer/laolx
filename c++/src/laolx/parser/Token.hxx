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

class Int : public _Acceptor {
public:
    explicit Int()
    {}
    
    virtual ~Int()
    {}
    
    class Node : public _Terminal {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
        NODE_TYPE_DECLARE;
        
    private:
        friend class Int;

		explicit Node(const TPNode& val);
    };
    
    static const Int& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Int::Node> TPIntNode;
DEF_TO_XXXNODE(Int)

class Float : public _Acceptor {
public:
    explicit Float()
    {}
    
    virtual ~Float()
    {}
    
    class Node : public _Terminal {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
        NODE_TYPE_DECLARE;
        
    private:
        friend class Float;

		explicit Node(const TPNode& mant1, const TPNode& mant2, const TPNode& exp);
    };
    
    static const Float& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Float::Node> TPFloatNode;
DEF_TO_XXXNODE(Float)

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
        
        NODE_TYPE_DECLARE;
        
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
        
        NODE_TYPE_DECLARE;
        
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
    explicit Ident()
    {}
    
    virtual ~Ident()
    {}
    
    class Node : public _Terminal {
    public:
        NODE_TYPE_DECLARE;
        
    private:
        friend class Ident;
        
        explicit Node(const TPNode& node)
        : _Terminal(node)
        {}
    };
    
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
        
        NODE_TYPE_DECLARE;
        
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
			eS_ANDEQ,
            eS_ARRAY,
            eS_COLON,
            eS_COMMA,
			eS_DIV,
			eS_DIVEQ,
            eS_DOT,
            eS_DOT_QMARK,
			eS_EQ,
			eS_EQ2,
            eS_EXCLAMATION,
            eS_GT,
            eS_GTEQ,
            eS_GT2,
			eS_GT2EQ,
            eS_LBRACK,
            eS_LCURLY,
            eS_LPAREN,
            eS_LT,
            eS_LTEQ,
            eS_LT2,
			eS_LT2EQ,
			eS_MAP,
            eS_MINUS,
            eS_MINUS2,
			eS_MINUSEQ,
			eS_NOT,
			eS_NOTEQ,
            eS_OR,
            eS_OR2,
			eS_OREQ,
			eS_PCNT,
			eS_PCNTEQ,
            eS_PLUS,
            eS_PLUS2,
			eS_PLUSEQ,
            eS_QMARK,
            eS_RBRACK,
            eS_RCURLY,
            eS_RPAREN,
            eS_SEMICOLON,
            eS_STAR,
			eS_STAREQ,
            eS_SYMBOLS,
            eS_TILDE,
			eS_VECTOR,
            eS_WORDS,
			eS_XOR,
			eS_XOREQ,
            //
            //keywords
            eK_BOOL,
            eK_CHAR,
            eK_FALSE,
            eK_FLOAT,
            eK_FROM,
            eK_IMPORT,
            eK_INT,
            eK_MAP,
            eK_NIL,
            eK_STRING,
            eK_SYMBOL,
            eK_THIS,
            eK_TRUE,
            eK_VECTOR,
            //
            //keep this LAST_UNSUSED since measured for termcode value.
            eK_LAST_UNUSED
        };
        
        const EType type;
        
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;

        virtual std::size_t typeCode() const {
            return type;
        }
        
    private:
        friend class Token;
        
        explicit Node(const TPNode& node, EType type)
        : _Terminal(node), type(type)
        {}
        
    protected:
        explicit Node(const Node& node) = default;
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
	S_ANDEQ,
    S_ARRAY,
    S_COLON,
    S_COMMA,
	S_DIV,
	S_DIVEQ,
    S_DOT,
    S_DOT_QMARK,
	S_EQ,
	S_EQ2,
    S_EXCLAMATION,
    S_GT,
    S_GTEQ,
    S_GT2,
	S_GT2EQ,
    S_LBRACK,
    S_LCURLY,
    S_LPAREN,
    S_LT,
    S_LTEQ,
    S_LT2,
	S_LT2EQ,
	S_MAP,
    S_MINUS,
    S_MINUS2,
	S_MINUSEQ,
	S_NOTEQ,
    S_OR,
    S_OR2,
	S_OREQ,
	S_PCNT,
	S_PCNTEQ,
    S_PLUS,
    S_PLUS2,
	S_PLUSEQ,
    S_QMARK,
    S_RBRACK,
    S_RCURLY,
    S_RPAREN,
    S_SEMICOLON,
    S_STAR,
	S_STAREQ,
    S_SYMBOLS,
    S_TILDE,
	S_VECTOR,
    S_WORDS,
	S_XOR,
	S_XOREQ,
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
    K_TRUE,
    K_MAP,
    K_VECTOR
;

typedef Token::Node              TokenNode;
typedef PTRcObjPtr<Token::Node>  TPTokenNode;
typedef PTRcObjPtr<Ident::Node>  TPIdentNode;

DEF_TO_XXXNODE(Token)
DEF_TO_XXXNODE(Ident)

class Bool : public _Acceptor {
public:
    explicit Bool()
    {}
    
    virtual ~Bool()
    {}
    
    class Node : public TokenNode {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
        bool isTrue() {
            return TokenNode::eK_TRUE == type;
        }
        
        NODE_TYPE_DECLARE;
        
    private:
        friend class Bool;

        explicit Node(const TPNode& node);
    };
    
    static const Bool& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Bool::Node> TPBoolNode;
DEF_TO_XXXNODE(Bool)

class Sign : public _Acceptor {
public:
    explicit Sign()
    {}
    
    virtual ~Sign()
    {}
    
    class Node : public TokenNode {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
        bool isPlus() {
            return TokenNode::eS_PLUS == type;
        }
        
        bool isMinus() {
            return TokenNode::eS_MINUS == type;
        }
        
        NODE_TYPE_DECLARE;
        
    private:
        friend class Sign;

        explicit Node(const TPNode& node);
    };
    
    static const Sign& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Sign::Node> TPSignNode;
DEF_TO_XXXNODE(Sign)

}
}

#endif /* laolx_parser_token_hxx */
