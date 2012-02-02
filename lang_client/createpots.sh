#!/bin/bash

function its {
    itstool -o ../../privtools/lang_client/pot/$1.pot $1.xml
}

DIR=`pwd`
cd ../../gittorious/clientdata-beta/


its items
its ea-skills
its emotes
its itemcolors
its monsters

cd $DIR

itstool -o pot/manaplus_emotes.pot tmp/manaplus_emotes.xml

msgcat pot/*.pot > clientdata-beta.pot
