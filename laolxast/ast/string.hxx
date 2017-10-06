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
 * File:   string.hxx
 * Author: kwpfalzer
 *
 * Created on October 3, 2017, 6:19 PM
 */

#ifndef STRING_HXX
#define STRING_HXX

#include "laolx/list.hxx"
#include "ast/common.hxx"

class String;
class StringList;
typedef std::shared_ptr<String> TRcString;
typedef std::shared_ptr<StringList> TRcStringList;

class String : public virtual AstNode {
public:
    static TRcString parse(Parser& parser);

    explicit String(const TRcToken& token);

    bool isSingleQuoted() const;

    bool isDoubleQuoted() const;

    const TRcToken m_token;
    
    virtual ~String();
};

class StringList : public virtual AstNode {
public:
    static TRcStringList parse(Parser& parser);

    explicit StringList(const TRcString& string);

    const laolx::List<TRcString>& getStrings() const {
        return m_strings;
    }
    
    virtual ~StringList();
    
private:
    void append(const TRcString& string);
    
    StringList& operator<<(const TRcString& string) {
        append(string);
        return *this;
    }
    
    laolx::List<TRcString> m_strings;
};


#endif /* STRING_HXX */

