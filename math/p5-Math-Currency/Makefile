# New ports collection makefile for:	Math-Currency
# Date created:				Wed Jan  3 10:58:59 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Math-Currency
PORTVERSION=	0.47
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for exact currency math with formatting and rounding

BUILD_DEPENDS=	p5-Math-FixedPrecision>=0:${PORTSDIR}/math/p5-Math-FixedPrecision
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Math::Currency.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
