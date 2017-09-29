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

#include <cassert>
#include <type_traits>
#include "lexer.hxx"

const std::string Lexer::EOLN = "\n";

const bool Lexer::stInited = Lexer::init();

bool Lexer::init() {
    static_assert('0' < '9' && 'a' < 'z' && 'A' < 'Z', "Failed char assumption.");
    return true;
}

bool Lexer::isIdentAny(char c) {
    return isIdentBegin(c) || isDigit(c);
}

bool Lexer::isIdentBegin(char c) {
    return isAlpha(c) || ('_' == c);
}

bool Lexer::isAlpha(char c) {
    return (('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z'));
}

bool Lexer::isDigit(char c) {
    return ('0' <= c) && (c <= '9');
}

void Lexer::setMatch(int n) {
    m_startColNumber = m_currColNumber;
    m_startLineNumber = m_currLineNumber;
    m_text = m_line.substr(m_currColNumber, n);
    advancePos(n);
}

void Lexer::advancePos(int n) {
    m_currColNumber += n;
    if (m_currColNumber < m_line.length()) {
        return;
    }
    assert(m_currColNumber == m_line.length()); //just past last valid char and no more
    readLine();
}

void Lexer::readLine(bool force) {
    assert(force || isEmpty() || (m_currColNumber >= m_line.length()));
    m_line = m_input.getLine();
    if (!isEmpty()) {
        m_line += EOLN; //we want to append actual EOLN
        m_currLineNumber += 1;
        m_currColNumber = 0;
    }
}


