#!/bin/bash

cd clientdata
rm -rf public
mkdir public

cd ..
ln -s clientdata client-data

rm -rf music
git clone --depth 1 https://gitlab.com/evol/evol-music.git music

cd tools/update
./createnew.sh
./create_music.sh

cp -r upload/* ../../clientdata/public
ls ../../clientdata/public
