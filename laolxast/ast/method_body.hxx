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
 * File:   method_body.hxx
 * Author: kwpfalzer
 *
 * Created on Mon Oct 23 17:55:39 2017
 */
#ifndef METHOD_BODY_HXX
#define METHOD_BODY_HXX

#include "ast/common.hxx"
#include "ast/method_body_item.hxx"

class MethodBody;
typedef const MethodBody* TPCMethodBody;

class MethodBody : public virtual AstNode {
public:
    typedef laolx::Array<TPCMethodBodyItem> TItems;
    
    static TPCMethodBody parse(Parser& parser);

    explicit MethodBody(const TItems& items);

    const TItems items;
    
    virtual ~MethodBody();
};

#endif /* METHOD_BODY_HXX */
