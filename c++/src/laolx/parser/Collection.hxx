//
//  Collection.hxx
//  
//
//  Created by Karl W Pfalzer.
//

#ifndef laolx_parser_Collection_hxx
#define laolx_parser_Collection_hxx

#include "laolx/parser/laolx.hxx"

namespace laolx {
namespace parser {

class Array : public _Acceptor {
public:
    explicit Array()
    {}
    
    virtual ~Array()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class Array;

		explicit Node(const TPNode& node);
    };
    
    static const Array& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Array::Node> TPArrayNode;
DEF_TO_XXXNODE(Array)

class Vector : public _Acceptor {
public:
    explicit Vector()
    {}
    
    virtual ~Vector()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class Vector;

		explicit Node(const TPNode& node);
    };
    
    static const Vector& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Vector::Node> TPVectorNode;
DEF_TO_XXXNODE(Vector)

class MapEntry : public _Acceptor {
public:
    explicit MapEntry()
    {}
    
    virtual ~MapEntry()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class MapEntry;

		explicit Node(const TPNode& node);
    };
    
    static const MapEntry& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<MapEntry::Node> TPMapEntryNode;
DEF_TO_XXXNODE(MapEntry)

class MapEntryList : public _Acceptor {
public:
    explicit MapEntryList()
    {}
    
    virtual ~MapEntryList()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class MapEntryList;

		explicit Node(const TPNode& node);
    };
    
    static const MapEntryList& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<MapEntryList::Node> TPMapEntryListNode;
DEF_TO_XXXNODE(MapEntryList)

class Map : public _Acceptor {
public:
    explicit Map()
    {}
    
    virtual ~Map()
    {}
    
    class Node : public NodeVector {
    public:
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
		NODE_TYPE_DECLARE;

    private:
        friend class Map;

		explicit Node(const TPNode& node);
    };
    
    static const Map& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<Map::Node> TPMapNode;
DEF_TO_XXXNODE(Map)

}
}

#endif /* laolx_parser_Collection_stmt_hxx */
