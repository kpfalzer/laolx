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
 * File:   source_file.cxx
 * Author: kwpfalzer
 *
 * Created on Thu Oct  5 19:05:57 2017
 */
#include "source_file.hxx"

TRcSourceFile SourceFile::parse(Parser& parser) {
    static const TRcSourceFile stNull(nullptr);
    auto result = std::make_shared<SourceFile>();
    bool includeOK = true;
    while (!parser.isEOF() && !parser.hasError()) {
        if (includeOK) {
            auto include = IncludeStatement::parse(parser);
            includeOK = (bool)include;
            if (includeOK) {
                *result << include;
            }
        } else {
            const auto startSize = result->items().size();
            auto declaration = Declaration::parse(parser);
            if (declaration) {
                *result << declaration;
            }
            auto statement = Statement::parse(parser);
            if (statement) {
                *result << statement;
            }
            if (startSize == result->items().size()) {
                parser.error("unexpected '%s'", parser.peek());
            }
        }
    }
    if (parser.hasError()) {
        return stNull;
    }
    auto token = parser.accept();
    assert(token->isEOF());
    return result;
}

SourceFile& SourceFile::operator<<(const TRcStatement& statement) {
    m_items << std::static_pointer_cast<AstNode>(statement);
    return *this;
}

SourceFile& SourceFile::operator<<(const TRcDeclaration& declaration) {
    m_items << std::static_pointer_cast<AstNode>(declaration);
    return *this;
}

SourceFile& SourceFile::operator<<(const TRcIncludeStatement& include) {
    m_includeStatements << include;
    return *this;
}

SourceFile::SourceFile() {
}

SourceFile::~SourceFile() {
}
