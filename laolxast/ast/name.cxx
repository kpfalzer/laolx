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
 * File:   name.cxx
 * Author: kpfalzer
 *
 * Created on Wed Nov 22 14:19:15 2017
 */
#include "ast/name.hxx"
#include "ast/simple_template_id.hxx"

TPCName Name::parse(Parser& parser) {
    //Name: IDENT | SimpleTemplateId
    auto stid = SimpleTemplateId::parse(parser);
    if (stid) {
        return new Name(stid);
    } else {
        if (Token::IDENT == parser.peek()->code) {
            return new Name(parser.accept());
        }
        return nullptr;
    }
}

Name::Name(const TRcToken id)
: ident(id), simplTemplId(nullptr) {

}

Name::Name(const TPCSimpleTemplateId simplTemplId)
: simplTemplId(simplTemplId) {

}

Name::~Name() {
    delete simplTemplId;
}
