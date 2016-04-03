#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT([Reusable C++ Sofware], [1.0], [john.r.harwell@gmail.com])

# Define command line arguments
AC_ARG_ENABLE([debug],
        [AC_HELP_STRING([--enable-debug=@<:@static/dynamic/no@:>@],
        [Enable debug (static or dynamic) @<:@default=no@:>@])],
        [],
        [enable_debug=no])

AC_ARG_ENABLE([posix],
        [AC_HELP_STRING([--enable-posix=@<:@yes/no@:>@],
        [Enable use of POSIX API @<:@default=yes@:>@])],
        [],
        [enable_posix=yes])

AC_ARG_ENABLE([opt],
        [AC_HELP_STRING([--enable-opt=@<:@yes/no@:>@],
        [Enable optimization @<:@default=no@:>@])],
        [],
        [enable_opt=no])

# Define args
AC_ARG_VAR(DEBUG,Debug level)
AC_ARG_VAR(POSIX,POSIX definitions)
AC_ARG_VAR(CCDEFS,Compiler defines)
AC_ARG_VAR(CCOPTS,Compiler options)
AC_ARG_VAR(ARCHDEFS,Architecture definitions)
AC_ARG_VAR(LIBS,Libraries to link with)

AC_SUBST(target)
AC_SUBST(host)

# Define files to be instantiated
AC_CONFIG_FILES([Makefile:config/Makefile.in])

# Configure optimization
if test "$enable_opt" == yes
then
AC_MSG_NOTICE([optimization enabled])
OPT=-Os
else
AC_MSG_NOTICE([optimization disabled])
OPT=-O0
fi

# Configure target architecture
AC_MSG_CHECKING(target architecture)
case "$target" in
x86*)
        echo "X86"
        TARGET_ARCH="x86"
        ;;
sparc*)
        echo "SPARC"
        TARGET_ARCH="sparc"
        ;;
*)
        echo "Not found"
        AC_MSG_ERROR([ERROR: Target architecture "$target" not supported])
esac

# Configure target OS
AC_MSG_CHECKING(target OS)
case "$host" in
linux*)
        echo "Linux"
        host="linux"
        ;;
rtems*)
        echo "rtems"
        host="rtems"
        ;;
*)
        echo "Not found"
        AC_MSG_ERROR([ERROR: Target OS "$host" not supported])
esac

# When building for Linux
if test "$host" == linux
then

AC_MSG_NOTICE([configuring for Linux])
AC_PROG_CXX
if test "$CXX" == ""
then
AC_MSG_ERROR([Cannot configure for linux without gcc])
fi

if test "$CCDEFS" == ""
then
CCDEFS="-D__linux__"
fi

RTEMS_PATH=""

fi # Linux

# Create all Makefiles for subdirs that do not require additional configuration,
# as well as the main Makefile
AC_OUTPUT
