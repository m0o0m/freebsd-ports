--- src/unix-gcc.mak.orig	Tue Feb  5 09:20:42 2002
+++ src/unix-gcc.mak	Fri Feb  8 05:16:49 2002
@@ -27,14 +27,15 @@
 # source, generated intermediate file, and object directories
 # for the graphics library (GL) and the PostScript/PDF interpreter (PS).
 
-BINDIR=./bin
-GLSRCDIR=./src
-GLGENDIR=./obj
-GLOBJDIR=./obj
-PSSRCDIR=./src
-PSLIBDIR=./lib
-PSGENDIR=./obj
-PSOBJDIR=./obj
+.CURDIR?=.
+BINDIR=${.CURDIR}/bin
+GLSRCDIR=${.CURDIR}/src
+GLGENDIR=${.CURDIR}/obj
+GLOBJDIR=${.CURDIR}/obj
+PSSRCDIR=${.CURDIR}/src
+PSLIBDIR=${.CURDIR}/lib
+PSGENDIR=${.CURDIR}/obj
+PSOBJDIR=${.CURDIR}/obj
 
 # Do not edit the next group of lines.
 
@@ -53,17 +54,17 @@
 # the directories also define the default search path for the
 # initialization files (gs_*.ps) and the fonts.
 
-INSTALL = $(GLSRCDIR)/instcopy -c
-INSTALL_PROGRAM = $(INSTALL) -m 755
-INSTALL_DATA = $(INSTALL) -m 644
+INSTALL_PROGRAM = $(BSD_INSTALL_SCRIPT)
+INSTALL_DATA = $(BSD_INSTALL_DATA)
 
-prefix = /usr/local
+prefix = $(PREFIX)
 exec_prefix = $(prefix)
 bindir = $(exec_prefix)/bin
 scriptdir = $(bindir)
 libdir = $(exec_prefix)/lib
 mandir = $(prefix)/man
 man1ext = 1
+man1dir = $(mandir)/man$(man1ext)
 datadir = $(prefix)/share
 gsdir = $(datadir)/ghostscript
 gsdatadir = $(gsdir)/$(GS_DOT_VERSION)
@@ -103,14 +104,6 @@
 #	  No execution time or space penalty.
 
 GENOPT=
-# Choose capability options.
-
-# -DHAVE_MKSTEMP
-#	uses mkstemp instead of mktemp
-#		This gets rid of several security warnings that look
-#		ominous.  Enable this if you wish to get rid of them.
-
-CAPOPT= -DHAVE_MKSTEMP
 
 # Choose capability options.
 
@@ -121,7 +114,6 @@
 
 CAPOPT= -DHAVE_MKSTEMP
 
-
 # Define the name of the executable file.
 
 GS=gs
@@ -147,7 +139,7 @@
 # You may need to change this if the IJG library version changes.
 # See jpeg.mak for more information.
 
-JSRCDIR=jpeg
+JSRCDIR=${.CURDIR}/jpeg
 JVERSION=6
 
 # Choose whether to use a shared version of the IJG JPEG library (-ljpeg).
@@ -167,14 +159,14 @@
 # You may need to change this if the libpng version changes.
 # See libpng.mak for more information.
 
-PSRCDIR=libpng
+PSRCDIR=${LOCALBASE}/include
 PVERSION=10012
 
 # Choose whether to use a shared version of the PNG library, and if so,
 # what its name is.
 # See gs.mak and Make.htm for more information.
 
-SHARE_LIBPNG=0
+SHARE_LIBPNG=1
 LIBPNG_NAME=png
 
 # Define the directory where the zlib sources are stored.
@@ -186,7 +178,7 @@
 # what its name is (usually libz, but sometimes libgz).
 # See gs.mak and Make.htm for more information.
 
-SHARE_ZLIB=0
+SHARE_ZLIB=1
 #ZLIB_NAME=gz
 ZLIB_NAME=z
 
@@ -197,6 +189,8 @@
 IJSSRCDIR=ijs
 IJSEXECTYPE=unix
 
+STPLIB=gimpprint
+
 # Define how to build the library archives.  (These are not used in any
 # standard configuration.)
 
@@ -208,7 +202,7 @@
 
 # Define the name of the C compiler.
 
-CC=gcc
+CC?=cc
 
 # Define the name of the linker for the final link step.
 # Normally this is the same as the C compiler.
@@ -225,9 +219,9 @@
 # Define the added flags for standard, debugging, profiling 
 # and shared object builds.
 
-CFLAGS_STANDARD=-O2
-CFLAGS_DEBUG=-g -O
-CFLAGS_PROFILE=-pg -O2
+CFLAGS_STANDARD?=-O2
+CFLAGS_DEBUG=-g
+CFLAGS_PROFILE=-pg
 CFLAGS_SO=-fPIC
 
 # Define the other compilation flags.  Add at most one of the following:
@@ -241,7 +235,7 @@
 # We don't include -ansi, because this gets in the way of the platform-
 #   specific stuff that <math.h> typically needs; nevertheless, we expect
 #   gcc to accept ANSI-style function prototypes and function definitions.
-XCFLAGS=
+XCFLAGS+=-I${.CURDIR}/gimp-print
 
 CFLAGS=$(CFLAGS_STANDARD) $(GCFLAGS) $(XCFLAGS)
 
@@ -252,7 +246,7 @@
 #	-R /usr/local/xxx/lib:/usr/local/lib
 # giving the full path names of the shared library directories.
 # XLDFLAGS can be set from the command line.
-XLDFLAGS=
+XLDFLAGS=-L${.CURDIR}/gimp-print -L${LOCALBASE}/lib
 
 LDFLAGS=$(XLDFLAGS) -fno-common
 
@@ -285,7 +279,7 @@
 # Note that x_.h expects to find the header files in $(XINCLUDE)/X11,
 # not in $(XINCLUDE).
 
-XINCLUDE=-I/X11R6/include
+XINCLUDE=-I${X11BASE}/include
 
 # Define the directory/ies and library names for the X11 library files.
 # XLIBDIRS is for ld and should include -L; XLIBDIR is for LD_RUN_PATH
@@ -297,12 +291,12 @@
 # Solaris and other SVR4 systems with dynamic linking probably want
 #XLIBDIRS=-L/usr/openwin/lib -R/usr/openwin/lib
 # X11R6 (on any platform) may need
-#XLIBS=Xt SM ICE Xext X11
+XLIBS=Xt SM ICE Xext X11
 
 #XLIBDIRS=-L/usr/local/X/lib
-XLIBDIRS=-L/usr/X11R6/lib
+XLIBDIRS=-L${X11BASE}/lib
 XLIBDIR=
-XLIBS=Xt Xext X11
+#XLIBS=Xt Xext X11
 
 # Define whether this platform has floating point hardware:
 #	FPU_TYPE=2 means floating point is faster than fixed point.
