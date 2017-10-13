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
	${OBJECTDIR}/ast/access.o \
	${OBJECTDIR}/ast/actual_declaration.o \
	${OBJECTDIR}/ast/actual_type_parameters.o \
	${OBJECTDIR}/ast/array_type_modifier.o \
	${OBJECTDIR}/ast/base_name.o \
	${OBJECTDIR}/ast/class_body.o \
	${OBJECTDIR}/ast/class_declaration.o \
	${OBJECTDIR}/ast/declaration.o \
	${OBJECTDIR}/ast/extends_declaration.o \
	${OBJECTDIR}/ast/implements_declaration.o \
	${OBJECTDIR}/ast/include_statement.o \
	${OBJECTDIR}/ast/interface_declaration.o \
	${OBJECTDIR}/ast/linkage.o \
	${OBJECTDIR}/ast/method_declaration.o \
	${OBJECTDIR}/ast/mutability.o \
	${OBJECTDIR}/ast/namespace_declaration.o \
	${OBJECTDIR}/ast/parameter_declaration.o \
	${OBJECTDIR}/ast/parameter_declaration_list.o \
	${OBJECTDIR}/ast/parameter_name.o \
	${OBJECTDIR}/ast/primitive_type.o \
	${OBJECTDIR}/ast/scope_name.o \
	${OBJECTDIR}/ast/scoped_type.o \
	${OBJECTDIR}/ast/simple_type.o \
	${OBJECTDIR}/ast/source_file.o \
	${OBJECTDIR}/ast/statement.o \
	${OBJECTDIR}/ast/string.o \
	${OBJECTDIR}/ast/type.o \
	${OBJECTDIR}/ast/type_modifier.o \
	${OBJECTDIR}/ast/type_name.o \
	${OBJECTDIR}/ast/type_parameters.o \
	${OBJECTDIR}/ast/typedef_declaration.o \
	${OBJECTDIR}/ast/union_type.o \
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

${OBJECTDIR}/ast/actual_declaration.o: ast/actual_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/actual_declaration.o ast/actual_declaration.cxx

${OBJECTDIR}/ast/actual_type_parameters.o: ast/actual_type_parameters.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/actual_type_parameters.o ast/actual_type_parameters.cxx

${OBJECTDIR}/ast/array_type_modifier.o: ast/array_type_modifier.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/array_type_modifier.o ast/array_type_modifier.cxx

${OBJECTDIR}/ast/base_name.o: ast/base_name.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_name.o ast/base_name.cxx

${OBJECTDIR}/ast/class_body.o: ast/class_body.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/class_body.o ast/class_body.cxx

${OBJECTDIR}/ast/class_declaration.o: ast/class_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/class_declaration.o ast/class_declaration.cxx

${OBJECTDIR}/ast/declaration.o: ast/declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/declaration.o ast/declaration.cxx

${OBJECTDIR}/ast/extends_declaration.o: ast/extends_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/extends_declaration.o ast/extends_declaration.cxx

${OBJECTDIR}/ast/implements_declaration.o: ast/implements_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/implements_declaration.o ast/implements_declaration.cxx

${OBJECTDIR}/ast/include_statement.o: ast/include_statement.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/include_statement.o ast/include_statement.cxx

${OBJECTDIR}/ast/interface_declaration.o: ast/interface_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/interface_declaration.o ast/interface_declaration.cxx

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

${OBJECTDIR}/ast/parameter_declaration.o: ast/parameter_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/parameter_declaration.o ast/parameter_declaration.cxx

${OBJECTDIR}/ast/parameter_declaration_list.o: ast/parameter_declaration_list.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/parameter_declaration_list.o ast/parameter_declaration_list.cxx

${OBJECTDIR}/ast/parameter_name.o: ast/parameter_name.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/parameter_name.o ast/parameter_name.cxx

${OBJECTDIR}/ast/primitive_type.o: ast/primitive_type.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/primitive_type.o ast/primitive_type.cxx

${OBJECTDIR}/ast/scope_name.o: ast/scope_name.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/scope_name.o ast/scope_name.cxx

