--- session.c.orig	Mon May 13 02:48:58 2002
+++ session.c	Thu May 23 14:10:44 2002
@@ -64,6 +64,13 @@
 #define is_winnt       (GetVersion() < 0x80000000)
 #endif
 
+#ifdef __FreeBSD__
+#include <libutil.h>
+#include <syslog.h>
+#include <time.h>
+#define _PATH_CHPASS "/usr/bin/passwd"
+#endif /* __FreeBSD__ */
+
 /* func */
 
 Session *session_new(void);
@@ -383,6 +390,13 @@
 		log_init(__progname, options.log_level, options.log_facility, log_stderr);
 
 		/*
+		 * Using login and executing a specific "command" are mutually
+		 * exclusive, so turn off use_login if there's a command.
+		 */
+		if (command != NULL)
+			options.use_login = 0;
+
+		/*
 		 * Create a new session and process group since the 4.4BSD
 		 * setlogin() affects the entire process group.
 		 */
@@ -497,6 +511,14 @@
 
 		/* Child.  Reinitialize the log because the pid has changed. */
 		log_init(__progname, options.log_level, options.log_facility, log_stderr);
+
+		/*
+		 * Using login and executing a specific "command" are mutually
+		 * exclusive, so turn off use_login if there's a command.
+		 */
+		if (command != NULL)
+			options.use_login = 0;
+
 		/* Close the master side of the pseudo tty. */
 		close(ptyfd);
 
@@ -623,6 +645,18 @@
 	struct sockaddr_storage from;
 	struct passwd * pw = s->pw;
 	pid_t pid = getpid();
+#ifdef HAVE_LOGIN_CAP
+	FILE *f;
+	char buf[256];
+	char *fname;
+	const char *shorttty;
+#endif /* HAVE_LOGIN_CAP */
+#ifdef __FreeBSD__
+#define DEFAULT_WARN  (2L * 7L * 86400L)  /* Two weeks */
+	char *newcommand;
+	struct timeval tv;
+	time_t warntime = DEFAULT_WARN;
+#endif /* __FreeBSD__ */
 
 	/*
 	 * Get IP address of client. If the connection is not a socket, let
@@ -656,6 +690,72 @@
 	}
 #endif
 
+#ifdef __FreeBSD__
+	if (pw->pw_change || pw->pw_expire)
+		(void)gettimeofday(&tv, NULL);
+#ifdef HAVE_LOGIN_CAP
+	warntime = login_getcaptime(lc, "warnpassword",
+				    DEFAULT_WARN, DEFAULT_WARN);
+#endif /* HAVE_LOGIN_CAP */
+	/*
+	 * If the password change time is set and has passed, give the
+	 * user a password expiry notice and chance to change it.
+	 */
+	if (pw->pw_change != 0) {
+		if (tv.tv_sec >= pw->pw_change) {
+			(void)printf(
+			    "Sorry -- your password has expired.\n");
+			log("%s Password expired - forcing change",
+			    pw->pw_name);
+			if (newcommand != NULL)
+				xfree(newcommand);
+			newcommand = xstrdup(_PATH_CHPASS);
+		} else if (pw->pw_change - tv.tv_sec < warntime &&
+			   !check_quietlogin(s, command))
+			(void)printf(
+			    "Warning: your password expires on %s",
+			     ctime(&pw->pw_change));
+	}
+
+#ifndef USE_PAM
+	if (pw->pw_expire) {
+		if (tv.tv_sec >= pw->pw_expire) {
+			(void)printf(
+			    "Sorry -- your account has expired.\n");
+			log(
+	   "LOGIN %.200s REFUSED (EXPIRED) FROM %.200s ON TTY %.200s",
+				pw->pw_name, get_remote_name_or_ip(utmp_len,
+				options.verify_reverse_mapping), s->tty);
+			exit(254);
+		} else if (pw->pw_expire - tv.tv_sec < warntime &&
+			   !check_quietlogin(s, command))
+			(void)printf(
+			    "Warning: your account expires on %s",
+			     ctime(&pw->pw_expire));
+	}
+#endif /* !USE_PAM */
+#endif /* __FreeBSD__ */
+
+#ifdef HAVE_LOGIN_CAP
+	/* check if we have a pathname in the ttyname */
+	shorttty = rindex( s->tty, '/' );
+	if (shorttty != NULL ) {
+		/* use only the short filename to check */
+		shorttty ++;
+	} else {
+		/* nothing found, use the whole name found */
+		shorttty = s->tty;
+	}
+	if (!auth_ttyok(lc, shorttty)) {
+		(void)printf("Permission denied.\n");
+		log(
+	       "LOGIN %.200s REFUSED (TTY) FROM %.200s ON TTY %.200s",
+		    pw->pw_name, get_remote_name_or_ip(utmp_len,
+			options.verify_reverse_mapping), s->tty);
+		exit(254);
+	}
+#endif /* HAVE_LOGIN_CAP */
+
 	if (check_quietlogin(s, command))
 		return;
 
@@ -668,7 +768,17 @@
 		printf("%s\n", aixloginmsg);
 #endif /* WITH_AIXAUTHENTICATE */
 
