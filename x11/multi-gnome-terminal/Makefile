# New ports collection makefile for:   multi-gnome-terminal
# Date created:		19 March 2002
# Whom:		 	Frederic Dubuy <fdubuy@free.fr>
#
# $FreeBSD$
#   $MCom: ports/x11/multi-gnome-terminal/Makefile,v 1.3 2007/08/07 03:43:51 mezz Exp $
#

PORTNAME=	multi-gnome-terminal
PORTVERSION=	1.6.2
PORTREVISION=	11
CATEGORIES=	x11 gnome
MASTER_SITES=	SF/multignometerm/multignometerm/mgt-${PORTVERSION}

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Gnome tabbed terminal emulator

INSTALLS_OMF=	yes
USE_GNOME=	gnomehack gnomeprefix libglade
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		mgt-helper.1 multi-gnome-terminal.1

post-patch:
	@${REINPLACE_CMD} -e 's|NO_XALF ||' ${WRKSRC}/gnome-terminal/multi-gnome-terminal.desktop

post-install:
	${INSTALL_DATA} ${WRKSRC}/pixmaps/multignometerm.png \
		${PREFIX}/share/pixmaps/multignometerm.png

.include <bsd.port.mk>
