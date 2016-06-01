#!/bin/bash

function its {
    itstool -o ../tools/lang_client/pot/$1.pot $1.xml
}

function its2 {
    itstool -o ../tools/lang_client/pot/$1.pot -i ../tools/lang_client/its/$1.xml $1.xml
}

DIR=`pwd`
cd ../../client-data


its items
its skills
its emotes
its itemcolors
its monsters
its quests
its pets
its npcs
its deadmessages
its2 itemfields

cd $DIR

itstool -o pot/manaplus_emotes1.pot tmp/manaplus_emotes.xml
itstool -o pot/deadmessages1.pot tmp/deadmessages.xml

msgcat pot/*.pot > clientdata-beta.pot
