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
 * File:   istream.hxx
 * Author: kpfalzer
 *
 * Created on September 26, 2017, 12:11 PM
 */

#ifndef LAOLX_ISTREAM_HXX
#define LAOLX_ISTREAM_HXX

#include <istream>
#include <string>
#include <fstream>
#include <sstream>
#include "laolx/object.hxx"

namespace laolx {

    class LineReader : public virtual Object {
    public:
        typedef unsigned long int linenumber_type;

        virtual const std::string& getLine();

        /**
         * Line number of line from prior getLine().
         * @return line number of prior getLine().
         */
        linenumber_type getLineNumber() const {
            return m_lineNumber;
        }

        virtual const std::string& getFilename() const {
            static const std::string UNKNOWN = "?";
            return UNKNOWN;
        }
        
        virtual bool isEOF() const;

    protected:
        virtual ~LineReader() = 0;

        LineReader(std::istream& ins) : m_ins(ins), m_lineNumber(0) {
        }

        std::istream& m_ins;
        std::string m_line;
        linenumber_type m_lineNumber;
    };

    class StringInputStream : public virtual Object, public LineReader {
    public:
        explicit StringInputStream(const std::string& ins);
        
        virtual ~StringInputStream();
        
    private:
        std::istringstream m_ins;
    };
    
    class FileInputStream : public virtual Object, public LineReader {
    public:

        explicit FileInputStream(const std::string& filename);

        void close();

        const std::string& getFilename() const override {
            return filename;
        }

        virtual ~FileInputStream();

        const std::string filename;
        
    private:
        std::ifstream m_ifs;
    };
}

#endif /* LAOLX_ISTREAM_HXX */

