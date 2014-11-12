#!/bin/bash

cd ../../server-code
make clean
./build.sh static

if [[ $? == 0 ]]; then
    cp -f char-server ../server-bin
    cp -f login-server ../server-bin
    cp -f map-server ../server-bin
else
    echo Build failed
    exit 1
fi

cd src/evol
make clean
./build.sh

if [[ $? == 0 ]]; then
    mkdir ../../../server-local/plugins
    cp -f build/src/.libs/*.so ../../../server-local/plugins
    echo Build success
else
    echo Build failed
fi
