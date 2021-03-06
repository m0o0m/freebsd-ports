# New ports collection makefile for:	ogmtools
# Date created:		Sun Oct 20 13:06:13 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogmtools
PORTVERSION=	1.5
PORTREVISION=	9
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.bunkus.org/videotools/ogmtools/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create OGG media streams

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ogg-prefix=${LOCALBASE} \
  		--with-vorbis-prefix=${LOCALBASE}
MAKE_JOBS_SAFE=	yes

MAN1=		ogmcat.1 ogmdemux.1 ogminfo.1 ogmmerge.1 ogmsplit.1

OPTIONS_DEFINE=	DVDREAD
OPTIONS_DEFAULT=	DVDREAD
DVDREAD_DESC=	DVD title chapter extraction via libdvdread

post-patch:
# disable GNU auto* tools
	@${FIND} ${WRKSRC} -type f -name "Makefile.in" | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E -e \
		's!^(ACLOCAL|AUTOCONF|AUTOMAKE|AUTOHEADER).+$$!\1=${TRUE}!'
# C{,XX}FLAGS safeness
	@${REINPLACE_CMD} -E -e \
		's|^(CFLAGS).*(-DLINUX)|\1=${CFLAGS} \2|' \
		${WRKSRC}/avilib/Makefile.in
	@${REINPLACE_CMD} -E -e \
		's|^(CFLAGS[[:space:]]*)=|\1+=|; \
		s|^(CXXFLAGS[[:space:]]*)=|\1+=|' \
		${WRKSRC}/Makefile.in

post-configure:
# malloc.h -> stdlib.h
# stdint.h -> inttypes.h
	@${FIND} ${WRKSRC} -type f | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E -e \
		's!malloc.h!stdlib.h!; \
		s|stdint.h|inttypes.h|'

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDVDREAD}
LIB_DEPENDS+=	dvdread.4:${PORTSDIR}/multimedia/libdvdread

CONFIGURE_ARGS+=	--with-dvdread \
			--with-dvdread-includes=${LOCALBASE} \
			--with-dvdread-libs=${LOCALBASE}
PLIST_SUB+=	DVDREAD=""

MAN1+=	dvdxchap.1
.else
CONFIGURE_ARGS+=	--without-dvdread
PLIST_SUB+=	DVDREAD="@comment "
.endif

.include <bsd.port.mk>