-	if (options.print_lastlog && s->last_login_time != 0) {
+	/*
+	 * If the user has logged in before, display the time of last
+	 * login. However, don't display anything extra if a command
+	 * has been specified (so that ssh can be used to execute
+	 * commands on a remote machine without users knowing they
+	 * are going to another machine). Login(1) will do this for
+	 * us as well, so check if login(1) is used
+	 */
+	if (command == NULL && options.print_lastlog &&
+	    s->last_login_time != 0 &&
+	    !options.use_login) {
 		time_string = ctime(&s->last_login_time);
 		if (strchr(time_string, '\n'))
 			*strchr(time_string, '\n') = 0;
@@ -679,7 +789,30 @@
 			    s->hostname);
 	}
 
-	do_motd();
+#ifdef HAVE_LOGIN_CAP
+	if (command == NULL &&
+	    !options.use_login) {
+		fname = login_getcapstr(lc, "copyright", NULL, NULL);
+		if (fname != NULL && (f = fopen(fname, "r")) != NULL) {
+			while (fgets(buf, sizeof(buf), f) != NULL)
+				fputs(buf, stdout);
+			fclose(f);
+		} else
+			(void)printf("%s\n\t%s %s\n",
+	"Copyright (c) 1980, 1983, 1986, 1988, 1990, 1991, 1993, 1994",
+	    "The Regents of the University of California. ",
+	    "All rights reserved.");
+	}
+#endif /* HAVE_LOGIN_CAP */
+
+	/*
+	 * Print /etc/motd unless a command was specified or printing
+	 * it was disabled in server options or login(1) will be
+	 * used.  Note that some machines appear to print it in
+	 * /etc/profile or similar.
+	 */
+	if (command == NULL && !options.use_login)
+		do_motd();
 }
 
 /*
@@ -695,9 +828,9 @@
 #ifdef HAVE_LOGIN_CAP
 		f = fopen(login_getcapstr(lc, "welcome", "/etc/motd",
 		    "/etc/motd"), "r");
-#else
+#else /* !HAVE_LOGIN_CAP */
 		f = fopen("/etc/motd", "r");
-#endif
+#endif /* HAVE_LOGIN_CAP */
 		if (f) {
 			while (fgets(buf, sizeof(buf), f))
 				fputs(buf, stdout);
@@ -724,10 +857,10 @@
 #ifdef HAVE_LOGIN_CAP
 	if (login_getcapbool(lc, "hushlogin", 0) || stat(buf, &st) >= 0)
 		return 1;
-#else
+#else /* HAVE_LOGIN_CAP */
 	if (stat(buf, &st) >= 0)
 		return 1;
-#endif
+#endif /* HAVE_LOGIN_CAP */
 	return 0;
 }
 
@@ -856,6 +989,10 @@
 #endif
 
 	if (!options.use_login) {
+#ifdef HAVE_LOGIN_CAP
+		char *var;
+#endif /* HAVE_LOGIN_CAP */
+
 		/* Set basic environment. */
 		child_set_env(&env, &envsize, "USER", pw->pw_name);
 		child_set_env(&env, &envsize, "LOGNAME", pw->pw_name);
@@ -863,6 +1000,12 @@
 #ifdef HAVE_LOGIN_CAP
 		(void) setusercontext(lc, pw, pw->pw_uid, LOGIN_SETPATH);
 		child_set_env(&env, &envsize, "PATH", getenv("PATH"));
+		var= login_getcapstr(lc, "lang", NULL, NULL);
+		if ( var ) child_set_env(&env, &envsize, "LANG", var);
+		var= login_getcapstr(lc, "charset", NULL, NULL);
+		if ( var ) child_set_env(&env, &envsize, "MM_CHARSET", var);
+		var= login_getcapstr(lc, "timezone", NULL, NULL);
+		if ( var ) child_set_env(&env, &envsize, "TZ", var);
 #else /* HAVE_LOGIN_CAP */
 # ifndef HAVE_CYGWIN
 		/*
@@ -1221,7 +1364,7 @@
 	 * initgroups, because at least on Solaris 2.3 it leaves file
 	 * descriptors open.
 	 */
-	for (i = 3; i < 64; i++)
+	for (i = 3; i < getdtablesize(); i++)
 		close(i);
 
 	/*
@@ -1251,6 +1394,31 @@
 			exit(1);
 #endif
 	}
+
+#ifdef __FreeBSD__
+  	if (!options.use_login) {
+		/*
+		 * If the password change time is set and has passed, give the
+		 * user a password expiry notice and chance to change it.
+		 */
+		if (pw->pw_change != 0) {
+			struct timeval tv;
+
+			(void)gettimeofday(&tv, NULL);
+			if (tv.tv_sec >= pw->pw_change) {
+				(void)printf(
+				    "Sorry -- your password has expired.\n");
+				syslog(LOG_INFO,
+				    "%s Password expired - forcing change",
+				    pw->pw_name);
+				if (system("/usr/bin/passwd") != 0) {
+					perror("/usr/bin/passwd");
+					exit(1);
+				}
+			}
+		}
+	}
+#endif /* __FreeBSD__ */
 
 	if (!options.use_login)
 		do_rc_files(s, shell);
