# New ports collection makefile for:	mytop
# Date created:				28 Augest 2000
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mytop
PORTVERSION=	1.6
PORTREVISION=	9
CATEGORIES=	databases
MASTER_SITES=	http://jeremy.zawodny.com/mysql/mytop/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	A top clone for MySQL

RUN_DEPENDS=	p5-DBD-mysql>1.0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-DBI>=1.13:${PORTSDIR}/databases/p5-DBI \
		p5-Term-ReadKey>=2.10:${PORTSDIR}/devel/p5-Term-ReadKey

CONFLICTS=	mariadb-scripts-[0-9]*

PERL_CONFIGURE=	yes

MAN1=		mytop.1

.include <bsd.port.mk>
