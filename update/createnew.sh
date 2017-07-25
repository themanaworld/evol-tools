#!/usr/bin/env bash

# Copyright (C) 2011-2012  Evol Online
# Author: Andrei Karas (4144)

dir=`pwd`

rm adler32
gcc -lz adler32.c -o adler32

mkdir files
mkdir upload

rm files/evol.zip
cd ../../client-data
find -iregex ".+[.]\(xml\|png\|tmx\|ogg\|txt\|po\|tsx\)" -exec touch --date=2015-01-01 {} \;
find -iregex ".+[.]\(xml\|png\|tmx\|ogg\|txt\|po\|tsx\)" -printf "%P\n" | zip -X -@ ../tools/update/files/evol.zip
git log --pretty=oneline -n 1 | awk '{print $1}' >../tools/update/commit.txt

cd $dir/files
sum=`../adler32 1 evol.zip`
echo "evol.zip ${sum}" >resources2.txt

echo '<?xml version="1.0"?>
<updates>' >xml_header.txt
echo '</updates>' >xml_footer.txt

echo "    <update type=\"data\" file=\"evol.zip\" hash=\"${sum}\" />" >> xml_header.txt
cp xml_header.txt resources.xml
cat xml_footer.txt >>resources.xml

cp evol.zip ../upload/
cp resources2.txt ../upload/
cp resources.xml ../upload/
cp ../news.txt ../upload/
