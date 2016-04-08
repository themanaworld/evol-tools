#!/bin/bash

cd clientdata
rm -rf public
mkdir public
mkdir .shared
echo >.shared/error.log
echo ${CI_BUILD_ID} >.shared/buildid.log

cd ..
ln -s clientdata client-data

rm -rf music
git clone --depth 1 https://gitlab.com/evol/evol-music.git music

cd tools/testxml

./xsdcheck.sh
export RES=$(cat errors.txt)
if [[ -n "${RES}" ]]; then
    echo "xml check failed"
    echo "xml check failed" >../../clientdata/.shared/error.log
    echo ${RES} >>../../clientdata/.shared/error.log
    exit 1
fi

./testxml.py silent >../../clientdata/.shared/error.log
if [ "$?" != 0 ]; then
    echo "test xml error"
    exit 2
fi

echo >../../clientdata/.shared/error.log

cd ../update
./createnew.sh
./create_music.sh

cp -r upload/* ../../clientdata/public
ls ../../clientdata/public
