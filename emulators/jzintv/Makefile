# New ports collection makefile for: jzintv
# Date created:                      05 Apr 2008
# Whom:                              Ganael Laplanche <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	jzintv
PORTVERSION=	1.0b3
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://spatula-city.org/~im14u2c/intv/dl/
DISTNAME=	jzintv-1.0-beta3-src

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Portable Intellivision(TM) Emulator

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/jzintv-1.0-beta3
BUILD_WRKSRC=	${WRKSRC}/src
USE_GMAKE=	yes
USE_XORG=	x11 xau xdmcp
USE_SDL=	sdl
USE_ZIP=	yes
CPPFLAGS+=	-I${LOCALBASE}/include `${SDL_CONFIG} --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} `${SDL_CONFIG} --libs`

OPTIONS_DEFINE=	TOOLS
TOOLS_DESC=	Install additional tools

TOOLS=		as1600 crc32 dasm1600 dis1600 frombit_r gms2rom imvtoppm rom2bin \
		show_grom tobit tobit_r bin2rom dasm0256 dasm1600o frombit fromhex \
		imvtogif rom_merge split_rom tobit_f tohex

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTOOLS}
PLIST_SUB+=	PL_TOOLS=""
.else
PLIST_SUB+=	PL_TOOLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} '227s|/usr/local/share/jzintv|${DATADIR}|' ${BUILD_WRKSRC}/config.h
	@${CP} ${BUILD_WRKSRC}/Makefile.freebsd ${BUILD_WRKSRC}/Makefile
	@${FIND} ${WRKSRC} -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e 's|dprintf|dbprintf|g'
	@${FIND} ${WRKSRC} -name "*.c.bak" -delete

do-install:
	${MKDIR} ${DATADIR}/rom
	${INSTALL_DATA} ${WRKSRC}/rom/*.rom ${DATADIR}/rom/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/jzintv ${PREFIX}/bin/jzintv
.if ${PORT_OPTIONS:MTOOLS}
.for tool in ${TOOLS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${tool} ${PREFIX}/bin/jzintv-${tool}
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Release-Notes.txt ${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/doc)
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
