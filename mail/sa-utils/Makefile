# New ports collection makefile for:  sa-utils
# Date created:    3 January 2010
# Whom:            Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#
# Port is self-contained in the files directory.

PORTNAME=	sa-utils
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	SpamAssassin nightly periodic maintenance

RUN_DEPENDS=	sa-update:${PORTSDIR}/mail/p5-Mail-SpamAssassin

OPTIONS_DEFINE=	SACOMPILE
SACOMPILE_DESC=	"Enable sa-compile support"

NO_BUILD=	yes
SUB_FILES=	sa-utils

PERIODIC_DAILY=	etc/periodic/daily

PLIST_FILES=	${PERIODIC_DAILY}/sa-utils
PLIST_DIRS=	${PERIODIC_DAILY} ${PERIODIC_DAILY:H}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSACOMPILE}
RUN_DEPENDS+=	re2c>=0.12.0:${PORTSDIR}/devel/re2c
SUB_LIST+=	SACOMPILE=YES
.else
SUB_LIST+=	SACOMPILE=NO
.endif

do-install:
	${MKDIR} ${PREFIX}/${PERIODIC_DAILY}/
	${INSTALL_SCRIPT} ${WRKDIR}/sa-utils \
	    ${PREFIX}/${PERIODIC_DAILY}/sa-utils

.include <bsd.port.mk>
