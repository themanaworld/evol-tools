#!/bin/bash

function its {
    itstool -o ../tools/lang_client/pot/$1.pot $1.xml
}

function its2 {
    itstool -o ../tools/lang_client/pot/$1.pot -i ../tools/lang_client/its/$1.xml $1.xml
}

function its2dict {
    itstool -o ../tools/lang_client/dict/$1.pot -i ../tools/lang_client/its/$1.xml $1.xml
}

DIR=`pwd`
cd ../../client-data

#its2 avatars
its2 deadmessages
its2 emotes
its2 groups
its2 homunculuses
its2 itemcolors
its2 itemfields
its2 items
its2 mercenaries
its2 monsters
# disabled for now because here testing strings only
#its2 npcdialogs
its2 npcs
its2 pets
its quests
its2 skills
its2 skillunits
its2 stats
its2 status-effects
its2dict texts

cd $DIR

rm pot/map*.pot

itstool -o pot/manaplus_emotes1.pot tmp/manaplus_emotes.xml
itstool -o pot/deadmessages1.pot tmp/deadmessages.xml

find ../../client-data/maps -type f -name "*.tmx" -exec ./processtmx.sh {} \;

msgcat pot/*.pot > clientdata-beta.pot
msgcat dict/*.pot > clientdata-dict.pot
