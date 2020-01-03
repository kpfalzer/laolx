//
//  Words.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_Words_hxx
#define laolx_parser_Words_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class Words : public _Acceptor {
public:
    explicit Words()
    {}
    
    virtual ~Words()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
    private:
        friend class Words;

		explicit Node(const TPNode& node);
    };
    
    static const Words& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Words::Node> TPWordsNode;
DEF_TO_XXXNODE(Words)

class Symbols : public _Acceptor {
public:
    explicit Symbols()
    {}
    
    virtual ~Symbols()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
    private:
        friend class Symbols;

		explicit Node(const TPNode& node);
    };
    
    static const Symbols& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Symbols::Node> TPSymbolsNode;
DEF_TO_XXXNODE(Symbols)

}
}

#endif /* laolx_parser_Words_hxx */
