#!/bin/bash

function genpackets {
    cpp -DPACKETVER=$1 "-Dpacket(id,size,...)=packet(id,size,__VA_ARGS__)" ../../../server-code/src/map/packets.h $1/packets.h
    cpp -DPACKETVER=$1 -I../../../server-code/src ../../../server-code/src/map/packets_struct.h $1/packets_struct.h
    ./packets.py $1
}

genpackets 20141016
genpackets 20141022
genpackets 20150226
genpackets 20150513
genpackets 20150805
