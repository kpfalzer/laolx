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
#include "istream.hxx"

namespace laolx {

    static const std::string EMPTY;

    const std::string& LineReader::getLine() {
        if (isEOF()) {
            return EMPTY;
        }
        std::ostringstream line;
        char ch = 0;
        while (true) {
            m_ins.get(ch);
            if (m_ins.fail() || isEOF()) {
                break;
            }
            if (!m_keepNewLine && (ch == '\n')) {
                break;
            }
            if (ch != '\r') {
                line.rdbuf()->sputc(ch);
            }
        }
        if (m_ins.fail() && !isEOF()) {
            throw FileException(getFilename(), FileException::READ);
        }
        m_line = line.rdbuf()->str();
        if (!isEOF()) {
            m_lineNumber++;
        }
        return m_line;
    }

    bool LineReader::isEOF() const {
        return m_ins.eof();
    }

    LineReader::~LineReader() {
    }

    StringInputStream::StringInputStream(const std::string& ins, bool keepNewLine) 
    : LineReader(m_ins, keepNewLine), m_ins(ins) {

    }

    StringInputStream::~StringInputStream() {
    }

    FileInputStream::FileInputStream(const std::string& filename, bool keepNewLine)
    : LineReader(m_ifs, keepNewLine), filename(filename), m_ifs(filename) {
        if (!m_ifs) {
            throw FileException(filename);
        }
    }

    FileInputStream::~FileInputStream() {
    }

    void FileInputStream::close() {
        m_ifs.close();
    }

}
