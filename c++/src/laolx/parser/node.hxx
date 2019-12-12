//
//  node.hxx
//  
//
//  Created by Karl W Pfalzer on 12/11/19.
//

#ifndef laolx_node_parsable_hxx
#define laolx_node_parsable_hxx

#include "xyzzy/refcnt.hxx"
#include "laolx/parser/common.hxx"

namespace laolx {
namespace parser {

class _Node : public virtual TRcObj {
public:
    
protected:
    virtual ~_Node() = 0;
    
};

typedef PTRcObjPtr<_Node>   TPNode;

class _NodeCollector : public virtual TRcObj {
public:
    
protected:
    virtual ~_NodeCollector() = 0;
    
};

typedef PTRcObjPtr<_NodeCollector> TPNodeCollector;

}
}

#endif /* laolx_node_parsable_hxx */
