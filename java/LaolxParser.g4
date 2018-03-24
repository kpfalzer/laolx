parser grammar LaolxParser;

options {
	tokenVocab = LaolxLexer;
}

sourceFile
: 	importStatement* (declaration | statement)* EOF
;

importStatement
:	IMPORT importSpecifierList
;

importSpecifierList
:	importSpecifier (COMMA importSpecifier)*
;

importSpecifier
:	hierName (AS ID)?
;

hierName
:	ID (DOT ID)*
;

declaration
:	linkage? classDeclaration
|	linkage? interfaceDeclaration
|	linkage? variableDeclaration
|	linkage? methodDeclaration
|	typedefDeclaration
|	namespaceDeclaration
;

namespaceDeclaration
:	NAMESPACE hierName LCURLY declaration* RCURLY
;

access
:	PUBLIC | PROTECTED | PRIVATE
;

classDeclaration
:	CLASS ID templateParameterList?
        methodParametersDeclaration?
        baseClause?
        LCURLY classBody? RCURLY
;

interfaceDeclaration
:	INTERFACE ID templateParameterList?
        //An interface cannot inherit
        LCURLY methodDeclaration* RCURLY
;

templateParameterList
:	LT templateParameter (COMMA templateParameter)* GT
;

templateParameter
: 	ID (EQ templateArgument)?
;

methodParametersDeclaration
:	LPAREN methodParameterList? RPAREN
;

methodParameterList
:   methodParameter (COMMA methodParameter)*
;

methodParameter
:   access? mutability? simpleTypeSpecifier
        varOrAttrName (EQ initializerClause)?
;

varOrAttrName
:	ID
|	AT ID
|	AT PLUS ID
|	AT MINUS ID
;

mutability
:	CONST
|	VAR
;

variableDeclaration
:	mutability? STATIC? simpleTypeSpecifier?
        varOrAttrName (EQ initializerClause)?
;

simpleTypeSpecifier
:	simpleTypeSpecifierX arraySpecifier*
;

arraySpecifier
:	LBRACK RBRACK
;

simpleTypeSpecifierX
: 	nestedNameSpecifier? name
|   INT
|   FLOAT
|   STRING
|   CHAR
|   BOOL
|   SYMBOL
;

nestedNameSpecifier
:	ID DOT
|	nestedNameSpecifier ID DOT
|	nestedNameSpecifier simpleTemplateId DOT
;

name
:	ID
|	simpleTemplateId
;

simpleTemplateId
:	ID LT templateArgumentList? GT
;

templateId
:	simpleTemplateId
|	operatorFunctionId LT templateArgumentList? GT
;

templateArgumentList
:	templateArgument (COMMA templateArgument)*
;

templateArgument
:	(ID COLON)?
        (   constantExpression
        |   simpleTypeSpecifier
        )
;

operatorFunctionId
:	OPERATOR overloadableOperator
;

classBody
:	//TODO
;

methodBody
:	//TODO
;

overloadableOperator
:	//TODO
;

statement
:	//TODO
;

baseClause
:	//TODO
;

constantExpression
:	//TODO
;

initializerClause
:	//TODO
;

linkage
:	//TODO
;

methodDeclaration
:	//TODO
;

typedefDeclaration
:	//TODO
;

