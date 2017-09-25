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
 * File:   list.hxx
 * Author: kwpfalzer
 *
 * Created on September 23, 2017, 4:11 PM
 */

#ifndef LAOLX_LIST_HXX
#define LAOLX_LIST_HXX

#include <list>
#include <functional>
#include "laolx/object.hxx"
#include "object.hxx"

namespace laolx {

    template<typename T>
    class List : public virtual Object {
    public:
        typedef std::list<T> collection_type;
        typedef typename collection_type::size_type size_type;
        typedef typename collection_type::reference reference;
        typedef typename collection_type::const_reference const_reference;

        List() {
        }

        List(std::initializer_list<T> init) : m_list(init) {
        }

        List& operator<<(const T& item) {
            return push_last(item);
        }

        reference first() {
            return m_list.front();
        }

        const_reference first() const {
            return m_list.front();
        }

        reference last() {
            return m_list.back();
        }

        const_reference last() const {
            return m_list.back();
        }

        List& push_last(const T& item) {
            m_list.push_back(item);
            return *this;
        }

        List& push_first(const T& item) {
            m_list.push_front(item);
            return *this;
        }

        T pop_last() {
            T last = last();
            m_list.pop_back();
            return last;
        }

        T pop_first() {
            T front = front();
            m_list.pop_front();
            return front;
        }

        size_type length() const {
            return m_list.size();
        }

        void each(const std::function<void (const T& ele)>& consume) const {
            eachImpl(m_list, consume);
        }

        List select(const std::function<bool (const T& ele)>& predicate) const {
            return selectImpl(*this, predicate);
        }

        template<typename T2>
        List<T2> map(const std::function<const T2& (const T& ele)>& mapper) const {
            List<T2> mapped;
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

        virtual ~List() {
        }

    private:
        collection_type m_list;
    };
}


#endif /* LAOLX_ARRAY_HXX */

