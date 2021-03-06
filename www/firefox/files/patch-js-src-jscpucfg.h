--- js/src/jscpucfg.h.orig	2012-01-18 17:38:54.409461514 +0100
+++ js/src/jscpucfg.h	2012-01-18 17:38:59.522462164 +0100
@@ -77,6 +77,19 @@
 #define IS_BIG_ENDIAN 1
 #endif
 
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+
+#if defined(BYTE_ORDER)
+#if BYTE_ORDER == LITTLE_ENDIAN
+#define IS_LITTLE_ENDIAN 1
+#undef  IS_BIG_ENDIAN
+#elif BYTE_ORDER == BIG_ENDIAN
+#undef  IS_LITTLE_ENDIAN
+#define IS_BIG_ENDIAN 1
+#endif
+#endif
+
 #elif defined(JS_HAVE_ENDIAN_H)
 #include <endian.h>
 
