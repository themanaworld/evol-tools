#!/bin/bash

export $LOCALDIR="../server-local/bin"
cd ../../server-code
make clean
./build.sh static

if [[ $? == 0 ]]; then
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
autoreconf -i
cd build
make clean
../configure
make -j3
cd ..

if [[ $? == 0 ]]; then
    mkdir ../../../server-local/bin/plugins
    cp -f build/src/.libs/*.so ../../../server-local/bin/plugins
    echo Build success
else
    echo Build failed
    exit 1
fi
