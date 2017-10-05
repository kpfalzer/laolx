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

#include "ast/linkage.hxx"
#include "string.hxx"

Linkage::Linkage(const TRcString& linkage) : m_linkage(linkage) {

}

TRcLinkage Linkage::parse(Parser& parser) {
    TRcLinkage linkage(nullptr);
    if (parser.peek()->code != Token::K_EXTERN) {
        return linkage;
    }
    Parser::index_type start = parser.getMark();
    parser.accept();
    TRcString str = String::parse(parser);
    if (str) {
        linkage = std::make_shared<Linkage>(str);
    } else {
        parser.setMark(start);
    }
    return linkage;
}

Linkage::~Linkage() {

}


