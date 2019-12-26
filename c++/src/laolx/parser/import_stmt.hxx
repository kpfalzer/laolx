//
//  import_stmt.hxx
//  
//
//  Created by Karl W Pfalzer on 12/11/19.
//

#ifndef laolx_parser_import_stmt_hxx
#define laolx_parser_import_stmt_hxx

#include <vector>
#include "laolx/parser/laolx.hxx"
#include "laolx/parser/token.hxx"

namespace laolx {
namespace parser {

/**
 ImportSpecifier: IDENT (S_DOT IDENT)*
 */
class ImportSpecifier : public _Acceptor {
public:
    explicit ImportSpecifier()
    {}
    
    virtual ~ImportSpecifier()
    {}
    
    class Node : public NodeVector {
    public:
        const TPIdentNode nodeAt(size_t pos) const {
            return toIdentNode(at(pos));
        }
        
        const TPIdentNode operator[](size_t pos) const {
            return nodeAt(pos);
        }
        
        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;

    private:
        friend class ImportSpecifier;
        
        explicit Node(const TPNode& node);
    };
    
    static const ImportSpecifier& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<ImportSpecifier::Node>       TPImportSpecifierNode;
DEF_TO_XXXNODE(ImportSpecifier)

/**
 ImportSpecifierList: ImportSpecifier (COMMA ImportSpecifier)*
 */
class ImportSpecifierList : public _Acceptor {
public:
    explicit ImportSpecifierList()
    {}
    
    virtual ~ImportSpecifierList()
    {}
    
    class Node : public NodeVector {
    public:
        const TPImportSpecifierNode nodeAt(size_t pos) const {
            return toImportSpecifierNode(at(pos));
        }
        
        //overload [] to access
        const TPImportSpecifierNode operator[](size_t pos) const {
            return nodeAt(pos);
        }
        
        virtual ~Node()
        {}

        virtual ostream& operator<<(ostream& os) const;

    private:
        friend class ImportSpecifierList;
        
        explicit Node(const TPNode& node);
    };
    
    static const ImportSpecifierList& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<ImportSpecifierList::Node>   TPImportSpecifierListNode;
DEF_TO_XXXNODE(ImportSpecifierList)

/**
 ImportStatement:
    K_IMPORT ImportSpecifierList S_SEMICOLON
 |      K_FROM ImportSpecifier IMPORT ImportSpecifierList S_SEMICOLON
 */
class ImportStmt : public _Acceptor {
public:
    explicit ImportStmt()
    {}
    
    virtual ~ImportStmt()
    {}
    
    class Node : public NodeVector {
    public:
        bool isFrom() const {
            return __from.isValid();
        }

        virtual ~Node()
        {}
        
        virtual ostream& operator<<(ostream& os) const;
        
        const TPImportSpecifierNode       __from;
        const TPImportSpecifierListNode   __imports;
        
    private:
        friend class ImportStmt;
        
        explicit Node(const TPNode& all, const TPNode& from, const TPNode& imports);
        explicit Node(const TPNode& all, const TPNode& imports);
    };
    
    static const ImportStmt& THE_ONE;
    
protected:
    TPNode _accept(Consumer& consumer) const;
};

typedef PTRcObjPtr<ImportStmt::Node>            TPImportStmtNode;
DEF_TO_XXXNODE(ImportStmt)

}
}

#endif /* laolx_parser_import_stmt_hxx */
