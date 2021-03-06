# New ports collection makefile for:	optipng
# Date created:				09 July 2003
# Whom:					Thomas Hurst <freaky@aagh.net>
#
# $FreeBSD$
#

PORTNAME=	optipng
PORTVERSION=	0.6.5
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/OptiPNG/${PORTNAME}-${PORTVERSION}

MAINTAINER=	tom@hur.st
COMMENT=	An optimizer for PNG files

OPTIONS=	BUNDLED_LIBPNG	"Use bundled libpng"	off \
		BUNDLED_ZLIB	"Use bundled zlib"	off

HAS_CONFIGURE=	yes
BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	scripts/unix.mak
ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/optipng
MAN1=		optipng.1
PORTDOCS=	caveat.txt history.txt manual.html manual.pdf manual.txt \
		png_optimization_guide.html thanks.html todo.txt

.include <bsd.port.options.mk>

.ifndef(WITH_BUNDLED_LIBPNG)
BROKEN=		does not build with libpng 1.5.x
CONFIGURE_ARGS+=	--with-system-libpng
CFLAGS+=	"-I${LOCALBASE}/include"
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
.endif

.ifndef(WITH_BUNDLED_ZLIB)
CONFIGURE_ARGS+=	--with-system-zlib
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/optipng ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/optipng.1 ${MAN1PREFIX}/man/man1/

post-install:
.ifndef NOPORTDOCS
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
