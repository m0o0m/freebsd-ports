# New Ports collection makefile for:    black-box
# Date created:         2012-04-27
# Whom:                 nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	black-box
PORTVERSION=	1.4.8
CATEGORIES=	games
MASTER_SITES=	http://www.linux-games.com/black-box/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	You can shoot in and watch, where the shot leaves the box

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_SDL=	sdl image mixer
MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
