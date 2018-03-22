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
	${OBJECTDIR}/ast/array_specifier.o \
	${OBJECTDIR}/ast/assignment_expression.o \
	${OBJECTDIR}/ast/base_clause.o \
	${OBJECTDIR}/ast/base_initializer.o \
	${OBJECTDIR}/ast/base_initializer_list.o \
	${OBJECTDIR}/ast/base_initializer_specifier.o \
	${OBJECTDIR}/ast/base_name.o \
	${OBJECTDIR}/ast/base_specifier.o \
	${OBJECTDIR}/ast/base_specifier_list.o \
	${OBJECTDIR}/ast/base_type_specifier.o \
	${OBJECTDIR}/ast/binary_op.o \
	${OBJECTDIR}/ast/bool.o \
	${OBJECTDIR}/ast/braced_init_list.o \
	${OBJECTDIR}/ast/case_statement.o \
	${OBJECTDIR}/ast/catch_statement.o \
	${OBJECTDIR}/ast/class_body.o \
	${OBJECTDIR}/ast/class_declaration.o \
	${OBJECTDIR}/ast/common.o \
	${OBJECTDIR}/ast/compound_statement.o \
	${OBJECTDIR}/ast/condition.o \
	${OBJECTDIR}/ast/conditional_expression.o \
	${OBJECTDIR}/ast/constant_expression.o \
	${OBJECTDIR}/ast/declaration.o \
	${OBJECTDIR}/ast/expression.o \
	${OBJECTDIR}/ast/expression_ele.o \
	${OBJECTDIR}/ast/expression_list.o \
	${OBJECTDIR}/ast/finally_statement.o \
	${OBJECTDIR}/ast/for_statement.o \
	${OBJECTDIR}/ast/id_expression.o \
	${OBJECTDIR}/ast/if_statement.o \
	${OBJECTDIR}/ast/import_specifier.o \
	${OBJECTDIR}/ast/import_specifier_list.o \
	${OBJECTDIR}/ast/import_statement.o \
	${OBJECTDIR}/ast/initializer_clause.o \
	${OBJECTDIR}/ast/initializer_list.o \
	${OBJECTDIR}/ast/interface_declaration.o \
	${OBJECTDIR}/ast/iteration_statement.o \
	${OBJECTDIR}/ast/jump_statement.o \
	${OBJECTDIR}/ast/lambda_expression.o \
	${OBJECTDIR}/ast/linkage.o \
	${OBJECTDIR}/ast/literal.o \
	${OBJECTDIR}/ast/member_variable_declaration.o \
	${OBJECTDIR}/ast/method_body.o \
	${OBJECTDIR}/ast/method_body_item.o \
	${OBJECTDIR}/ast/method_declaration.o \
	${OBJECTDIR}/ast/method_parameter.o \
	${OBJECTDIR}/ast/method_parameter_list.o \
	${OBJECTDIR}/ast/method_parameters_declaration.o \
	${OBJECTDIR}/ast/mutability.o \
	${OBJECTDIR}/ast/name.o \
	${OBJECTDIR}/ast/namespace_declaration.o \
	${OBJECTDIR}/ast/namespace_declaration_name.o \
	${OBJECTDIR}/ast/nested_name_specifier.o \
	${OBJECTDIR}/ast/operator_function_id.o \
	${OBJECTDIR}/ast/overloadable_operator.o \
	${OBJECTDIR}/ast/postfix_expression.o \
	${OBJECTDIR}/ast/primary_expression.o \
	${OBJECTDIR}/ast/qualified_id.o \
	${OBJECTDIR}/ast/return_specifier.o \
	${OBJECTDIR}/ast/simple_template_id.o \
	${OBJECTDIR}/ast/simple_type_specifier.o \
	${OBJECTDIR}/ast/source_file.o \
	${OBJECTDIR}/ast/statement.o \
	${OBJECTDIR}/ast/string.o \
	${OBJECTDIR}/ast/symbols.o \
	${OBJECTDIR}/ast/template_argument.o \
	${OBJECTDIR}/ast/template_argument_list.o \
	${OBJECTDIR}/ast/template_id.o \
	${OBJECTDIR}/ast/template_parameter.o \
	${OBJECTDIR}/ast/template_parameter_list.o \
	${OBJECTDIR}/ast/try_statement.o \
	${OBJECTDIR}/ast/typedef_declaration.o \
	${OBJECTDIR}/ast/unary_expression.o \
	${OBJECTDIR}/ast/unary_operator.o \
	${OBJECTDIR}/ast/unqualified_id.o \
	${OBJECTDIR}/ast/var_or_attr_name.o \
	${OBJECTDIR}/ast/variable_declaration.o \
	${OBJECTDIR}/ast/words.o \
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

