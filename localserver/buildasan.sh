#!/bin/bash

export DIR=`pwd`
rm -rf ../../server-plugin/build/
mkdir ../../server-plugin/build/
cd ${DIR}/../../server-code/
make clean
./build.sh
