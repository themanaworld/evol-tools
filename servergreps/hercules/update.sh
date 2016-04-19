#!/bin/bash

function preproc {
    cpp -DPACKETVER=$2 \
    -DCOMMON_SOCKET_H \
    "-DWFIFOW(fd,pos)=WFIFOW(fd,pos)" \
    "-DWBUFW(p,pos)=WBUFW(p,pos)" \
    -I../../../server-code/src -I../../../server-code/3rdparty \
    ../../../server-code/src/$3/$4 \
    $1/src/$4
}

function genpackets {
    if [ ! -d "$1/src" ]; then
        mkdir -p "$1/src"
    fi
    cpp -DPACKETVER=$2 "-Dpacket(id,size,...)=packet(id,size,__VA_ARGS__)" ../../../server-code/src/map/packets.h $1/src/packets.h
    preproc $1 $2 map packets_struct.h
    preproc $1 $2 char char.c
    preproc $1 $2 login login.c
    preproc $1 $2 map clif.c
    preproc $1 $2 login lclif.p.h
    preproc $1 $2 login lclif.c
    ./packets.py $2
}

genpackets 00000000 0
genpackets 00000007 7
genpackets 20120700 20120700
genpackets 20130000 20130000
genpackets 20130221 20130221
genpackets 20140000 20140000
genpackets 20140403 20140403
genpackets 20141016 20141016
genpackets 20141022 20141022
genpackets 20150000 20150000
genpackets 20150226 20150226
genpackets 20150513 20150513
genpackets 20150805 20150805
