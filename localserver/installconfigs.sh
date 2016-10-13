#!/bin/bash

export SD="../../server-data"
export CONF="$SD/conf/import"

mkdir $CONF
cp conf/* $CONF
cp -f conf/inter_conf.txt $CONF
cp -f ${SD}/conf/channels.conf.base ${SD}/conf/channels.conf
mkdir versions
echo "3" >versions/confver
