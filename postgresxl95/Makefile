# $NetBSD$

PKGNAME=	${DISTNAME:C/-xl-/xl95-/}
COMMENT=	An all-purpose fully ACID open source scale-out SQL database solution.

DEPENDS+=	postgresxl95-client>=${PKGVERSION_NOREV}:../../zeroae/postgresxl95-client
DEPENDS+=	postgresxl95-docs>=${PKGVERSION_NOREV}:../../zeroae/postgresxl95-docs
DEPENDS+=	postgresxl95-server>=${PKGVERSION_NOREV}:../../zeroae/postgresxl95-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
