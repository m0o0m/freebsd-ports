# New ports collection makefile for:	eaccelerator
# Date created:			Sat Mar 1 13:55:55 CET 2003
# Whom:				Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	eaccelerator
PORTVERSION=	0.9.6.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/eAccelerator%20${PORTVERSION}/ \
		http://bart.eaccelerator.net/source/${PORTVERSION}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A free open-source PHP accelerator & optimizer

OPTIONS=	DOCCOMM "Retain doc-comments in internal php structures" off

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5

CONFIGURE_ARGS=	--enable-eaccelerator=shared \
		--with-eaccelerator-userid=80 \
		--without-eaccelerator-use-inode

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if defined(WITH_DOCCOMM)
CONFIGURE_ARGS+=--with-eaccelerator-doc-comment-inclusion
.endif

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_DATA} ${WRKSRC}/modules/${PORTNAME}.so \
	       ${PREFIX}/lib/php/${PHP_EXT_DIR}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.ini ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/control.php ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dasm.php ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
