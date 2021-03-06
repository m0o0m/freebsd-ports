# New ports collection makefile for:   monotone
# Date created:                05 Feb 2004
# Whom:                        Mark A. Wicks <mwicks@kettering.edu>
#
# $FreeBSD$
#

PORTNAME=	monotone
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.monotone.ca/downloads/${PORTVERSION}/

MAINTAINER=	lapo@lapo.it
COMMENT=	A distributed version control system with digital signatures

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	pcre.1:${PORTSDIR}/devel/pcre \
		idn.17:${PORTSDIR}/dns/libidn \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		botan.0:${PORTSDIR}/security/botan

SUB_FILES=	pkg-message
USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_LUA=	5.1+

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/mtn bin/mtn-cleanup bin/mtnopt \
		share/monotone/hooks/authorize_remote_automate.lua \
		share/monotone/hooks/get_passphrase_from_file.lua \
		share/monotone/hooks/monotone-buildbot.lua \
		share/monotone/hooks/monotone-ciabot.lua \
		share/monotone/hooks/monotone-cluster-push.lua \
		share/monotone/hooks/monotone-cvs-ignore.lua \
		share/monotone/hooks/monotone-mail-notify.lua \
		share/monotone/scripts/monotone-ciabot.py \
		share/monotone/scripts/monotone-mail-notify \
		etc/bash_completion.d/monotone.bash_completion \
		share/zsh/site-functions/_mtn \
		"@unexec [ -f %D/bin/zsh ] || ${RMDIR} %D/share/zsh/site-functions 2>/dev/null || true" \
		"@dirrmtry share/zsh" \
		"@dirrmtry etc/bash_completion.d" \
		"@dirrm share/monotone/hooks" \
		"@dirrm share/monotone/scripts" \
		"@dirrm share/monotone"
.if !defined(NO_INSTALL_MANPAGES)
INFO=		monotone
MAN1=		mtn.1 \
		mtn-cleanup.1 \
		mtnopt.1
.endif
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
USE_GCC=	4.2+
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
.else
USE_GETTEXT=	yes
PLIST_FILES+=	share/locale/de/LC_MESSAGES/monotone.mo \
		share/locale/fr/LC_MESSAGES/monotone.mo \
		share/locale/it/LC_MESSAGES/monotone.mo \
		share/locale/pt/LC_MESSAGES/monotone.mo \
		share/locale/sv/LC_MESSAGES/monotone.mo
.endif

post-extract:
	@${RM} -f ${WRKSRC}/monotone.info*

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -Ee '/^install-(contrib|examples)-data:/{' -e 'n' -e 'd' -e '}' ${WRKSRC}/Makefile.in
.endif
.if defined(NO_INSTALL_MANPAGES)
	${REINPLACE_CMD} -Ee '/^install-(info|man): /s/ install-.*$$//' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -Ee '/^install-info: /s/ install-info-am$$//' \
	-e '/^install-data-am:/s/ install-info-am$$//' ${WRKSRC}/doc/Makefile.in
.endif

post-install:
	${MKDIR} ${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/contrib/monotone.zsh_completion ${PREFIX}/share/zsh/site-functions/_mtn
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} NEWS UPGRADE ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
