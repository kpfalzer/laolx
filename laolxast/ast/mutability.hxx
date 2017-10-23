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
 * File:   mutability.hxx
 * Author: kwpfalzer
 *
 * Created on Thu Oct 19 19:53:52 2017
 */
#ifndef MUTABILITY_HXX
#define MUTABILITY_HXX

#include "ast/common.hxx"

class Mutability;
typedef const Mutability* TPCMutability;

class Mutability : public virtual AstNode {
public:
    static TPCMutability parse(Parser& parser);

    explicit Mutability(const TRcToken& keyword)
    : mutability(keyword) {
    }

    /**
     * Return true if (explicitly declared) var/mutable.
     * @return true if var/mutable.
     */
    bool isVar() const;
    
    /**
     * Return true if const/immutable.
     * By default, all state is const/immutable.
     * @return true if const/immutable.
     */
    bool isConst() const;
    
    const TRcToken mutability;

    virtual ~Mutability();
};

#endif /* MUTABILITY_HXX */
