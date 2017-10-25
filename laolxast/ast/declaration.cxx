/*
 * The MIT License
 *
 * Copyright 2017 kwpfalzer.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "ast/declaration.hxx"
#include "ast/class_declaration.hxx"
#include "ast/variable_declaration.hxx"
#include "ast/method_declaration.hxx"
#include "ast/typedef_declaration.hxx"
#include "ast/namespace_declaration.hxx"

Declaration::Declaration(const TRcLinkage& linkage, const TRcAstNode& declaration)
: linkage(linkage), declaration(declaration) {

}

TRcDeclaration Declaration::parse(Parser& parser) {
    TRcDeclaration actual(nullptr);
    TRcAstNode decl(nullptr);
    Parser::index_type start = parser.getMark();
    TRcLinkage linkage = Linkage::parse(parser);

#define PARSE_CAST(_class)                                              \
        {                                                               \
            auto xdecl = _class::parse(parser);                         \
            if (xdecl) {                                                \
                decl = std::static_pointer_cast<AstNode>(xdecl);        \
                break;                                                  \
            }                                                           \
        }

    do {
        PARSE_CAST(ClassDeclaration)
        PARSE_CAST(VariableDeclaration)
        PARSE_CAST(MethodDeclaration)
        if (linkage) {
            // no linkage before remaining...
            parser.setMark(start);
            return actual;
        }
        PARSE_CAST(TypedefDeclaration)
        PARSE_CAST(NamespaceDeclaration)
    } while (false); //one pass through
    if (decl) {
        actual = std::make_shared<Declaration>(linkage, decl);
    } else {
        parser.setMark(start);
    }
    return actual;
}

Declaration::~Declaration() {

}

#undef PARSE_CAST


