# New ports collection makefile for:	nut
# Date created:		Tue Apr 29 12:45:30 GMT 2003
# Whom:			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	17.9
CATEGORIES=	misc
MASTER_SITES=	SF
PKGNAMEPREFIX=	health-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Nutrition software to record what you eat

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}

MAN1=		${PORTNAME}.1
PORTDOCS=	CREDITS README nut.html
PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/FOOD_DES.txt \
		%%DATADIR%%/NUT_DATA.txt %%DATADIR%%/WEIGHT.lib \
		%%DATADIR%%/WEIGHT.txt %%DATADIR%%/sr24.nut
PLIST_DIRS=	%%DATADIR%%

OPTIONS_DEFINE=	GUI

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
USE_XORG=	xpm
BUILD_DEPENDS+=	${LOCALBASE}/lib/fltk11/libfltk.so:${PORTSDIR}/x11-toolkits/fltk11
MAKE_ENV+=	HAVE_FLTK=1 FLTK_NUT="fltk/Nut"
PLIST_FILES+=	bin/Nut
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(prefix)/lib/nut|${DATADIR}| ; \
		 s|^CC =|CC ?=| ; \
		 s|^CXX =|CXX ?=| ; \
		 s|^CFLAGS :=|CFLAGS +=| ; \
		 s| -O | | ; \
		 s|^HAVE_FLTK =|#HAVE_FLTK =| ; \
		 s|^FLTK_NUT =|#FLTK_NUT =| ; \
		 s|ldstaticflags|ldflags| ; \
		 s|fltk-config|${LOCALBASE}/bin/fltk11/fltk-config|'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if defined(WITH_GUI)
	${INSTALL_PROGRAM} ${WRKSRC}/fltk/Nut ${PREFIX}/bin
.endif
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/raw.data && ${COPYTREE_SHARE} . ${DATADIR})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
