parser grammar LaolxParser;

options {
	tokenVocab = LaolxLexer;
}

/**
 *  The syntax of simpleDecl is different than c++ (and more like python/ruby) where
 *  there is single RHS which can be "splat" to multiple LHS.
 *  (In c++, there can be 'T1 v = 12, v2 = 13')
 */
simpleDecl
:   simpleDeclItem (COMMA simpleDeclItem)* initializer?
;

simpleDeclItem
:   mutability? simpleTypeSpec? splat? IDENT
;

splat
:   STAR
;

initializer
:   braceOrEqualInitializer
|   LPAREN initializerList RPAREN   //shorthand for T.new(...)
;

braceOrEqualInitializer
:   assignmentOp initializerClause
|   bracedInitList
;

initializerList
:   positionalInitializerItem (COMMA positionalInitializerItem)*
|   namedInitializerList
;

positionalInitializerItem
:   initializerClause
;

namedInitializerItem
:   IDENT COLON initializerClause
;

// No conflict with nested templates
leftShiftOp
:   LT LT
;

// No conflict with nested templates
rightShiftOp
:   GT GT
;

leftShiftEqOp
:   leftShiftOp EQ
;

rightShiftEqOp
:   rightShiftOp EQ
;

assignmentOp
:   EQ
|   STAREQ
|   SLASHEQ
|   PCNTEQ
|   PLUSEQ
|   MINUSEQ
|   leftShiftEqOp
|   rightShiftEqOp
|   ANDEQ
|   CARETEQ
|   OREQ
|   OR2EQ
;

// Unlike c++, we do not allow 'expr, expr, ...'
expression
:   conditionalExpr
;

conditionalExpr
:   logicalOrExpr (QMARK expression COLON  expression)?
;

multiplicativeExpr
:   unaryExpr
|   multiplicativeExpr STAR unaryExpr
|   multiplicativeExpr SLASH unaryExpr
|   multiplicativeExpr PCNT unaryExpr
;

additiveExpr
:   multiplicativeExpr
|   additiveExpr PLUS multiplicativeExpr
|   additiveExpr MINUS multiplicativeExpr
;

shiftExpr
:   additiveExpr
|   shiftExpr leftShiftOp additiveExpr
|   shiftExpr rightShiftOp additiveExpr
;

relationalExpr
:   shiftExpr
|   relationalExpr LT shiftExpr
|   relationalExpr GT shiftExpr
|   relationalExpr LT EQ shiftExpr
|   relationalExpr GT EQ shiftExpr
;

equalityExpr
:   relationalExpr
|   equalityExpr EQ2 relationalExpr
|   equalityExpr NOTEQ relationalExpr
;

andExpr
:   equalityExpr
|   andExpr AND equalityExpr
;

exclusiveOrExpr
:   andExpr
|   exclusiveOrExpr CARET andExpr
;

inclusiveOrExpr
:   exclusiveOrExpr
|   inclusiveOrExpr OR exclusiveOrExpr
;

logicalAndExpr
:   inclusiveOrExpr
|   logicalAndExpr AND2 inclusiveOrExpr
;

logicalOrExpr
:   logicalAndExpr
|   logicalOrExpr OR2 logicalAndExpr
;

namedInitializerList
:   namedInitializerItem (COMMA namedInitializerItem)*
;

bracedInitList
:   LCURLY namedInitializerList? RCURLY
|   LBRACK expressions? RBRACK
;

initializerClause
:   expression
|   bracedInitList
;

lambdaTypeSpec
:   LAMBDA LCURLY lambdaDeclHeading RCURLY
;

lambdaDeclHeading
:   lambdaDeclParms RARROW methodReturnType
;

lambdaDeclParms
:   LPAREN simpleDecl? RPAREN
;

methodReturnType
:   simpleTypeSpec
|   VOID
;

mutability
:   CONST | VAR
;

string
:   SQSTRING
|   DQSTRING
;

simpleTypeSpec
:   INT | FLOAT | STRING | SYMBOL | CHAR | REGEXPK
|   tupleTypeSpec
|   mapTypeSpec
|   lambdaTypeSpec
|   COLON2? nestedNamedSpec? typeName
|   simpleTypeSpec arrayTypeSpec
;

mapTypeSpec
:   LCURLY RCURLY
;

arrayTypeSpec
:   LBRACK RBRACK
;

tupleTypeSpec
:   TUPLE simpleTypeSpecList RCURLY
;

simpleTypeSpecList
:   simpleTypeSpecListItem (COMMA simpleTypeSpecListItem)*
;

simpleTypeSpecListItem
:   simpleTypeSpec IDENT
;

nestedNamedSpec
:   (IDENT COLON2)+
;

typeName
:   IDENT (LT templateArgumentList? GT)?
;

templateArgumentList
:   namedTemplateArgument (COMMA namedTemplateArgument)*
|   positionalTemplateArgument (COMMA positionalTemplateArgument)*
;

namedTemplateArgument
:   IDENT COLON positionalTemplateArgument
;

positionalTemplateArgument
:   simpleTypeSpec //NOTE: no ... yet
|   constantExpression
;

constantExpression
:   IDENT //TODO: placeholder
;

number
:   VINTEGER | VFLOAT | VHEX | VSIZED
;

unaryExpr
:   TODO
;

primaryExpr
:   literal
|   THIS
|   LPAREN expression RPAREN
|   idExpr
|   lambdaExpr
;

literal
:   string
|   REGEXP
|   number
|   bool
|   NIL
|   symbol
|   symbols
|   words
|   bracedInitList  //map
|   tuple
;

array
:   LBRACK expressions RBRACK
;

tuple
:   TUPLE expressions? RCURLY
;

expressions
:   expression (COMMA expression)*
;

symbol
:   COLON IDENT
;

words
:   WORDS IDENT* RCURLY
;

symbols
:   SYMBOLS IDENT* RCURLY
;

idExpr
:   unqualifiedId
|   qualifiedId
;

unqualifiedId
:   IDENT
//todo: c++ allows operator here...
|   simpleTemplateId
;

simpleTemplateId
:   IDENT LT templateArgumentList? GT
;

qualifiedId
:   TODO
;

lambdaExpr
:   TODO
;

bool
:   TRUE | FALSE
;

