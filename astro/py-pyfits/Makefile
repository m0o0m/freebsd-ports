# New ports collection makefile for:	pyfits
# Date created:		2008-10-28
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pyfits
PORTVERSION=	2.3
CATEGORIES=	astro python
MASTER_SITES=	http://www.stsci.edu/resources/software_hardware/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tonymaher@optusnet.com.au
COMMENT=	Python Interface to FITS Formatted Files

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy/core/numeric.py:${PORTSDIR}/math/py-numpy
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
