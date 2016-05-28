# $NetBSD: Makefile,v 1.1 2015/01/14 21:01:19 adam Exp $

PKGNAME=	${DISTNAME:C/-xl-/xl95-pgxc-/}
COMMENT=	Postgres-XL binary upgrade tool
MAINTAINER=	pkgsrc-users@NetBSD.org

DEPENDS+=	postgresxl95-client>=${PKGVERSION_NOREV}:../../zeroae/postgresxl95-client

.include "../../zeroae/postgresxl95/Makefile.common"

INSTALL_DIRS+=	contrib/pgxc_clean
INSTALL_DIRS+=	contrib/pgxc_ctl
BUILD_DIRS=	src/common
BUILD_DIRS+=	src/port
BUILD_DIRS+=	src/gtm
BUILD_DIRS+=	${INSTALL_DIRS}

LIBS.SunOS+=	-lintl

.include "../../zeroae/postgresxl95-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
