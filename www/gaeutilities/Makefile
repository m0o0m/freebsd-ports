# New ports collection makefile for:	gaeutilities
# Date created:		2009-08-18
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gaeutilities
PORTVERSION=	1.4
PORTREVISION=	0
CATEGORIES=	www devel
MASTER_SITES=	http://cloud.github.com/downloads/joerussbowman/${PORTNAME}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Utility classes to make working with Google App Engine easier

RUN_DEPENDS=	google-appengine>=1.2.4_1:${PORTSDIR}/www/google-appengine

MANUAL_PACKAGE_BUILD=	uses Python 2.5
USE_PYTHON=	2.5 # same as www/google-appengine

WRKSRC=	${WRKDIR}/joerussbowman-gaeutilities-ea3f7e1

do-build:
	${PYTHON_CMD} -m compileall -f ${WRKSRC}/appengine_utilities
	${PYTHON_CMD} -O -m compileall -f ${WRKSRC}/appengine_utilities

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} appengine_utilities ${PYTHONPREFIX_SITELIBDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} && cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