${OBJECTDIR}/ast/array_specifier.o: ast/array_specifier.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/array_specifier.o ast/array_specifier.cxx

${OBJECTDIR}/ast/assignment_expression.o: ast/assignment_expression.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/assignment_expression.o ast/assignment_expression.cxx

${OBJECTDIR}/ast/base_clause.o: ast/base_clause.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_clause.o ast/base_clause.cxx

${OBJECTDIR}/ast/base_initializer.o: ast/base_initializer.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_initializer.o ast/base_initializer.cxx

${OBJECTDIR}/ast/base_initializer_list.o: ast/base_initializer_list.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_initializer_list.o ast/base_initializer_list.cxx

${OBJECTDIR}/ast/base_initializer_specifier.o: ast/base_initializer_specifier.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_initializer_specifier.o ast/base_initializer_specifier.cxx

${OBJECTDIR}/ast/base_name.o: ast/base_name.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_name.o ast/base_name.cxx

${OBJECTDIR}/ast/base_specifier.o: ast/base_specifier.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_specifier.o ast/base_specifier.cxx

${OBJECTDIR}/ast/base_specifier_list.o: ast/base_specifier_list.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_specifier_list.o ast/base_specifier_list.cxx

${OBJECTDIR}/ast/base_type_specifier.o: ast/base_type_specifier.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_type_specifier.o ast/base_type_specifier.cxx

${OBJECTDIR}/ast/binary_op.o: ast/binary_op.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/binary_op.o ast/binary_op.cxx

${OBJECTDIR}/ast/bool.o: ast/bool.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/bool.o ast/bool.cxx

${OBJECTDIR}/ast/braced_init_list.o: ast/braced_init_list.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/braced_init_list.o ast/braced_init_list.cxx

${OBJECTDIR}/ast/case_statement.o: ast/case_statement.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/case_statement.o ast/case_statement.cxx

${OBJECTDIR}/ast/catch_statement.o: ast/catch_statement.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/catch_statement.o ast/catch_statement.cxx

${OBJECTDIR}/ast/class_body.o: ast/class_body.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/class_body.o ast/class_body.cxx

${OBJECTDIR}/ast/class_declaration.o: ast/class_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/class_declaration.o ast/class_declaration.cxx

${OBJECTDIR}/ast/common.o: ast/common.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/common.o ast/common.cxx

${OBJECTDIR}/ast/compound_statement.o: ast/compound_statement.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/compound_statement.o ast/compound_statement.cxx

${OBJECTDIR}/ast/condition.o: ast/condition.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/condition.o ast/condition.cxx

${OBJECTDIR}/ast/conditional_expression.o: ast/conditional_expression.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/conditional_expression.o ast/conditional_expression.cxx

${OBJECTDIR}/ast/constant_expression.o: ast/constant_expression.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/constant_expression.o ast/constant_expression.cxx

${OBJECTDIR}/ast/declaration.o: ast/declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/declaration.o ast/declaration.cxx

${OBJECTDIR}/ast/expression.o: ast/expression.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/expression.o ast/expression.cxx

${OBJECTDIR}/ast/expression_ele.o: ast/expression_ele.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/expression_ele.o ast/expression_ele.cxx

