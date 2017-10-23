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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ast/class_declaration.o \
	${OBJECTDIR}/ast/import_specifier.o \
	${OBJECTDIR}/ast/import_specifier_list.o \
	${OBJECTDIR}/ast/import_statement.o \
	${OBJECTDIR}/ast/linkage.o \
	${OBJECTDIR}/ast/method_declaration.o \
	${OBJECTDIR}/ast/mutability.o \
	${OBJECTDIR}/ast/namespace_declaration.o \
	${OBJECTDIR}/ast/namespace_declaration_name.o \
	${OBJECTDIR}/ast/namespace_name.o \
	${OBJECTDIR}/ast/string.o \
	${OBJECTDIR}/ast/typedef_declaration.o \
	${OBJECTDIR}/ast/variable_declaration.o \
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
	${TESTDIR}/tests/test1.o

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblaolxast.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblaolxast.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblaolxast.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblaolxast.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblaolxast.a

${OBJECTDIR}/ast/class_declaration.o: ast/class_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/class_declaration.o ast/class_declaration.cxx

${OBJECTDIR}/ast/import_specifier.o: ast/import_specifier.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/import_specifier.o ast/import_specifier.cxx

${OBJECTDIR}/ast/import_specifier_list.o: ast/import_specifier_list.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/import_specifier_list.o ast/import_specifier_list.cxx

${OBJECTDIR}/ast/import_statement.o: ast/import_statement.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/import_statement.o ast/import_statement.cxx

${OBJECTDIR}/ast/linkage.o: ast/linkage.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/linkage.o ast/linkage.cxx

${OBJECTDIR}/ast/method_declaration.o: ast/method_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/method_declaration.o ast/method_declaration.cxx

${OBJECTDIR}/ast/mutability.o: ast/mutability.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/mutability.o ast/mutability.cxx

${OBJECTDIR}/ast/namespace_declaration.o: ast/namespace_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/namespace_declaration.o ast/namespace_declaration.cxx

${OBJECTDIR}/ast/namespace_declaration_name.o: ast/namespace_declaration_name.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/namespace_declaration_name.o ast/namespace_declaration_name.cxx

${OBJECTDIR}/ast/namespace_name.o: ast/namespace_name.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/namespace_name.o ast/namespace_name.cxx

${OBJECTDIR}/ast/string.o: ast/string.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/string.o ast/string.cxx

${OBJECTDIR}/ast/typedef_declaration.o: ast/typedef_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/typedef_declaration.o ast/typedef_declaration.cxx

${OBJECTDIR}/ast/variable_declaration.o: ast/variable_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/variable_declaration.o ast/variable_declaration.cxx

${OBJECTDIR}/parser/astnode.o: parser/astnode.cxx
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/astnode.o parser/astnode.cxx

${OBJECTDIR}/parser/lexer.o: parser/lexer.cxx
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/lexer.o parser/lexer.cxx

${OBJECTDIR}/parser/parser.o: parser/parser.cxx
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/parser.o parser/parser.cxx

${OBJECTDIR}/parser/token.o: parser/token.cxx
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/token.o parser/token.cxx

# Subprojects
.build-subprojects:
	cd ../laolxcxx && ${MAKE}  -f Makefile CONF=Debug

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/test1.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   -L../laolxcxx/dist/Debug/CLang-MacOSX -llaolxcxx 


${TESTDIR}/tests/test1.o: tests/test1.cxx 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/test1.o tests/test1.cxx


${OBJECTDIR}/ast/class_declaration_nomain.o: ${OBJECTDIR}/ast/class_declaration.o ast/class_declaration.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/class_declaration.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/class_declaration_nomain.o ast/class_declaration.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/class_declaration.o ${OBJECTDIR}/ast/class_declaration_nomain.o;\
	fi

${OBJECTDIR}/ast/import_specifier_nomain.o: ${OBJECTDIR}/ast/import_specifier.o ast/import_specifier.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/import_specifier.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/import_specifier_nomain.o ast/import_specifier.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/import_specifier.o ${OBJECTDIR}/ast/import_specifier_nomain.o;\
	fi

