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

class DotOp : public _Acceptor {
public:
    explicit DotOp()
    {}
    
    virtual ~DotOp()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class DotOp;

		explicit Node(const TPNode& node);
        
    };
    
    static const DotOp& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<DotOp::Node> TPDotOpNode;
DEF_TO_XXXNODE(DotOp)

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
        
		NODE_TYPE_DECLARE;

    private:
        friend class NestedNameSpecifier;

		explicit Node(const TPNode& node);
        
    };
    
    static const NestedNameSpecifier& THE_ONE;
    
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
	        
			NODE_TYPE_DECLARE;
	
	    private:
	        friend class X;
	
			explicit Node(const TPNode& node);
	    };
	    
	    static const X& THE_ONE;
	    
	protected:
	    TPNode _accept(Consumer& consumer) const;
	};

	class Y : public _Acceptor {
	public:
	    explicit Y()
	    {}
	    
	    virtual ~Y()
	    {}
	    
	    class Node : public NodeVector {
	    public:
	        virtual ~Node()
	        {}
	        
	        virtual ostream& operator<<(ostream& os) const;
	        
			NODE_TYPE_DECLARE;
	
	    private:
	        friend class Y;
	
			explicit Node(const TPNode& node);
	    };
	    
	    static const Y& THE_ONE;
	    
	protected:
	    TPNode _accept(Consumer& consumer) const;
	};

protected:
    TPNode _accept(Consumer& consumer) const;
    
private:
    LEFT_RECURSION_DECLARE;
};

typedef PTRcObjPtr<NestedNameSpecifier::Node> TPNestedNameSpecifierNode;
DEF_TO_XXXNODE(NestedNameSpecifier)

}
}

#endif /* laolx_parser_NestedNameSpecifier_hxx */
