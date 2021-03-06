# New ports collection makefile for:	sympa5
# Date created:		16 September 2005
# Whom:			Olivier Girard <Olivier.Girard@Univ-Angers.fr>
#
# $FreeBSD$
#

PORTNAME=	sympa
PORTVERSION=	5.4.7
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES?=	http://www.sympa.org/distribution/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Sympa is an electronic mailing list manager

BUILD_DEPENDS+=	\
	p5-Archive-Zip>0:${PORTSDIR}/archivers/p5-Archive-Zip \
	p5-IO-stringy>0:${PORTSDIR}/devel/p5-IO-stringy \
	p5-SOAP-Lite>0:${PORTSDIR}/net/p5-SOAP-Lite \
	p5-MIME-EncWords>0:${PORTSDIR}/mail/p5-MIME-EncWords \
	p5-File-NFSLock>0:${PORTSDIR}/devel/p5-File-NFSLock \
	p5-Locale-libintl>0:${PORTSDIR}/devel/p5-Locale-libintl \
	p5-Regexp-Common>0:${PORTSDIR}/textproc/p5-Regexp-Common \
	p5-Template-Toolkit>0:${PORTSDIR}/www/p5-Template-Toolkit \
	p5-XML-LibXML>0:${PORTSDIR}/textproc/p5-XML-LibXML \
	p5-Crypt-CipherSaber>0:${PORTSDIR}/security/p5-Crypt-CipherSaber \
	p5-Crypt-OpenSSL-X509>0:${PORTSDIR}/security/p5-Crypt-OpenSSL-X509 \
	p5-perl-ldap>0:${PORTSDIR}/net/p5-perl-ldap \
	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
	p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser \
	${LOCALBASE}/bin/mhonarc:${PORTSDIR}/www/mhonarc
RUN_DEPENDS:=	${BUILD_DEPENDS}

FORBIDDEN=	Multiple vulnerabilities have been discovered in Sympa archive management that allow to skip the scenario-based authorization mechanisms.  http://www.sympa.org/security_advisories#security_breaches_in_archives_management
DEPRECATED=	Unsupported by upstream, ${FORBIDDEN}
EXPIRATION_DATE=2012-07-05

USERS=		sympa
GROUPS=		sympa
SUB_FILES=	pkg-install
SUB_LIST=	DB_TYPE=${DB_TYPE}

LATEST_LINK=	sympa5
USE_APACHE=	20+
HAS_CONFIGURE=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--with-confdir=${PREFIX}/etc/sympa \
		--with-initdir=${PREFIX}/etc/rc.d \
		--with-etcdir=${PREFIX}/etc/sympa \
		--with-cgidir=${PREFIX}/sympa/cgi-bin \
		--with-iconsdir=${PREFIX}/sympa/icons \
		--with-sbindir=${PREFIX}/sbin \
		--with-libdir=${PREFIX}/lib/sympa \
		--with-libexecdir=${PREFIX}/libexec/sympa \
		--with-datadir=${DATADIR} \
		--with-expldir=${PREFIX}/sympa/expl \
		--with-lockdir=/var/spool/lock \
		--with-piddir=/var/run \
		--with-localedir=${PREFIX}/share/locale \
		--with-docdir=${DOCSDIR} \
		--with-sampledir=${EXAMPLESDIR} \
		--with-spooldir=${PREFIX}/sympa/spool \
		--enable-secure
CONFIGURE_ENV+=	lt_cv_sys_max_cmd_len=${CONFIGURE_MAX_CMD_LEN}
MAKE_ENV?=	PERL_EXTUTILS_AUTOINSTALL=--skip

MAN8=		alias_manager.8 archived.8 bounced.8 sympa.8

CONFLICTS=	sympa-[0-46-9]*

DB_TYPE?=mysql

PORTDOCS=	*

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FASTCGI)
BUILD_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi
BUILD_DEPENDS+=	p5-FCGI>=0:${PORTSDIR}/www/p5-FCGI
SUB_LIST+=	WITH_FASTCGI=yes
.endif

.if ${DB_TYPE} == "Oracle"
BUILD_DEPENDS+=	p5-DBD-Oracle>=0:${PORTSDIR}/databases/p5-DBD-Oracle
.else
.if ${DB_TYPE} == "Pg"
BUILD_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
.else
.if ${DB_TYPE} == "Sybase"
BUILD_DEPENDS+=	p5-DBD-Sybase>=0:${PORTSDIR}/databases/p5-DBD-Sybase
.else
.if ${DB_TYPE} == "mysql"
BUILD_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.endif
.endif
.endif
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      DB_TYPE=type                    Optional: mysql, Oracle, Pg or Sybase"
	@${ECHO} "      WITHOUT_FASTCGI                 Use plain CGI instead of FastCGI"
	@${ECHO} ""

post-patch:
	${MV} ${WRKSRC}/src/etc/script/sympa ${WRKSRC}/src/etc/script/sympa.sh
	@${REINPLACE_CMD} -E 's,^(INITSRC.*=.*sympa)$$,\1.sh,' \
		${WRKSRC}/src/etc/script/Makefile
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e 's, locale$$,,g' \
			  -e 's, installlocale,,g' \
		${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e 's, checklocales,,' \
		${WRKSRC}/po/Makefile
.endif
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's, installdoc,,g' -e 's, $$(DOCDIR),,g'\
		${WRKSRC}/Makefile.in
.endif
	@${FIND} ${WRKSRC} -name "*.orig" -a -exec ${RM} -f {} \;

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_MAN} ${WRKSRC}/doc/man8/alias_manager.8 ${MAN8PREFIX}/man/man8/
	@${INSTALL_MAN} ${WRKSRC}/doc/man8/archived.8 ${MAN8PREFIX}/man/man8/
	@${INSTALL_MAN} ${WRKSRC}/doc/man8/bounced.8 ${MAN8PREFIX}/man/man8/
	@${INSTALL_MAN} ${WRKSRC}/doc/man8/sympa.8 ${MAN8PREFIX}/man/man8/

.include <bsd.port.post.mk>
