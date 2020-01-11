//
//  SimpleTypeSpecifier.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_SimpleTypeSpecifier_hxx
#define laolx_parser_SimpleTypeSpecifier_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class ArraySpecifier : public _Acceptor {
public:
    explicit ArraySpecifier()
    {}
    
    virtual ~ArraySpecifier()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class ArraySpecifier;

		explicit Node(const TPNode& node);
    };
    
    static const ArraySpecifier& THE_ONE;

	class X : public _Acceptor {
	public:
	    explicit X()
	    {}
	    
	    virtual ~X()
	    {}
	    
	    class Node : public NodeVector {
	    public:
	        virtual ~Node()
	        {}
	        
	        virtual ostream& operator<<(ostream& os) const;
	        
	    private:
	        friend class X;
	
			explicit Node(const TPNode& node);
	    };
	    
	    static const X& THE_ONE;
	    
	protected:
	    TPNode _accept(Consumer& consumer) const;
	};
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<ArraySpecifier::Node> TPArraySpecifierNode;
DEF_TO_XXXNODE(ArraySpecifier)

class SimpleTypeSpecifier : public _Acceptor {
public:
    explicit SimpleTypeSpecifier()
    {}
    
    virtual ~SimpleTypeSpecifier()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class SimpleTypeSpecifier;

		explicit Node(const TPNode& node);
    };
    
    static const SimpleTypeSpecifier& THE_ONE;

	class X : public _Acceptor {
	public:
	    explicit X()
	    {}
	    
	    virtual ~X()
	    {}
	    
	    class Node : public NodeVector {
	    public:
	        virtual ~Node()
	        {}
	        
	        virtual ostream& operator<<(ostream& os) const;
	        
	    private:
	        friend class X;
	
			explicit Node(const TPNode& node);
	    };
	    
	    static const X& THE_ONE;
	    
	protected:
	    TPNode _accept(Consumer& consumer) const;
	};
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<SimpleTypeSpecifier::Node> TPSimpleTypeSpecifierNode;
DEF_TO_XXXNODE(SimpleTypeSpecifier)

}
}

#endif /* laolx_parser_SimpleTypeSpecifier_hxx */
