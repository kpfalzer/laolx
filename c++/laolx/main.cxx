//
//  main.cpp
//  laolx
//
//  Created by George P. Burdell on 12/18/19.
//  Copyright © 2019 George P. Burdell. All rights reserved.
//

#include <string>
#include <iostream>
#include "laolx/parser/String.hxx"
#include "laolx/parser/ImportStmt.hxx"
#include "laolx/parser/Bool.hxx"

using std::string;
using std::cout;
using std::endl;
using apfev3::TPNode;
using apfev3::Consumer;
using apfev3::CharBuf;
using apfev3::Repetition;
using laolx::parser::String;
using laolx::parser::TPIdentNode;

#define USING(_x) \
using laolx::parser::to##_x##Node; \
using laolx::parser::TP##_x##Node; \
using laolx::parser::_x
//
USING(ImportSpecifier);
USING(ImportSpecifierList);
USING(ImportStmt);
USING(Bool);
//

int main(int argc, const char** argv) {
    {
        CharBuf INPUT("\"we are here\"");
        Consumer consumer(INPUT);
        TPNode match = String::THE_ONE.accept(consumer);
        cout << "match1=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    {
        CharBuf INPUT("p1.p2.p3");
        Consumer consumer(INPUT);
        TPNode match = ImportSpecifier::THE_ONE.accept(consumer);
        cout << "match2=" << *match << endl;
        INVARIANT(consumer.isEOF());
        {
            const ImportSpecifier::Node& ids = toImportSpecifierNode(match).asT();
            TPIdentNode id = ids[0];
            id = ids[1];
            auto stop = true;
        }
    }
    {
        CharBuf INPUT("p1.p2.p3 , q.r,t.uuuu");
        Consumer consumer(INPUT);
        TPNode match = ImportSpecifierList::THE_ONE.accept(consumer);
        cout << "match3=" << *match << endl;
        INVARIANT(consumer.isEOF());
        {
            const ImportSpecifierList::Node& specs = toImportSpecifierListNode(match).asT();
            for (size_t i = 0; i < specs.size(); ++i) {
                TPImportSpecifierNode sn = specs[i];
                cout << "match3." << i << ": " << *sn << endl;
            }
        }
    }
    {
        CharBuf INPUT("import a,b,c, p1.ALL;");
        Consumer consumer(INPUT);
        TPNode match = ImportStmt::THE_ONE.accept(consumer);
        cout << "match4=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    {
        CharBuf INPUT("from p1.p2 import a,b,c;");
        Consumer consumer(INPUT);
        TPNode match = ImportStmt::THE_ONE.accept(consumer);
        cout << "match5=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    {
        const Repetition GRAM(Bool::THE_ONE, Repetition::eOneOrMore);
        CharBuf INPUT("false true false");
        Consumer consumer(INPUT);
        TPNode match = GRAM.accept(consumer);
        cout << "match6=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    return 0;
}
