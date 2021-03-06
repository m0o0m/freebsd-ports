--- cpp.orig/src/IceUtil/RecMutex.cpp	2011-06-15 21:43:59.000000000 +0200
+++ cpp/src/IceUtil/RecMutex.cpp	2012-03-04 20:14:53.000000000 +0100
@@ -148,8 +148,11 @@
 IceUtil::RecMutex::~RecMutex()
 {
     assert(_count == 0);
+#ifndef NDEBUG
     int rc = 0;
-    rc = pthread_mutex_destroy(&_mutex);
+    rc = 
+#endif
+    pthread_mutex_destroy(&_mutex);
     assert(rc == 0);
 }
 
@@ -196,8 +199,11 @@
 {
     if(--_count == 0)
     {
+#ifndef NDEBUG
         int rc = 0; // Prevent warnings when NDEBUG is defined.
-        rc = pthread_mutex_unlock(&_mutex);
+        rc = 
+#endif
+        pthread_mutex_unlock(&_mutex);
         assert(rc == 0);
     }
 }
