# New ports collection makefile for:	fetchmail
# Date created:		25 Feb 2000
# Whom:			Ville Eerola <ve@sci.fi>
#
# $FreeBSD$
#
# NOTE:  The fetchmailconf program (an interactive program for
# writing .fetchmailrc files) requires Python, Tk, X11, etc..
#
# The fetchmail program itself does not need Python, but if you
# want fetchmailconf to work, define the X11 option.

PORTNAME=	fetchmail
PORTVERSION=	6.3.21
CATEGORIES=	mail ipv6
MASTER_SITES=	BERLIOS/${PORTNAME}/ \
		SF/${PORTNAME}/branch_6.3/ \
		http://mandree.home.pages.de/${PORTNAME}/ \
		SUNSITE/system/mail/pop/${PORTNAME}/

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Batch mail retrieval utility for IMAP/POP3/ETRN/ODMR

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

# Note USERS can only contain a single word as parts below rely on that.
USERS=		${PORTNAME}
GROUPS=		${USERS}

USE_RC_SUBR=	fetchmail
FETCHMAILRC=	${PREFIX}/etc/fetchmailrc
SUB_FILES=	pkg-message
PATCH_STRIP=	-p1

USE_XZ=		yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--enable-opie --enable-RPA --enable-SDPS \
		--with-hesiod=no --enable-fallback=no PYTHON=:
# bsd.openssl.mk will add the LDFLAGS to CONFIGURE_ENV:
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	${CONFIGURE_ENV}
MAN1=		fetchmail.1
MLINKS=		fetchmail.1 fetchmailconf.1

OPTIONS=	X11	"Python/Tkinter dependencies for fetchmailconf" off \
		NLS	"National language support (NLS)."		on \
		NTLM	"Build in support for NTLM/MSN authentication." off \
		GSSAPI	"Build GSSAPI/Kerberos 5 support" 		on

.include <bsd.port.options.mk>

.if defined(WITH_X11)
USE_PYTHON=	yes
RUN_DEPENDS+=	${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
.endif

.include <bsd.port.pre.mk>

# Pop2 is obsolete
.if defined(WITH_POP2)
CONFIGURE_ARGS+=--enable-POP2
.endif

CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}

DOCS=		FAQ FEATURES NEWS NOTES README README.SSL \
		design-notes.html fetchmail-FAQ.html fetchmail-features.html \
		esrs-design-notes.html

.if !defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS=""
USE_GETTEXT=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if !defined(KRB5_HOME)
.if exists(${LOCALBASE}/lib/libkrb5.a)
KRB5_HOME=	${LOCALBASE}
.elif exists(/usr/lib/libkrb5.a)
KRB5_HOME=	/usr
.endif
.endif

.if defined(KRB5_HOME) && !exists(${KRB5_HOME}/lib/libkrb5.a)
BROKEN=		KRB5_HOME is set but doesn't provide lib/libkrb5.a
.endif

.if defined(WITH_GSSAPI)
.if defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libkrb5.a)
CONFIGURE_ARGS += --with-gssapi=${KRB5_HOME}
.endif
.endif

.if defined(WITH_NTLM)
CONFIGURE_ARGS += --enable-NTLM
DOCS+=		README.NTLM
PLIST_SUB+=	NTLMDOCS="%%PORTDOCS%%"
.else
PLIST_SUB+=	NTLMDOCS="%%PORTDOCS%%@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} -e "s,^#!/usr/bin/env python,#!${LOCALBASE}/bin/python,g" \
		${WRKSRC}/fetchmailconf.py
	@${CP} ${FILESDIR}/fetchmailconf ${WRKDIR}/fetchmailconf
	@${REINPLACE_CMD} -e "s,@LOCALBASE@,${LOCALBASE},g" \
		 ${WRKDIR}/fetchmailconf

post-build:
	@cd ${WRKSRC} && ${MAKE} check

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 555 -o ${DOCOWN} -g ${DOCGRP} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

	${INSTALL_SCRIPT} ${WRKDIR}/fetchmailconf ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf.py ${PREFIX}/libexec

	${MKDIR} -m 0755 "/var/run/${PORTNAME}"
	${CHOWN} "${USERS}:${GROUPS}" "/var/run/${PORTNAME}"
	${INSTALL} -m 644 -o ${USERS} -g ${GROUPS} ${FILESDIR}/fetchmailrc.sample ${PREFIX}/etc/fetchmailrc.sample
	if [ ! -f ${PREFIX}/etc/fetchmailrc ]; then \
		${CP} -p ${PREFIX}/etc/fetchmailrc.sample ${PREFIX}/etc/fetchmailrc ; \
		${CHMOD} 600 ${PREFIX}/etc/fetchmailrc ; \
	fi

	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""

.include <bsd.port.post.mk>
