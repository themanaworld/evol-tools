#!/bin/bash

cd clientdata
rm -rf public
mkdir public

cd ..
ln -s clientdata client-data

rm -rf music
git clone --depth 1 https://gitlab.com/evol/evol-music.git music

cd tools/testxml

./xsdcheck.sh
export RES=$(cat errors.txt)
if [[ -n "${RES}" ]]; then
    echo "xml check failed"
    exit(1)
fi

cd ../update
./createnew.sh
./create_music.sh

cp -r upload/* ../../clientdata/public
ls ../../clientdata/public
