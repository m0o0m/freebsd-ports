# New ports collection makefile for:	pdnsd
# Date Created:				27 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	pdnsd
PORTVERSION=	1.2.9a
CATEGORIES=	dns ipv6
MASTER_SITES=	http://members.home.nl/p.a.rombouts/pdnsd/releases/ \
		http://distfiles.pirateparty.in/ashish/
DISTNAME=	${PORTNAME}-${PORTVERSION}-par

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Caching (permanently, writes to disk on exit) DNS proxy-server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	pdnsd
CONFIGURE_ARGS=	--with-cachedir=${PDNSDB} \
		--disable-src-addr-disc

OPTIONS=	IPV6	"Enable IPv6 support"	on

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN5=		pdnsd.conf.5
MAN8=		pdnsd.8 pdnsd-ctl.8

PDNSDB=		/var/db/pdnsd
DOCSRCDIR=	${WRKSRC}/doc
DOC_FILES=	html/dl.html html/doc.html html/faq.html html/index.html
DOC_FILES+=	txt/faq.txt txt/intro.txt txt/manual.txt

CFLAGS+=	${PTHREAD_LIBS}

OPTIONS=	IPV6	"IPv6 support"	on

.include <bsd.port.pre.mk>

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOC_FILES:S@^@${DOCSRCDIR}/@} ${DOCSDIR}
.endif
	@[ -f ${PREFIX}/etc/pdnsd.conf ] || \
		${INSTALL_DATA} ${PREFIX}/etc/pdnsd.conf.sample ${PREFIX}/etc/pdnsd.conf
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
