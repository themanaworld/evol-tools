#!/bin/bash

# Copyright (C) 2011-2014  Evol Online
# Author: Andrei Karas (4144)

dir=`pwd`

rm adler32
gcc -lz adler32.c -o adler32

mkdir files
mkdir upload

rm files/hercules.zip
cd ../../herculesclientdata
find -iregex ".+[.]\(xml\|png\|tmx\|ogg\|txt\|po\|tsx\)" -printf "%P\n" | zip -@ ../privtools/hercules_update/files/hercules.zip
git log --pretty=oneline -n 1 | awk '{print $1}' >../privtools/update/commit.txt

cd $dir/files
sum=`../adler32 1 hercules.zip`
echo "evol.zip ${sum}" >resources2.txt

echo '<?xml version="1.0"?>
<updates>' >xml_header.txt
echo '</updates>' >xml_footer.txt

echo "    <update type=\"data\" file=\"hercules.zip\" hash=\"${sum}\" />" >> xml_header.txt
cp xml_header.txt resources.xml
cat xml_footer.txt >>resources.xml

cp hercules.zip ../upload/
cp resources2.txt ../upload/
cp resources.xml ../upload/
cp ../news.txt ../upload/
