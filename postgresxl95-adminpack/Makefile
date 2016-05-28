# $NetBSD: Makefile,v 1.1 2015/01/14 21:01:18 adam Exp $

PKGNAME=	${DISTNAME:C/-xl-/xl95-adminpack-/}
COMMENT=	Admin pack module for pgAdmin management

DEPENDS+=	postgresxl95-server>=${PKGVERSION_NOREV}:../../zeroae/postgresxl95-server

.include "../../zeroae/postgresxl95/Makefile.common"

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/adminpack

.include "../../zeroae/postgresxl95-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
