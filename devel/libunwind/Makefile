# New ports collection makefile for:		libunwind
# Date created:					04/30/2010
# Whom:						stas
#
# $FreeBSD$
#

PORTNAME=	libunwind
PORTVERSION=	20110911	# This is actually official libunwind 1.0.1
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH
DISTNAME=	${PORTNAME}-1.0.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A generic stack unwinding library

ONLY_FOR_ARCHS=	i386 amd64

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize libtool
ACLOCAL_ARGS=	-I . -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	-c -a
LIBTOOLFILES=	#empty

MAN3=		_U_dyn_cancel.3 \
		_U_dyn_register.3 \
		libunwind.3 \
		libunwind-dynamic.3 \
		libunwind-ia64.3 \
		libunwind-ptrace.3 \
		libunwind-setjmp.3 \
		unw_create_addr_space.3 \
		unw_destroy_addr_space.3 \
		unw_flush_cache.3 \
		unw_get_accessors.3 \
		unw_get_fpreg.3 \
		unw_get_proc_info.3 \
		unw_get_proc_info_by_ip.3 \
		unw_get_proc_name.3 \
		unw_get_reg.3 \
		unw_getcontext.3 \
		unw_init_local.3 \
		unw_init_remote.3 \
		unw_is_fpreg.3 \
		unw_is_signal_frame.3 \
		unw_regname.3 \
		unw_resume.3 \
		unw_set_caching_policy.3 \
		unw_set_fpreg.3 \
		unw_set_reg.3 \
		unw_step.3 \
		unw_strerror.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 701100 || (${OSVERSION} > 800000 && ${OSVERSION} < 800053)
IGNORE=	your FreeBSD version is not supported
.endif

.if ${ARCH} == i386
PLIST_SUB=	ARCH=x86
.elif ${ARCH} == amd64
PLIST_SUB=	ARCH=x86_64
.endif

#
# The original ltmain.sh is buggy and hangs sometimes
#
pre-configure:
	@${CP} ${LTMAIN} ${WRKSRC}/aux/

#
# Get rid of .la and static library files
#
post-configure:
	@${REINPLACE_CMD} -E -e \
	'/Install the pseudo-library/,/staticlibs=/s,^,#,' ${WRKSRC}/libtool

.include <bsd.port.post.mk>
