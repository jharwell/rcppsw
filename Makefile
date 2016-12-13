################################################################################
# Name            : Makefile
# Project         : Project
# Description     : Makefile Template
# Creation Date   : Fri May 16 14:59:49 2014
# Original Author : jharwell
#
# Note: This file is -j (parallel build) safe, provided you don't mess with it
# too much
#
#  Products:
#  Make Target     Product                  Description
#  ===========     =======                  ===================
#
################################################################################

###############################################################################
# Directory Definitions
###############################################################################
# src/      - Root of the source tree for the project
# lib/      - Directory where libraries are built, if applicable
# bin/      - Directory where all executables are built
# tests/    - Root directory of all test code for the project
# obj/      - Directory where all object files are built
# lst/      - Direcory where all assembly listing (.lst) files are built
# analysis/ - Root directory for all code analysis that are run
# logs/     - Output directory of stdout of unit tests and some tools
SRCDIR          = ./src
LIBDIR          = ./lib
BINDIR          = ./bin
TESTDIR         = ./tests
OBJDIR          = ./obj
PREPROCDIR      = ./preproc
ANALYSIS_ROOT   = ./analysis
ANALYSIS_DIR    = $(ANALYSIS_ROOT)/$(DATE1)
SCANDIR         = $(ANALYSIS_ROOT)/scan
RELEASE_DIR     = ./release/$(DATE1)
LOGDIR          = ./logs

###############################################################################
# Definitions
###############################################################################
# The prefix to install things to via 'make install'
PREFIX         ?= /usr/local

# Tell make we want to execute all commands using bash (otherwise it uses sh)
SHELL           = bash

# Tell make we want to:
# 1 - Redirect results to a file--nothing is printed on stdout.
# 0 - Dump results to stdout, AND redirect them to a file.
#
NO_STDOUT ?= 0

ifeq ($(NO_STDOUT),1)
REDIRECT1 = >
REDIRECT2 = 2>&1
else
REDIRECT1 = | tee
REDIRECT2 = 2>&1
endif

# You can't have colons in a file/directory name that is a dependency for a
# make target, hence the separation of day and time into two pieces
DATE1 = $(shell date --iso-8601)
DATE2 = $(shell date +"%T")

# Define the remote host/location things should be copied to. Useful if your
# devel machine is different than the machine which is connected to the board
# you're using.
REMOTE =

###############################################################################
# Library Directories
###############################################################################

###############################################################################
# Include Directories
###############################################################################
# Query the gcc-ish compiler and build a list of the system includes. Not
# necessary for compilation (obviously), but needed for some of the analysis
# tools to work.
CCSYS_INCDIRS  := $(addprefix -isystem,$(call inc-query,$(CC)))
CXXSYS_INCDIRS := $(addprefix -isystem,$(call inc-query,$(CXX)))

###############################################################################
# CC Compilation Options
###############################################################################
CCLIBDIRS  = -L$(LIBDIR)
CCLIB_SELF = -l$(shell echo $(notdir $(shell pwd))).x86
CCLIBS     = -lrt -lm -lpthread
OPT        = -O0

###############################################################################
# C Compilation Options
###############################################################################
CDEBUG    = -DDBG_LVL_DYNAMIC=DBG_N

CLIBS     = $(CCLIB_SELF) -lcommon.x86 -levtlog.x86 -lds.x86 -lutils.x86 $(CCLIBS)
CLIBDIRS  = $(CCLIBDIRS) -L$(rcswroot)/lib/x86/linux

define CINCDIRS
-I$(rcsw)/include \
-Iinclude
endef

CFLAGS   = $(OPT) -g -D__linux__ -W -Wall -Wextra -std=gnu99 -fmessage-length=0 $(CINCDIRS) $(CDEBUG)
CC       = $(develcc)

###############################################################################
# C++ Compilation Options
###############################################################################
CXXLIBDIRS ?= -L$(rcppsw)/lib -L$(LIBDIR)

define CXXINCDIRS
-Iinclude \
-I$(rcsw)/include \
-I$(rcppsw)/include \
-I$(develroot)/catch/single_include
endef

