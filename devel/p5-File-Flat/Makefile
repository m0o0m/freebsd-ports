# New ports collection makefile for:	File-Flat
# Date created:	   11 December 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	File-Flat
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implements a flat filesystem

RUN_DEPENDS=	p5-Test-ClassAPI>=0:${PORTSDIR}/devel/p5-Test-ClassAPI \
		p5-File-NCopy>=0:${PORTSDIR}/devel/p5-File-NCopy \
		p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-File-Remove>=0:${PORTSDIR}/devel/p5-File-Remove \
		p5-Class-Autouse>=0:${PORTSDIR}/devel/p5-Class-Autouse \
		p5-prefork>=0:${PORTSDIR}/devel/p5-prefork
BUILD_DEPENDS=	p5-Test-ClassAPI>=0:${PORTSDIR}/devel/p5-Test-ClassAPI \
		p5-File-NCopy>=0:${PORTSDIR}/devel/p5-File-NCopy \
		p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-File-Remove>=0:${PORTSDIR}/devel/p5-File-Remove \
		p5-Class-Autouse>=0:${PORTSDIR}/devel/p5-Class-Autouse \
		p5-prefork>=0:${PORTSDIR}/devel/p5-prefork

PERL_CONFIGURE=	yes

MAN3=		File::Flat.3

post-patch:
	@${PERL} -pi -e 's/^auto_install.*$$//' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
