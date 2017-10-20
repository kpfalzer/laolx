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
 * File:   import_specifier.cxx
 * Author: kpfalzer
 *
 * Created on Fri Oct 20 10:21:57 2017
 */
#include "ast/import_specifier.hxx"

TPCImportSpecifier ImportSpecifier::parse(Parser& parser) {
    auto names = new laolx::Array<TRcToken>();
    auto start = parser.getMark();
    while (parser.hasMore()) {
        if (parser.peek()->code != Token::IDENT) {
            break;
        }
        *names << parser.accept();
        start = parser.getMark();
        if (parser.accept()->code != Token::S_DOT) {
            break;
        }
    }
    parser.setMark(start);
    if (names->isEmpty()) {
        return nullptr;
    }
    TRcToken asIdent(nullptr);
    if (!names->isEmpty()) {
        laolx::Array<TRcToken> toks(2);
        if (parser.accept(toks, {Token::K_AS, Token::IDENT})) {
            asIdent = toks.last();
        }
    }
    return new ImportSpecifier(names, asIdent);
}

ImportSpecifier::ImportSpecifier(TPCNames names, const TRcToken& asIdent)
: names(names), asIdent(asIdent) {
}

ImportSpecifier::~ImportSpecifier() {
    delete names;
}
