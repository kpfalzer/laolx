grammar Laolx;

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
:   'CEXPR' //TODO: placeholder
;

number
:   VINTEGER | VFLOAT | VHEX | VSIZED
;

// Lexer definition
//
AS			: 'as' 			SPACING? ;
BOOL		: 'bool'		SPACING? ;
BREAK		: 'break'		SPACING? ;
CASE		: 'case'		SPACING? ;
CATCH		: 'catch'  		SPACING? ;
CHAR		: 'char'		SPACING? ;
CLASS		: 'class'		SPACING? ;
CONST		: 'const'		SPACING? ;
DEF			: 'def'			SPACING? ;
DEFAULT		: 'default'		SPACING? ;
DO			: 'do'			SPACING? ;
ELSE		: 'else'		SPACING? ;
ELSIF		: 'elsif'		SPACING? ;
FALSE		: 'false'		SPACING? ;
FLOAT		: 'float'		SPACING? ;
FOR			: 'for'			SPACING? ;
IF			: 'if'			SPACING? ;
IMPORT		: 'import' 		SPACING? ;
IN		    : 'in'   		SPACING? ;
INT			: 'int'			SPACING? ;
INTERFACE	: 'interface'	SPACING? ;
NAMESPACE	: 'namespace'	SPACING? ;
NEW			: 'new'			SPACING? ;
NIL			: 'nil'			SPACING? ;
OPERATOR	: 'operator'	SPACING? ;
PRIVATE		: 'private'		SPACING? ;
PROTECTED	: 'protected'	SPACING? ;
PUBLIC		: 'public'		SPACING? ;
RETURN  	: 'return'		SPACING? ;
STATIC		: 'static'		SPACING? ;
STRING		: 'string'		SPACING? ;
SYMBOL		: 'symbol'		SPACING? ;
THIS		: 'this'		SPACING? ;
THROW   	: 'throw'		SPACING? ;
TRUE		: 'true'		SPACING? ;
TRY			: 'try'			SPACING? ;
TYPEDEF		: 'typedef'		SPACING? ;
UNLESS		: 'unless'		SPACING? ;
UNTIL		: 'until'		SPACING? ;
VAR			: 'var'			SPACING? ;
WHEN		: 'when'		SPACING? ;
WHILE		: 'while'		SPACING? ;

AND		: '&' SPACING? ;
AT		: '@' SPACING? ;
CARET	: '^' SPACING? ;
COLON	: ':' SPACING? ;
COLON2	: '::' SPACING? ;
COMMA	: ',' SPACING? ;
DOT		: '.' SPACING? ;
EQ		: '=' SPACING? ;
EXCL	: '!' SPACING? ;
GT		: '>' SPACING? ;
LBRACK	: '[' SPACING? ;
LCURLY	: '{' SPACING? ;
LPAREN	: '(' SPACING? ;
LT		: '<' SPACING? ;
MINUS	: '-' SPACING? ;
OR		: '|' SPACING? ;
PCNT	: '%' SPACING? ;
PLUS	: '+' SPACING? ;
QMARK	: '?' SPACING? ;
RBRACK	: ']' SPACING? ;
RCURLY	: '}' SPACING? ;
RPAREN	: ')' SPACING? ;
SEMI	: ';' SPACING? ;
SLASH	: '/' SPACING? ;
STAR	: '*' SPACING? ;

SQSTRING :	'\'' (ESC | ~['])? '\'' SPACING? ;
DQSTRING :	'"' (ESC | ~["])* '"' SPACING? ;
IDENT 	 :	ID_LETTER (ID_LETTER | DIGIT)* SPACING? ;

//
// Number values
//
VINTEGER: INTFRAG SPACING? ;
fragment INTFRAG: [0-9][0-9_]* ;
VHEX    : '0x' [0-9a-fA-F][0-9_a-fA-F]* SPACING? ;
VFLOAT  : INTFRAG '.' INTFRAG ([eE][-+]? INTFRAG)? ;
VSIZED  : INTFRAG '\'' [bBhHoOdD][0-9a-fA-F][0-9a-fA-F_]* SPACING? ;

SPACING: SPACING_ALTS+ ;

fragment ESC :	'\\' .  ;

fragment
ID_LETTER
:	'a'..'z'
|	'A'..'Z'
| 	'_'
;

fragment SPACING_ALTS : WS | EOLN | COMMENT ;		

fragment DIGIT : '0'..'9' ;

fragment WS            : [ \t]+ ;
fragment EOLN          : ('\r'? '\n')+  ;
fragment BLOCK_COMMENT : '/*' .*? '*/'  ;
fragment LINE_COMMENT  : '//' ~[\r\n]*  ;
fragment COMMENT	   : LINE_COMMENT | BLOCK_COMMENT ;
