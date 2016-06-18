#!/bin/bash

# Copyright (C) 2010-2012  Evol Online
# Author: Andrei Karas (4144)

dir=`pwd`

rm adler32
gcc -lz adler32.c -o adler32

mkdir files
mkdir upload

previous=`cat musiccommit.txt`

cd ../../music
head=`git log --pretty=oneline -n 1 | awk '{print $1}'`
u1=`echo ${previous} | cut -c 1-7`
u2=`echo ${head} | cut -c 1-7`
git log --name-status ${previous}..${head} \
| awk '/^(A|M)\t/ {print $2}'
#    grep -e "[.]\(ogg\)" | sort | uniq | \
#    xargs zip -X -9 -r ../../evol-tools/update/files/music-${u1}..${u2}.zip
exit

cd $dir/files
if [ -f evol-${u1}..${u2}.zip ]; then
    mv ../muciscommit.txt ../muciscommit_old.txt
    echo ${head} >../muciscommit.txt
    sum=`../adler32 1 music-${u1}..${u2}.zip`
    echo "    <update type=\"music\" required=\"no\" file=\"music-${u1}..${u2}.zip\" hash=\"${sum}\" description=\"Evol music\" />" >> xml_header.txt
    cp xml_header.txt resources.xml
    cat xml_footer.txt >>resources.xml

    cp music-${u1}..${u2}.zip ../upload/
    cp resources2.txt ../upload/
    cp resources.xml ../upload/
    cp ../news.txt ../upload
fi
