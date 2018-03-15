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
 * File:   simple_type_specifier.hxx
 * Author: kwpfalzer
 *
 * Created on Mon Oct 23 17:41:53 2017
 */
#ifndef SIMPLE_TYPE_SPECIFIER_HXX
#define SIMPLE_TYPE_SPECIFIER_HXX

#include <array>
#include "ast/common.hxx"
#include "ast/nested_name_specifier.hxx"
#include "ast/name.hxx"
#include "array_specifier.hxx"

class SimpleTypeSpecifier : public virtual AstNode {
public:
    class X;
    typedef const X* TPCX;
    typedef laolx::Array<TPCArraySpecifier> ArraySpecifiers;

    static TPCSimpleTypeSpecifier parse(Parser& parser);

    explicit SimpleTypeSpecifier(const TPCX simpleType, const ArraySpecifiers* arraySpecs);

    const TPCX simpleType;
    const ArraySpecifiers* arraySpecs;

    virtual ~SimpleTypeSpecifier();

    class X {
    public:
        static TPCX parse(Parser& parser);
        explicit X(const TRcToken& token);
        explicit X(TPCNestedNameSpecifier spec, TPCName type);
        const std::array<TPCAstNode, 2> nodes;
        virtual ~X();
    };
};

#endif /* SIMPLE_TYPE_SPECIFIER_HXX */
