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
 * File:   map.hxx
 * Author: kwpfalzer
 *
 * Created on September 23, 2017, 9:36 AM
 */

#ifndef LAOLX_MAP_HXX
#define LAOLX_MAP_HXX

#include <unordered_map>
#include <functional>
#include <array>
#include "laolx/object.hxx"
#include "laolx/array.hxx"

namespace laolx {

    /**
     * Map with key order (as inserted).
     * V must have 
     */
    template<typename K, typename V>
    class Map : public virtual Object {
    public:
        typedef std::unordered_map<K, V> collection_type;
        typedef typename collection_type::size_type size_type;
        typedef typename collection_type::value_type value_type;
        typedef typename collection_type::key_type key_type;
        typedef typename collection_type::mapped_type mapped_type;
        typedef typename collection_type::const_iterator const_iterator;

        explicit Map() {
        }

        explicit Map(std::initializer_list<value_type> init) : m_map(init) {
        }

        /**
         * Lookup value by key.
         * If no entry for key, then construct empty value.
         * @param key index into map.
         * @return current value or (reference to) empty value.
         */
        V& operator[](const K & key) {
            return m_map[key];
        }

        const V& operator[](const K & key) const {
            // unordered_map does not have a const operator[] since
            // it wants to insert if no key (thus an non-const operation.
            // TODO: need to fix the semantics here!
            // throw no key??
            return const_cast<collection_type*>(&m_map)->operator[](key);
        }

        Map& operator<<(const value_type& kv) {
            m_map[kv.first] = kv.second;
            return *this;
        }

        bool hasKey(const K & key) const {
            return m_map.find(key) != m_map.end();
        }

        void each(const std::function<void (const value_type&) >& consume) const {
            eachImpl(m_map, consume);
        }

        Map select(const std::function<bool (const value_type&) >& predicate) const {
            return selectImpl<Map>(*this, predicate);
        }

        template<typename K2, typename V2, typename R = Map<K2, V2> >
        R map(const std::function<std::pair<K2, V2> (const value_type& kv)>& mapper) const {
            return mapImpl<R>(*this, mapper);
        }

        Array<K> keys() const {
            Array<K> keys(size());
            for (const auto& k : m_map) {
                keys << k.first;
            }
            return keys;
        }

        Array<V> values() const {
            Array<V> values(size());
            for (const auto& k : m_map) {
                values << k.second;
            }
            return values;
        }

        const_iterator begin() const {
            return m_map.begin();
        }

        const_iterator end() const {
            return m_map.end();
        }

        size_type size() const {
            return m_map.size();
        }

        bool isEmpty() const {
            return m_map.empty();
        }

        bool operator==(const Map & other) const {
            return m_map == other.m_map;
        }

        virtual ~Map() {
        }

    private:
        collection_type m_map;
    };
}


#endif /* LAOLX_MAP_HXX */

