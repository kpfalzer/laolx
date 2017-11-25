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

#include "ast/class_declaration.hxx"

TPCClassDeclaration ClassDeclaration::parse(Parser& parser) {
    static const std::initializer_list<Token::Code> stFirst({Token::K_CLASS, Token::IDENT});
    auto start = parser.getMark();
    laolx::Array<TRcToken> first(2);
    if (!parser.accept(first, stFirst)) {
        return nullptr;
    }
    const auto className = first[1];
    const auto templParams = TemplateParameterList::parse(parser);
    const auto methodParams = MethodParametersDeclaration::parse(parser);
    const auto baseClause = BaseClause::parse(parser);
    bool ok = (Token::S_LCURLY == parser.accept()->code);
    if (ok) {
        auto classBody = ClassBody::parse(parser);
        ok &= (Token::S_RCURLY == parser.accept()->code);
        if (ok) {
            return new ClassDeclaration(
                    className,
                    templParams,
                    methodParams,
                    baseClause,
                    classBody
                    );
        }
    }
    parser.setMark(start);
    return nullptr;
}

ClassDeclaration::ClassDeclaration(
        const TRcToken name,
        TPCTemplateParameterList templParams,
        TPCMethodParametersDeclaration methodParams,
        TPCBaseClause baseClause,
        TPCClassBody body)
: name(name),
templParams(templParams),
methodParams(methodParams),
baseClause(baseClause),
body(body) {
}

ClassDeclaration::~ClassDeclaration() {
    delete templParams;
    delete methodParams;
    delete baseClause;
    delete body;
}

