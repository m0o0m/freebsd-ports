# New ports collection makefile for: science/meep
# Date created:		26 Dec 2009
# Whom:			Stas Timokhin <devel@stasyan.com>
#
# $FreeBSD$
#

PORTNAME=	meep
PORTVERSION=	1.1.1
PORTREVISION=	4
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/meep/

MAINTAINER=	devel@stasyan.com
COMMENT=	FDTD simulation software to model electromagnetic systems

BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash \
		harminv:${PORTSDIR}/science/harminv \
		gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS+=	guile.21:${PORTSDIR}/lang/guile \
		blas.2:${PORTSDIR}/math/blas \
		ctl.4:${PORTSDIR}/science/libctl \
		hdf5.0:${PORTSDIR}/science/hdf5
RUN_DEPENDS+=	harminv:${PORTSDIR}/science/harminv

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_FORTRAN=	yes
USE_GCC=	4.6+
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS+=	libltdl
CPPFLAGS+=	-I${LOCALBASE}/include
LD_LIBRARY_PATH=	-L${LOCALBASE}/lib -L/usr/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	LD_LIBRARY_PATH="${LD_LIBRARY_PATH}"

OPTIONS=	OPENMPI "Enable MPI support using openmpi" On

.include <bsd.port.pre.mk>

.if defined(WITH_OPENMPI)
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpiCC:${PORTSDIR}/net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpirun:${PORTSDIR}/net/openmpi
CONFIGURE_ARGS+=--with-mpi
CONFIGURE_ENV+=	MPICXX=${LOCALBASE}/mpi/openmpi/bin/mpiCC
PLIST_SUB+=	MPI="" NOMPI="@comment "
.else
CONFIGURE_ARGS+=--without-mpi
PLIST_SUB+=	MPI="@comment " NOMPI=""
.endif

post-patch:
	${REINPLACE_CMD} -e 's+\#\! /bin/sh+\#\! ${PREFIX}/bin/bash+' \
		-e s+\$$\(SHELL\)+${PREFIX}/bin/bash+ ${WRKSRC}/configure

.include <bsd.port.post.mk>
