# New ports collection makefile for:	mailwatch plugin for xfce4
# Date created:				23 Januar 2007
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xfce4-mailwatch-plugin
PORTVERSION=	1.1.0
PORTREVISION=	15
CATEGORIES=	mail xfce
MASTER_SITES=	http://spuriousinterrupt.org/files/mailwatch/ \
		http://freebsd.unixfreunde.de/sources/
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	A mailwatch plugin for Xfce

LIB_DEPENDS=	gnutls.47:${PORTSDIR}/security/gnutls \
		gcrypt.18:${PORTSDIR}/security/libgcrypt

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui libutil panel
USE_XORG=	x11 xt xaw

post-patch:
	@${REINPLACE_CMD} -e 's|--libs "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g; \
		s|--cflags "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g' \
		${WRKSRC}/configure
post-configure:
	@${REINPLACE_CMD} -e 's|-lgnutls|-lgnutls -lgcrypt|g' \
		${WRKSRC}/panel-plugin/Makefile

.include <bsd.port.mk>
