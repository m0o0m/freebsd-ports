# New ports collection Makefile for:	dlv
# Date created:				2007-06-01
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	dlv
PORTVERSION=	20111221
CATEGORIES=	lang
MASTER_SITES=	http://www.dlvsystem.com/dlvsystem/files/
DISTNAME=	dlv.i386-linux-elf-static.bin
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Disjunctive Datalog System

NO_BUILD=	yes
PLIST_FILES=	bin/dlv
ONLY_FOR_ARCHS=	i386 amd64
RESTRICTED=	Not sure if we can redistribute it

do-extract:
	${RM} -rf ${WRKDIR}
	${MKDIR} ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${PREFIX}/bin/dlv
	${BRANDELF} -t Linux ${PREFIX}/bin/dlv

.include <bsd.port.mk>
