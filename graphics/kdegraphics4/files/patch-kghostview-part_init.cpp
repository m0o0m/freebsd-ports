--- /dev/null	1 Jan 1970 00:00:00 -0000
+++ kghostview/part_init.cpp	15 Mar 2004 10:29:55 -0000
@@ -0,0 +1,22 @@
+// part_init.cpp
+// Copyright (C)  2004  Dominique Devriese <devriese@kde.org>
+
+// This program is free software; you can redistribute it and/or
+// modify it under the terms of the GNU General Public License
+// as published by the Free Software Foundation; either version 2
+// of the License, or (at your option) any later version.
+
+// This program is distributed in the hope that it will be useful,
+// but WITHOUT ANY WARRANTY; without even the implied warranty of
+// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+// GNU General Public License for more details.
+
+// You should have received a copy of the GNU General Public License
+// along with this program; if not, write to the Free Software
+// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
+// 02111-1307, USA.
+
+#include "kgvfactory.h"
+
+K_EXPORT_COMPONENT_FACTORY( libkghostviewpart, KGVFactory )
+
