#!/bin/bash

export VER=$(cat versions/confver 2>/dev/null)
export CONFDIR="../../server-data/"

if [[ -z "${VER}" ]]; then
    export VER="0"
    mkdir versions
fi

if [ "${VER}" -lt "1" ]; then
    cp -f ${CONFDIR}/conf/channels.conf ${CONFDIR}/conf/channels.conf.bak
    cp -f ${CONFDIR}/conf/channels.conf.base ${CONFDIR}/conf/channels.conf
    echo "1" >versions/confver
fi
