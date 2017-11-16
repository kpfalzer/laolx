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
 * Created on Thu Nov 16 10:37:38 2017
 */
#ifndef SOURCE_FILE_HXX
#define SOURCE_FILE_HXX

#include "ast/common.hxx"
#include "ast/import_statement.hxx"

class SourceFile;
typedef const SourceFile* TPCSourceFile;

class SourceFile : public virtual AstNode {
public:
    typedef laolx::Array<TPCImportStatement> TImports;
    typedef laolx::Array<TPCAstNode> TNodes;
    
    static TPCSourceFile parse(Parser& parser);

    explicit SourceFile(const TImports& imports, const TNodes& declsAndStmts);
    
    const TImports  imports;
    const TNodes    declsAndStmts;

    virtual ~SourceFile();
};

#endif /* SOURCE_FILE_HXX */
