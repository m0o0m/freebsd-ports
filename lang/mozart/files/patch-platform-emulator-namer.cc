--- ./platform/emulator/namer.cc.orig	Fri Aug  2 16:20:44 2002
+++ ./platform/emulator/namer.cc	Sat Sep  3 18:46:09 2005
@@ -8,8 +8,8 @@
  *    Organization or Person (Year(s))
  * 
  *  Last change:
- *    $Date$ by $Author$
- *    $Revision$
+ *    $Date$ by $Author$
+ *    $Revision$
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -30,10 +30,11 @@
 //-----------------------------------------------------------------------------
 // naming variables
 
+template class Namer<OZ_Term, const char *>;
+
 typedef Namer<OZ_Term, const char *> VarNamer;
-template VarNamer;
 
-VarNamer * VarNamer::_head;
+template <> VarNamer * VarNamer::_head = NULL;
 
 VarNamer varNamer; 
 
@@ -94,10 +95,11 @@
 //-----------------------------------------------------------------------------
 // naming propagators
 
-typedef Namer<Propagator *, OZ_Term> PropNamer;
-template PropNamer;
+template class Namer<Propagator *, OZ_Term>;
+
+typedef class Namer<Propagator *, OZ_Term> PropNamer;
 
-PropNamer * PropNamer::_head;
+template <> PropNamer * PropNamer::_head = NULL;
 
 PropNamer propNamer; 
 
