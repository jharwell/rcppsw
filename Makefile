################################################################################
# Name            : Makefile
# Project         : Templates
# Description     : Makefile Template
# Creation Date   : 05/16/14
# Copyright       : 2014 John Harwell, All rights reserved
#
# Note: This file is -j (parallel build) safe
#
#  Products:
#  Make Target      Product           Description
#  ===========      =======           ===================
#  all              $(TARGET)          The target library/executable, with
#                                      optimizations disabled and debugging
#                                      enabled
#
#  release          $(TARGET)          The target library/excetubale, with
#                                      optimizations enabled and debugging
#                                      disabled.
#
#  unit_tests       bin/*              Build all the C/C++ unit tests (after
#                                      $(TARGET))
#
#  install          varies             Install $(TARGET) to the filesysetm
#
#  uninstall        N/A                Uninstall $(TARGET) from the filesystem
#
#  rcopy            $(TARGET)          Build the target and then copy it to a
#                                      remote machine
#
#  preprocessor     preproc/*          Preprocess C/C++ code and output the
#                                      result. Useful for tracking down strange
#                                      bugs/compiler errors
#
#  clean           N/A                 Removes all files/directories this
#                                      Makefile can generate, except release/
#                                      and analysis/
#
#  veryclean       N/A                 Does everything clean does, but also
#                                      removes the release/ and analysis/
#                                      directories
#
###############################################################################

###############################################################################
# Directory Definitions
###############################################################################
# src/      - Root of the source tree for the project
# lib/      - Directory where libraries are built, if applicable
# bin/      - Directory where all executables are built
# tests/    - Root directory of all test code for the project
# obj/      - Directory where all object files are built
# doc/      - Documentation directory
SRCDIR          = src
LIBDIR          = lib
BINDIR          = bin
TESTDIR         = tests
OBJDIR          = obj
PREPROCDIR      = preproc
RELEASE_DIR     = release/$(DATE1)
DOCDIR          = doc

###############################################################################
# Definitions
###############################################################################
# The prefix to install things to via 'make install'
PREFIX         ?= $(HOME)/local

# Tell make we want to execute all commands using bash (otherwise it uses sh)
SHELL           = bash

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
# C Compilation Options
###############################################################################
CLIBS     = $(CCLIBS)
CLIBDIRS  = $(CCLIBDIRS)

define CINCDIRS
-I. \
-Iinclude \
-I$(develroot)/catch/single_include
endef

CFLAGS   += -g $(CCFLAGS) $(CINCDIRS)
CC       = $(develcc)

###############################################################################
# C++ Compilation Options
###############################################################################
CXXLIBDIRS = $(CCLIBDIRS)

define CXXINCDIRS
-I. \
-Iinclude \
-I$(rcsw)/include \
-I$(develroot)/catch/single_include
endef

CXXFLAGS    += -g $(CCFLAGS) $(CXXINCDIRS)
CXXLIBS     = -lrcppsw.x86 -lboost_system -lboost_filesystem -lboost_thread $(CCLIBS)
CXX         = $(develcxx)

###############################################################################
# CC Compilation Options
###############################################################################
# Parallelization options are included even when not optimizing so that OpenMP
# and MPI directives/functions are understood and enabled.
INTEL_POPTS = -qopenmp -parallel -parallel-source-info=2
GNU_POPTS = -fopenmp

FPC        = -DFPC_TYPE=FPC_ABORT
CCLIBDIRS  = -L$(LIBDIR)
CCLIBS     = -lrt -lm -lpthread $(MPI_LIBS)
CCDEBUG    =
CCFLAGS    = $(FPC) $(CCDEBUG)

ifneq (,$(findstring gcc,$(CC)))
CFLAGS += $(GNU_POPTS)
endif

ifneq (,$(findstring icc,$(CC)))
CFLAGS += $(INTEL_POPTS)
endif

ifneq (,$(findstring g++,$(CXX)))
CXXFLAGS += $(GNU_POPTS)
endif
ifneq (,$(findstring icpc,$(CXX)))
CXXFLAGS += $(INTEL_POPTS)
endif

###############################################################################
# Diagnostic Options (icc/gcc, g++/icpc)
#
# 981 - warnings about operands evaluated in unspecified order
# 181 - warnings about using an int for a %lu or a long for a %d, etc
# 2259 - warnings about converting uint16_t to uint8_t losing precision
# 2282 - warnings about unrecognized gcc/g++ pragmas
# 10382 - Telling me what option xHost was setting
###############################################################################
GNU_CDFLAGS = -W -Wall -Wextra -std=gnu99 -fmessage-length=0 -fdiagnostics-color=always
GNU_CXXDFLAGS = -W -Wall -Wextra -Weffc++ -Wshadow -std=gnu++11 -fmessage-length=0 -fdiagnostics-color=always
INTEL_CDFLAGS += -w2 -Wall -Wcheck -Winline -Wshadow -Wremarks -wd181 -wd981 -wd2282
INTEL_CXXDFLAGS += -w2 -Wall -Wcheck -Weffc++ -Winline -Wshadow -std=gnu++11 -Wremarks -wd181 -wd981 -wd2282 -wd2015 -wd2012

ifneq (,$(findstring gcc,$(CC)))
CFLAGS += $(GNU_CDFLAGS)
endif
ifneq (,$(findstring icc,$(CC)))
CFLAGS += $(INTEL_CDFLAGS)
endif

ifneq (,$(findstring g++,$(CXX)))
CXXFLAGS += $(GNU_CXXDFLAGS)
endif
ifneq (,$(findstring icpc,$(CXX)))
CXXFLAGS += $(INTEL_CXXDFLAGS)
endif

