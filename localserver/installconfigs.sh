#!/bin/bash

export SD="../../server-data"
export CONF="$SD/conf/import"

mkdir $CONF
cp conf/*.txt $CONF
cp -f conf/inter_conf.txt $CONF
