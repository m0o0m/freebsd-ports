# New ports collection makefile for:	IO::Callback
# Date created:		02 Jun 2012
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Callback
PORTVERSION=	1.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to emulate file interface for a code reference

RUN_DEPENDS=	\
	p5-IO-String>0:${PORTSDIR}/devel/p5-IO-String
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp \
	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception \
	p5-Test-NoWarnings>0:${PORTSDIR}/devel/p5-Test-NoWarnings

PERL_CONFIGURE=	yes

MAN3=	IO::Callback.3

.include <bsd.port.mk>
