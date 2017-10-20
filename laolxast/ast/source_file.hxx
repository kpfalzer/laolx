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
 * File:   source_file.hxx
 * Author: kwpfalzer
 *
 * Created on Thu Oct  5 19:05:57 2017
 */
#ifndef SOURCE_FILE_HXX
#define SOURCE_FILE_HXX

#include "laolx/array.hxx"
#include "ast/common.hxx"
#include "ast/declaration.hxx"
#include "ast/statement.hxx"
#include "ast/include_statement.hxx"

class SourceFile;
typedef std::shared_ptr<SourceFile> TRcSourceFile;

class SourceFile : public virtual AstNode {
public:
    typedef laolx::Array<TRcAstNode> TItems;
    typedef laolx::Array<TRcIncludeStatement> TIncludes;
    
    static TRcSourceFile parse(Parser& parser);

    explicit SourceFile();
    
    SourceFile& operator<<(const TRcStatement& statement);
    
    SourceFile&  operator<<(const TRcDeclaration& declaration);
    
    SourceFile&  operator<<(const TRcIncludeStatement& include);
    
    const TItems& items() const {
        return m_items;
    }
    
    const TIncludes& includes() const {
        return m_includeStatements;
    }

    virtual ~SourceFile();
    
private:
    // declaration and statements
    TItems    m_items;
    TIncludes m_includeStatements;
};

#endif /* SOURCE_FILE_HXX */
