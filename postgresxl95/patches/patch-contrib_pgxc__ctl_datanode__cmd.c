diff --git a/contrib/pgxc_ctl/datanode_cmd.c b/contrib/pgxc_ctl/datanode_cmd.c
index 109c0f5..34705f0 100644
--- a/contrib/pgxc_ctl/datanode_cmd.c
+++ b/contrib/pgxc_ctl/datanode_cmd.c
@@ -1263,7 +1263,12 @@ int add_datanodeMaster(char *name, char *host, int port, int pooler, char *dir,
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
