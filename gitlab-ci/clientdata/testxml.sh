#!/bin/bash

cd clientdata
rm -rf public
mkdir public
mkdir shared
echo >shared/error.log
echo ${CI_BUILD_ID} >shared/buildid.log

function gitclone {
    git clone $*
    if [ "$?" != 0 ]; then
        sleep 1s
        git clone $*
        if [ "$?" != 0 ]; then
            sleep 3s
            git clone $*
        fi
    fi
}

cd ..
ln -s clientdata client-data

cd tools/testxml

./xsdcheck.sh
export RES=$(cat errors.txt)
if [[ -n "${RES}" ]]; then
    echo "xml check failed"
    echo "xml check failed" >../../clientdata/shared/error.log
    echo ${RES} >>../../clientdata/shared/error.log
    cat ../../clientdata/shared/error.log
    exit 1
fi

echo >../../clientdata/shared/error.log
./testxml.py silent >../../clientdata/shared/error.log
if [ "$?" != 0 ]; then
    echo "test xml error"
    cat ../../clientdata/shared/error.log
    exit 1
fi

echo >../../clientdata/shared/error.log
