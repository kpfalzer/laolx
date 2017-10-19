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
	${OBJECTDIR}/ast/access.o \
	${OBJECTDIR}/ast/assignment_expression.o \
	${OBJECTDIR}/ast/braced_init_list.o \
	${OBJECTDIR}/ast/class_declaration.o \
	${OBJECTDIR}/ast/conditional_expression.o \
	${OBJECTDIR}/ast/declaration.o \
	${OBJECTDIR}/ast/include_statement.o \
	${OBJECTDIR}/ast/initializer_clause.o \
	${OBJECTDIR}/ast/initializer_list.o \
	${OBJECTDIR}/ast/linkage.o \
	${OBJECTDIR}/ast/method_declaration.o \
	${OBJECTDIR}/ast/namespace_declaration.o \
	${OBJECTDIR}/ast/source_file.o \
	${OBJECTDIR}/ast/string.o \
	${OBJECTDIR}/ast/template_parameter.o \
	${OBJECTDIR}/ast/template_parameter_list.o \
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

${OBJECTDIR}/ast/access.o: ast/access.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/access.o ast/access.cxx

${OBJECTDIR}/ast/assignment_expression.o: ast/assignment_expression.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/assignment_expression.o ast/assignment_expression.cxx

${OBJECTDIR}/ast/braced_init_list.o: ast/braced_init_list.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/braced_init_list.o ast/braced_init_list.cxx

${OBJECTDIR}/ast/class_declaration.o: ast/class_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/class_declaration.o ast/class_declaration.cxx

${OBJECTDIR}/ast/conditional_expression.o: ast/conditional_expression.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/conditional_expression.o ast/conditional_expression.cxx

${OBJECTDIR}/ast/declaration.o: ast/declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/declaration.o ast/declaration.cxx

${OBJECTDIR}/ast/include_statement.o: ast/include_statement.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/include_statement.o ast/include_statement.cxx

${OBJECTDIR}/ast/initializer_clause.o: ast/initializer_clause.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/initializer_clause.o ast/initializer_clause.cxx

${OBJECTDIR}/ast/initializer_list.o: ast/initializer_list.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/initializer_list.o ast/initializer_list.cxx

${OBJECTDIR}/ast/linkage.o: ast/linkage.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/linkage.o ast/linkage.cxx

${OBJECTDIR}/ast/method_declaration.o: ast/method_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/method_declaration.o ast/method_declaration.cxx

${OBJECTDIR}/ast/namespace_declaration.o: ast/namespace_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/namespace_declaration.o ast/namespace_declaration.cxx

${OBJECTDIR}/ast/source_file.o: ast/source_file.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/source_file.o ast/source_file.cxx

${OBJECTDIR}/ast/string.o: ast/string.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/string.o ast/string.cxx

${OBJECTDIR}/ast/template_parameter.o: ast/template_parameter.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/template_parameter.o ast/template_parameter.cxx

${OBJECTDIR}/ast/template_parameter_list.o: ast/template_parameter_list.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/template_parameter_list.o ast/template_parameter_list.cxx

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


${OBJECTDIR}/ast/access_nomain.o: ${OBJECTDIR}/ast/access.o ast/access.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/access.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/access_nomain.o ast/access.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/access.o ${OBJECTDIR}/ast/access_nomain.o;\
	fi

${OBJECTDIR}/ast/assignment_expression_nomain.o: ${OBJECTDIR}/ast/assignment_expression.o ast/assignment_expression.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/assignment_expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/assignment_expression_nomain.o ast/assignment_expression.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/assignment_expression.o ${OBJECTDIR}/ast/assignment_expression_nomain.o;\
	fi

${OBJECTDIR}/ast/braced_init_list_nomain.o: ${OBJECTDIR}/ast/braced_init_list.o ast/braced_init_list.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/braced_init_list.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/braced_init_list_nomain.o ast/braced_init_list.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/braced_init_list.o ${OBJECTDIR}/ast/braced_init_list_nomain.o;\
	fi

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

${OBJECTDIR}/ast/conditional_expression_nomain.o: ${OBJECTDIR}/ast/conditional_expression.o ast/conditional_expression.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/conditional_expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/conditional_expression_nomain.o ast/conditional_expression.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/conditional_expression.o ${OBJECTDIR}/ast/conditional_expression_nomain.o;\
	fi

${OBJECTDIR}/ast/declaration_nomain.o: ${OBJECTDIR}/ast/declaration.o ast/declaration.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/declaration.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/declaration_nomain.o ast/declaration.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/declaration.o ${OBJECTDIR}/ast/declaration_nomain.o;\
	fi

${OBJECTDIR}/ast/include_statement_nomain.o: ${OBJECTDIR}/ast/include_statement.o ast/include_statement.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/include_statement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/include_statement_nomain.o ast/include_statement.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/include_statement.o ${OBJECTDIR}/ast/include_statement_nomain.o;\
	fi

${OBJECTDIR}/ast/initializer_clause_nomain.o: ${OBJECTDIR}/ast/initializer_clause.o ast/initializer_clause.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/initializer_clause.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/initializer_clause_nomain.o ast/initializer_clause.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/initializer_clause.o ${OBJECTDIR}/ast/initializer_clause_nomain.o;\
	fi

${OBJECTDIR}/ast/initializer_list_nomain.o: ${OBJECTDIR}/ast/initializer_list.o ast/initializer_list.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/initializer_list.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/initializer_list_nomain.o ast/initializer_list.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/initializer_list.o ${OBJECTDIR}/ast/initializer_list_nomain.o;\
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

${OBJECTDIR}/ast/source_file_nomain.o: ${OBJECTDIR}/ast/source_file.o ast/source_file.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/source_file.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/source_file_nomain.o ast/source_file.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/source_file.o ${OBJECTDIR}/ast/source_file_nomain.o;\
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

${OBJECTDIR}/ast/template_parameter_nomain.o: ${OBJECTDIR}/ast/template_parameter.o ast/template_parameter.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/template_parameter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/template_parameter_nomain.o ast/template_parameter.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/template_parameter.o ${OBJECTDIR}/ast/template_parameter_nomain.o;\
	fi

${OBJECTDIR}/ast/template_parameter_list_nomain.o: ${OBJECTDIR}/ast/template_parameter_list.o ast/template_parameter_list.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/template_parameter_list.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/template_parameter_list_nomain.o ast/template_parameter_list.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/template_parameter_list.o ${OBJECTDIR}/ast/template_parameter_list_nomain.o;\
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