${OBJECTDIR}/ast/expression_list.o: ast/expression_list.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/expression_list.o ast/expression_list.cxx

${OBJECTDIR}/ast/finally_statement.o: ast/finally_statement.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/finally_statement.o ast/finally_statement.cxx

${OBJECTDIR}/ast/for_statement.o: ast/for_statement.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/for_statement.o ast/for_statement.cxx

${OBJECTDIR}/ast/id_expression.o: ast/id_expression.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/id_expression.o ast/id_expression.cxx

${OBJECTDIR}/ast/if_statement.o: ast/if_statement.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/if_statement.o ast/if_statement.cxx

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

${OBJECTDIR}/ast/initializer_clause.o: ast/initializer_clause.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/initializer_clause.o ast/initializer_clause.cxx

${OBJECTDIR}/ast/initializer_list.o: ast/initializer_list.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/initializer_list.o ast/initializer_list.cxx

${OBJECTDIR}/ast/interface_declaration.o: ast/interface_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/interface_declaration.o ast/interface_declaration.cxx

${OBJECTDIR}/ast/iteration_statement.o: ast/iteration_statement.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/iteration_statement.o ast/iteration_statement.cxx

${OBJECTDIR}/ast/jump_statement.o: ast/jump_statement.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/jump_statement.o ast/jump_statement.cxx

${OBJECTDIR}/ast/lambda_expression.o: ast/lambda_expression.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/lambda_expression.o ast/lambda_expression.cxx

${OBJECTDIR}/ast/linkage.o: ast/linkage.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/linkage.o ast/linkage.cxx

${OBJECTDIR}/ast/literal.o: ast/literal.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/literal.o ast/literal.cxx

${OBJECTDIR}/ast/member_variable_declaration.o: ast/member_variable_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/member_variable_declaration.o ast/member_variable_declaration.cxx

${OBJECTDIR}/ast/method_body.o: ast/method_body.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/method_body.o ast/method_body.cxx

${OBJECTDIR}/ast/method_body_item.o: ast/method_body_item.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/method_body_item.o ast/method_body_item.cxx

${OBJECTDIR}/ast/method_declaration.o: ast/method_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/method_declaration.o ast/method_declaration.cxx

${OBJECTDIR}/ast/method_parameter.o: ast/method_parameter.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/method_parameter.o ast/method_parameter.cxx

${OBJECTDIR}/ast/method_parameter_list.o: ast/method_parameter_list.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/method_parameter_list.o ast/method_parameter_list.cxx

${OBJECTDIR}/ast/method_parameters_declaration.o: ast/method_parameters_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/method_parameters_declaration.o ast/method_parameters_declaration.cxx

${OBJECTDIR}/ast/mutability.o: ast/mutability.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/mutability.o ast/mutability.cxx

${OBJECTDIR}/ast/name.o: ast/name.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/name.o ast/name.cxx

${OBJECTDIR}/ast/namespace_declaration.o: ast/namespace_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/namespace_declaration.o ast/namespace_declaration.cxx

${OBJECTDIR}/ast/namespace_declaration_name.o: ast/namespace_declaration_name.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/namespace_declaration_name.o ast/namespace_declaration_name.cxx

${OBJECTDIR}/ast/nested_name_specifier.o: ast/nested_name_specifier.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/nested_name_specifier.o ast/nested_name_specifier.cxx

${OBJECTDIR}/ast/operator_function_id.o: ast/operator_function_id.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/operator_function_id.o ast/operator_function_id.cxx

${OBJECTDIR}/ast/overloadable_operator.o: ast/overloadable_operator.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/overloadable_operator.o ast/overloadable_operator.cxx

${OBJECTDIR}/ast/postfix_expression.o: ast/postfix_expression.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/postfix_expression.o ast/postfix_expression.cxx

${OBJECTDIR}/ast/primary_expression.o: ast/primary_expression.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/primary_expression.o ast/primary_expression.cxx

