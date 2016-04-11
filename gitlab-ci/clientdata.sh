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

rm -rf music
gitclone https://gitlab.com/evol/evol-music.git music

cd tools/testxml

./xsdcheck.sh
export RES=$(cat errors.txt)
if [[ -n "${RES}" ]]; then
    echo "xml check failed"
    echo "xml check failed" >../../clientdata/shared/error.log
    echo ${RES} >>../../clientdata/shared/error.log
    exit 0
fi

echo >../../clientdata/shared/error.log
./testxml.py silent >../../clientdata/shared/error.log
if [ "$?" != 0 ]; then
    echo "test xml error"
    exit 0
fi

echo >../../clientdata/shared/error.log

cd ../update
./createnew.sh
./create_music.sh

cp -r upload/* ../../clientdata/public
cd ../../clientdata
gitclone https://gitlab.com/4144/pagesindexgen.git pagesindexgen
cd pagesindexgen
./pagesindexgen.py ../public
ls ../public
