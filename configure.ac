dnl Process this file with autoconf to produce a configure script.

AC_INIT([src/gyrate.cc])

dnl Get rid of all the -D stuff
AM_CONFIG_HEADER(config.h)

dnl automake stuff

AM_INIT_AUTOMAKE([binary], [1.0.3])

dnl Checks for programs.
AC_PROG_CXX
AC_PROG_CC

dnl Initialise libtool
AC_CONFIG_MACRO_DIR([m4])
AC_PROG_LIBTOOL

dnl Make C++ the default
AC_LANG_CPLUSPLUS
AC_REQUIRE_CPP

dnl My other software

AC_CHECK_HEADERS([trm_subs.h trm_position.h trm_constants.h trm_array1d.h],[],AC_MSG_ERROR(cannot find headers associated with 'subs'))

AC_CHECK_LIB([subs], [main], [], [AC_MSG_ERROR(cannot find the subs library)])

dnl Third-party software

AC_CHECK_HEADERS([stdlib.h float.h math.h sstream string fstream iostream], [], AC_MSG_ERROR(missing header; please fix))

AC_CHECK_HEADERS([pcrecpp.h slalib.h], [], AC_MSG_ERROR(missing header; please fix))

AC_CHECK_LIB([pcrecpp], [main], [], AC_MSG_ERROR(cannot find the pcre C++ library))

AC_CHECK_LIB([csla], [main], [], AC_MSG_ERROR(cannot find the sla C library))

dnl PGPLOT has its own macro 'cos its a pain
TRM_LIB_PGPLOT

dnl Installation program
AC_PROG_INSTALL

dnl The Makefiles to create

AC_OUTPUT([Makefile include/Makefile src/Makefile doc/Makefile]) 