${OBJECTDIR}/ast/qualified_id.o: ast/qualified_id.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/qualified_id.o ast/qualified_id.cxx

${OBJECTDIR}/ast/return_specifier.o: ast/return_specifier.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/return_specifier.o ast/return_specifier.cxx

${OBJECTDIR}/ast/simple_template_id.o: ast/simple_template_id.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/simple_template_id.o ast/simple_template_id.cxx

${OBJECTDIR}/ast/simple_type_specifier.o: ast/simple_type_specifier.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/simple_type_specifier.o ast/simple_type_specifier.cxx

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

${OBJECTDIR}/ast/symbols.o: ast/symbols.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/symbols.o ast/symbols.cxx

${OBJECTDIR}/ast/template_argument.o: ast/template_argument.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/template_argument.o ast/template_argument.cxx

${OBJECTDIR}/ast/template_argument_list.o: ast/template_argument_list.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/template_argument_list.o ast/template_argument_list.cxx

${OBJECTDIR}/ast/template_id.o: ast/template_id.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/template_id.o ast/template_id.cxx

${OBJECTDIR}/ast/template_parameter.o: ast/template_parameter.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/template_parameter.o ast/template_parameter.cxx

${OBJECTDIR}/ast/template_parameter_list.o: ast/template_parameter_list.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/template_parameter_list.o ast/template_parameter_list.cxx

${OBJECTDIR}/ast/try_statement.o: ast/try_statement.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/try_statement.o ast/try_statement.cxx

${OBJECTDIR}/ast/typedef_declaration.o: ast/typedef_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/typedef_declaration.o ast/typedef_declaration.cxx

${OBJECTDIR}/ast/unary_expression.o: ast/unary_expression.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/unary_expression.o ast/unary_expression.cxx

${OBJECTDIR}/ast/unary_operator.o: ast/unary_operator.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/unary_operator.o ast/unary_operator.cxx

${OBJECTDIR}/ast/unqualified_id.o: ast/unqualified_id.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/unqualified_id.o ast/unqualified_id.cxx

${OBJECTDIR}/ast/var_or_attr_name.o: ast/var_or_attr_name.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/var_or_attr_name.o ast/var_or_attr_name.cxx

${OBJECTDIR}/ast/variable_declaration.o: ast/variable_declaration.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/variable_declaration.o ast/variable_declaration.cxx

