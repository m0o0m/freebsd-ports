# New ports collection makefile for:	Spreadsheet/Excel for Ruby
# Date created:		8 December 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	spreadsheet
PORTVERSION=	0.7.2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby module to generate Microsoft Excel compatible files

RUN_DEPENDS=	rubygem-ruby-ole>=1.0:${PORTSDIR}/devel/rubygem-ruby-ole

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/xlsopcodes

.include <bsd.port.mk>
