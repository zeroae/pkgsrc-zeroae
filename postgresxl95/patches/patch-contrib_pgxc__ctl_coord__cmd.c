$NetBSD$

--- contrib/pgxc_ctl/coord_cmd.c.orig	2016-05-12 08:20:42.000000000 +0000
+++ contrib/pgxc_ctl/coord_cmd.c
@@ -1220,6 +1220,18 @@ int add_coordinatorMaster(char *name, ch
 			fprintf(f, "\\q\n");
 			pclose(f);
 		}
+		else if (strcmp(aval(VAR_coordNames)[ii], name) == 0)
+		{
+			if ((f = pgxc_popen_wRaw("psql -h %s -p %d %s", host, atoi(port), sval(VAR_defaultDatabase))) == NULL)
+			{
+				elog(ERROR, "ERROR: cannot connect to the coordinator master %s.\n", host);
+				continue;
+			}                                                                                                                                                                
+			fprintf(f, "UPDATE pgxc_node SET nodeis_preferred=(node_host = '%s') WHERE node_type = 'D';\n", host)
+				fprintf(f, "SELECT pgxc_pool_reload();\n");
+			fprintf(f, "\\q\n");
+			pclose(f);
+		}
 	}
 	/* Issue CREATE NODE on datanodes */
 	for (ii = 0; aval(VAR_datanodeNames)[ii]; ii++)
