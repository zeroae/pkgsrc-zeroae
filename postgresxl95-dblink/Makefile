# $NetBSD: Makefile,v 1.1 2015/01/14 21:01:19 adam Exp $

PKGNAME=	${DISTNAME:C/-xl-/xl95-dblink-/}
COMMENT=	Dblink module for remote database connections

DEPENDS+=	postgresxl95-server>=${PKGVERSION_NOREV}:../../zeroae/postgresxl95-server

.include "../../zeroae/postgresxl95/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl
BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/dblink

.include "../../zeroae/postgresxl95-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
