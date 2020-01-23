//
//  IdExpression.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_IdExpression_hxx
#define laolx_parser_IdExpression_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class UnqualifiedId : public _Acceptor {
public:
    explicit UnqualifiedId()
    {}
    
    virtual ~UnqualifiedId()
    {}
    
    class Node : public AlternativeNode {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class UnqualifiedId;

		explicit Node(const TPNode& node);
    };
    
    static const UnqualifiedId& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<UnqualifiedId::Node> TPUnqualifiedIdNode;
DEF_TO_XXXNODE(UnqualifiedId)

class QualifiedId : public _Acceptor {
public:
    explicit QualifiedId()
    {}
    
    virtual ~QualifiedId()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class QualifiedId;

		explicit Node(const TPNode& node);
    };
    
    static const QualifiedId& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<QualifiedId::Node> TPQualifiedIdNode;
DEF_TO_XXXNODE(QualifiedId)

class IdExpression : public _Acceptor {
public:
    explicit IdExpression()
    {}
    
    virtual ~IdExpression()
    {}
    
    class Node : public AlternativeNode {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class IdExpression;

		explicit Node(const TPNode& node);
    };
    
    static const IdExpression& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<IdExpression::Node> TPIdExpressionNode;
DEF_TO_XXXNODE(IdExpression)

}
}

#endif /* laolx_parser_IdExpression_hxx */
