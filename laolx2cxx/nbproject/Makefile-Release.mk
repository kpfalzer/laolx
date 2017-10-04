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
CC=clang
CCC=clang++
CXX=clang++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=CLang-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ast/string.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/parser/astnode.o \
	${OBJECTDIR}/parser/lexer.o \
	${OBJECTDIR}/parser/parser.o \
	${OBJECTDIR}/parser/token.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/parser_test.o

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/laolx2cxx

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/laolx2cxx: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/laolx2cxx ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/ast/string.o: ast/string.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I../laolxcxx -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/string.o ast/string.cxx

${OBJECTDIR}/main.o: main.cxx
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I../laolxcxx -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cxx

${OBJECTDIR}/parser/astnode.o: parser/astnode.cxx
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I../laolxcxx -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/astnode.o parser/astnode.cxx

${OBJECTDIR}/parser/lexer.o: parser/lexer.cxx
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I../laolxcxx -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/lexer.o parser/lexer.cxx

${OBJECTDIR}/parser/parser.o: parser/parser.cxx
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I../laolxcxx -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/parser.o parser/parser.cxx

${OBJECTDIR}/parser/token.o: parser/token.cxx
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I../laolxcxx -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/token.o parser/token.cxx

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/parser_test.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/parser_test.o: tests/parser_test.cxx 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I../laolxcxx -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/parser_test.o tests/parser_test.cxx


${OBJECTDIR}/ast/string_nomain.o: ${OBJECTDIR}/ast/string.o ast/string.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/string.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I../laolxcxx -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/string_nomain.o ast/string.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/string.o ${OBJECTDIR}/ast/string_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cxx 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I../laolxcxx -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/parser/astnode_nomain.o: ${OBJECTDIR}/parser/astnode.o parser/astnode.cxx 
	${MKDIR} -p ${OBJECTDIR}/parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parser/astnode.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I../laolxcxx -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/astnode_nomain.o parser/astnode.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/parser/astnode.o ${OBJECTDIR}/parser/astnode_nomain.o;\
	fi

${OBJECTDIR}/parser/lexer_nomain.o: ${OBJECTDIR}/parser/lexer.o parser/lexer.cxx 
	${MKDIR} -p ${OBJECTDIR}/parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parser/lexer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I../laolxcxx -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/lexer_nomain.o parser/lexer.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/parser/lexer.o ${OBJECTDIR}/parser/lexer_nomain.o;\
	fi

${OBJECTDIR}/parser/parser_nomain.o: ${OBJECTDIR}/parser/parser.o parser/parser.cxx 
	${MKDIR} -p ${OBJECTDIR}/parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parser/parser.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I../laolxcxx -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/parser_nomain.o parser/parser.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/parser/parser.o ${OBJECTDIR}/parser/parser_nomain.o;\
	fi

${OBJECTDIR}/parser/token_nomain.o: ${OBJECTDIR}/parser/token.o parser/token.cxx 
	${MKDIR} -p ${OBJECTDIR}/parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parser/token.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I../laolxcxx -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/token_nomain.o parser/token.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/parser/token.o ${OBJECTDIR}/parser/token_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
