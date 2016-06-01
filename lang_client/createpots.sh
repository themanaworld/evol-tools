#!/bin/bash

function its {
    itstool -o ../tools/lang_client/pot/$1.pot $1.xml
}

function its2 {
    itstool -o ../tools/lang_client/pot/$1.pot -i ../tools/lang_client/its/$1.xml $1.xml
}

DIR=`pwd`
cd ../../client-data

#its2 avatars
its2 deadmessages
its2 emotes
its2 homunculuses
its2 itemcolors
its2 itemfields
its2 items
its2 mercenaries
its2 monsters
#its2 npcdialogs
its2 npcs
its2 pets
its quests
its2 skills
its2 skillunits
its2 status-effects

cd $DIR

itstool -o pot/manaplus_emotes1.pot tmp/manaplus_emotes.xml
itstool -o pot/deadmessages1.pot tmp/deadmessages.xml

msgcat pot/*.pot > clientdata-beta.pot
