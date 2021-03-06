#!/usr/bin/env bash

# Copyright (C) 2010-2012  Evol Online
# Author: Andrei Karas (4144)

dir=`pwd`
CC=${CC:=gcc}

rm adler32
$CC -lz adler32.c -o adler32

mkdir files
mkdir upload

previous=`cat commit.txt`

cd ../../client-data/mods

FILES=`ls`

for file in $FILES; do
    cd $file
    find . -type f | xargs zip -9 -r ../../../../evol-tools/update/files/mod-$file.zip
    cd $dir/files
    sum=`../adler32 1 mod-$file.zip`
    echo "    <update type=\"data\" group=\"$file\" file=\"mod-$file.zip\" hash=\"${sum}\" />" >> xml_header.txt
    cp xml_header.txt resources.xml
    cat xml_footer.txt >>resources.xml
    cp mod-$file.zip ../upload/
    cp resources2.txt ../upload/
    cp resources.xml ../upload/
done
