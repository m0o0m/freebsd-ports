# New ports collection makefile for: linux-tiff
# Date created:		2001.02.08
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tiff
PORTVERSION=	3.7.1
PORTREVISION=	2
CATEGORIES=	graphics linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
DISTNAME=	libtiff-${PORTVERSION}-6.fc4.2

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	TIFF library, Linux/i386 binary

FORBIDDEN=	Vulnerable since 2004-10-13, http://portaudit.freebsd.org/8816bf3a-7929-11df-bcce-0018f3e2eb82.html
# EXPIRATION_DATE is the EoL of the last 7.x release
EXPIRATION_DATE=2013-02-28

CONFLICTS=	linux-f8-tiff-[0-9]* linux-f10-tiff-[0-9]*

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	jpeg
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
BRANDELF_DIRS=	usr/bin
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
