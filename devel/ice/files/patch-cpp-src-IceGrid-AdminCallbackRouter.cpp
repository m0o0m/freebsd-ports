--- cpp.orig/src/IceGrid/AdminCallbackRouter.cpp	2011-06-15 21:43:59.000000000 +0200
+++ cpp/src/IceGrid/AdminCallbackRouter.cpp	2012-03-04 20:14:53.000000000 +0100
@@ -49,7 +49,12 @@
 #ifndef NDEBUG
     bool inserted =
 #endif
-        _categoryToConnection.insert(map<string, ConnectionPtr>::value_type(category, con)).second;
+        _categoryToConnection.insert(map<string, ConnectionPtr>::value_type(category, con))
+#ifndef NDEBUG
+        .second
+#endif
+        ;
+
     
     assert(inserted == true);
 }
