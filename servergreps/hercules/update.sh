#!/bin/bash

function preproc {
    cpp -DPACKETVER=$3 \
    -DCOMMON_SOCKET_H \
    "-DWFIFOW(fd,pos)=WFIFOW(fd,pos)" \
    "-DWBUFW(p,pos)=WBUFW(p,pos)" \
    -I../links/$1/src -I../links/$1/3rdparty \
    ../links/$1/src/$4/$5 \
    $2/src/$5
}

function genpackets {
    if [ ! -d "$2/src" ]; then
        mkdir -p "$2/src"
    fi
    cpp -DPACKETVER=$3 "-Dpacket(id,size,...)=packet(id,size,__VA_ARGS__)" ../links/$1/src/map/packets.h $2/src/packets.h
    preproc $1 $2 $3 map packets_struct.h
    preproc $1 $2 $3 char char.c
    preproc $1 $2 $3 login login.c
    preproc $1 $2 $3 map clif.c
    preproc $1 $2 $3 login lclif.p.h
    preproc $1 $2 $3 login lclif.c
    ./packets.py $3
}

genpackets hercules 00000000 0
genpackets hercules 00000007 7
genpackets hercules 20120700 20120700
genpackets hercules 20130000 20130000
genpackets hercules 20130221 20130221
genpackets hercules 20131223 20131223
genpackets hercules 20131230 20131230
genpackets hercules 20140000 20140000
genpackets hercules 20140402 20140402
genpackets hercules 20141016 20141016
genpackets hercules 20141022 20141022
genpackets hercules 20150000 20150000
genpackets hercules 20150226 20150226
genpackets hercules 20150513 20150513
genpackets hercules 20150805 20150805
genpackets ragemu 20150916 20150916
genpackets ragemu 20151001 20151001
genpackets ragemu 20151029 20151029
genpackets ragemu 20151104 20151104
genpackets ragemu 20151216 20151216
genpackets ragemu 20160316 20160316
