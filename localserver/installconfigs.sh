#!/bin/bash

export SD="../../server-data"
export CONF="$SD/conf/import"
export NPC="$SD/npc"

mkdir $CONF
cp conf/* $CONF
cp -f ${SD}/conf/channels.conf.base ${SD}/conf/channels.conf
cp -f npc/motd-* ${NPC}/commands/
mkdir versions
echo "4" >versions/confver