${OBJECTDIR}/ast/scoped_type.o: ast/scoped_type.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/scoped_type.o ast/scoped_type.cxx

${OBJECTDIR}/ast/simple_type.o: ast/simple_type.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/simple_type.o ast/simple_type.cxx

${OBJECTDIR}/ast/source_file.o: ast/source_file.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/source_file.o ast/source_file.cxx

${OBJECTDIR}/ast/statement.o: ast/statement.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/statement.o ast/statement.cxx

${OBJECTDIR}/ast/string.o: ast/string.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/string.o ast/string.cxx

${OBJECTDIR}/ast/type.o: ast/type.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/type.o ast/type.cxx

${OBJECTDIR}/ast/type_modifier.o: ast/type_modifier.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/type_modifier.o ast/type_modifier.cxx

${OBJECTDIR}/ast/type_name.o: ast/type_name.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/type_name.o ast/type_name.cxx

${OBJECTDIR}/ast/type_parameters.o: ast/type_parameters.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/type_parameters.o ast/type_parameters.cxx

${OBJECTDIR}/ast/typedef_declaration.o: ast/typedef_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/typedef_declaration.o ast/typedef_declaration.cxx

${OBJECTDIR}/ast/union_type.o: ast/union_type.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/union_type.o ast/union_type.cxx

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
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


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

${OBJECTDIR}/ast/actual_declaration_nomain.o: ${OBJECTDIR}/ast/actual_declaration.o ast/actual_declaration.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/actual_declaration.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/actual_declaration_nomain.o ast/actual_declaration.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/actual_declaration.o ${OBJECTDIR}/ast/actual_declaration_nomain.o;\
	fi

${OBJECTDIR}/ast/actual_type_parameters_nomain.o: ${OBJECTDIR}/ast/actual_type_parameters.o ast/actual_type_parameters.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/actual_type_parameters.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/actual_type_parameters_nomain.o ast/actual_type_parameters.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/actual_type_parameters.o ${OBJECTDIR}/ast/actual_type_parameters_nomain.o;\
	fi

${OBJECTDIR}/ast/array_type_modifier_nomain.o: ${OBJECTDIR}/ast/array_type_modifier.o ast/array_type_modifier.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/array_type_modifier.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/array_type_modifier_nomain.o ast/array_type_modifier.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/array_type_modifier.o ${OBJECTDIR}/ast/array_type_modifier_nomain.o;\
	fi

${OBJECTDIR}/ast/base_name_nomain.o: ${OBJECTDIR}/ast/base_name.o ast/base_name.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/base_name.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_name_nomain.o ast/base_name.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/base_name.o ${OBJECTDIR}/ast/base_name_nomain.o;\
	fi

${OBJECTDIR}/ast/class_body_nomain.o: ${OBJECTDIR}/ast/class_body.o ast/class_body.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/class_body.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/class_body_nomain.o ast/class_body.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/class_body.o ${OBJECTDIR}/ast/class_body_nomain.o;\
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

${OBJECTDIR}/ast/extends_declaration_nomain.o: ${OBJECTDIR}/ast/extends_declaration.o ast/extends_declaration.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/extends_declaration.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/extends_declaration_nomain.o ast/extends_declaration.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/extends_declaration.o ${OBJECTDIR}/ast/extends_declaration_nomain.o;\
	fi

${OBJECTDIR}/ast/implements_declaration_nomain.o: ${OBJECTDIR}/ast/implements_declaration.o ast/implements_declaration.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/implements_declaration.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/implements_declaration_nomain.o ast/implements_declaration.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/implements_declaration.o ${OBJECTDIR}/ast/implements_declaration_nomain.o;\
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

${OBJECTDIR}/ast/interface_declaration_nomain.o: ${OBJECTDIR}/ast/interface_declaration.o ast/interface_declaration.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/interface_declaration.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/interface_declaration_nomain.o ast/interface_declaration.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/interface_declaration.o ${OBJECTDIR}/ast/interface_declaration_nomain.o;\
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

