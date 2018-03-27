#!/usr/bin/env bash

# Copyright (C) 2011-2012  Evol Online
# Author: Andrei Karas (4144)

dir=`pwd`
CC=${CC:=gcc}

rm adler32
$CC -lz adler32.c -o adler32

mkdir files
mkdir upload

rm files/music.zip
cd ../../music
find -iregex ".+[.]\(ogg\)" -exec touch --date=2015-01-01 {} \;
find -iregex ".+[.]\(ogg\)" -printf "%P\n" | zip -X -@ ../tools/update/files/music.zip
git log --pretty=oneline -n 1 | awk '{print $1}' >../tools/update/musiccommit.txt

cd $dir/files
sum=`../adler32 1 music.zip`

echo "    <update type=\"music\" required=\"no\" file=\"music.zip\" hash=\"${sum}\" description=\"Evol music\" />" >> xml_header.txt

cp xml_header.txt resources.xml
cat xml_footer.txt >>resources.xml

cp music.zip ../upload/
cp resources.xml ../upload/
cp ../news.txt ../upload/
