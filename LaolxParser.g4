parser grammar LaolxParser;

options {
	tokenVocab = LaolxLexer;
}

simpleDecl
:   simpleDeclItem (COMMA simpleDeclItem)*
;

simpleDeclItem
:   mutability? simpleTypeSpec? IDENT
;

lambdaTypeSpec
:   LAMBDA LCURLY lambdaDeclHeading RCURLY
;

lambdaDeclHeading
:   lambdaDeclParms RARROW methodReturnType
;

lambdaDeclParms
:   LPAREN simpleTypeSpecList? RPAREN
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
:   INT | FLOAT | STRING | SYMBOL | CHAR | REGEXP
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

