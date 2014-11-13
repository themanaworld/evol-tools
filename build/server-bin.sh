#!/bin/bash

cd ../../server-code
make clean
./build.sh static

if [[ $? == 0 ]]; then
    cp -f char-server ../server-local
    cp -f login-server ../server-local
    cp -f map-server ../server-local
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
    mkdir ../../../server-local/plugins
    cp -f build/src/.libs/*.so ../../../server-local/plugins
    echo Build success
else
    echo Build failed
fi
