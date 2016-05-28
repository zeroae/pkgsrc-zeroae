# $NetBSD: Makefile,v 1.1 2015/01/14 21:01:19 adam Exp $

PKGNAME=	${DISTNAME:C/-xl-/xl95-plpython-/}
COMMENT=	PL/Python procedural language for the Postgres-XL backend

DEPENDS+=	postgresxl95-server>=${PKGVERSION_NOREV}:../../zeroae/postgresxl95-server

.include "../../zeroae/postgresxl95/Makefile.common"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plpython

.include "../../zeroae/postgresxl95-client/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
