# New ports collection makefile for:	varnish-nagios
# Date created:				2012-04-15
# Whom:					anders
#
# $FreeBSD$
#

PORTNAME=	varnish-nagios
DISTVERSION=	1.1
CATEGORIES=	www
MASTER_SITES=	http://repo.varnish-cache.org/source/ \
		http://anders.fupp.net/distfiles/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Nagios plugin to check status of Varnish

BUILD_DEPENDS=	${LOCALBASE}/include/varnish/varnishapi.h:${PORTSDIR}/www/varnish

LICENSE=	BSD

GNU_CONFIGURE=	yes

USE_GNOME=	pkgconfig

PLIST_DIRSTRY=	libexec/nagios
PLIST_FILES=	libexec/nagios/check_varnish

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_varnish ${PREFIX}/libexec/nagios

.include <bsd.port.mk>
