# New ports collection makefile for: roundup
# Date created:		23 Mar 2003
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	roundup
PORTVERSION=	1.4.19
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	An Issue-Tracking System for Knowledge Workers

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USE_GETTEXT=	yes
USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes

OPTIONS=	SQLITE	"Support Sqlite as backend" on
OPTIONS+=	PGSQL	"Support posggresql as backend" off
OPTIONS+=	MYSQL	"Support mysql as backend" off
OPTIONS+=	NLS	"Native Language Support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SQLITE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopgmodule.so:${PORTSDIR}/databases/py-psycopg
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:${PORTSDIR}/databases/py-MySQLdb
.endif

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		roundup-admin.1 roundup-demo.1 roundup-mailgw.1 \
		roundup-server.1
MANCOMPRESSED=	no
.endif

SCRIPTS=	roundup-admin roundup-demo roundup-gettext roundup-mailgw \
		roundup-server roundup-xmlrpc-server

post-install:
	@${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/build/scripts-${PYTHON_VER}/,} ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/share/man/man1/,} ${MAN1PREFIX}/man/man1
.endif
.if !defined(WITHOUT_NLS)
	@(cd ${WRKSRC}/build/share/locale/ && ${COPYTREE_SHARE} \* ${PREFIX}/share/locale/)
.endif

.include <bsd.port.post.mk>
