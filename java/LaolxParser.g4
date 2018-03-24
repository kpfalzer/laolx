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
:	ID (DOT ID)* (AS ID)?
;

declaration
:	//TODO
;

statement
:	//TODO
;
