#!/bin/sh
# $FreeBSD$

dir=$@
if [ ! -d $dir ]; then
	echo "Directory not found.  Aborting."
	exit 1
fi

tar xzvf $dir/ports.tar.gz
cd ports
rm -f distfiles packages
mkdir distfiles packages
(echo "copying packages ..." && cd packages && cp -R $dir/packages/ .)
#(echo "copying distfiles ..." && cd distfiles && cp -R $dir/distfiles/ .)
