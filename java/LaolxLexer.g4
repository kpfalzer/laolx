lexer grammar LaolxLexer;

channels { SemiNlChan, CommentChan}

AS			: 'as' 			;
BOOL		: 'bool'		;
BREAK		: 'break'		;
CASE		: 'case'		;
CATCH		: 'catch'  		;
CHAR		: 'char'		;
CLASS		: 'class'		;
CONST		: 'const'		;
DEF			: 'def'			;
DEFAULT		: 'default'		;
DO			: 'do'			;
ELSE		: 'else'		;
ELSIF		: 'elsif'		;
FALSE		: 'false'		;
FLOAT		: 'float'		;
FOR			: 'for'			;
IF			: 'if'			;
IMPORT		: 'import' 		;
INT			: 'int'			;
INTERFACE	: 'interface'	;
NAMESPACE	: 'namespace'	;
NEW			: 'new'			;
NIL			: 'nil'			;
OPERATOR	: 'operator'	;
PRIVATE		: 'private'		;
PROTECTED	: 'protected'	;
PUBLIC		: 'public'		;
RETURN  	: 'return'		;
STATIC		: 'static'		;
STRING		: 'string'		;
SYMBOL		: 'symbol'		;
THIS		: 'this'		;
THROW   	: 'throw'		;
TRUE		: 'true'		;
TRY			: 'try'			;
TYPEDEF		: 'typedef'		;
UNLESS		: 'unless'		;
UNTIL		: 'until'		;
VAR			: 'var'			;
WHEN		: 'when'		;
WHILE		: 'while'		;

EXCL	: '!' ;
AT		: '@' ;
PCNT	: '%' ;
CARET	: '^' ;
AND		: '&' ;
STAR	: '*' ;
LPAREN	: '(' ;
RPAREN	: ')' ;
MINUS	: '-' ;
PLUS	: '+' ;
EQ		: '=' ;
LCURLY	: '{' ;
RCURLY	: '}' ;
LBRACK	: '[' ;
RBRACK	: ']' ;
LT		: '<' ;
GT		: '>' ;
SLASH	: '/' ;
QMARK	: '?' ;
OR		: '|' ;
COLON	: ':' ;
SEMI	: ';' -> channel(SemiNlChan) ;
DOT		: '.' ;
COMMA	: ',' ;

SQSTRING
:	'\'' (ESC | ~['])? '\''
;

DQSTRING
:	'"' (ESC | ~["])* '"'
;

ID
:	ID_LETTER (ID_LETTER | DIGIT)* 
;

fragment
ESC
:	'\\' .
;

fragment
ID_LETTER
:	'a'..'z'
|	'A'..'Z'
| 	'_'
;

fragment
DIGIT
:	'0'..'9'
;

WS
:
    [ \t]+ -> skip
;

NL
:
    ('\r'? '\n')+ -> channel(SemiNlChan)
;

COMMENT
:
    '/*' .*? '*/' -> channel(CommentChan)
;

LINE_COMMENT
:
    '//' ~[\r\n]* -> channel(CommentChan)
;


