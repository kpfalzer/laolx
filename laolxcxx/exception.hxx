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
 * File:   exception.hxx
 * Author: kpfalzer
 *
 * Created on September 25, 2017, 11:06 AM
 */

#ifndef LAOLX_EXCEPTION_HXX
#define LAOLX_EXCEPTION_HXX

#include <stdexcept>
#include <string>

namespace laolx {

    class NoMethodException : public std::runtime_error {
    public:

        explicit NoMethodException(const std::string& methodName);

        explicit NoMethodException(const char* methodName)
        : NoMethodException(std::string(methodName)) {
        }

        virtual ~NoMethodException();
    };
    
    class FileException : public std::runtime_error {
    public:

        enum Type {
            OPEN,
            READ
        };
        
        explicit FileException(const std::string& filename, Type type = OPEN);

        explicit FileException(const char* filename, Type type = OPEN)
        : FileException(std::string(filename), type) {
        }

        virtual ~FileException();
    };
}

#endif /* LAOLX_EXCEPTION_HXX */

