# New ports collection makefile for:	p5-Mojolicious-Plugin-YamlConfig
# Date created:		2012-04-25
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mojolicious-Plugin-YamlConfig
PORTVERSION=	0.1.4
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	YAML Configuration Plugin

BUILD_DEPENDS=	p5-Mojolicious>=1.80:${PORTSDIR}/www/p5-Mojolicious \
		p5-YAML-Tiny>=1.51:${PORTSDIR}/textproc/p5-YAML-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.10.1+

MAN3=		Mojolicious::Plugin::YamlConfig.3

.include <bsd.port.mk>
