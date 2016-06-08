$NetBSD$

--- contrib/pgxc_ctl/datanode_cmd.c.orig	2016-05-12 08:20:42.000000000 +0000
+++ contrib/pgxc_ctl/datanode_cmd.c
@@ -1263,7 +1263,12 @@ int add_datanodeMaster(char *name, char
 				elog(ERROR, "ERROR: cannot connect to the coordinator master %s.\n", aval(VAR_coordNames)[ii]);
 				continue;
 			}
-			fprintf(f, "CREATE NODE %s WITH (TYPE = 'datanode', host='%s', PORT=%d);\n", name, host, port);
+			if (strcmp(aval(VAR_coordMasterServers)[ii], host) == 0)
+				/* Preferred node */
+				fprintf(f, "CREATE NODE %s WITH (TYPE = 'datanode', host='%s', PORT=%d, PREFERRED);\n", name, host, port);
+			else
+				/* non-Preferred node */
+				fprintf(f, "CREATE NODE %s WITH (TYPE = 'datanode', host='%s', PORT=%d);\n", name, host, port);
 			fprintf(f, "SELECT pgxc_pool_reload();\n");
 			fprintf(f, "\\q\n");
 			pclose(f);
