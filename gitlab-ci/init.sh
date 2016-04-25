#!/bin/bash

function gitclone {
    git clone $*
    if [ "$?" != 0 ]; then
        sleep 1s
        git clone $*
        if [ "$?" != 0 ]; then
            sleep 3s
            git clone $*
        fi
    fi
}

function clientdata_init {
    cd clientdata
    mkdir shared
    echo >shared/error.log
    echo ${CI_BUILD_ID} >shared/buildid.log
}

ln -s clientdata client-data
