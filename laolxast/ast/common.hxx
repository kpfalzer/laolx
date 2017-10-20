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
 * File:   common.hxx
 * Author: kwpfalzer
 *
 * Created on October 4, 2017, 5:55 PM
 */

#ifndef COMMON_HXX
#define COMMON_HXX

#include <memory>
#include "parser/astnode.hxx"
#include "parser/token.hxx"
#include "parser/parser.hxx"

/**
 * Parse sequence of C separated by delimiter: C,C,...
 * @param parser the parser.
 * @param start update mark as match done.
 * @param delimiter sequence delimiter.
 * @return compacted array of C.
 */
template<class C>
std::shared_ptr<laolx::Array<std::shared_ptr<C>>>
sequenceOf(Parser& parser, Parser::index_type& start, const Token::Code delimiter) {
    auto items = std::make_shared<laolx::Array<std::shared_ptr<C>>>();
    while (parser.hasMore()) {
        auto item = C::parse(parser);
        if (!item) {
            break;
        }
        *items << item;
        start = parser.getMark();
        if (parser.accept()->code != delimiter) {
            break;
        }
    }
    items->compact();
    return items;
}

#endif /* COMMON_HXX */

