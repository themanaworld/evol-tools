#!/bin/bash

source ./tools/gitlab-ci/init.sh

clientdata_init

rm -rf public
mkdir public

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
