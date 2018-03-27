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
|	namedTemplateArgument (COMMA namedTemplateArgument)*
;

namedTemplateArgument
:	ID COLON templateArgument
;

templateArgument
: 	constantExpression
|   simpleTypeSpecifier
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

assignmentOperator
:	EQ
| 	STAR EQ
| 	SLASH EQ
| 	PCNT EQ
| 	PLUS EQ
| 	MINUS EQ
| 	rightShiftOp EQ
| 	leftShiftOp EQ
| 	AND EQ
| 	CARET EQ
| 	OR EQ
;

rightShiftOp: GT GT ;
leftShiftOp : LT LT ;

multiplicativeExpression
:
	unaryExpression
	| multiplicativeExpression STAR unaryExpression
	| multiplicativeExpression SLASH unaryExpression
	| multiplicativeExpression PCNT unaryExpression
;

additiveExpression
:
	multiplicativeExpression
	| additiveExpression PLUS multiplicativeExpression
	| additiveExpression MINUS multiplicativeExpression
;

shiftExpression
:
	additiveExpression
	| shiftExpression leftShiftOp additiveExpression
	| shiftExpression rightShiftOp additiveExpression
;

relationalExpression
:
	shiftExpression
	| relationalExpression LT shiftExpression
	| relationalExpression GT shiftExpression
	| relationalExpression LT EQ shiftExpression
	| relationalExpression GT EQ shiftExpression
;

equalityExpression
:
	relationalExpression
	| equalityExpression EQ EQ relationalExpression
	| equalityExpression EXCL EQ relationalExpression
;

andExpression
:
	equalityExpression
	| andExpression AND equalityExpression
;

exclusiveOrExpression
:
	andExpression
	| exclusiveOrExpression CARET andExpression
;

inclusiveOrExpression
:
	exclusiveOrExpression
	| inclusiveOrExpression OR exclusiveOrExpression
;

logicalAndExpression
:
	inclusiveOrExpression
	| logicalAndExpression AND AND inclusiveOrExpression
;

logicalOrExpression
:
	logicalAndExpression
	| logicalOrExpression OR OR logicalAndExpression
;

conditionalExpression
:
	logicalOrExpression
	| logicalOrExpression QMARK expression COLON assignmentExpression
;

assignmentExpression
:
	conditionalExpression
	//todo: lhs of assignment should be simpler
	//lhs: allow comma separated lhs?
	| logicalOrExpression assignmentOperator initializerClause
	| throwExpression
;

expression
:	assignmentExpression
	//todo: dont allow assigns inside expr?
|	expression COMMA assignmentExpression
;

unaryExpression
:
	postfixExpression
	| '++' unaryExpression
	| '--' unaryExpression
	| unaryOperator unaryExpression
;

unaryOperator
:
	OR
	| STAR
	| AND
	| PLUS
	| EXCL
	| TILDE
	| MINUS
;

postfixExpression
:
	primaryExpression
	| postfixExpression LBRACK expression RBRACK
	| postfixExpression LBRACK bracedInitList RBRACK
	| postfixExpression LPAREN expressionList? RPAREN
	| postfixExpression DOT TEMPLATE? idExpression
	| postfixExpression PLUS PLUS
	| postfixExpression MINUS MINUS
;

primaryExpression
:
	literal
	| THIS
	| '(' expression ')'
	| idExpression
	| lambdaExpression
;

idExpression
:
	unqualifiedId
	| qualifiedId
;

unqualifiedId
:
	ID
	| operatorFunctionId
	| literalOperatorId
;

qualifiedid
:
	nestedNameSpecifier TEMPLATE? unqualifiedId
;

lambdaExpression:
	DEF name
		methodParametersDeclaration?
		returnSpecifier?
		LCURLY methodBody RCURLY
;

literal:
	SYMBOL
|	INT
|	FLOAT
|	string
|	REGEXP
|	words
|	symbols
|	NIL
|	bool
;

bool: TRUE | FALSE
;

words
//todo: add predicate ID == 'w'
:	PCNT ID LCURLY ID* RCURLY
;

symbols
//todo: add predicate ID == 's'
: 	PCNT ID LCURLY ID* RCURLY
;
