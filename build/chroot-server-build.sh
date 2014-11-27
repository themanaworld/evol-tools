#!/bin/bash

export CHROOT="$1"
export NAME=lenny
export DSTCHDIR="$2"
export DSTDIR="$CHROOT$DSTCHDIR"
export SRCDIR="$DSTDIR/server-code"
export SRCPLUGINSDIR="$SRCDIR/src/evol/build/src/.libs/"
export LOCALDIR="../../server-local/bin"

echo Removing old files...
rm -rf "$DSTDIR"
mkdir "$DSTDIR"

echo Coping files...
cp -r ../../server-code "$DSTDIR/server-code"
cp -r ../../server-data "$DSTDIR/server-data"
cp -r ../../server-local "$DSTDIR/server-local"
cp -r ../../tools "$DSTDIR/tools"

echo Enter chroot...
schroot -c "$NAME" --directory "$DSTCHDIR/tools/build/" "server-bin.sh"

if [[ $? == 0 ]]; then
    cp "$SRCDIR/char-server" "$LOCALDIR"
    cp "$SRCDIR/login-server" "$LOCALDIR"
    cp "$SRCDIR/map-server" "$LOCALDIR"
    cp "$SRCDIR/mapcache" "$LOCALDIR"
    mkdir "$LOCALDIR/plugins/"
    cp "$SRCDIR/plugins"/*.so "$LOCALDIR/plugins/"
    cp -f "$SRCPLUGINSDIR"/*.so "$LOCALDIR/plugins/"
fi
echo Exit chroot...
