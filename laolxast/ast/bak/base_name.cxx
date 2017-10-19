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
 * File:   base_name.cxx
 * Author: kwpfalzer
 *
 * Created on Fri Oct  6 19:30:04 2017
 */
#include "ast/base_name.hxx"

// BaseName: IDENT (COLON2 IDENT)* ActualTypeParameters?

TRcBaseName BaseName::parse(Parser& parser) {
    TRcBaseName result(nullptr);
    if (Token::IDENT != parser.peek()->code) {
        return result;
    }
    laolx::Array<TRcToken> names, nextName(2);
    names << parser.accept();
    while (parser.accept(nextName,{Token::S_COLON2, Token::IDENT})) { // (COLON2 IDENT)*
        names << nextName.last();
    }
    auto params = ActualTypeParameters::parse(parser);
    result = std::make_shared<BaseName>(names.compact(), params);
    return result;
}

BaseName::BaseName(const laolx::Array<TRcToken>& names, const TRcActualTypeParameters& params)
: m_names(names), m_params(params) {
}

BaseName::~BaseName() {
}
