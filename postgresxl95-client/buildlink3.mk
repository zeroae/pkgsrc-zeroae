# $NetBSD: buildlink3.mk,v 1.1 2015/01/14 21:01:18 adam Exp $

BUILDLINK_TREE+=	postgresxl95-client

.if !defined(POSTGRESXL95_CLIENT_BUILDLINK3_MK)
POSTGRESXL95_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresxl95-client+=	postgresxl95-client>=9.5.0
BUILDLINK_ABI_DEPENDS.postgresxl95-client+=	postgresxl95-client>=9.5.0
BUILDLINK_PKGSRCDIR.postgresxl95-client?=	../postgresxl95-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresxl95-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresxl95-client+=	bin/pg_config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # POSTGRESXL95_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresxl95-client
