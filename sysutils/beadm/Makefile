# New ports collection makefile for:	beadm
# Date created:		26 April 2012
# Whom:			Bryan Drewery <bryan@shatow.net>
#
# $FreeBSD$
#

PORTNAME=	beadm
PORTVERSION=	0.6
CATEGORIES=	sysutils
MASTER_SITES=	SF/beadm/dist/ \
	http://www.shatow.net/freebsd/

MAINTAINER=	bryan@shatow.net
COMMENT=	Solaris-like utility to manage Boot Environments on ZFS

LICENSE=	BSD

NO_BUILD=	YES
USE_BZIP2=	yes

PLIST_FILES=	sbin/${PORTNAME}

MAN1=		${PORTNAME}.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		not supported on 7.x
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1/

.include <bsd.port.post.mk>
