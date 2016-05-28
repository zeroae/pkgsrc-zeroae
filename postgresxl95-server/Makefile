# $NetBSD: Makefile,v 1.1 2015/01/14 21:01:19 adam Exp $

PKGNAME=	${DISTNAME:C/-xl-/xl95-server-/}
COMMENT=	Postgres-XL database server programs

# mips has no TAS implementation
BROKEN_ON_PLATFORM=	*-*-mips

.include "../../zeroae/postgresxl95/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl

INSTALL_DIRS=	src/gtm
INSTALL_DIRS+=	src/timezone
INSTALL_DIRS+=	src/backend
INSTALL_DIRS+=	src/backend/utils/mb/conversion_procs
INSTALL_DIRS+=	src/backend/snowball
INSTALL_DIRS+=	src/backend/replication/libpqwalreceiver
INSTALL_DIRS+=	src/bin/initdb
INSTALL_DIRS+=	src/bin/initgtm
INSTALL_DIRS+=	src/bin/pg_archivecleanup
INSTALL_DIRS+=	src/bin/pg_controldata
INSTALL_DIRS+=	src/bin/pg_ctl
INSTALL_DIRS+=	src/bin/pg_resetxlog
INSTALL_DIRS+=	src/bin/pg_rewind
INSTALL_DIRS+=	src/bin/pg_test_fsync
INSTALL_DIRS+=	src/bin/pg_test_timing
INSTALL_DIRS+=	src/bin/pg_upgrade
INSTALL_DIRS+=	src/bin/pg_xlogdump
INSTALL_DIRS+=	src/pl
BUILD_DIRS=	src/common
BUILD_DIRS+=	src/port
BUILD_DIRS+=	src/interfaces
BUILD_DIRS+=	${INSTALL_DIRS}

LIBS.SunOS+=	-lintl

# PostgreSQL has loadable server-side language modules.
#
# Explicitly set DLOPEN_REQUIRE_PTHREADS to "no" on NetBSD as NetBSD-2.x
# had problems with mixing dlopen() and pthreads, which blows up in
# PostgreSQL's backend (pkg/28729).  This works on older and newer
# versions of NetBSD as well since they don't have the bad interaction
# between dlopen() and pthreads.
.if ${OPSYS} == "NetBSD"
DLOPEN_REQUIRE_PTHREADS=	no
.endif
.include "../../mk/dlopen.buildlink3.mk"

# If we're using libltdl to provide "dlopen" functionality, then add the
# dependency and make sure that we link against -lltdl.
.if !empty(USE_LIBLTDL:M[yY][eE][sS])
DL_LIBS+=	-lltdl
.  include "../../devel/libltdl/buildlink3.mk"
.endif

# PGUSER	username of the database administrator
# PGGROUP	group of the database administrator
# PGHOME	home directory of the database administrator and location of
#		the databases
FILES_SUBST+=		PGUSER=${PGUSER}
FILES_SUBST+=		PGGROUP=${PGGROUP}
FILES_SUBST+=		PGHOME=${PGHOME}
BUILD_DEFS+=		PGHOME VARBASE

ALL_ENV+=		INSTALLED_LIBPQ=yes

PKG_GROUPS_VARS+=	PGGROUP
PKG_USERS_VARS+=	PGUSER

PKG_GROUPS=		${PGGROUP}
PKG_USERS=		${PGUSER}:${PGGROUP}
PKG_GECOS.${PGUSER}=	PostgreSQL database administrator
PKG_HOME.${PGUSER}=	${PGHOME}

OWN_DIRS_PERMS=		${PGHOME} ${PGUSER} ${PGGROUP} 0700
OWN_DIRS_PERMS+=	${PGHOME}/gtm ${PGUSER} ${PGGROUP} 0700
OWN_DIRS_PERMS+=	${PGHOME}/gtm_proxy ${PGUSER} ${PGGROUP} 0700
OWN_DIRS_PERMS+=	${PGHOME}/coordinator ${PGUSER} ${PGGROUP} 0700
OWN_DIRS_PERMS+=	${PGHOME}/datanode ${PGUSER} ${PGGROUP} 0700
OWN_DIRS_PERMS+=	${VARBASE}/log/pgsql ${PGUSER} ${PGGROUP} 0700

RCD_SCRIPTS=		pgsql
SMF_NAME=		postgresql
SMF_METHODS=		postgresql
SMF_METHODS+=		gtm
SMF_INSTANCES=		coordinator
SMF_INSTANCES+=		datanode
SMF_INSTANCES+=		gtm
SMF_INSTANCES+=		gtm_proxy

.include "../../zeroae/postgresxl95-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

# Avoid conflict between "${SSLBASE}/include/openssl/des.h" and
# "/usr/include/crypt.h" -- we want the definitions in the former.
post-wrapper:
.if ${OPSYS} == "SunOS"
	touch ${BUILDLINK_DIR}/include/crypt.h
.endif

.include "../../mk/bsd.pkg.mk"
