# New ports collection makefile for:	asunder
# Date created:				14 September 2007
# Whom:					frase@frase.id.au
#
# $FreeBSD$

PORTNAME=	asunder
PORTVERSION=	2.0
PORTREVISION?=	2
CATEGORIES=	audio
MASTER_SITES=	http://littlesvr.ca/asunder/releases/

MAINTAINER=	frase@frase.id.au
COMMENT=	A lightweight GTK+ CD ripper

LIB_DEPENDS=	cddb.4:${PORTSDIR}/audio/libcddb
RUN_DEPENDS=	${LOCALBASE}/bin/cdparanoia:${PORTSDIR}/audio/cdparanoia

OPTIONS=	LAME "lame support" on \
		OGG "ogg-vorbis support" on \
		FLAC "FLAC support" on \
		WAVPACK "WavPack support" off \
		MONKEYAUDIO "Monkey's Audio support" off \
		WINDOWS_CHARS "Allow Windows special chars in filenames" off

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README TODO

.include <bsd.port.pre.mk>

.if defined(WITH_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if defined(WITH_OGG)
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
.endif

.if defined(WITH_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if defined(WITH_WAVPACK)
RUN_DEPENDS+=	wavpack:${PORTSDIR}/audio/wavpack
.endif

.if defined(WITH_MONKEYAUDIO)
RUN_DEPENDS+=	mac:${PORTSDIR}/audio/mac
.endif

post-patch:
.if defined(WITH_WINDOWS_CHARS)
	@${REINPLACE_CMD} -e 's^#define[[:blank:]]*BADCHARS.*^#define BADCHARS "/"^' ${WRKSRC}/src/util.h
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
