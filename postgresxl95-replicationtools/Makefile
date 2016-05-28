# $NetBSD: Makefile,v 1.1 2015/01/14 21:01:19 adam Exp $

PKGNAME=	${DISTNAME:C/-xl-/xl95-replicationtools-/}
COMMENT=	Postgres-XL replication tools

.include "../../zeroae/postgresxl95/Makefile.common"

BUILD_DIRS+=		contrib/pg_standby

.include "../../zeroae/postgresxl95-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
