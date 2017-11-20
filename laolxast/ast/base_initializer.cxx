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
 * File:   base_initializer.cxx
 * Author: kpfalzer
 *
 * Created on Fri Nov 17 12:52:23 2017
 */
#include "ast/base_initializer.hxx"

TPCBaseInitializer BaseInitializer::parse(Parser& parser) {
    auto start = parser.getMark();
    TRcToken ident;
    {
        laolx::Array<TRcToken> toks;
        if (parser.accept(toks,{Token::IDENT, Token::S_COLON})) {
            ident = toks[0];
        }
    }
    auto inits = InitializerClause::parse(parser);
    if (inits) {
        return (ident) 
                ? new BaseInitializer(ident, inits)
                : new BaseInitializer(inits);
    }
    parser.setMark(start);
    return nullptr;
}

BaseInitializer::BaseInitializer(const TRcToken& ident, TPCInitializerClause init)
: ident(ident), init(init) {

}

BaseInitializer::BaseInitializer(TPCInitializerClause init)
: init(init) {

}

BaseInitializer::~BaseInitializer() {
    delete init;
}
