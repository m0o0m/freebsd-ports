# New ports collection makefile for:	ruby-mecab
# Date created:		23 April 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mecab
PORTVERSION=	0.98
CATEGORIES=	japanese textproc ruby
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-ruby/${PORTVERSION}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	MeCab library module for Ruby

LIB_DEPENDS=	mecab.1:${PORTSDIR}/japanese/mecab

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/bindings.html ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.post.mk>
