# New ports collection Makefile for:	geany
# Date Created:				15 Jan 06
# Whom:					Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	geany
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	devel editors
MASTER_SITES=	http://download.geany.org/ SF

MAINTAINER=	ar@null.lv
COMMENT=	A fast and lightweight GTK+ IDE

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	VTE	"Enable Virtual Terminal Emulation support"	on \
		NLS	"Enable Native Language support"		on

MAN1=		geany.1

.include <bsd.port.options.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_VTE)
USE_GNOME+=	vte
CONFIGURE_ARGS+=--enable-vte
.else
CONFIGURE_ARGS+=--disable-vte
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|doc||' ${WRKSRC}/Makefile.in
.endif
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|po||' ${WRKSRC}/Makefile.in
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/geany.desktop ${PREFIX}/share/applications/
	${INSTALL_MAN} ${WRKSRC}/doc/geany.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
