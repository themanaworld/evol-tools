#!/bin/bash

function genpackets {
    cpp -DPACKETVER=$2 "-Dpacket(id,size,...)=packet(id,size,__VA_ARGS__)" ../../../server-code/src/map/packets.h $1/src/packets.h
    cpp -DPACKETVER=$2 -I../../../server-code/src ../../../server-code/src/map/packets_struct.h $1/src/packets_struct.h
    ./packets.py $2
}

genpackets 00000007 7
genpackets 20130000 20130000
genpackets 20140000 20140000
genpackets 20141016 20141016
genpackets 20141022 20141022
genpackets 20150226 20150226
genpackets 20150513 20150513
genpackets 20150805 20150805
