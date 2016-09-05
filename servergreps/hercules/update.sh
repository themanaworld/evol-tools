#!/bin/bash

function preproc {
    cpp -DPACKETVER=$3 \
    -DCOMMON_SOCKET_H \
    "-DWFIFOW(fd,pos)=WFIFOW(fd,pos)" \
    "-DWBUFW(p,pos)=WBUFW(p,pos)" \
    -I../links/$1/src -I../links/$1/3rdparty \
    ../links/$1/src/$4/$5 \
    $2/src/hercules/$5
}

function genpackets {
    rm -rf "$2/src"
    mkdir -p "$2/src/hercules"
    cpp -DPACKETVER=$3 "-Dpacket(id,size,...)=packet(id,size,__VA_ARGS__)" ../links/$1/src/map/packets.h $2/src/hercules/packets.h
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
genpackets hercules 20100105 20100105
genpackets hercules 20100303 20100303
genpackets hercules 20100420 20100420
genpackets hercules 20100608 20100608
genpackets hercules 20100803 20100803
genpackets hercules 20101124 20101124
genpackets hercules 20110718 20110718
genpackets hercules 20111005 20111005
genpackets hercules 20111102 20111102
genpackets hercules 20120307 20120307
genpackets hercules 20120410 20120410
genpackets hercules 20120418 20120418
genpackets hercules 20120604 20120604
genpackets hercules 20120702 20120702
# bug in 20120710. it hide one packet
genpackets hercules 20120710 20120710
genpackets hercules 20120716 20120716
genpackets hercules 20130320 20130320
genpackets hercules 20130515 20130515
genpackets hercules 20130522 20130522
genpackets hercules 20130529 20130529
genpackets hercules 20130605 20130605
genpackets hercules 20130612 20130612
genpackets hercules 20130618 20130618
genpackets hercules 20130626 20130626
genpackets hercules 20130703 20130703
genpackets hercules 20130724 20130724
genpackets hercules 20130807 20130807
genpackets hercules 20130814 20130814
genpackets hercules 20131218 20131218
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
