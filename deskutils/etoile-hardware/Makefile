# New ports collection makefile for:    etoile-hardware
# Date created:         19 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	hardware
PORTVERSION=	0.1.${SNAPSHOT}
PORTREVISION=	2
CATEGORIES=	deskutils gnustep
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
PKGNAMEPREFIX=	etoile-
DISTNAME=	Etoile-${SNAPSHOT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Etoile Project Hardware application

DEPRECATED=	API no longer supported
EXPIRATION_DATE=	2012-07-20

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	PaneKit:${PANEKIT_PORT}

SNAPSHOT=	20061221
WRKSRC=	${WRKDIR}/Etoile/
USE_GNUSTEP_MAKE_DIRS+=	Services/User/Hardware

PANEKIT_PORT?=	deskutils/etoile-panekit

post-patch:
	${MKDIR} ${WRKSRC}/Services/User/Hardware/PreferencesKit
	${TOUCH} ${WRKSRC}/Services/User/Hardware/PreferencesKit/PreferencesKit.h

.include <bsd.port.mk>
