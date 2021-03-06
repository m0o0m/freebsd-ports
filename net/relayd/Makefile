# New ports collection makefile for: relayd
# Date created:         5 Jun 2007
# Whom:                 Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	relayd
PORTVERSION=	5.1.20120305
CATEGORIES=	net
MASTER_SITES=	https://github.com/downloads/mmatuska/relayd/

FETCH_ARGS=	-pRr
MASTER_SITE_SUBDIR=	mm

MAINTAINER=	mm@FreeBSD.org
COMMENT=	OpenBSD relay daemon

LICENSE=	BSD

DISTNAME=	${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
MANCOMPRESSED=	yes

WRKSRC=		${WRKDIR}/src/usr.sbin
MAN5=		relayd.conf.5
MAN8=		relayctl.8 relayd.8
USE_RC_SUBR=	relayd

CFLAGS+=	-I${PREFIX}/include -Wall

MAKE_ARGS+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

USERS=		_relayd
GROUPS=		_relayd

OPTIONS=	LIBEVENT_STATIC "Build with static libevent" Off

.include <bsd.port.pre.mk>

.if defined(WITH_LIBEVENT_STATIC)
BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent
MAKE_ARGS+=	LIBEVENT=${LOCALBASE}/lib/libevent.a
.else
LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent
MAKE_ARGS+=	LIBEVENT=-levent
.endif

.if ${OSVERSION} < 800041
BROKEN=		does not build on FreeBSD 7.X
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/relayd/relay.c \
		${WRKSRC}/relayd/relayd.h \
		${WRKSRC}/relayd/relayd.conf.5 \
		${WRKSRC}/relayd/relayd.8

post-install:
	@${INSTALL_DATA} ${WRKSRC}/../etc/relayd.conf \
		${PREFIX}/etc/relayd.conf.sample
	@${CP} -n ${PREFIX}/etc/relayd.conf.sample \
		${PREFIX}/etc/relayd.conf

.include <bsd.port.post.mk>
