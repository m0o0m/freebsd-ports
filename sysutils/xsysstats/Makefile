# ex:ts=8
# Ports collection makefile for:  xsysstats
# Date created:			  12 December 1994
# Whom:				  asami
#
# $FreeBSD$
#

PORTNAME=	xsysstats
PORTVERSION=	1.51
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system information display tool

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	x11
MAN1=		xsysstats.1

ALL_TARGET=	xsysstats

PLIST_FILES=	bin/xsysstats

pre-patch:
	${RM} ${WRKSRC}/headers.h && ${TOUCH} ${WRKSRC}/headers.h

.include <bsd.port.mk>
