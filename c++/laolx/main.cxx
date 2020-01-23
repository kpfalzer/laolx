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
#include "laolx/parser/Literal.hxx"
#include "laolx/parser/Number.hxx"
#include "laolx/parser/UnaryExpression.hxx"
#include "laolx/parser/Expression.hxx"

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
USING(Regexp);
USING(Symbol);
USING(Sized);
USING(Int);
USING(Float);
USING(Literal);
USING(Number);
USING(UnaryExpression);
USING(Expression);
//

int main(int argc, const char** argv) {
    {
        CharBuf INPUT("\"we are here\"");
        Consumer consumer(INPUT);
        TPNode match = String::THE_ONE.accept(consumer);
        cout << "String=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    {
        CharBuf INPUT("p1.p2.p3");
        Consumer consumer(INPUT);
        TPNode match = ImportSpecifier::THE_ONE.accept(consumer);
        cout << "ImportSpecified=" << *match << endl;
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
        cout << "ImportSpecifierList=" << *match << endl;
        INVARIANT(consumer.isEOF());
        {
            const ImportSpecifierList::Node& specs = toImportSpecifierListNode(match).asT();
            for (size_t i = 0; i < specs.size(); ++i) {
                TPImportSpecifierNode sn = specs[i];
                cout << "ImportSpecifierList." << i << ": " << *sn << endl;
            }
        }
    }
    {
        CharBuf INPUT("import a,b,c, p1.ALL;");
        Consumer consumer(INPUT);
        TPNode match = ImportStmt::THE_ONE.accept(consumer);
        cout << "ImportStmt=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    {
        CharBuf INPUT("from p1.p2 import a,b,c;");
        Consumer consumer(INPUT);
        TPNode match = ImportStmt::THE_ONE.accept(consumer);
        cout << "ImportStmt.2=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    {
        const Repetition GRAM(Bool::THE_ONE, Repetition::eOneOrMore);
        CharBuf INPUT("false true false");
        Consumer consumer(INPUT);
        TPNode match = GRAM.accept(consumer);
        cout << "Bool=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    {
        const Repetition GRAM(Regexp::THE_ONE, Repetition::eOneOrMore);
        CharBuf INPUT("/foobar.*$/ %r{and\\s+this\\}or}");
        Consumer consumer(INPUT);
        TPNode match = GRAM.accept(consumer);
        cout << "Regexp=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    {
        const Repetition GRAM(Symbol::THE_ONE, Repetition::eOneOrMore);
        CharBuf INPUT(":sym1 :_symb1234");
        Consumer consumer(INPUT);
        TPNode match = GRAM.accept(consumer);
        cout << "Symbol=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    {
        const Repetition GRAM(Sized::THE_ONE, Repetition::eOneOrMore);
        CharBuf INPUT("1'd0 16'b001_110 32'hDEAD_beef    32'd12_34");
        Consumer consumer(INPUT);
        TPNode match = GRAM.accept(consumer);
        cout << "Sized=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    {
        const Repetition GRAM(Int::THE_ONE, Repetition::eOneOrMore);
        CharBuf INPUT("123_456 4 000 98888_0");
        Consumer consumer(INPUT);
        TPNode match = GRAM.accept(consumer);
        cout << "Int=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    {
        const Repetition GRAM(Float::THE_ONE, Repetition::eOneOrMore);
        CharBuf INPUT("123.4 56e09 78.0e+1");
        Consumer consumer(INPUT);
        TPNode match = GRAM.accept(consumer);
        cout << "Float=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    {
        const Repetition GRAM(Literal::THE_ONE, Repetition::eOneOrMore);
        CharBuf INPUT("123.4 12'b000111 'string' :sym1  %w{word1 word} 1234 %s{sym1 _s1}");
        Consumer consumer(INPUT);
        TPNode match = GRAM.accept(consumer);
        cout << "Literal=" << *match << endl;
        INVARIANT(consumer.isEOF());
        {
            const TPLiteralNode litNode = toLiteralNode(toNodeVector(match)->at(0));
            INVARIANT(litNode->typeCode() == Literal::Node::TYPE_CODE);
            const TPNumberNode numNode = toNumberNode(litNode->actual());
            INVARIANT(toNodeVector(numNode->actual())->at(1)->typeCode() == Float::Node::TYPE_CODE);
        }
    }
    {
        const Repetition GRAM(UnaryExpression::THE_ONE, Repetition::eOneOrMore);
        CharBuf INPUT("123 456 -a");
        Consumer consumer(INPUT);
        TPNode match = GRAM.accept(consumer);
        cout << "UnaryExpression=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    {
        const Expression& GRAM = Expression::THE_ONE;
        CharBuf INPUT("a+b-c[3]");
        Consumer consumer(INPUT);
        TPNode match = GRAM.accept(consumer);
        cout << "Expression=" << *match << endl;
        INVARIANT(consumer.isEOF());
    }
    return 0;
}
