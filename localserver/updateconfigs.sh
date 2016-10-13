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
fi

if [ "${VER}" -lt "2" ]; then
    rm ${CONFDIR}/conf/import/*.txt
    cp conf/* ${CONFDIR}/conf/import
    echo "2" >versions/confver
fi

if [ "${VER}" -lt "3" ]; then
    cp conf/constants.conf ${CONFDIR}/conf/import/
    echo "3" >versions/confver
fi
