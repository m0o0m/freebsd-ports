# New ports collection makefile for:	xcalendar-4.0
# Date created:		25 June 1996
# Whom:			MITA Yoshio <mita@iis.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xcalendar
PORTVERSION=	4.0.2008
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_PORTS_JP}
DISTNAME=	${PORTNAME}-4.0+i18n

MAINTAINER=	sarumaru@jp.FreeBSD.org
COMMENT=	A calendar with a notebook for X11 (internationalized version)

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xt
USE_GMAKE=	yes
MAKE_ENV=	FILESDIR=${FILESDIR}
ALL_TARGET=	all XCal-uj.ad xcalendar-uj.hlp xcalendar-uj.man
MAN1=		xcalendar.1
MANLANG=	"" ja

.include <bsd.port.mk>
