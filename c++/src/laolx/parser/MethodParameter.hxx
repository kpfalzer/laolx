//
//  MethodParameter.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_MethodParameter_hxx
#define laolx_parser_MethodParameter_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class MethodParameter : public _Acceptor {
public:
    explicit MethodParameter()
    {}
    
    virtual ~MethodParameter()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
    private:
        friend class MethodParameter;

		explicit Node(const TPNode& node);
    };
    
    static const MethodParameter& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<MethodParameter::Node> TPMethodParameterNode;
DEF_TO_XXXNODE(MethodParameter)

class MethodParameterList : public _Acceptor {
public:
    explicit MethodParameterList()
    {}
    
    virtual ~MethodParameterList()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
    private:
        friend class MethodParameterList;

		explicit Node(const TPNode& node);
    };
    
    static const MethodParameterList& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<MethodParameterList::Node> TPMethodParameterListNode;
DEF_TO_XXXNODE(MethodParameterList)

class MethodParametersDeclaration : public _Acceptor {
public:
    explicit MethodParametersDeclaration()
    {}
    
    virtual ~MethodParametersDeclaration()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
    private:
        friend class MethodParametersDeclaration;

		explicit Node(const TPNode& node);
    };
    
    static const MethodParametersDeclaration& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<MethodParametersDeclaration::Node> TPMethodParametersDeclarationNode;
DEF_TO_XXXNODE(MethodParametersDeclaration)

}
}

#endif /* laolx_parser_MethodParameterList_hxx */
