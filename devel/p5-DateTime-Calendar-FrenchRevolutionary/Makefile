# New ports collection makefile for:	p5-DateTime-Calendar-FrenchRevolutionary
# Date created:	   26 june 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	DateTime-Calendar-FrenchRevolutionary
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dates in the French Revolutionary Calendar

BUILD_DEPENDS:=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Roman>=0:${PORTSDIR}/math/p5-Roman

PERL_MODBUILD=	yes

MAN3=		DateTime::Calendar::FrenchRevolutionary.3 \
		DateTime::Calendar::FrenchRevolutionary::Locale::en.3

.include <bsd.port.mk>