CXXFLAGS    = $(OPT) -g -D__linux__ -W -Wall -Wextra -Weffc++ -std=gnu++11 -fmessage-length=0 $(CXXINCDIRS)
CXXLIBS     = $(CCLIB_SELF) -lrcppsw.x86 -lboost_system -lboost_filesystem -lboost_thread $(CCLIBS)
CXX         = $(develcxx)

###############################################################################
# Functions
###############################################################################
# Compiler query: Get the list of built in system include directories
# by querying the gcc-ish compiler. Not necessary for compilation
# (obviously), but needed for some of the analysis tools to work.
# usage: $(call inc-query,compiler-name)
#
inc-query=$(shell echo | $(1) -xc -E -v - |& grep  '^ ' |grep include | sed 's/ //g'))

# Recursive wildcard: search a list of directories for all files that match a pattern
# usage: $(call rwildcard, $(DIRS1) $(DIRS2) ..., pattern)
#
# All directory lists passed as first arg must be separated by spaces, and they
# themselves must be space separated as well. There must NOT be a space between
# the last dir list the , and the start of the pattern.
#
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)  $(filter $(subst *,%,$2),$d))

# make-depend: generate dependencies for C/C++ source files dynamically. Very useful
# for including .h files as target dependencies.
# usage: $(call make-depend,source-file,object-file,depend-file)
#
# Note that this will not work on files in $(TESTDIR) without modification to
# this makefile.
#
make-depend-cc=$(CC) -MM -MF $3 -MP -MT $2 $(CFLAGS) $1
make-depend-cxx=$(CXX) -MM -MF $3 -MP -MT $2 $(CXXFLAGS) $1

# cppcheck analyzer: An analyzer that sometimes reports different things than the
# clang static checker. Sometimes it reports the same stuff too. This command
# redirects the output of all issues found to a file rather than reporting them
# to stdout.
#
# usage: $(call analyze-cppcheck-cmd,lang-type)
#
# lang-type must be either C or CXX, and there must be the following variables defined
# elsewhere in the Makefile for the analyzer to give accurate results:
# ANALYZE_SRC_[C,CXX],
# [C,CXX]INCDIRS,
# [C,CXX]SYS_INCDIRS,
# [C,CXX]DEBUG
define analyze-cppcheck-cmd
cppcheck --enable=all $($(addprefix ANALYZE_SRC_,$1)) \
$($(addprefix $1,INCDIRS)) $($(addprefix $1,SYS_INCDIRS)) $($(addprefix $1,DEBUG)) \
$(REDIRECT1) $(ANALYSIS_DIR)/cppcheck-analysis-$(DATE2).txt $(REDIRECT2)
endef

# clang-syntax: A VERY verbose set of compiler warnings (way more than
# gcc/g++), which can be helpful at times.
#
# usage: $(call analyze-clang-syntax-cmd,lang-type)
#
# lang-type must be either C or CXX, and there must be the following variables defined
# elsewhere in the Makefile for the analyzer to give accurate results:
# ANALYZE_SRC_[C,CXX],
# [C,CXX]INCDIRS,
# [C,CXX]FLAGS,
# [C,CXX]SYS_INCDIRS,
define analyze-clang-syntax-cmd
clang -fsyntax-only -fcolor-diagnostics -Weverything -Wno-undef -Wno-pedantic -Wno-reserved-id-macro\
-Wno-padded -Wno-packed -Wno-gnu-zero-variadic-macro-arguments -Wno-c++98-compat -Wno-c++98-compat-pedantic\
$($(addprefix $1,INCDIRS)) $($(addprefix $1,SYS_INCDIRS)) $($(addprefix $1,FLAGS)) \
$($(addprefix ANALYZE_SRC_,$1)) $(REDIRECT1)  $(ANALYSIS_DIR)/clang-syntax-analysis-$(DATE2).txt $(REDIRECT2)
endef

