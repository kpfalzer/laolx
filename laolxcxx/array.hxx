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
 * File:   array.hxx
 * Author: kwpfalzer
 *
 * Created on September 23, 2017, 4:11 PM
 */

#ifndef LAOLX_ARRAY_HXX
#define LAOLX_ARRAY_HXX

#include <vector>
#include <functional>
#include "laolx/object.hxx"

namespace laolx {

    template<typename T>
    class Array : public virtual Object {
    public:
        typedef std::vector<T> collection_type;
        typedef typename collection_type::size_type size_type;
        typedef typename collection_type::reference reference;
        typedef typename collection_type::const_reference const_reference;
        typedef long int index_type;
        
        Array() {
        }

        Array(size_type n) : m_array(n) {
        }

        Array& operator<<(const T& item) {
            m_array.push_back(item);
            return *this;
        }

        /**
         * Return reference to element at index.
         * @param index if 0 or positive: index from beginning.
         *              if negative: index from end (i.e., -1 is last item).
         * @return reference to element at index.
         */
        reference operator[](index_type index) {
            return m_array.at(actual_index(index));
        }

        const_reference operator[](index_type index) const {
            return m_array.at(actual_index(index));
        }

        reference first() {
            return operator[](0);
        }
        
        const_reference first() const {
            return operator[](0);
        }
        
        reference last() {
            return operator[](-1);
        }
        
        const_reference last() const {
            return operator[](-1);
        }
        
        size_type length() const {
            return m_array.size();
        }

        void each(const std::function<void (const T& ele)>& consume) const {
            eachImpl(m_array, consume);
        }

        Array select(const std::function<bool (const T& ele)>& predicate) const {
            return selectImpl(*this, predicate);
        }

        template<typename T2>
        Array<T2> map(const std::function<const T2& (const T& ele)>& mapper) const {
            Array<T2> mapped(length());
            each([&](auto ele) {
                mapped << mapper(ele);
            });
            return mapped;
        }

        template<typename R>
        R reduce(const R& init, const std::function<const R& (const R& a, const T& b)>& binop) const {
            R reduced = init;
            each([&](auto ele) {
                reduced = binop(reduced, ele);
            });
            return reduced;
        }
        
        virtual ~Array() {
        }

    private:
        size_type actual_index(index_type ix) {
            return (0 <= ix) ? ix : (length() + ix);
        }
        
        collection_type m_array;
    };
}


#endif /* LAOLX_ARRAY_HXX */

