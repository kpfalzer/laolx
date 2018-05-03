parser grammar LaolxParser;

options {
	tokenVocab = LaolxLexer;
}

string
:   SQSTRING
|   DQSTRING
;

simpleTypeSpecifier
:   INT | FLOAT | STRING | SYMBOL | CHAR
|   COLON2? nestedNamedSpecifier? typeName
;

nestedNamedSpecifier
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
:   simpleTypeSpecifier //NOTE: no ... yet
|   constantExpression
;

constantExpression
:   IDENT //TODO: placeholder
;

number
:   VINTEGER | VFLOAT | VHEX | VSIZED
;

