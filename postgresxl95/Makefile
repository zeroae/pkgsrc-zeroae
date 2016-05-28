# $NetBSD$

PKGNAME=	${DISTNAME:C/-xl-/xl-95-/}
COMMENT=	An all-purpose fully ACID open source scale-out SQL database solution.

DEPENDS+=	postgresxl95-client>=${PKGVERSION_NOREV}:../postgresxl95-client
#DEPENDS+=	postgresql94-docs>=${PKGVERSION_NOREV}:../../databases/postgresql94-docs
#DEPENDS+=	postgresql94-server>=${PKGVERSION_NOREV}:../../databases/postgresql94-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
