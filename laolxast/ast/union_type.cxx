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
 * File:   union_type.cxx
 * Author: kwpfalzer
 *
 * Created on Fri Oct  6 19:30:04 2017
 */
#include "ast/union_type.hxx"

TRcUnionType UnionType::parse(Parser& parser) {
    TRcUnionType result(nullptr);
    Parser::index_type start = parser.getMark();
    if (Token::S_LPAREN != parser.peek()->code) {
        return result;
    }
    TTypes types;
    while (parser.hasMore()) {
        TRcType type = Type::parse(parser);
        if (!type) {
            break;
        }
        types << type;
        if (Token::S_OR != parser.accept()->code) {
            break;
        }
    }
    if (Token::S_RPAREN == parser.accept()->code) {
        result = std::make_shared<UnionType>(types);
    } else {
        parser.setMark(start);
    }
    return result;
}

UnionType::UnionType(const TTypes& types)
: m_types(types) {

}

UnionType::~UnionType() {
}
