# New ports collection makefile for:	openobex
# Date created:				15 March 2004
# Whom:					Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	openobex
PORTVERSION=	1.4
CATEGORIES=	comms net
MASTER_SITES=	${MASTER_SITE_KERNEL_ORG}
MASTER_SITE_SUBDIR=	linux/bluetooth

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open source implementation of the OBEX protocol

USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	USB

USB_DESC=	Enable OBEX over USB

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUSB}
. if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
CFLAGS+=	-I${PREFIX}/include
. else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure
. endif
CONFIGURE_ARGS+=--enable-usb
.else
CONFIGURE_ARGS+=--disable-usb
.endif

.include <bsd.port.mk>
