# New ports collection makefile for:	p5-Net-Telnet-Netscreen
# Date created:		2006-07-30
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-Telnet-Netscreen
PORTVERSION=	1.2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	A Perl interface for interact with a Netscreen firewall

BUILD_DEPENDS=	${SITE_PERL}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Telnet::Netscreen.3

.include <bsd.port.mk>
