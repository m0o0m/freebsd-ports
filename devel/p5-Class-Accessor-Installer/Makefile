# New ports collection makefile for:	p5-Class-Accessor-Installer
# Date created:		2012-02-09
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Accessor-Installer
PORTVERSION=	1.100880
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Install an accessor subroutine

BUILD_DEPENDS=	p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::Accessor::Installer.3

.include <bsd.port.mk>
