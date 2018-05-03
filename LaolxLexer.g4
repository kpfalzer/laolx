lexer grammar LaolxLexer;

channels { SemiNlChan, CommentChan}

// Lexer definition
//
AS			: 'as' 			 ;
BOOL		: 'bool'		 ;
BREAK		: 'break'		 ;
CASE		: 'case'		 ;
CATCH		: 'catch'  		 ;
CHAR		: 'char'		 ;
CLASS		: 'class'		 ;
CONST		: 'const'		 ;
DEF			: 'def'			 ;
DEFAULT		: 'default'		 ;
DO			: 'do'			 ;
ELSE		: 'else'		 ;
ELSIF		: 'elsif'		 ;
FALSE		: 'false'		 ;
FLOAT		: 'float'		 ;
FOR			: 'for'			 ;
IF			: 'if'			 ;
IMPORT		: 'import' 		 ;
IN		    : 'in'   		 ;
INT			: 'int'			 ;
INTERFACE	: 'interface'	 ;
LAMBDA      : 'lambda'       ;
NAMESPACE	: 'namespace'	 ;
NEW			: 'new'			 ;
NIL			: 'nil'			 ;
OPERATOR	: 'operator'	 ;
PRIVATE		: 'private'		 ;
PROTECTED	: 'protected'	 ;
PUBLIC		: 'public'		 ;
REGEXPK     : 'regexp'       ;
RETURN  	: 'return'		 ;
STATIC		: 'static'		 ;
STRING		: 'string'		 ;
SYMBOL		: 'symbol'		 ;
THIS		: 'this'		 ;
THROW   	: 'throw'		 ;
TRUE		: 'true'		 ;
TRY			: 'try'			 ;
TYPEDEF		: 'typedef'		 ;
UNLESS		: 'unless'		 ;
UNTIL		: 'until'		 ;
VAR			: 'var'			 ;
VOID        : 'void'         ;
WHEN		: 'when'		 ;
WHILE		: 'while'		 ;

AND		: '&'  ;
RARROW  : '->' ;
AT		: '@'  ;
CARET	: '^'  ;
COLON	: ':'  ;
COLON2	: '::'  ;
COMMA	: ','  ;
DOT		: '.'  ;
EQ		: '='  ;
EXCL	: '!'  ;
GT		: '>'  ;
LBRACK	: '['  ;
LCURLY	: '{'  ;
LPAREN	: '('  ;
LT		: '<'  ;
MINUS	: '-'  ;
OR		: '|'  ;
PCNT	: '%'  ;
PLUS	: '+'  ;
QMARK	: '?'  ;
RBRACK	: ']'  ;
RCURLY	: '}'  ;
RPAREN	: ')'  ;
SEMI	: ';'  -> channel(SemiNlChan);
SLASH	: '/'  ;
STAR	: '*'  ;
WORDS   : '%w{' ;
SYMBOLS : '%s{' ;
TUPLE   : '%t{' ;

SQSTRING :	'\'' (ESC | ~['])? '\''  ;
DQSTRING :	'"' (ESC | ~["])* '"'  ;
IDENT 	 :	ID_LETTER (ID_LETTER | DIGIT)*  ;

REGEXP   : '%r{' (ESC | ~[{])* '}' [i]? ;

//
// Number values
//
VINTEGER: INTFRAG  ;
fragment INTFRAG: [0-9][0-9_]* ;
VHEX    : '0x' [0-9a-fA-F][0-9_a-fA-F]*  ;
VFLOAT  : INTFRAG '.' INTFRAG ([eE][-+]? INTFRAG)? ;
VSIZED  : INTFRAG '\'' [bBhHoOdD][0-9a-fA-F][0-9a-fA-F_]*  ;

fragment ESC :	'\\' .  ;

fragment
ID_LETTER
:	'a'..'z'
|	'A'..'Z'
| 	'_'
;

fragment DIGIT : '0'..'9' ;

WS            : [ \t]+ -> skip;
EOLN          : ('\r'? '\n')+  -> channel(SemiNlChan) ;
BLOCK_COMMENT : '/*' .*? '*/'  -> channel(CommentChan);
LINE_COMMENT  : '//' ~[\r\n]*  -> channel(CommentChan);
