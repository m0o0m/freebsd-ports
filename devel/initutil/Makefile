# ex:ts=8
# Ports collection makefile for:	initutil
# Date created:			Mar 12, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	initutil
PORTVERSION=	2.1.b
CATEGORIES=	devel
MASTER_SITES=	http://www.bdsoft.com/dist/
DISTNAME=	${PORTNAME}2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An STL Container Initialization Library

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_DOS2UNIX=	InitUtil.h

PLIST_FILES=	include/InitUtil.h

do-install:
	@${INSTALL_DATA} ${WRKSRC}/InitUtil.h ${PREFIX}/include

.include <bsd.port.mk>
