# New ports collection makefile for:	pure
# Date created:		2011-03-17
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure
PORTVERSION=	0.55
CATEGORIES=	lang
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz ${PORTNAME}-docs-${PORTVERSION}.tar.gz

MAINTAINER=	lichray@gmail.com
COMMENT=	A modern-style functional programming language

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		mpfr:${PORTSDIR}/math/mpfr
BUILD_DEPENDS=	llvm>=2.9:${PORTSDIR}/devel/llvm
RUN_DEPENDS=	llvm>=2.9:${PORTSDIR}/devel/llvm

MAN1=		pure.1
SUB_FILES=	pkg-message

USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_PURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--with-libgmp-prefix=${LOCALBASE} --enable-release

OPTIONS_DEFINE=	EMACS

EMACS_DESC=	"Compile pure-mode.el with Emacs"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMACS}
USE_EMACS=	yes
MAKE_ARGS+=	emacs_prefix=${PREFIX}
PLIST_SUB+=	ELC=""
.else
CONFIGURE_ARGS+=	--without-elisp
PLIST_SUB+=	ELC="@comment "
.endif

# automatically disable readline support if editline support is available
.if exists(/usr/include/edit/readline/readline.h)
CONFIGURE_ARGS+=	--without-readline
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd
.endif

PORTDATA=	*
PORTEXAMPLES=	*
PORTDOCS=	*

.if !defined(NOPORTDATA)
SUB_LIST+=	ETC=""
.else
SUB_LIST+=	ETC="@comment "
.endif

.if !defined(NOPORTDOCS)
PLIST_SUB+=	DOCS=""
.else
PLIST_SUB+=	DOCS="@comment "
.endif

.if ${OSVERSION} < 900014
SUB_LIST+=	NOCLANG=""
.else
SUB_LIST+=	NOCLANG="@comment "
.endif

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}/etc/
	(cd ${WRKSRC} && ${RM} -f etc/*.in && ${COPYTREE_SHARE} etc/ ${DATADIR}/)
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKDIR}/${PORTNAME}-docs-${PORTVERSION} && ${RM} -f Makefile && ${COPYTREE_SHARE} \* ${DOCSDIR})
	${LN} -fs ${DOCSDIR} ${PREFIX}/lib/${PORTNAME}/docs
.endif

	@${CAT} ${PKGMESSAGE}

.include "bsd.pure.mk"
.include <bsd.port.post.mk>
