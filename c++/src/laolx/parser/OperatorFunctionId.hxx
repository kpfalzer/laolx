//
//  OperatorFunctionId.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_OperatorFunctionId_hxx
#define laolx_parser_OperatorFunctionId_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class OverloadableOperator : public _Acceptor {
public:
    explicit OverloadableOperator()
    {}
    
    virtual ~OverloadableOperator()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class OverloadableOperator;

		explicit Node(const TPNode& node);
    };
    
    static const OverloadableOperator& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<OverloadableOperator::Node> TPOverloadableOperatorNode;
DEF_TO_XXXNODE(OverloadableOperator)

class OperatorFunctionId : public _Acceptor {
public:
    explicit OperatorFunctionId()
    {}
    
    virtual ~OperatorFunctionId()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class OperatorFunctionId;

		explicit Node(const TPNode& node);
    };
    
    static const OperatorFunctionId& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<OperatorFunctionId::Node> TPOperatorFunctionIdNode;
DEF_TO_XXXNODE(OperatorFunctionId)

}
}

#endif /* laolx_parser_OperatorFunctionId_stmt_hxx */
