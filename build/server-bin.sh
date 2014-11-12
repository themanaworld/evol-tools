#!/bin/bash

cd ../../server-code
make clean
./build.sh static

if [[ $? == 0 ]]; then
    cp char-server ../server-bin
    cp login-server ../server-bin
    cp map-server ../server-bin
    echo Build success
else
    echo Build failed
fi
