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
 * File:   regex.hxx
 * Author: kwpfalzer
 *
 * Created on September 24, 2017, 7:58 AM
 */

#ifndef LAOLX_REGEX_HXX
#define LAOLX_REGEX_HXX

#include <regex>
#include <string>
#include "laolx/object.hxx"

namespace laolx {

    class Regex : public virtual Object {
    public:
        typedef unsigned long size_type;
        
        explicit Regex() {
        }

        /**
         * Construct regular expression matcher.
         * @param patt regular expression.
         */
        explicit Regex(const std::string& patt) 
        : m_rex(patt) {
        }

        Regex& operator=(const std::string& patt) {
            m_rex = patt;
            return *this;
        }
        
        /**
         * Match to regular expression.
         * @param text text to match.
         * @return true if any part of text matches.
         */
        bool match(const std::string& text);
        
        size_type getMatchCount() const;
        
        /**
         * Return sub-match.
         * @param n 0 is full-match; 1 is 1st sub-match, ...
         * @return sub-match.
         */
        std::string getMatch(int n) const;
        
        virtual ~Regex() {
        }

    private:
        std::regex m_rex;
        std::smatch m_matcher;
    };
}

#endif /* LAOLX_REGEX_HXX */

