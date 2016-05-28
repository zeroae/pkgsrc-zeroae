# $NetBSD: Makefile,v 1.1 2015/01/14 21:01:19 adam Exp $

PKGNAME=	${DISTNAME:C/-xl-/xl95-monitoring-/}
COMMENT=	Postgres-XL monitoring tools

DEPENDS+=	postgresxl95-server>=${PKGVERSION_NOREV}:../../zeroae/postgresxl95-server

.include "../../zeroae/postgresxl95/Makefile.common"

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS+=		contrib/auto_explain
BUILD_DIRS+=		contrib/pg_buffercache
BUILD_DIRS+=		contrib/pg_stat_statements
BUILD_DIRS+=		contrib/pgstattuple

.include "../../zeroae/postgresxl95-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
