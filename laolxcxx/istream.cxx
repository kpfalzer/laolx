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

#include <sstream>
#include <cassert>
#include "laolx/istream.hxx"
#include "laolx/exception.hxx"

namespace laolx {

    static const std::string EMPTY;
    
    FileInputStream::FileInputStream(const std::string& filename)
    : m_filename(filename), m_ifs(filename), m_lineNumber(0) {
        if (!m_ifs) {
            throw FileOpenException(m_filename);
        }
    }

    FileInputStream::~FileInputStream() {
    }
    
    void FileInputStream::close() {
        m_ifs.close();
    }

    const std::string& FileInputStream::getLine() {
        if (isEOF())     {
            return EMPTY;
        }
        std::ostringstream line;
        char ch = 0;
        while (true) {
            m_ifs.get(ch);
            if (m_ifs.fail() || isEOF()) {
                break;
            }
            if (ch == '\n') {
                break;
            }
            if (ch != '\r') {
                line.rdbuf()->sputc(ch);
            }
        }
        assert(!(m_ifs.fail() && !isEOF()));
        m_line = line.rdbuf()->str();
        if (! isEOF()) {
            m_lineNumber++;
        }
        return m_line;
    }

    bool FileInputStream::isEOF() const {
        return m_ifs.eof();
    }
}