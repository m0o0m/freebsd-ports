# New ports collection makefile for:	Proc-InvokeEditor
# Date created:		2011-04-05
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Proc-InvokeEditor
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	editors perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSTEVENS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for starting a text editor

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Carp-Assert>=0:${PORTSDIR}/devel/p5-Carp-Assert
RUN_DEPENDS=	p5-Carp-Assert>=0:${PORTSDIR}/devel/p5-Carp-Assert

PERL_CONFIGURE=	yes

MAN3=	Proc::InvokeEditor.3

.include <bsd.port.mk>
