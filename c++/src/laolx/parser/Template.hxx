//
//  Template.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_Template_hxx
#define laolx_parser_Template_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class SimpleTemplateId : public _Acceptor {
public:
    explicit SimpleTemplateId()
    {}
    
    virtual ~SimpleTemplateId()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class SimpleTemplateId;

		explicit Node(const TPNode& node);
    };
    
    static const SimpleTemplateId& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<SimpleTemplateId::Node> TPSimpleTemplateIdNode;
DEF_TO_XXXNODE(SimpleTemplateId)

class TemplateSpecifier : public _Acceptor {
public:
    explicit TemplateSpecifier()
    {}
    
    virtual ~TemplateSpecifier()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class TemplateSpecifier;

		explicit Node(const TPNode& node);
    };
    
    static const TemplateSpecifier& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<TemplateSpecifier::Node> TPTemplateSpecifierNode;
DEF_TO_XXXNODE(TemplateSpecifier)

class TemplateId : public _Acceptor {
public:
    explicit TemplateId()
    {}
    
    virtual ~TemplateId()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class TemplateId;

		explicit Node(const TPNode& node);
    };
    
    static const TemplateId& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<TemplateId::Node> TPTemplateIdNode;
DEF_TO_XXXNODE(TemplateId)

class TemplateArgumentList : public _Acceptor {
public:
    explicit TemplateArgumentList()
    {}
    
    virtual ~TemplateArgumentList()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class TemplateArgumentList;

		explicit Node(const TPNode& node);
    };
    
    static const TemplateArgumentList& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<TemplateArgumentList::Node> TPTemplateArgumentListNode;
DEF_TO_XXXNODE(TemplateArgumentList)

class TemplateArgument : public _Acceptor {
public:
    explicit TemplateArgument()
    {}
    
    virtual ~TemplateArgument()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class TemplateArgument;

		explicit Node(const TPNode& node);
    };
    
    static const TemplateArgument& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<TemplateArgument::Node> TPTemplateArgumentNode;
DEF_TO_XXXNODE(TemplateArgument)

}
}

#endif /* laolx_parser_Template_hxx */
