## Copyright (c) 2009-2014  Openismus GmbH <http://www.openismus.com/>
##
## This file is part of cluttermm.
##
## cluttermm is free software: you can redistribute it and/or modify it
## under the terms of the GNU Lesser General Public License as published
## by the Free Software Foundation, either version 2.1 of the License,
## or (at your option) any later version.
##
## cluttermm is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
## See the GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.

AC_INIT([cluttermm], [1.23.1],
        [http://bugzilla.gnome.org/enter_bug.cgi?product=cluttermm],
        [cluttermm], [http://www.gtkmm.org/])
AC_PREREQ([2.59])

AC_CONFIG_SRCDIR([clutter/cluttermm.h])
AC_CONFIG_AUX_DIR([build])
AC_CONFIG_MACRO_DIR([build])
AC_CONFIG_HEADERS([build/config.h clutter/cluttermmconfig.h])

AM_INIT_AUTOMAKE([1.9 -Wno-portability check-news no-dist-gzip dist-xz tar-ustar no-define nostdinc])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES])
AM_MAINTAINER_MODE
AC_ARG_VAR([ACLOCAL_FLAGS], [aclocal flags, e.g. -I <macro dir>])

MM_PREREQ([0.9.8])
MM_INIT_MODULE([cluttermm-1.0])

# Copy the mm-common .pl scripts into docs/,
# and use them from there,
# so we can dist them to avoid a tarball-build dependency.
MM_CONFIG_DOCTOOL_DIR([doc])

# http://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html
AC_SUBST([CLUTTERMM_SO_VERSION], [1:0:0])

AC_PROG_CXX
MM_AX_CXX_COMPILE_STDCXX_11([noext],[mandatory])

AC_DISABLE_STATIC
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL

AC_SUBST([CLUTTERMM_MODULES], ['clutter-1.0 >= 1.24.0 pangomm-1.4 >= 2.37.2 atkmm-1.6 >= 2.23.3'])
PKG_CHECK_MODULES([CLUTTERMM], [$CLUTTERMM_MODULES])
MM_PKG_CONFIG_SUBST([GMMPROC_DIR], [--variable=gmmprocdir glibmm-2.4])
MM_PKG_CONFIG_SUBST([GMMPROC_EXTRA_M4_DIR], [--variable=gmmprocm4dir pangomm-1.4 atkmm-1.6])

PKG_CHECK_MODULES([CLUTTERMM_EXAMPLES], [$CLUTTERMM_MODULES] gtkmm-3.0 >= 3.17.90)

MM_ARG_ENABLE_DOCUMENTATION
MM_ARG_WITH_TAGFILE_DOC([libstdc++.tag], [mm-common-libstdc++])
MM_ARG_WITH_TAGFILE_DOC([libsigc++-2.0.tag], [sigc++-2.0])
MM_ARG_WITH_TAGFILE_DOC([glibmm-2.4.tag], [glibmm-2.4])
MM_ARG_WITH_TAGFILE_DOC([cairomm-1.0.tag], [cairomm-1.0])
MM_ARG_WITH_TAGFILE_DOC([pangomm-1.4.tag], [pangomm-1.4])
MM_ARG_WITH_TAGFILE_DOC([atkmm-1.6.tag], [atkmm-1.6])

AC_LANG([C++])
MM_ARG_ENABLE_WARNINGS([CLUTTERMM_WXXFLAGS],
                       [-Wall],
                       [-pedantic -Wall -Wextra -Wformat-security -Wno-long-long -DGSEAL_ENABLE],
                       [G PANGO ATK GDK GDK_PIXBUF CLUTTER GLIBMM ATKMM PANGOMM CAIROMM SIGCXX])

AC_CONFIG_FILES([Makefile
                 codegen/Makefile
                 clutter/${CLUTTERMM_MODULE_NAME}.pc:clutter/cluttermm.pc.in
                 clutter/${CLUTTERMM_MODULE_NAME}-uninstalled.pc:clutter/cluttermm-uninstalled.pc.in
                 clutter/src/Makefile
                 clutter/cluttermm/Makefile
                 examples/Makefile
                 tests/Makefile
                 doc/Makefile
                 doc/reference/Doxyfile])
AC_OUTPUT
