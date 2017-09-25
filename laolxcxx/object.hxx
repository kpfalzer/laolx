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
 * File:   laolobj.hxx
 * Author: kwpfalzer
 *
 * Created on September 23, 2017, 9:24 AM
 */

#ifndef LAOLX_OBJECT_HXX
#define LAOLX_OBJECT_HXX

#include <functional>

namespace laolx {

    class Object {
    protected:

        Object() {
        }

        virtual ~Object() = 0;

        template<typename T, typename COLL>
        static void eachImpl(const COLL& coll, const std::function<void (const T& ele)>& consume) {
            for (const auto e : coll) {
                consume(e);
            }
        }
        
        template<class C, typename T>
        C selectImpl(const C& coll, const std::function<bool (const T& ele)>& predicate) const {
            C selected;
            coll.each([&](auto ele) {
                if (predicate(ele)) {
                    selected << ele;
                }
            });
            return selected;
        }

    };
}

#endif /* LAOLX_OBJECT_HXX */

