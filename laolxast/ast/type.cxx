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
 * File:   type.cxx
 * Author: kwpfalzer
 *
 * Created on Fri Oct  6 19:30:04 2017
 */
#include "ast/type.hxx"
#include "union_type.hxx"
#include "primitive_type.hxx"
#include "simple_type.hxx"
#include "scoped_type.hxx"

TRcType Type::parse(Parser& parser) {
    TRcType result(nullptr);
    TRcAstNode node(nullptr);
    auto unionType = UnionType::parse(parser);
    if (unionType) {
        node = std::static_pointer_cast<AstNode>(unionType);
    } else {
        auto primitiveType = PrimitiveType::parse(parser);
        if (primitiveType) {
            node = std::static_pointer_cast<AstNode>(primitiveType);
        } else {
            auto simpleType = SimpleType::parse(parser);
            if (simpleType) {
                node = std::static_pointer_cast<AstNode>(simpleType);
            } else {
                auto scopedType = ScopedType::parse(parser);
                if (scopedType) {
                    node = std::static_pointer_cast<AstNode>(scopedType);
                }
            }
        }
    }
    if (node) {
        result = std::make_shared<Type>(node);
    }
    return result;
}

Type::Type(const TRcAstNode& type) : m_type(type) {

}

Type::~Type() {
}
