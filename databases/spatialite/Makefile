# New ports collection makefile for:	spatialite
# Date created:				11 July 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	spatialite
PORTVERSION=	3.0.1
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Spatial Extensions for SQLite

LIB_DEPENDS=	geos_c.8:${PORTSDIR}/graphics/geos \
		proj.7:${PORTSDIR}/graphics/proj \
		freexl.1:${PORTSDIR}/textproc/freexl

EXTRACT_SUFX =	.tar.gz
WRKSRC=		${WRKDIR}/lib${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SQLITE=	yes
USE_ICONV=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