${OBJECTDIR}/ast/parameter_declaration_nomain.o: ${OBJECTDIR}/ast/parameter_declaration.o ast/parameter_declaration.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/parameter_declaration.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/parameter_declaration_nomain.o ast/parameter_declaration.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/parameter_declaration.o ${OBJECTDIR}/ast/parameter_declaration_nomain.o;\
	fi

${OBJECTDIR}/ast/parameter_declaration_list_nomain.o: ${OBJECTDIR}/ast/parameter_declaration_list.o ast/parameter_declaration_list.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/parameter_declaration_list.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/parameter_declaration_list_nomain.o ast/parameter_declaration_list.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/parameter_declaration_list.o ${OBJECTDIR}/ast/parameter_declaration_list_nomain.o;\
	fi

${OBJECTDIR}/ast/parameter_name_nomain.o: ${OBJECTDIR}/ast/parameter_name.o ast/parameter_name.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/parameter_name.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/parameter_name_nomain.o ast/parameter_name.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/parameter_name.o ${OBJECTDIR}/ast/parameter_name_nomain.o;\
	fi

${OBJECTDIR}/ast/primitive_type_nomain.o: ${OBJECTDIR}/ast/primitive_type.o ast/primitive_type.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/primitive_type.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/primitive_type_nomain.o ast/primitive_type.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/primitive_type.o ${OBJECTDIR}/ast/primitive_type_nomain.o;\
	fi

${OBJECTDIR}/ast/scope_name_nomain.o: ${OBJECTDIR}/ast/scope_name.o ast/scope_name.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/scope_name.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/scope_name_nomain.o ast/scope_name.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/scope_name.o ${OBJECTDIR}/ast/scope_name_nomain.o;\
	fi

${OBJECTDIR}/ast/scoped_type_nomain.o: ${OBJECTDIR}/ast/scoped_type.o ast/scoped_type.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/scoped_type.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/scoped_type_nomain.o ast/scoped_type.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/scoped_type.o ${OBJECTDIR}/ast/scoped_type_nomain.o;\
	fi

${OBJECTDIR}/ast/simple_type_nomain.o: ${OBJECTDIR}/ast/simple_type.o ast/simple_type.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/simple_type.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/simple_type_nomain.o ast/simple_type.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/simple_type.o ${OBJECTDIR}/ast/simple_type_nomain.o;\
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

${OBJECTDIR}/ast/statement_nomain.o: ${OBJECTDIR}/ast/statement.o ast/statement.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/statement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/statement_nomain.o ast/statement.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/statement.o ${OBJECTDIR}/ast/statement_nomain.o;\
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

${OBJECTDIR}/ast/type_nomain.o: ${OBJECTDIR}/ast/type.o ast/type.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/type.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/type_nomain.o ast/type.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/type.o ${OBJECTDIR}/ast/type_nomain.o;\
	fi

${OBJECTDIR}/ast/type_modifier_nomain.o: ${OBJECTDIR}/ast/type_modifier.o ast/type_modifier.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/type_modifier.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/type_modifier_nomain.o ast/type_modifier.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/type_modifier.o ${OBJECTDIR}/ast/type_modifier_nomain.o;\
	fi

${OBJECTDIR}/ast/type_name_nomain.o: ${OBJECTDIR}/ast/type_name.o ast/type_name.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/type_name.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/type_name_nomain.o ast/type_name.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/type_name.o ${OBJECTDIR}/ast/type_name_nomain.o;\
	fi

${OBJECTDIR}/ast/type_parameters_nomain.o: ${OBJECTDIR}/ast/type_parameters.o ast/type_parameters.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/type_parameters.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/type_parameters_nomain.o ast/type_parameters.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/type_parameters.o ${OBJECTDIR}/ast/type_parameters_nomain.o;\
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

${OBJECTDIR}/ast/union_type_nomain.o: ${OBJECTDIR}/ast/union_type.o ast/union_type.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/union_type.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/union_type_nomain.o ast/union_type.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/union_type.o ${OBJECTDIR}/ast/union_type_nomain.o;\
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
