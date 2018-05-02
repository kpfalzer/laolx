
ANTLR_CMD := antlr4
ANTLR_DIR  := src/laolx/parser

ANTLR_ARGS := -package laolx.parser
ANTLR_ARGS += -o ${ANTLR_DIR}

${ANTLR_DIR}/LaolxLexer.java: Laolx.g4
	${ANTLR_CMD} ${ANTLR_ARGS} ${<}

.PHONY: clean
clean:
	-rm -f ${ANTLR_DIR}/LaolxLexer.java
