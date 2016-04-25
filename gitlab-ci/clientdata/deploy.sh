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

cd tools/update

./createnew.sh
./create_music.sh

cp -r upload/* ../../clientdata/public
cd ../../clientdata
gitclone https://gitlab.com/4144/pagesindexgen.git pagesindexgen
cd pagesindexgen
./pagesindexgen.py ../public
ls ../public
