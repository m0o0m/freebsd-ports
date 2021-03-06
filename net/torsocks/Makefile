# New ports collection makefile for:	torsocks
# Date created:				13 February 2009
# Whom:					Andrei Lavreniyuk <andy.lavr@gmail.com>
#
# $FreeBSD$

PORTNAME=	torsocks
PORTVERSION=	1.2
CATEGORIES=	net security
MASTER_SITES=	GOOGLE_CODE \
		http://tor.reactor-xg.kiev.ua/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	andy.lavr@gmail.com
COMMENT=	Most SOCKS-friendly applications way with Tor

USE_AUTOTOOLS=	libtool aclocal autoconf
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal

USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		torsocks.1 usewithtor.1
MAN5=		torsocks.conf.5
MAN8=		torsocks.8

SUB_FILES=	pkg-message

OPTIONS=	SOCKSDNS "Use socks server for DNS lookups" off \
		OLDMETHOD "Do not use RTLD_NEXT parameter to dlsym" off \
		NODEBUG "Disable output of error messages" off \
		HOSTNAMES "Enable DNS lookups of socks server" off

.include <bsd.port.pre.mk>

.if defined(WITH_SOCKSDNS)
CONFIGURE_ARGS+=	--enable-socksdns
.endif

.if defined(WITH_OLDMETHOD)
CONFIGURE_ARGS+=	--enable-oldmethod
.endif

.if defined(WITH_NODEBUG)
CONFIGURE_ARGS+=	--disable-debug
.endif

.if defined(WITH_HOSTNAMES)
CONFIGURE_ARGS+=	--enable-hostnames
.endif

.if defined(WITH_SOCKSDNS) && defined(WITH_HOSTNAMES)
BROKEN=		HOSTNAMES option is not allowed when SOCKSDNS option is enabled
.endif

pre-everything::
.if !defined(WITH_SOCKSDNS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the SOCKSDNS option."
	@${ECHO_MSG} "This option causes torsocks to intercept"
	@${ECHO_MSG} "DNS lookups and attempt to force them"
	@${ECHO_MSG} "to use TCP instead of UDP and thus"
	@${ECHO_MSG} "be proxied through the socks server."
	@${ECHO_MSG}
.endif

.if !defined(WITH_OLDMETHOD)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the OLDMETHOD option."
	@${ECHO_MSG} "This forces torsocks not to use the"
	@${ECHO_MSG} "RTLD_NEXT parameter to dlsym to get the"
	@${ECHO_MSG} "address of the connect() method torsocks"
	@${ECHO_MSG} "overrides, instead it loads a reference"
	@${ECHO_MSG} "to the libc shared library and then uses dlsym()."
	@${ECHO_MSG}
.endif

.if !defined(WITH_NODEBUG)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the NODEBUG option."
	@${ECHO_MSG} "This configuration option tells torsocks"
	@${ECHO_MSG} "to never output error messages to stderr."
	@${ECHO_MSG}
.endif

.if !defined(WITH_HOSTNAMES)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the HOSTNAMES option."
	@${ECHO_MSG} "This enables DNS lookups on names"
	@${ECHO_MSG} "provided as socks servers in the config"
	@${ECHO_MSG} "file. This option is not allowed"
	@${ECHO_MSG} "if socks dns is enabled since torsocks"
	@${ECHO_MSG} "can't send a socks dns request to resolve"
	@${ECHO_MSG} "the location of the socks server."
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@prefix@|${PREFIX}|' ${WRKSRC}/src/torsocks.in
	@${REINPLACE_CMD} -e 's|MAP_ANONYMOUS|MAP_ANON|' ${WRKSRC}/src/dead_pool.c
	@${MV} ${WRKSRC}/doc/torsocks.conf ${WRKSRC}/doc/torsocks.conf.sample

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.sample ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.sample ${PREFIX}/etc
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
