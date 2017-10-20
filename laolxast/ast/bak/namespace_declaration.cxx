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
/* 
 * File:   namespace_declaration.cxx
 * Author: kpfalzer
 *
 * Created on Mon Oct  9 14:17:22 2017
 */
#include "ast/namespace_declaration.hxx"

TRcNamespaceDeclaration NamespaceDeclaration::parse(Parser& parser) {
    TRcNamespaceDeclaration result(nullptr);
    if (parser.peek()->code != Token::K_NAMESPACE) {
        return result;
    }
    Parser::index_type start = parser.getMark();
    auto name = NamespaceDeclarationName::parse(parser.advance());
    if (name) {
        if (parser.accept()->code == Token::S_LCURLY) {
            TRcDeclarations decls;
            while (parser.hasMore()) {
                auto decl = Declaration::parse(parser);
                if (decl) {
                    *decls << decl;
                } else {
                    break;
                }
            }
            if (parser.accept()->code == Token::S_RCURLY) {
                decls->compact();
                return std::make_shared<NamespaceDeclaration>(name, decls);
            }
        }
    }
    parser.setMark(start);
    return result;
}

NamespaceDeclaration::NamespaceDeclaration(
        const TRcNamespaceDeclarationName& name,
        const TRcDeclarations& declarations)
: name(name), declarations(declarations) {
}

NamespaceDeclaration::~NamespaceDeclaration() {
}