# clang-check: A very good static analyzer for all types of
# bugs/ambiguities.
#
# usage: $(call analyze-clang-check-cmd,lang-type)
#
# lang-type must be either C or CXX, and there must be the following variables defined
# elsewhere in the Makefile for the analyzer to give accurate results:
# ANALYZE_SRC_[C,CXX],
# [C,CXX]SYS_INCDIRS,
# [C,CXX]FLAGS,
# [C,CXX]INCDIRS
define analyze-clang-static-cmd
clang-check -analyze $($(addprefix ANALYZE_SRC_,$1)) -ast-dump -- $($(addprefix $1,INCDIRS)) $($(addprefix $1,FLAGS)) \
$($(addprefix $1,SYS_INCDIRS)) -fcolor-diagnostics $(REDIRECT1) $(ANALYSIS_DIR)/clang-static-analysis-$(DATE2).txt $(REDIRECT2)
endef

# clang-tidy-check: Check your code for adherence to a given coding standard, flag
# potential readability issues, etc. You must have clang-tidy installed
#
# usage: $(call analyze-clang-tidy-cmd,lang-type)
#
# lang-type must be either C or CXX, and there must be the following variables defined
# elsewhere in the Makefile for the analyzer to give accurate results:
# ANALYZE_SRC_[C,CXX],
# [C,CXX]SYS_INCDIRS
# [C,CXX]FLAGS
define analyze-clang-tidy-cmd
clang-tidy -checks=\* $($(addprefix ANALYZE_SRC_,$1)) -- $($(addprefix $1, FLAGS)) \
$($(addprefix $1,SYS_INCDIRS)) $(REDIRECT1) $(ANALYSIS_DIR)/clang-tidy-analysis-$(DATE2).txt $(REDIRECT2)
endef

# clang-tidy-fix: Same as clang-tidy-check, but automatically fix the issues
# instead of reporting them. You must have clang-tidy installed.
#
# usage: $(call fix-clang-tidy-cmd,lang-type)
#
# lang-type must be either C or CXX, and there must be the following variables defined
# elsewhere in the Makefile for the analyzer to give accurate results:
# ANALYZE_SRC_[C,CXX],
# [C,CXX]SYS_INCDIRS
# [C,CXX]FLAGS
define fix-clang-tidy-cmd
clang-tidy -fix
clang-tidy -fix -checks=cert\*,clang-analyzer*,cppcoreguidelnes\*,google\*,llvm\*,modernize\*,readability\*,-readability-else-after-return,modernize\* \
$($(addprefix ANALYZE_SRC_,$1)) -- $($(addprefix $1,FLAGS)) \
$($(addprefix $1,SYS_INCDIRS))
endef

# format-clang-cmd: Format the code according to user-specified rules in a
# .clang-format file (must be in same directory as Makefile). This WILL modify
# the source code. You must have clang-format installed.
#
# usage: $(call clang-format-cmd,lang-type)
#
# lang-type must be either C or CXX, and there must be the following variables defined
# elsewhere in the Makefile for the analyzer to give accurate results:
# ANALYZE_SRC_[C,CXX],
define format-clang-cmd
clang-format -i $($(addprefix ANALYZE_SRC_,$1))
endef

# Variable checking: Check to be sure the user defined a
# variable, and printing a helpful message when it's not before
# exiting. Note that all checks using this function must be AFTER this
# definition.
check-var-defined=$(if $(strip $($1)),,$(error "$1" is not defined ($(strip $2))))

###############################################################################
# Target Definitions
###############################################################################
# The actual source code
SOURCES    = $(SRCDIR)
SRC_C      = $(call rwildcard,$(SOURCES),*.c)
SRC_CXX    = $(call rwildcard,$(SOURCES),*.cpp)
SRC        = $(SRC_C) $(SRC_CXX)
ANALYZE_SRC_C ?= $(SRC_C)
ANALYZE_SRC_CXX ?= $(SRC_CXX)
OBJECTS_C    = $(notdir $(patsubst %.c,%.o,$(SRC_C)))
OBJECTS_CXX  = $(notdir $(patsubst %.cpp,%.o,$(SRC_CXX)))
OBJECTS      = $(OBJECTS_C) $(OBJECTS_CXX)
VPATH        = $(shell find $(SRCDIR) -type d):$(shell find $(TESTDIR) -type d)

# The target library
TARGET = $(LIBDIR)/lib$(notdir $(shell pwd)).x86.a

