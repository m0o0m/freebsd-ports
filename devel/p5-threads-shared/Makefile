# New ports collection makefile for:	p5-threads-shared
# Date created:		2007-03-18
# Whom:			Ruben van Staveren
#
# $FreeBSD$
#

PORTNAME=	threads-shared
PORTVERSION=	1.39
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JDHEDDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ruben@verweg.com
COMMENT=	Perl extension for sharing data structures between threads

BUILD_DEPENDS=	p5-threads>=1.73:${PORTSDIR}/devel/p5-threads
RUN_DEPENDS=	p5-threads>=1.73:${PORTSDIR}/devel/p5-threads

PERL_CONFIGURE=	yes

MAN3=		threads::shared.3

.include <bsd.port.mk>
