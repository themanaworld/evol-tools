#!/bin/bash

export DIR=`pwd`
cd ../../server-plugin/build/
make clean
cd ${DIR}/../../server-code/
make clean
./build.sh old
