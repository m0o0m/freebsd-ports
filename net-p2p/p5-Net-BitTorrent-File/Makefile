# New ports collection makefile for:	p5-Net-BitTorrent-File
# Date created:				February 06th 2006
# Whom:	      				Oleg R. Muhutdinov <mor@WhiteLuna.com>
#
# $FreeBSD$
#

PORTNAME=	Net-BitTorrent-File
PORTVERSION=	1.02
CATEGORIES=	net-p2p perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}-fix

MAINTAINER=	mor@WhiteLuna.com
COMMENT=	Perl5 module for handles loading and saveing of .torrent file

RUN_DEPENDS=	${SITE_PERL}/Convert/Bencode.pm:${PORTSDIR}/converters/p5-Convert-Bencode \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple

WRKSRC=		${WRKDIR}/${DISTNAME:S/-fix//}

PERL_CONFIGURE=	yes

MAN3=		Net::BitTorrent::File.3

.include <bsd.port.mk>