${OBJECTDIR}/ast/words.o: ast/words.cxx
	${MKDIR} -p ${OBJECTDIR}/ast
	${RM} "$@.d"
	$(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/words.o ast/words.cxx

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

${OBJECTDIR}/ast/array_specifier_nomain.o: ${OBJECTDIR}/ast/array_specifier.o ast/array_specifier.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/array_specifier.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/array_specifier_nomain.o ast/array_specifier.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/array_specifier.o ${OBJECTDIR}/ast/array_specifier_nomain.o;\
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

${OBJECTDIR}/ast/base_clause_nomain.o: ${OBJECTDIR}/ast/base_clause.o ast/base_clause.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/base_clause.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_clause_nomain.o ast/base_clause.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/base_clause.o ${OBJECTDIR}/ast/base_clause_nomain.o;\
	fi

${OBJECTDIR}/ast/base_initializer_nomain.o: ${OBJECTDIR}/ast/base_initializer.o ast/base_initializer.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/base_initializer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_initializer_nomain.o ast/base_initializer.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/base_initializer.o ${OBJECTDIR}/ast/base_initializer_nomain.o;\
	fi

${OBJECTDIR}/ast/base_initializer_list_nomain.o: ${OBJECTDIR}/ast/base_initializer_list.o ast/base_initializer_list.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/base_initializer_list.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_initializer_list_nomain.o ast/base_initializer_list.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/base_initializer_list.o ${OBJECTDIR}/ast/base_initializer_list_nomain.o;\
	fi

${OBJECTDIR}/ast/base_initializer_specifier_nomain.o: ${OBJECTDIR}/ast/base_initializer_specifier.o ast/base_initializer_specifier.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/base_initializer_specifier.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_initializer_specifier_nomain.o ast/base_initializer_specifier.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/base_initializer_specifier.o ${OBJECTDIR}/ast/base_initializer_specifier_nomain.o;\
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

${OBJECTDIR}/ast/base_specifier_nomain.o: ${OBJECTDIR}/ast/base_specifier.o ast/base_specifier.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/base_specifier.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_specifier_nomain.o ast/base_specifier.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/base_specifier.o ${OBJECTDIR}/ast/base_specifier_nomain.o;\
	fi

${OBJECTDIR}/ast/base_specifier_list_nomain.o: ${OBJECTDIR}/ast/base_specifier_list.o ast/base_specifier_list.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/base_specifier_list.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_specifier_list_nomain.o ast/base_specifier_list.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/base_specifier_list.o ${OBJECTDIR}/ast/base_specifier_list_nomain.o;\
	fi

${OBJECTDIR}/ast/base_type_specifier_nomain.o: ${OBJECTDIR}/ast/base_type_specifier.o ast/base_type_specifier.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/base_type_specifier.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/base_type_specifier_nomain.o ast/base_type_specifier.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/base_type_specifier.o ${OBJECTDIR}/ast/base_type_specifier_nomain.o;\
	fi

${OBJECTDIR}/ast/binary_op_nomain.o: ${OBJECTDIR}/ast/binary_op.o ast/binary_op.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/binary_op.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/binary_op_nomain.o ast/binary_op.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/binary_op.o ${OBJECTDIR}/ast/binary_op_nomain.o;\
	fi

${OBJECTDIR}/ast/bool_nomain.o: ${OBJECTDIR}/ast/bool.o ast/bool.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/bool.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/bool_nomain.o ast/bool.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/bool.o ${OBJECTDIR}/ast/bool_nomain.o;\
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

${OBJECTDIR}/ast/case_statement_nomain.o: ${OBJECTDIR}/ast/case_statement.o ast/case_statement.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/case_statement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/case_statement_nomain.o ast/case_statement.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/case_statement.o ${OBJECTDIR}/ast/case_statement_nomain.o;\
	fi

${OBJECTDIR}/ast/catch_statement_nomain.o: ${OBJECTDIR}/ast/catch_statement.o ast/catch_statement.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/catch_statement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/catch_statement_nomain.o ast/catch_statement.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/catch_statement.o ${OBJECTDIR}/ast/catch_statement_nomain.o;\
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

${OBJECTDIR}/ast/common_nomain.o: ${OBJECTDIR}/ast/common.o ast/common.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/common.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/common_nomain.o ast/common.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/common.o ${OBJECTDIR}/ast/common_nomain.o;\
	fi

${OBJECTDIR}/ast/compound_statement_nomain.o: ${OBJECTDIR}/ast/compound_statement.o ast/compound_statement.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/compound_statement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/compound_statement_nomain.o ast/compound_statement.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/compound_statement.o ${OBJECTDIR}/ast/compound_statement_nomain.o;\
	fi

${OBJECTDIR}/ast/condition_nomain.o: ${OBJECTDIR}/ast/condition.o ast/condition.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/condition.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/condition_nomain.o ast/condition.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/condition.o ${OBJECTDIR}/ast/condition_nomain.o;\
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

${OBJECTDIR}/ast/constant_expression_nomain.o: ${OBJECTDIR}/ast/constant_expression.o ast/constant_expression.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/constant_expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/constant_expression_nomain.o ast/constant_expression.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/constant_expression.o ${OBJECTDIR}/ast/constant_expression_nomain.o;\
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

${OBJECTDIR}/ast/expression_nomain.o: ${OBJECTDIR}/ast/expression.o ast/expression.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/expression_nomain.o ast/expression.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/expression.o ${OBJECTDIR}/ast/expression_nomain.o;\
	fi

${OBJECTDIR}/ast/expression_ele_nomain.o: ${OBJECTDIR}/ast/expression_ele.o ast/expression_ele.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/expression_ele.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/expression_ele_nomain.o ast/expression_ele.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/expression_ele.o ${OBJECTDIR}/ast/expression_ele_nomain.o;\
	fi

${OBJECTDIR}/ast/expression_list_nomain.o: ${OBJECTDIR}/ast/expression_list.o ast/expression_list.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/expression_list.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/expression_list_nomain.o ast/expression_list.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/expression_list.o ${OBJECTDIR}/ast/expression_list_nomain.o;\
	fi

${OBJECTDIR}/ast/finally_statement_nomain.o: ${OBJECTDIR}/ast/finally_statement.o ast/finally_statement.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/finally_statement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/finally_statement_nomain.o ast/finally_statement.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/finally_statement.o ${OBJECTDIR}/ast/finally_statement_nomain.o;\
	fi

${OBJECTDIR}/ast/for_statement_nomain.o: ${OBJECTDIR}/ast/for_statement.o ast/for_statement.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/for_statement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/for_statement_nomain.o ast/for_statement.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/for_statement.o ${OBJECTDIR}/ast/for_statement_nomain.o;\
	fi

${OBJECTDIR}/ast/id_expression_nomain.o: ${OBJECTDIR}/ast/id_expression.o ast/id_expression.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/id_expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/id_expression_nomain.o ast/id_expression.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/id_expression.o ${OBJECTDIR}/ast/id_expression_nomain.o;\
	fi

${OBJECTDIR}/ast/if_statement_nomain.o: ${OBJECTDIR}/ast/if_statement.o ast/if_statement.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/if_statement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/if_statement_nomain.o ast/if_statement.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/if_statement.o ${OBJECTDIR}/ast/if_statement_nomain.o;\
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

${OBJECTDIR}/ast/iteration_statement_nomain.o: ${OBJECTDIR}/ast/iteration_statement.o ast/iteration_statement.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/iteration_statement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/iteration_statement_nomain.o ast/iteration_statement.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/iteration_statement.o ${OBJECTDIR}/ast/iteration_statement_nomain.o;\
	fi

${OBJECTDIR}/ast/jump_statement_nomain.o: ${OBJECTDIR}/ast/jump_statement.o ast/jump_statement.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/jump_statement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/jump_statement_nomain.o ast/jump_statement.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/jump_statement.o ${OBJECTDIR}/ast/jump_statement_nomain.o;\
	fi

${OBJECTDIR}/ast/lambda_expression_nomain.o: ${OBJECTDIR}/ast/lambda_expression.o ast/lambda_expression.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/lambda_expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/lambda_expression_nomain.o ast/lambda_expression.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/lambda_expression.o ${OBJECTDIR}/ast/lambda_expression_nomain.o;\
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

${OBJECTDIR}/ast/literal_nomain.o: ${OBJECTDIR}/ast/literal.o ast/literal.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/literal.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/literal_nomain.o ast/literal.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/literal.o ${OBJECTDIR}/ast/literal_nomain.o;\
	fi

${OBJECTDIR}/ast/member_variable_declaration_nomain.o: ${OBJECTDIR}/ast/member_variable_declaration.o ast/member_variable_declaration.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/member_variable_declaration.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/member_variable_declaration_nomain.o ast/member_variable_declaration.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/member_variable_declaration.o ${OBJECTDIR}/ast/member_variable_declaration_nomain.o;\
	fi

${OBJECTDIR}/ast/method_body_nomain.o: ${OBJECTDIR}/ast/method_body.o ast/method_body.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/method_body.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/method_body_nomain.o ast/method_body.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/method_body.o ${OBJECTDIR}/ast/method_body_nomain.o;\
	fi

${OBJECTDIR}/ast/method_body_item_nomain.o: ${OBJECTDIR}/ast/method_body_item.o ast/method_body_item.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/method_body_item.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/method_body_item_nomain.o ast/method_body_item.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/method_body_item.o ${OBJECTDIR}/ast/method_body_item_nomain.o;\
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

${OBJECTDIR}/ast/method_parameter_nomain.o: ${OBJECTDIR}/ast/method_parameter.o ast/method_parameter.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/method_parameter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/method_parameter_nomain.o ast/method_parameter.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/method_parameter.o ${OBJECTDIR}/ast/method_parameter_nomain.o;\
	fi

${OBJECTDIR}/ast/method_parameter_list_nomain.o: ${OBJECTDIR}/ast/method_parameter_list.o ast/method_parameter_list.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/method_parameter_list.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/method_parameter_list_nomain.o ast/method_parameter_list.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/method_parameter_list.o ${OBJECTDIR}/ast/method_parameter_list_nomain.o;\
	fi

${OBJECTDIR}/ast/method_parameters_declaration_nomain.o: ${OBJECTDIR}/ast/method_parameters_declaration.o ast/method_parameters_declaration.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/method_parameters_declaration.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/method_parameters_declaration_nomain.o ast/method_parameters_declaration.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/method_parameters_declaration.o ${OBJECTDIR}/ast/method_parameters_declaration_nomain.o;\
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

${OBJECTDIR}/ast/name_nomain.o: ${OBJECTDIR}/ast/name.o ast/name.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/name.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/name_nomain.o ast/name.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/name.o ${OBJECTDIR}/ast/name_nomain.o;\
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

${OBJECTDIR}/ast/nested_name_specifier_nomain.o: ${OBJECTDIR}/ast/nested_name_specifier.o ast/nested_name_specifier.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/nested_name_specifier.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/nested_name_specifier_nomain.o ast/nested_name_specifier.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/nested_name_specifier.o ${OBJECTDIR}/ast/nested_name_specifier_nomain.o;\
	fi

${OBJECTDIR}/ast/operator_function_id_nomain.o: ${OBJECTDIR}/ast/operator_function_id.o ast/operator_function_id.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/operator_function_id.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/operator_function_id_nomain.o ast/operator_function_id.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/operator_function_id.o ${OBJECTDIR}/ast/operator_function_id_nomain.o;\
	fi

${OBJECTDIR}/ast/overloadable_operator_nomain.o: ${OBJECTDIR}/ast/overloadable_operator.o ast/overloadable_operator.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/overloadable_operator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/overloadable_operator_nomain.o ast/overloadable_operator.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/overloadable_operator.o ${OBJECTDIR}/ast/overloadable_operator_nomain.o;\
	fi

${OBJECTDIR}/ast/postfix_expression_nomain.o: ${OBJECTDIR}/ast/postfix_expression.o ast/postfix_expression.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/postfix_expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/postfix_expression_nomain.o ast/postfix_expression.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/postfix_expression.o ${OBJECTDIR}/ast/postfix_expression_nomain.o;\
	fi

${OBJECTDIR}/ast/primary_expression_nomain.o: ${OBJECTDIR}/ast/primary_expression.o ast/primary_expression.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/primary_expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/primary_expression_nomain.o ast/primary_expression.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/primary_expression.o ${OBJECTDIR}/ast/primary_expression_nomain.o;\
	fi

${OBJECTDIR}/ast/qualified_id_nomain.o: ${OBJECTDIR}/ast/qualified_id.o ast/qualified_id.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/qualified_id.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/qualified_id_nomain.o ast/qualified_id.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/qualified_id.o ${OBJECTDIR}/ast/qualified_id_nomain.o;\
	fi

${OBJECTDIR}/ast/return_specifier_nomain.o: ${OBJECTDIR}/ast/return_specifier.o ast/return_specifier.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/return_specifier.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/return_specifier_nomain.o ast/return_specifier.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/return_specifier.o ${OBJECTDIR}/ast/return_specifier_nomain.o;\
	fi

${OBJECTDIR}/ast/simple_template_id_nomain.o: ${OBJECTDIR}/ast/simple_template_id.o ast/simple_template_id.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/simple_template_id.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/simple_template_id_nomain.o ast/simple_template_id.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/simple_template_id.o ${OBJECTDIR}/ast/simple_template_id_nomain.o;\
	fi

${OBJECTDIR}/ast/simple_type_specifier_nomain.o: ${OBJECTDIR}/ast/simple_type_specifier.o ast/simple_type_specifier.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/simple_type_specifier.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/simple_type_specifier_nomain.o ast/simple_type_specifier.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/simple_type_specifier.o ${OBJECTDIR}/ast/simple_type_specifier_nomain.o;\
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

${OBJECTDIR}/ast/symbols_nomain.o: ${OBJECTDIR}/ast/symbols.o ast/symbols.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/symbols.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/symbols_nomain.o ast/symbols.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/symbols.o ${OBJECTDIR}/ast/symbols_nomain.o;\
	fi

${OBJECTDIR}/ast/template_argument_nomain.o: ${OBJECTDIR}/ast/template_argument.o ast/template_argument.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/template_argument.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/template_argument_nomain.o ast/template_argument.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/template_argument.o ${OBJECTDIR}/ast/template_argument_nomain.o;\
	fi

${OBJECTDIR}/ast/template_argument_list_nomain.o: ${OBJECTDIR}/ast/template_argument_list.o ast/template_argument_list.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/template_argument_list.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/template_argument_list_nomain.o ast/template_argument_list.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/template_argument_list.o ${OBJECTDIR}/ast/template_argument_list_nomain.o;\
	fi

${OBJECTDIR}/ast/template_id_nomain.o: ${OBJECTDIR}/ast/template_id.o ast/template_id.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/template_id.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/template_id_nomain.o ast/template_id.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/template_id.o ${OBJECTDIR}/ast/template_id_nomain.o;\
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

${OBJECTDIR}/ast/try_statement_nomain.o: ${OBJECTDIR}/ast/try_statement.o ast/try_statement.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/try_statement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/try_statement_nomain.o ast/try_statement.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/try_statement.o ${OBJECTDIR}/ast/try_statement_nomain.o;\
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

${OBJECTDIR}/ast/unary_expression_nomain.o: ${OBJECTDIR}/ast/unary_expression.o ast/unary_expression.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/unary_expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/unary_expression_nomain.o ast/unary_expression.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/unary_expression.o ${OBJECTDIR}/ast/unary_expression_nomain.o;\
	fi

${OBJECTDIR}/ast/unary_operator_nomain.o: ${OBJECTDIR}/ast/unary_operator.o ast/unary_operator.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/unary_operator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/unary_operator_nomain.o ast/unary_operator.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/unary_operator.o ${OBJECTDIR}/ast/unary_operator_nomain.o;\
	fi

${OBJECTDIR}/ast/unqualified_id_nomain.o: ${OBJECTDIR}/ast/unqualified_id.o ast/unqualified_id.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/unqualified_id.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/unqualified_id_nomain.o ast/unqualified_id.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/unqualified_id.o ${OBJECTDIR}/ast/unqualified_id_nomain.o;\
	fi

${OBJECTDIR}/ast/var_or_attr_name_nomain.o: ${OBJECTDIR}/ast/var_or_attr_name.o ast/var_or_attr_name.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/var_or_attr_name.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/var_or_attr_name_nomain.o ast/var_or_attr_name.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/var_or_attr_name.o ${OBJECTDIR}/ast/var_or_attr_name_nomain.o;\
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

${OBJECTDIR}/ast/words_nomain.o: ${OBJECTDIR}/ast/words.o ast/words.cxx 
	${MKDIR} -p ${OBJECTDIR}/ast
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ast/words.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -I. -I../laolxcxx -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ast/words_nomain.o ast/words.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/ast/words.o ${OBJECTDIR}/ast/words_nomain.o;\
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
