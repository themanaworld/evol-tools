#!/bin/bash

dir=`pwd`

rm adler32
gcc -lz adler32.c -o adler32

rm files/evol.zip
cd ../../clientdata
find -iregex ".+[.]\(xml\|png\|tmx\|ogg\|txt\)" -printf "%P\n" | zip -@ ../evol-tools/update/files/evol.zip
git log --pretty=oneline -n 1 | awk '{print $1}' >../evol-tools/update/commit.txt

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