###############################################################################
# Functions
###############################################################################
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
make-depend-mpiccc=$(MPICC) -MM -MF $3 -MP -MT $2 $(CFLAGS) $1
make-depend-cxx=$(CXX) -MM -MF $3 -MP -MT $2 $(CXXFLAGS) $1

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
.PHONY: clean veryclean unit_tests rcopy release documentation

#
# Executable/library producing targets (feel free to build any of these)
#

# The Development Target (disables optimization)
dev: CFLAGS+=-O0
dev: CXXFLAGS+=-O0
dev: $(TARGET)

# Build ALL THE THINGS! (not in development mode). This is not the default for
# a reason, as developers typicall do not want optimizations on during
# development.
all: CFLAGS += $(OPT_CFLAGS)
all: CXXFLAGS += $(OPT_CXXFLAGS)
all: CCDEBUG=-DNDEBUG
all: $(TARGET)

# The Target Library (default target)
$(TARGET): $(addprefix $(OBJDIR)/, $(OBJECTS)) | $(LIBDIR)
	ar rcs $@ $(addprefix $(OBJDIR)/, $(OBJECTS))
	@ranlib $@

# The Releaser. Build target with (1) maximum optimization, and (2) no debug
# printing, and then copy it and everything used to build it to a timestamped
# directory.
release: all
release: $(TARGET) documentation | $(RELEASE_DIR)
	#@cp $(BINDIR)/* $(OBJDIR)/* $(LIBDIR)/* $(RELEASE_DIR)
	#@cp $(DOCDIR)/html $(DOCDIR)/latex $(RELEASE_DIR)
#
# Helper targets for executable/library targets (don't build any of these directly)
#
# The Objectifier
$(addprefix $(OBJDIR)/, $(OBJECTS) $(TH_OBJECTS)): | $(OBJDIR)

# Unless invoked with make clean, include generated dependencies and my other Makefiles
ifneq "$MAKECMDGOALS" "clean"
-include $(OBJDIR)/*.d
-include Makefile.optimize
-include Makefile.analyze
endif

# Bootstrap Bill
$(LIBDIR) $(BINDIR) $(OBJDIR) $(PREPROCDIR) $(RELEASE_DIR) $(DOCDIR):
	@mkdir -p $@

# The Unit Tests Engine
$(CTESTS) $(CXXTESTS): $(TARGET) $(addprefix $(OBJDIR)/,$(TH_OBJECTS)) | $(BINDIR)
unit_tests: $(CTESTS) $(CXXTESTS)

# The Installer
install: $(TARGET)
	@install -d $(PREFIX)/include/$(notdir $(shell pwd))
	@install -d $(PREFIX)/lib/$(notdir $(shell pwd))
	@install -d $(PREFIX)/bin
	@install $(TARGET) $(PREFIX)/lib/$(notdir $(shell pwd))
	@cp -r include/$(notdir $(shell pwd)) $(PREFIX)/include/

# The Uninstaller
uninstall:
	@rm -rf $(PREFIX)/include/$(notdir $(shell pwd))
	@rm -rf $(PREFIX)/lib/$(notdir $(shell pwd))
	@rm -rf $(PREFIX)/lib/$(notdir $(shell pwd))

# The Remote Copier
rcopy:
	@scp $(TARGET) $(REMOTE)

# The Helpful Preprocessor
$(PREPROC_OBJECTS): | $(PREPROCDIR)
preprocessor: $(PREPROC_OBJECTS)

# The Cleaner
clean:
	@rm -rf $(LIBDIR) $(LOGDIR) $(BINDIR) $(OBJDIR) $(PREPROCDIR) $(TESTS) \
	config.status config.log autom4te.cache *.o *~

# The Super Cleaner
veryclean: clean
	@rm -rf $(ANALYSIS_ROOT) $(RELEASE_DIR) $(REPORTDIR) $(DOCDIR)/latex $(DOCDIR)/html

# The Documenter
documentation: | $(DOCDIR)
	@cd $(DOCDIR) && doxygen Doxyfile

###############################################################################
# Pattern Rules
###############################################################################
# For compiling the C source and test harness
$(MPI_SRC_C): %.o: %.c
	$(call make-depend-cc,$<,$@,$(subst .o,.d,$@))
	mpicc $(CFLAGS) $(CLIBDIRS) -c -o  $@ $<

$(OBJDIR)/%.o:: %.c
	$(call make-depend-cc,$<,$@,$(subst .o,.d,$@))
	$(CC) $(CFLAGS) $(CLIBDIRS) -c -o  $@ $<

# For compiling the C++ source and test harness
$(OBJDIR)/%.o:: %.cpp
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	$(CXX) $(CXXFLAGS) $(CXXLIBDIRS) -c -o  $@ $<

# For compiling the C tests
$(BINDIR)/%:: %.c
	$(call make-depend-cc,$<,$@,$(OBJDIR)/$*.d)
	$(CC) $(CFLAGS) $(CLIBDIRS) $(addprefix $(OBJDIR)/,$(TH_OBJECTS)) $< -o $@ $(CLIBS)

# For compiling the C++ tests
$(BINDIR)/%:: %.cpp
	$(call make-depend-cxx,$<,$@,$(OBJDIR)/$*.d)
	$(CXX) $(CXXFLAGS) $(CXXLIBDIRS) $(addprefix $(OBJDIR)/,$(TH_OBJECTS)) $< -o $@ $(CXXLIBS)

# For getting preprocessor C/C++ output
$(PREPROCDIR)/%.preproc: %.c
	$(CC) $(CFLAGS) $(CINCDIRS) -E $< -o $@

$(PREPROCDIR)/%.preproc: %.cpp
	$(CXX) $(CXXFLAGS) $(CXXINCDIRS) -E $< -o $@
