#!/bin/bash

# Copyright (C) 2010-2011  Evol Online
# Author: Andrei Karas (4144)

dir=`pwd`

rm adler32
gcc -lz adler32.c -o adler32

previous=`cat commit.txt`

cd ../../clientdata
head=`git log --pretty=oneline -n 1 | awk '{print $1}'`
u1=`echo ${previous} | cut -c 1-7`
u2=`echo ${head} | cut -c 1-7`
git log --name-status ${previous}..${head} | awk '/^(A|M)\t/ {print $2}' | \
    grep -e "[.]\(xml\|png\|tmx\|ogg\|txt\)" | sort | uniq | \
    xargs zip -9 -r ../evol-tools/update/files/evol-${u1}..${u2}.zip

cd $dir/files
if [ -f evol-${u1}..${u2}.zip ]; then
    mv ../commit.txt ../commit_old.txt
    echo ${head} >../commit.txt
    sum=`../adler32 1 evol-${u1}..${u2}.zip`
    echo "evol-${u1}..${u2}.zip ${sum}" >>resources2.txt
    echo "    <update type=\"data\" file=\"evol-${u1}..${u2}.zip\" hash=\"${sum}\" />" >> xml_header.txt
    cp xml_header.txt resources.xml
    cat xml_footer.txt >>resources.xml

    cp evol-${u1}..${u2}.zip ../upload/
    cp resources2.txt ../upload/
    cp resources.xml ../upload/
    cp ../news.txt ../upload
fi
