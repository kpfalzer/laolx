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
 * File:   type_name.hxx
 * Author: kwpfalzer
 *
 * Created on Tue Nov 14 13:24:10 2017
 */
#ifndef TYPE_NAME_HXX
#define TYPE_NAME_HXX

#include "ast/common.hxx"

class TypeName;
typedef const TypeName* TPCTypeName;

// TODO: ambiguity on ClassName and TypedefName
class TypeName : public virtual AstNode {
public:
    static TPCTypeName parse(Parser& parser);

    explicit TypeName(TPCAstNode node) : node(node) {
    }

    const TPCAstNode node;

    virtual ~TypeName();
};

#endif /* TYPE_NAME_HXX */
