# New ports collection makefile for:	Magic Cube 4D
# Date Created: 			September 25, 2000
# Whom:					Jeremy <karlj000@unbc.ca>
#
# $FreeBSD$
#

PORTNAME=	magiccube4d
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.superliminal.com/cube/
DISTNAME=	mc4d-src-${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	karlj000@unbc.ca
COMMENT=	MagicCube4D is a four-dimensional analog of Rubik's cube

USE_XORG=	x11 xext xt sm ice xaw
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION:S/./_/}
DOCS=		ChangeLog Intro.txt MagicCube4D-unix.txt \
		ideas.txt readme-unix.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/magiccube4d ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

.include <bsd.port.post.mk>
