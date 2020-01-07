//
//  PostfixExpression.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_PostfixExpression_hxx
#define laolx_parser_PostfixExpression_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class PostfixExpression : public _Acceptor {
public:
    explicit PostfixExpression()
    {}
    
    virtual ~PostfixExpression()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class PostfixExpression;

		explicit Node(const TPNode& node);
    };
    
    static const PostfixExpression& THE_ONE;
    
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
};

typedef PTRcObjPtr<PostfixExpression::Node> TPPostfixExpressionNode;
DEF_TO_XXXNODE(PostfixExpression)
typedef PTRcObjPtr<PostfixExpression::X::Node> TPPostfixExpressionXNode;
DEF_TO_XXXICNODE(PostfixExpression::X, PostfixExpressionX)
typedef PTRcObjPtr<PostfixExpression::Y::Node> TPPostfixExpressionYNode;
DEF_TO_XXXICNODE(PostfixExpression::Y, PostfixExpressionY)

}
}

#endif /* laolx_parser_PostfixExpression_hxx */
