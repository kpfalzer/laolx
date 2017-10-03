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
    public:

        virtual bool operator==(const Object& other) const {
            return this == &other;
        }

        virtual bool operator!=(const Object& other) const {
            return !operator==(other);
        }

        virtual bool operator<(const Object& other) const;

        virtual bool operator>(const Object& other) const;

        virtual bool operator<=(const Object& other) const {
            return operator<(other) || operator==(other);
        }

        virtual bool operator>=(const Object& other) const {
            return operator>(other) || operator==(other);
        }

    protected:

        Object() {
        }

        virtual ~Object() = 0;

        template<typename IMPL, typename T>
        static void eachImpl(const IMPL& coll, const std::function<void (const T& ele)>& consume) {
            for (auto e : coll) {
                consume(e);
            }
        }

        template<typename R, typename T, typename COLL = R>
        R selectImpl(const COLL& coll, const std::function<bool (const T& ele)>& predicate) const {
            R selected;
            coll.each([&](auto ele) {
                if (predicate(ele)) {
                    selected << ele;
                }
            });
            return selected;
        }

        template<typename R, typename TO, typename COLL, typename FROM>
        R mapImpl(const COLL& coll, const std::function<TO(const FROM& ele)>& mapper) const {
            R mapped;
            coll.each([&](auto ele) {
                mapped << mapper(ele);
            });
            return mapped;
        }

        template<typename T, typename COLL, typename R=T>
        R reduceImpl(const COLL& coll, const R& init, const std::function<void (R& reduced, const T& ele)>& reducer) const {
            R reduced = init;
            coll.each([&](auto ele) {
                reducer(reduced, ele);
            });
            return reduced;
        }

    };
}

#endif /* LAOLX_OBJECT_HXX */