${OBJECTDIR}/ast/import_specifier_list_nomain.o: ${OBJECTDIR}/ast/import_specifier_list.o ast/import_specifier_list.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/import_specifier_list.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/import_specifier_list_nomain.o ast/import_specifier_list.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/import_specifier_list.o ${OBJECTDIR}/ast/import_specifier_list_nomain.o;\
	fi

${OBJECTDIR}/ast/import_statement_nomain.o: ${OBJECTDIR}/ast/import_statement.o ast/import_statement.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/import_statement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/import_statement_nomain.o ast/import_statement.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/import_statement.o ${OBJECTDIR}/ast/import_statement_nomain.o;\
	fi

${OBJECTDIR}/ast/linkage_nomain.o: ${OBJECTDIR}/ast/linkage.o ast/linkage.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/linkage.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/linkage_nomain.o ast/linkage.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/linkage.o ${OBJECTDIR}/ast/linkage_nomain.o;\
	fi

${OBJECTDIR}/ast/method_declaration_nomain.o: ${OBJECTDIR}/ast/method_declaration.o ast/method_declaration.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/method_declaration.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/method_declaration_nomain.o ast/method_declaration.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/method_declaration.o ${OBJECTDIR}/ast/method_declaration_nomain.o;\
	fi

${OBJECTDIR}/ast/mutability_nomain.o: ${OBJECTDIR}/ast/mutability.o ast/mutability.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/mutability.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/mutability_nomain.o ast/mutability.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/mutability.o ${OBJECTDIR}/ast/mutability_nomain.o;\
	fi

${OBJECTDIR}/ast/namespace_declaration_nomain.o: ${OBJECTDIR}/ast/namespace_declaration.o ast/namespace_declaration.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/namespace_declaration.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/namespace_declaration_nomain.o ast/namespace_declaration.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/namespace_declaration.o ${OBJECTDIR}/ast/namespace_declaration_nomain.o;\
	fi

${OBJECTDIR}/ast/namespace_declaration_name_nomain.o: ${OBJECTDIR}/ast/namespace_declaration_name.o ast/namespace_declaration_name.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/namespace_declaration_name.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/namespace_declaration_name_nomain.o ast/namespace_declaration_name.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/namespace_declaration_name.o ${OBJECTDIR}/ast/namespace_declaration_name_nomain.o;\
	fi

${OBJECTDIR}/ast/namespace_name_nomain.o: ${OBJECTDIR}/ast/namespace_name.o ast/namespace_name.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/namespace_name.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/namespace_name_nomain.o ast/namespace_name.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/namespace_name.o ${OBJECTDIR}/ast/namespace_name_nomain.o;\
	fi

${OBJECTDIR}/ast/string_nomain.o: ${OBJECTDIR}/ast/string.o ast/string.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/string.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/string_nomain.o ast/string.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/string.o ${OBJECTDIR}/ast/string_nomain.o;\
	fi

${OBJECTDIR}/ast/typedef_declaration_nomain.o: ${OBJECTDIR}/ast/typedef_declaration.o ast/typedef_declaration.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/typedef_declaration.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/typedef_declaration_nomain.o ast/typedef_declaration.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/typedef_declaration.o ${OBJECTDIR}/ast/typedef_declaration_nomain.o;\
	fi

${OBJECTDIR}/ast/variable_declaration_nomain.o: ${OBJECTDIR}/ast/variable_declaration.o ast/variable_declaration.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/variable_declaration.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/variable_declaration_nomain.o ast/variable_declaration.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/variable_declaration.o ${OBJECTDIR}/ast/variable_declaration_nomain.o;\
	fi

${OBJECTDIR}/parser/astnode_nomain.o: ${OBJECTDIR}/parser/astnode.o parser/astnode.cxx 
	${MKDIR} -p ${OBJECTDIR}/parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parser/astnode.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/astnode_nomain.o parser/astnode.cxx;\
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
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/lexer_nomain.o parser/lexer.cxx;\
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
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/parser_nomain.o parser/parser.cxx;\
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
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parser/token_nomain.o parser/token.cxx;\
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
	cd ../laolxcxx && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
