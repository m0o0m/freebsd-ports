# New ports collection makefile for:    etoile-scriptkit
# Date created:         23 Nov 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	scriptkit
PORTVERSION=	0.4.1
CATEGORIES=	lang gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Etoile Project ScriptKit framework

LICENSE=	BSD

DEPRECATED=	API no longer supported
EXPIRATION_DATE=	2012-07-20

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}
USE_GNUSTEP_LOCAL_LIBS+=	EtoileFoundation:${FOUNDATION_PORT}

DEFAULT_LIBVERSION=	0.1
WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/ScriptKit

FOUNDATION_PORT?=	devel/etoile-foundation

post-patch:
	${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/etoile.make \
		${WRKSRC}/Frameworks/ScriptKit/GNUmakefile

.include <bsd.port.mk>
