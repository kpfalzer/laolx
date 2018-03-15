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
#include <cassert>
#include "laolx/object.hxx"

namespace laolx {

    template<typename T>
    class Array : public virtual Object {
    public:
        typedef std::vector<T> collection_type;
        typedef typename collection_type::size_type size_type;
        typedef typename collection_type::reference reference;
        typedef typename collection_type::const_reference const_reference;
        typedef typename collection_type::const_iterator const_iterator;
        typedef long int index_type;

        explicit Array() {
        }

        explicit Array(size_type n) : m_array(n) {
        }

        explicit Array(std::initializer_list<T> init) : m_array(init) {
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

        bool is_valid_index(index_type index) const {
            return actual_index(index) < length();
        }
        
        reference first() {
            return operator[](0);
        }

        const_reference first() const {
            return this->operator[](0);
        }

        reference last() {
            return this->operator[](-1);
        }

        const_reference last() const {
            return this->operator[](-1);
        }

        bool isEmpty() const {
            return m_array.empty();
        }
        
        size_type length() const {
            return m_array.size();
        }

        size_type size() const {
            return length();
        }
        
        const Array& each(const std::function<void (const T& ele)>& consume) const {
            eachImpl(m_array, consume);
            return *this;
        }

        Array select(const std::function<bool (const T& ele)>& predicate) const {
            return selectImpl<Array>(*this, predicate);
        }

        template<typename T2, typename R=Array<T2> >
        R map(const std::function<T2 (const T& ele)>& mapper) const {
            return mapImpl<R>(*this, mapper);
        }

        template<typename R>
        R reduce(const R& init, const std::function<void (R& reduced, const T& ele)>& reducer) const {
            return reduceImpl<R>(*this, init, reducer);
        }

        /**
         * Sort in ascending order.
         * @param aLessThanB compare function: returns true if a < b;
         * i.e., a before b in sorted/ascending order.
         */
        Array& sort(const std::function<bool (const T& a, const T& b)>& aLessThanB) {
            std::sort(m_array.begin(), m_array.end(), aLessThanB);
            return *this;
        }
        
        const_iterator begin() const {
            return m_array.begin();
        }
        
        const_iterator end() const {
            return m_array.end();
        }
        
        /**
         * Sort in ascending order (natural ordering of T).
         */
        void sort() {
            std::sort(m_array.begin(), m_array.end());
        } 
        
        bool operator==(const Array& other) const {
            return m_array == other.m_array;
        }

        bool operator>(const Array& other) const {
            return m_array > other.m_array;
        }

        bool operator<(const Array& other) const {
            return m_array < other.m_array;
        }
        
        Array& compact() {
            m_array.shrink_to_fit();
            return *this;
        }

        virtual ~Array() {
        }

    private:

        size_type actual_index(index_type ix) const {
            return (0 <= ix) ? ix : (length() + ix);
        }

        collection_type m_array;
    };
}


#endif /* LAOLX_ARRAY_HXX */

