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
 * File:   qualified_id.hxx
 * Author: kwpfalzer
 *
 * Created on Tue Nov 14 13:31:23 2017
 */
#ifndef QUALIFIED_ID_HXX
#define QUALIFIED_ID_HXX

#include "ast/common.hxx"
#include "ast/nested_name_specifier.hxx"
#include "ast/unqualified_id.hxx"


class QualifiedId : public virtual AstNode {
public:
    static TPCQualifiedId parse(Parser& parser);

    explicit QualifiedId(TPCNestedNameSpecifier nested, TPCUnqualifiedId unqual);

    const TPCNestedNameSpecifier nestedName;
    const TPCUnqualifiedId unqualId;
    
    virtual ~QualifiedId();
};

#endif /* QUALIFIED_ID_HXX */
