# New ports collection makefile for:    xpi-gbutts
# Date created:         2008-05-22
# Whom:                 Anatoly Borodin <anatoly.borodin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	google_shortcuts
PORTVERSION=	2.1.5
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	anatoly.borodin@gmail.com
COMMENT=	Display all of your Google Services as buttons just next to your addressbar

XPI_ID=		{5C46D283-ABDE-4dce-B83C-08881401921C}
XPI_NUM=	3576
XPI_FILES=	chrome/googleshortcuts.jar chrome.manifest \
		defaults/preferences/install.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
