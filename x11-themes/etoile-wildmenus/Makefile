# New ports collection makefile for:    etoile-wildmenus
# Date created:         18 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	wildmenus
PORTVERSION=	0.1.${SNAPSHOT}
PORTREVISION=	2
CATEGORIES=	x11-themes gnustep
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
PKGNAMEPREFIX=	etoile-
DISTNAME=	Etoile-${SNAPSHOT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Etoile Project WildMenus bundle

DEPRECATED=	API no longer supported
EXPIRATION_DATE=	2012-07-20

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

SNAPSHOT=	20061221
WRKSRC=	${WRKDIR}/Etoile/
USE_GNUSTEP_MAKE_DIRS+=	Bundles/WildMenus

post-patch:
	${REINPLACE_CMD} -e 's|AppKit/NSDictionary.h|Foundation/NSDictionary.h|' \
		${WRKSRC}/Bundles/WildMenus/GSHorizontalMenuItemCell.m

.include <bsd.port.mk>
