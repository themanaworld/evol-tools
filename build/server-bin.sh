#!/usr/bin/env bash

export LOCALDIR="../server-local/bin"
cd ../../server-code
echo Build server...
make clean
./build.sh static

if [[ $? == 0 ]]; then
    echo Copy server binaries...
    cp -f char-server $LOCALDIR
    cp -f login-server $LOCALDIR
    cp -f map-server $LOCALDIR
    cp -f mapcache $LOCALDIR
else
    echo Build failed
    exit 1
fi

cd src/evol
mkdir build
echo Build evol plugin...
autoreconf -i
cd build
make clean
../configure
make -j3

if [[ $? == 0 ]]; then
    cd ..
    echo Copy plugin binaries...
    mkdir ../../../server-local/bin/plugins
    cp -f build/src/.libs/*.so ../../../server-local/bin/plugins
    echo Build success
else
    cd ..
    echo Build failed
    exit 1
fi
