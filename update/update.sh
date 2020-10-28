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

cd ../../client-data
head=`git log --pretty=oneline -n 1 | awk '{print $1}'`
u1=`echo ${previous} | cut -c 1-7`
u2=`echo ${head} | cut -c 1-7`
git log --name-status ${previous}..${head} | awk '/^(A|M)\t/ {print $2}' | \
    grep -e "[.]\(xml\|png\|tmx\|ogg\|txt\|po\|tsx\)" | sort | uniq | \
    xargs zip -X -9 -r ../tools/update/files/revolt-${u1}..${u2}.zip

cd $dir/files
if [ -f revolt-${u1}..${u2}.zip ]; then
    mv ../commit.txt ../commit_old.txt
    echo ${head} >../commit.txt
    sum=`../adler32 1 revolt-${u1}..${u2}.zip`
    echo "revolt-${u1}..${u2}.zip ${sum}" >>resources2.txt
    echo "    <update type=\"data\" file=\"revolt-${u1}..${u2}.zip\" hash=\"${sum}\" />" >> xml_header.txt
    cp xml_header.txt resources.xml
    cat xml_footer.txt >>resources.xml

    cp revolt-${u1}..${u2}.zip ../upload/
    cp resources2.txt ../upload/
    cp resources.xml ../upload/
    cp ../news.txt ../upload
fi
