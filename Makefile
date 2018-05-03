
ANTLR_CMD := antlr4
ANTLR_DIR  := src/laolx/parser

ANTLR_ARGS := -package laolx.parser
ANTLR_ARGS += -o ${ANTLR_DIR}
ANTLR_ARGS += -no-listener -no-visitor

ANTLR_DEPS := LaolxLexer.g4 LaolxParser.g4

.PHONY: goal

goal: ${ANTLR_DIR}/LaolxLexer.java

${ANTLR_DIR}/LaolxLexer.java: ${ANTLR_DEPS}
	${ANTLR_CMD} ${ANTLR_ARGS} ${ANTLR_DEPS}

.PHONY: clean
clean:
	-rm -f ${ANTLR_DIR}/*
