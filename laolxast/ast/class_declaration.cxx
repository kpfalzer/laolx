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

#include "class_declaration.hxx"

TRcClassDeclaration ClassDeclaration::parse(Parser& parser) {
    static const std::initializer_list<Token::Code> stFirst({Token::K_CLASS, Token::IDENT});
    TRcClassDeclaration classDecl(nullptr);
    Parser::index_type start = parser.getMark();
    laolx::Array<TRcToken> first(2);
    if (!parser.accept(first, stFirst)) {
        return classDecl;
    }
    const auto className = first[1];
    const auto typeParameters = TypeParameters::parse(parser);
    const auto parameterDeclationList = ParameterDeclarationList::parse(parser);
    const auto extendsDeclaration = ExtendsDeclaration::parse(parser);
    const auto implementsDeclaration = ImplementsDeclaration::parse(parser);
    TRcClassBody classBody;
    bool ok = (Token::S_LCURLY == parser.accept()->code);
    if (ok) {
        classBody = ClassBody::parse(parser);
        ok &= (Token::S_RCURLY == parser.accept()->code);
    }
    if (ok) {
        classDecl = std::make_shared<ClassDeclaration>(
                className,
                typeParameters,
                parameterDeclationList,
                extendsDeclaration,
                implementsDeclaration,
                classBody
                );
    } else {
        parser.setMark(start);
    }
    return classDecl;
}

ClassDeclaration::ClassDeclaration(
        const TRcToken& className,
        const TRcTypeParameters& typeParameters,
        const TRcParameterDeclarationList& parameterDeclarationList,
        const TRcExtendsDeclaration& extendsDeclaration,
        const TRcImplementsDeclaration& implementsDeclaration,
        const TRcClassBody& classBody)
: m_className(className),
m_typeParameters(typeParameters),
m_parameterDeclarationList(parameterDeclarationList),
m_extendsDeclaration(extendsDeclaration),
m_implementsDeclaration(implementsDeclaration) {

}

ClassDeclaration::~ClassDeclaration() {

}