# The unit tests. My convention is that all test files will end in -test, and
# that all test harness files will end in _test.
TEST_SOURCES = $(TESTDIR)
CTEST_SRC = $(notdir $(call rwildcard,$(TEST_SOURCES),*-test.c))
CTEST_HARNESS = $(strip $(call rwildcard,$(TEST_SOURCES),*_test.c))
CTESTS = $(patsubst %.c,$(BINDIR)/%,$(CTEST_SRC))

CXXTEST_SRC = $(notdir $(call rwildcard,$(TEST_SOURCES),*-test.cpp))
CXXTEST_HARNESS = $(strip $(call rwildcard,$(TEST_SOURCES),*_test.cpp))
CXXTESTS = $(patsubst %.cpp,$(BINDIR)/%,$(CXXTEST_SRC))

TH_OBJECTS_C = $(notdir $(patsubst %.c,%.o,$(CTEST_HARNESS)))
TH_OBJECTS_CXX = $(notdir $(patsubst %.c,%.o,$(CXXTEST_HARNESS)))
TH_OBJECTS = $(TH_OBJECTS_C) $(TH_OBJECTS_CXX)

# Preprocessor output for source code, test code, and test harness. Very
# useful for debugging strange compilation errors.
define PREPROC_OBJECTS
$(addprefix $(PREPROCDIR)/,$(addsuffix .preproc, \
$(basename \
$(notdir $(call rwildcard, $(CTEST_SOURCES) $(CXXTEST_SOURCES) $(SOURCES),*.c)) \
$(notdir $(call rwildcard, $(CTEST_SOURCES) $(CXXTEST_SOURCES) $(SOURCES),*.cpp)) \
)))
endef

###############################################################################
# All targets
###############################################################################
.PHONY: analyze-c analyze-cppcheck-c analyze-clang-syntax-c analyze-clang-static-c
.PHONY: analyze-c++ analyze-cppcheck-c++ analyze-clang-syntax-c++ analyze-clang-static-c++
.PHONY: analyze-clang-tidy-c analyze-clang-tidy-c++
.PHONY: fix-clang-tidy-c fix-clang-tidy-c++
.PHONY: format-clang-c format-clang-c++
.PHONY: analyze-scan clean veryclean scan unit_tests rcopy release

# The Target Library (default target)
$(TARGET): $(addprefix $(OBJDIR)/, $(OBJECTS)) | $(LIBDIR)
	ar rcs $@ $(addprefix $(OBJDIR)/, $(OBJECTS))
	@ranlib $@

# Build ALL THE THINGS!
all: $(TARGET)

