--- cpp.orig/src/IceGrid/InternalRegistryI.h	2011-06-15 21:43:59.000000000 +0200
+++ cpp/src/IceGrid/InternalRegistryI.h	2012-03-04 19:55:44.000000000 +0100
@@ -68,6 +68,8 @@
     ReplicaSessionManager& _session;
     int _nodeSessionTimeout;
     int _replicaSessionTimeout;
+    bool _requireNodeCertCN;
+    bool _requireReplicaCertCN;
 };
     
 };
