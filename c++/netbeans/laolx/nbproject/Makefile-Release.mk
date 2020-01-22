#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/6102ff06/main.o \
	${OBJECTDIR}/_ext/d61aa193/Collection.o \
	${OBJECTDIR}/_ext/d61aa193/Expression.o \
	${OBJECTDIR}/_ext/d61aa193/ExpressionEle.o \
	${OBJECTDIR}/_ext/d61aa193/ExpressionList.o \
	${OBJECTDIR}/_ext/d61aa193/IdExpression.o \
	${OBJECTDIR}/_ext/d61aa193/ImportStmt.o \
	${OBJECTDIR}/_ext/d61aa193/LambdaExpression.o \
	${OBJECTDIR}/_ext/d61aa193/Literal.o \
	${OBJECTDIR}/_ext/d61aa193/MethodParameter.o \
	${OBJECTDIR}/_ext/d61aa193/Name.o \
	${OBJECTDIR}/_ext/d61aa193/NestedNameSpecifier.o \
	${OBJECTDIR}/_ext/d61aa193/Number.o \
	${OBJECTDIR}/_ext/d61aa193/OperatorFunctionId.o \
	${OBJECTDIR}/_ext/d61aa193/PostfixExpression.o \
	${OBJECTDIR}/_ext/d61aa193/PrimaryExpression.o \
	${OBJECTDIR}/_ext/d61aa193/ReturnSpecifier.o \
	${OBJECTDIR}/_ext/d61aa193/SimpleTypeSpecifier.o \
	${OBJECTDIR}/_ext/d61aa193/SourceFile.o \
	${OBJECTDIR}/_ext/d61aa193/Statement.o \
	${OBJECTDIR}/_ext/d61aa193/String.o \
	${OBJECTDIR}/_ext/d61aa193/Template.o \
	${OBJECTDIR}/_ext/d61aa193/Token.o \
	${OBJECTDIR}/_ext/d61aa193/UnaryExpression.o \
	${OBJECTDIR}/_ext/d61aa193/UnaryOp.o \
	${OBJECTDIR}/_ext/d61aa193/Words.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/laolx

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/laolx: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/laolx ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/6102ff06/main.o: ../../laolx/main.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/6102ff06
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6102ff06/main.o ../../laolx/main.cxx

${OBJECTDIR}/_ext/d61aa193/Collection.o: ../../src/laolx/parser/Collection.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/Collection.o ../../src/laolx/parser/Collection.cxx

${OBJECTDIR}/_ext/d61aa193/Expression.o: ../../src/laolx/parser/Expression.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/Expression.o ../../src/laolx/parser/Expression.cxx

${OBJECTDIR}/_ext/d61aa193/ExpressionEle.o: ../../src/laolx/parser/ExpressionEle.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/ExpressionEle.o ../../src/laolx/parser/ExpressionEle.cxx

${OBJECTDIR}/_ext/d61aa193/ExpressionList.o: ../../src/laolx/parser/ExpressionList.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/ExpressionList.o ../../src/laolx/parser/ExpressionList.cxx

${OBJECTDIR}/_ext/d61aa193/IdExpression.o: ../../src/laolx/parser/IdExpression.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/IdExpression.o ../../src/laolx/parser/IdExpression.cxx

${OBJECTDIR}/_ext/d61aa193/ImportStmt.o: ../../src/laolx/parser/ImportStmt.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/ImportStmt.o ../../src/laolx/parser/ImportStmt.cxx

${OBJECTDIR}/_ext/d61aa193/LambdaExpression.o: ../../src/laolx/parser/LambdaExpression.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/LambdaExpression.o ../../src/laolx/parser/LambdaExpression.cxx

${OBJECTDIR}/_ext/d61aa193/Literal.o: ../../src/laolx/parser/Literal.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/Literal.o ../../src/laolx/parser/Literal.cxx

${OBJECTDIR}/_ext/d61aa193/MethodParameter.o: ../../src/laolx/parser/MethodParameter.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/MethodParameter.o ../../src/laolx/parser/MethodParameter.cxx

${OBJECTDIR}/_ext/d61aa193/Name.o: ../../src/laolx/parser/Name.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/Name.o ../../src/laolx/parser/Name.cxx

${OBJECTDIR}/_ext/d61aa193/NestedNameSpecifier.o: ../../src/laolx/parser/NestedNameSpecifier.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/NestedNameSpecifier.o ../../src/laolx/parser/NestedNameSpecifier.cxx

${OBJECTDIR}/_ext/d61aa193/Number.o: ../../src/laolx/parser/Number.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/Number.o ../../src/laolx/parser/Number.cxx

${OBJECTDIR}/_ext/d61aa193/OperatorFunctionId.o: ../../src/laolx/parser/OperatorFunctionId.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/OperatorFunctionId.o ../../src/laolx/parser/OperatorFunctionId.cxx

${OBJECTDIR}/_ext/d61aa193/PostfixExpression.o: ../../src/laolx/parser/PostfixExpression.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/PostfixExpression.o ../../src/laolx/parser/PostfixExpression.cxx

${OBJECTDIR}/_ext/d61aa193/PrimaryExpression.o: ../../src/laolx/parser/PrimaryExpression.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/PrimaryExpression.o ../../src/laolx/parser/PrimaryExpression.cxx

${OBJECTDIR}/_ext/d61aa193/ReturnSpecifier.o: ../../src/laolx/parser/ReturnSpecifier.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/ReturnSpecifier.o ../../src/laolx/parser/ReturnSpecifier.cxx

${OBJECTDIR}/_ext/d61aa193/SimpleTypeSpecifier.o: ../../src/laolx/parser/SimpleTypeSpecifier.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/SimpleTypeSpecifier.o ../../src/laolx/parser/SimpleTypeSpecifier.cxx

${OBJECTDIR}/_ext/d61aa193/SourceFile.o: ../../src/laolx/parser/SourceFile.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/SourceFile.o ../../src/laolx/parser/SourceFile.cxx

${OBJECTDIR}/_ext/d61aa193/Statement.o: ../../src/laolx/parser/Statement.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/Statement.o ../../src/laolx/parser/Statement.cxx

${OBJECTDIR}/_ext/d61aa193/String.o: ../../src/laolx/parser/String.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/String.o ../../src/laolx/parser/String.cxx

${OBJECTDIR}/_ext/d61aa193/Template.o: ../../src/laolx/parser/Template.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/Template.o ../../src/laolx/parser/Template.cxx

${OBJECTDIR}/_ext/d61aa193/Token.o: ../../src/laolx/parser/Token.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/Token.o ../../src/laolx/parser/Token.cxx

${OBJECTDIR}/_ext/d61aa193/UnaryExpression.o: ../../src/laolx/parser/UnaryExpression.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/UnaryExpression.o ../../src/laolx/parser/UnaryExpression.cxx

${OBJECTDIR}/_ext/d61aa193/UnaryOp.o: ../../src/laolx/parser/UnaryOp.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/UnaryOp.o ../../src/laolx/parser/UnaryOp.cxx

${OBJECTDIR}/_ext/d61aa193/Words.o: ../../src/laolx/parser/Words.cxx
	${MKDIR} -p ${OBJECTDIR}/_ext/d61aa193
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d61aa193/Words.o ../../src/laolx/parser/Words.cxx

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