# The Releaser. Build target and then copy it and everything used to build it
# to a timestamped directory.
release: $(TARGET) | $(RELEASE_DIR)
	@cp $(BINDIR)/* $(OBJDIR)/* $(LIBDIR)/* $(RELEASE_DIR)

# The Objectifier
$(addprefix $(OBJDIR)/, $(OBJECTS) $(TH_OBJECTS)): | $(OBJDIR)

# Unless invoked with make clean, include generated dependencies
ifneq "$MAKECMDGOALS" "clean"
-include $(addprefix $(OBJDIR)/,$(OBJECTS_C:.o=.d))
-include $(addprefix $(OBJDIR)/,$(OBJECTS_CXX:.o=.d))
endif

# Bootstrap Bill
$(LIBDIR) $(BINDIR) $(LOGDIR) $(OBJDIR) $(PREPROCDIR) $(ANALYSIS_DIR) $(SCANDIR) $(RELEASE_DIR):
	@mkdir -p $@

# The Unit Tests Engine
$(CTESTS) $(CXXTESTS): $(TARGET) $(addprefix $(OBJDIR)/,$(TH_OBJECTS)) | $(BINDIR) $(LOGDIR)
unit_tests: $(CTESTS) $(CXXTESTS)

# The Installer
install: $(TARGET)
	@install -d $(PREFIX)
	@install $(TARGET) $(PREFIX)

# The Remote Copier
rcopy:
	@scp $(TARGET) $(REMOTE)

# The Memory Savant
valgrind:
	@VALGRIND="valgrind --log-file=./logs/valgrind.log" $(MAKE)

# The Function Call Profiler
callgrind:
	@CALLGRIND="valgrind --tool=callgrind --log-file=./logs/callgrind.log" $(MAKE)

# The Helpful Preprocessor
$(PREPROC_OBJECTS): | $(PREPROCDIR)
preprocessor: $(PREPROC_OBJECTS)

# The Cleaner
clean:
	@rm -rf $(LIBDIR) $(LOGDIR) $(BINDIR) $(OBJDIR) $(PREPROCDIR) $(TESTS) \
	config.status config.log autom4te.cache *.o *~

# The Super Cleaner
veryclean: clean
	@rm -rf $(ANALYSIS_ROOT) $(RELEASE_DIR)

# The Analyzers
analyze-c: analyze-cppcheck-c analyze-clang-syntax-c analyze-clang-static-c analyze-clang-tidy-c
analyze-c++: analyze-cppcheck-c++ analyze-clang-syntax-c++ analyze-clang-static-c++ analyze-clang-tidy-c++
analyze-cppcheck-c: | $(ANALYSIS_DIR)
	$(call analyze-cppcheck-cmd,C)
analyze-clang-syntax-c: | $(ANALYSIS_DIR)
	$(call analyze-clang-syntax-cmd,C)
analyze-clang-static-c: | $(ANALYSIS_DIR)
	$(call analyze-clang-static-cmd,C)
	@rm -rf *.plist

analyze-cppcheck-c++: | $(ANALYSIS_DIR)
	$(call analyze-cppcheck-cmd,CXX)
analyze-clang-syntax-c++: | $(ANALYSIS_DIR)
	$(call analyze-clang-syntax-cmd,CXX)
analyze-clang-static-c++: | $(ANALYSIS_DIR)
	$(call analyze-clang-static-cmd,CXX)
	@rm -rf *.plist

# The Scanner
#
# Presents the results of the clang static analyzer in a nice GUI/webpage. To
# use this target, you must run 'make clean' first, so scan-build can hook into
# your build process.
analyze-scan: | $(SCANDIR)
	scan-build -V --use-cc="$(CC)" --use-c++="$(CXX)" -o $(SCANDIR) -analyze-headers -enable-checker core -enable-checker unix -enable-checker security -enable-checker llvm -enable-checker alpha -disable-checker alpha.core.CastToStruct $(MAKE)

# The Tidy Checkers
analyze-clang-tidy-c: | $(ANALYSIS_DIR)
	$(call analyze-clang-tidy-cmd,C)
analyze-clang-tidy-c++: | $(ANALYSIS_DIR)
	$(call analyze-clang-tidy-cmd,CXX)

# The Tidy Fixers
fix-clang-tidy-c: | $(ANALYSIS_DIR)
	$(call fix-clang-tidy-cmd,C)
fix-clang-tidy-c++: | $(ANALYSIS_DIR)
	$(call fix-clang-tidy-cmd,CXX)

# The Formatters
format-clang-c:
	$(call format-clang-cmd,C)
format-clang-c++:
	$(call format-clang-cmd,C)
###############################################################################
# Pattern Rules
###############################################################################
# For compiling the C source and test harness
$(OBJDIR)/%.o: %.c
	@$(call make-depend-cc,$<,$@,$(subst .o,.d,$@))
	$(CC) $(CFLAGS) $(CLIBDIRS) -c -o  $@ $<

# For compiling the C++ source and test harness
$(OBJDIR)/%.o:: $(SRCDIR)/%.cpp
	@$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	$(CXX) $(CXXFLAGS) $(CXXLIBDIRS) -c -o  $@ $<

# For compiling the C tests
$(BINDIR)/%:: %.c
	$(CC) $(CFLAGS) $(CLIBDIRS) $(addprefix $(OBJDIR)/,$(TH_OBJECTS)) $< -o $@ $(CLIBS)

# For compiling the C++ tests
$(BINDIR)/%:: %.cpp
	$(CXX) $(CXXFLAGS) $(CXXLIBDIRS) $(addprefix $(OBJDIR)/,$(TH_OBJECTS)) $< -o $@ $(CXXLIBS)

# For getting preprocessor C/C++ output
$(PREPROCDIR)/%.preproc: %.c
	$(CC) $(CFLAGS) $(CINCDIRS) -E $< -o $@

$(PREPROCDIR)/%.preproc: %.cpp
	$(CXX) $(CXXFLAGS) $(CXXINCDIRS) -E $< -o $@
