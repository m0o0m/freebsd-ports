# New ports collection makefile for:    spice
# Date created:         26 Mar 96
# Whom:                 Julian Jenkins <kaveman@magna.com.au>
#
# $FreeBSD$
#

PORTNAME=	spice
PORTVERSION=	3f5.2
PORTREVISION=	7
CATEGORIES=	cad
MASTER_SITES=	http://embedded.eecs.berkeley.edu/pubs/downloads/spice/:sources
DISTFILES=	spice3f5${EXTRACT_SUFX}:sources	\
		cp.ps toc.ps doc.ps
DIST_SUBDIR=	spice
EXTRACT_ONLY=	spice3f5${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general-purpose circuit simulation program

LICENSE=	BSD

WRKSRC=		${WRKDIR}/${PORTNAME}3f5
MAN1=		sconvert.1 nutmeg.1 spice.1
MAN3=		mfb.3
MAN5=		mfbcap.5
MLINKS=		spice.1 spice3.1
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV+=	STRIP_CMD=${STRIP_CMD}
MAKE_JOBS_UNSAFE=	yes

.ifdef WITHOUT_X11
PKGNAMESUFFIX=	-without-x11
COMMENT=	A general-purpose circuit simulation program (non-X11 version)
MAKE_ARGS+=	-DWITHOUT_X11
.else
USE_XORG=	x11 xaw xext xmu xt
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/ucb|${LOCALBASE}/bin|' ${WRKSRC}/util/build

do-configure:
	@${CP} ${FILESDIR}/FreeBSD ${WRKSRC}/conf/FreeBSD
	@${CP} ${FILESDIR}/FreeBSD.without_x11 ${WRKSRC}/conf/FreeBSD.without_x11
	@${REINPLACE_CMD} -e 's+@CC@+${CC}+ ; s+@CFLAGS@+${CFLAGS}+ ; \
	    s+@X11BASE@+${LOCALBASE}+;' \
	    ${WRKSRC}/conf/FreeBSD ${WRKSRC}/conf/FreeBSD.without_x11

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/*.ps > ${DOCSDIR}/spice3f3.ps
	${GZIP_CMD} ${DOCSDIR}/*.ps
.endif
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.cir ${EXAMPLESDIR}

.include <bsd.port.post.mk>
