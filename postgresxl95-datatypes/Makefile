# $NetBSD: Makefile,v 1.3 2015/05/27 13:27:28 adam Exp $

PKGNAME=	${DISTNAME:C/-xl-/xl95-datatypes-/}
COMMENT=	Postgres-XL data types support modules

DEPENDS+=	postgresxl95-server>=${PKGVERSION_NOREV}:../../zeroae/postgresxl95-server

.include "../../zeroae/postgresxl95/Makefile.common"

PLIST_VARS+=		uuid

.if ${OPSYS} != "Darwin"
PLIST.uuid=		yes
CONFIGURE_ARGS+=	--with-uuid=ossp
BUILD_DIRS+=		contrib/uuid-ossp
.include "../../devel/ossp-uuid/buildlink3.mk"

MAKE_FLAGS+=	UUID_LIBS=-lossp-uuid
.endif

BUILD_DIRS+=		contrib/btree_gist
BUILD_DIRS+=		contrib/citext
BUILD_DIRS+=		contrib/hstore
BUILD_DIRS+=		contrib/intarray
BUILD_DIRS+=		contrib/isn
BUILD_DIRS+=		contrib/ltree
BUILD_DIRS+=		contrib/lo
BUILD_DIRS+=		contrib/unaccent
BUILD_MAKE_FLAGS=	USE_PGXS=1

.include "../../zeroae/postgresxl95-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
