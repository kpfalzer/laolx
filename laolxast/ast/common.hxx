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
 * File:   common.hxx
 * Author: kwpfalzer
 *
 * Created on October 4, 2017, 5:55 PM
 */

#ifndef COMMON_HXX
#define COMMON_HXX

#include <memory>
#include "parser/astnode.hxx"
#include "parser/token.hxx"
#include "parser/parser.hxx"

class Access;
typedef const Access* TPCAccess;
class AssignmentExpression;
typedef const AssignmentExpression* TPCAssignmentExpression;
class BaseClause;
typedef const BaseClause* TPCBaseClause;
class BaseInitializer;
typedef const BaseInitializer* TPCBaseInitializer;
class BaseInitializerList;
typedef const BaseInitializerList* TPCBaseInitializerList;
class BaseInitializerSpecifier;
typedef const BaseInitializerSpecifier* TPCBaseInitializerSpecifier;
class BaseName;
typedef const BaseName* TPCBaseName;
class BaseSpecifier;
typedef const BaseSpecifier* TPCBaseSpecifier;
class BaseSpecifierList;
typedef const BaseSpecifierList* TPCBaseSpecifierList;
class BaseTypeSpecifier;
typedef const BaseTypeSpecifier* TPCBaseTypeSpecifier;
class BinaryOp;
typedef const BinaryOp* TPCBinaryOp;
class Bool;
typedef const Bool* TPCBool;
class BracedInitList;
typedef const BracedInitList* TPCBracedInitList;
class CaseStatement;
typedef const CaseStatement* TPCCaseStatement;
class ClassBody;
typedef const ClassBody* TPCClassBody;
class ClassDeclaration;
typedef const ClassDeclaration* TPCClassDeclaration;
class CompoundStatement;
typedef const CompoundStatement* TPCCompoundStatement;
class Condition;
typedef const Condition* TPCCondition;
class ConditionalExpression;
typedef const ConditionalExpression* TPCConditionalExpression;
class ConstantExpression;
typedef const ConstantExpression* TPCConstantExpression;
class Declaration;
typedef const Declaration* TPCDeclaration;
class Expression;
typedef const Expression* TPCExpression;
class ExpressionEle;
typedef const ExpressionEle* TPCExpressionEle;
class ExpressionList;
typedef const ExpressionList* TPCExpressionList;
class ForStatement;
typedef const ForStatement* TPCForStatement;
class IdExpression;
typedef const IdExpression* TPCIdExpression;
class IfStatement;
typedef const IfStatement* TPCIfStatement;
class ImportSpecifier;
typedef const ImportSpecifier* TPCImportSpecifier;
class ImportSpecifierList;
typedef const ImportSpecifierList* TPCImportSpecifierList;
class ImportStatement;
typedef const ImportStatement* TPCImportStatement;
class InitializerClause;
typedef const InitializerClause* TPCInitializerClause;
class InitializerList;
typedef const InitializerList* TPCInitializerList;
class IterationStatement;
typedef const IterationStatement* TPCIterationStatement;
class JumpStatement;
typedef const JumpStatement* TPCJumpStatement;
class LambdaExpression;
typedef const LambdaExpression* TPCLambdaExpression;
class Linkage;
typedef const Linkage* TPCLinkage;
class Literal;
typedef const Literal* TPCLiteral;
class MemberVariableDeclaration;
typedef const MemberVariableDeclaration* TPCMemberVariableDeclaration;
class MethodBody;
typedef const MethodBody* TPCMethodBody;
class MethodBodyItem;
typedef const MethodBodyItem* TPCMethodBodyItem;
class MethodDeclaration;
typedef const MethodDeclaration* TPCMethodDeclaration;
class MethodParameter;
typedef const MethodParameter* TPCMethodParameter;
class MethodParameterList;
typedef const MethodParameterList* TPCMethodParameterList;
class MethodParametersDeclaration;
typedef const MethodParametersDeclaration* TPCMethodParametersDeclaration;
class Mutability;
typedef const Mutability* TPCMutability;
class Name;
typedef const Name* TPCName;
class NamespaceDeclaration;
typedef const NamespaceDeclaration* TPCNamespaceDeclaration;
class NamespaceDeclarationName;
typedef const NamespaceDeclarationName* TPCNamespaceDeclarationName;
class NestedNameSpecifier;
typedef const NestedNameSpecifier* TPCNestedNameSpecifier;
class OperatorFunctionId;
typedef const OperatorFunctionId* TPCOperatorFunctionId;
class OverloadableOperator;
typedef const OverloadableOperator* TPCOverloadableOperator;
class PostfixExpression;
typedef const PostfixExpression* TPCPostfixExpression;
class PrimaryExpression;
typedef const PrimaryExpression* TPCPrimaryExpression;
class QualifiedId;
typedef const QualifiedId* TPCQualifiedId;
class ReturnSpecifier;
typedef const ReturnSpecifier* TPCReturnSpecifier;
class SimpleTemplateId;
typedef const SimpleTemplateId* TPCSimpleTemplateId;
class SimpleTypeSpecifier;
typedef const SimpleTypeSpecifier* TPCSimpleTypeSpecifier;
class SourceFile;
typedef const SourceFile* TPCSourceFile;
class Statement;
typedef const Statement* TPCStatement;
class String;
typedef const String* TPCString;
class Symbols;
typedef const Symbols* TPCSymbols;
class TemplateArgument;
typedef const TemplateArgument* TPCTemplateArgument;
class TemplateArgumentList;
typedef const TemplateArgumentList* TPCTemplateArgumentList;
class TemplateId;
typedef const TemplateId* TPCTemplateId;
class TemplateParameter;
typedef const TemplateParameter* TPCTemplateParameter;
class TemplateParameterList;
typedef const TemplateParameterList* TPCTemplateParameterList;
class TypedefDeclaration;
typedef const TypedefDeclaration* TPCTypedefDeclaration;
class UnaryExpression;
typedef const UnaryExpression* TPCUnaryExpression;
class UnaryOperator;
typedef const UnaryOperator* TPCUnaryOperator;
class UnqualifiedId;
typedef const UnqualifiedId* TPCUnqualifiedId;
class VarOrAttrName;
typedef const VarOrAttrName* TPCVarOrAttrName;
class VariableDeclaration;
typedef const VariableDeclaration* TPCVariableDeclaration;
class Words;
typedef const Words* TPCWords;

/**
 * Parse sequence of C separated by delimiter: C,C,...
 * @param parser the parser.
 * @param delimiter sequence delimiter.
 * @return compacted array of C (or nullptr if no sequence matched).
 */
template<class C, typename T = const C*>
laolx::Array<T>*
oneOrMore(Parser& parser, const Token::Code delimiter) {
    laolx::Array<T>* items = nullptr;
    auto start = parser.getMark();
    while (parser.hasMore()) {
        auto item = C::parse(parser);
        if (!item) {
            break;
        }
        if (!items) {
            items = new laolx::Array<T>();
        }
        *items << item;
        start = parser.getMark();
        if (parser.accept()->code != delimiter) {
            break;
        }
    }
    parser.setMark(start);
    if (items) {
        items->compact();
    }
    return items;
}

template<class C, typename T = const C*>
laolx::Array<T>*
zeroOrMore(Parser& parser, const Token::Code delimiter) {
    auto items = oneOrMore<C,T>(parser, delimiter);
    return items ? items : new laolx::Array<T>();
}

#endif /* COMMON_HXX */

