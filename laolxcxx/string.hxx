/*
 * The MIT License
 *
 * Copyright 2017 kpfalzer.
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
 * File:   string.hxx
 * Author: kpfalzer
 *
 * Created on September 29, 2017, 3:58 PM
 */

#ifndef LAOLX_STRING_HXX
#define LAOLX_STRING_HXX

#include <functional>
#include <string>
#include "laolx/object.hxx"

namespace laolx {

    class String : public virtual Object, public std::string {
    public:

        explicit String() {
        }

        String(const std::string& str) : std::string(str) {
        }

        String(const char* str) : std::string(str) {
        }

        const String& operator=(const String& ref) {
            std::string::operator=(ref);
            return *this;
        }
        
        String(const String& ref) : std::string(ref) {}
        
        /**
         * Return substring [start, end).
         * @param start starting position of substring (relative to beginning).
         * @param end position just past end of substring.
         * @return substring [start, end).
         */
        String slice(size_t start, size_t end) const;
        
        String slice(size_t start) const {
            return slice(start, length());
        }

        /**
         * Search for val starting at position startPos.
         * @param val value to search for.
         * @param startPos start position to start search.
         * @return absolute index of match or npos if no match.
         */
        size_t indexOf(const std::string& val, size_t startPos = 0) const;

        // We need this for using Map<>.
        bool operator==(const String& other) const {
            return (static_cast<const std::string&>(*this) == static_cast<const std::string&>(other));
        }
        
        virtual ~String();
    };
}

// Be sure to add hash function.
// (see http://marknelson.us/2011/09/03/hash-functions-for-c-unordered-containers/)
namespace std {

    template <>
    class hash<laolx::String> {
    public:

        size_t operator()(const laolx::String &str) const {
            return hash<std::string>()(str);
        }
    };
};

#endif /* LAOLX_STRING_HXX */

