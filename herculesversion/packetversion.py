#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import array
import base64
import gzip
import os
import re
import datetime
import xml
import csv
import ogg.vorbis
import StringIO
import sys
import zlib
import struct
import shutil
from sets import Set

defStart = "#if PACKETVER >= "
defEnd = "#endif"
packetStart = "packet(";
packetRe = re.compile("\tpacket[(](?P<id>([^,]+)),(?P<size>([^,])+),(?P<func>([^,]+))")

def makeDir(path):
    if not os.path.exists(path):
        os.makedirs(path)

def saveFile(fileName, data):
    with open(fileName, "w") as w:
        w.write(data)

def parsePacket(line):
    m = packetRe.search(line)
    if m is not None:
        return (m.group("id"), m.group("size"), m.group("func"))
    return None

def readPackets(path, oldVersion, newVersion):
    oldPackets = {}
    newPackets = {}
    with open(path, "r") as f:
        searchState = 0
        newBlock = False
        for line in f:
            if searchState == 0: # search for #if PACKETVER
                if line.find(defStart) == 0:
                    ver = int(line[len(defStart):])
                    if ver <= newVersion:
                        if ver > oldVersion:
                            newBlock = True
                        else:
                            newBlock = False
                        searchState = 1
            elif searchState == 1: # read block body
                if line.find(packetStart) == 1:
                    data = parsePacket(line)
                    if data is not None:
                        if newBlock == True:
                            newPackets[data[0]] = data
                        else:
                            oldPackets[data[0]] = data
                elif line.find(defEnd) == 0:
                    searchState = 0
    return (oldPackets, newPackets)

def findChangedPackets(data):
    old = data[0]
    new = data[1]
    ret = []
    for line in old.iteritems():
        if line[0] in new:
            ret.append(line[1])
    return (ret, new)

def showPlan(data):
    oldFunc = {}
    newFunc = {}
    for line in data[0]:
        oldFunc[line[2]] = line
    for line in data[1].iteritems():
        newFunc[line[1][2]] = line[1]

    for line in oldFunc:
        print "{0:30} {1:4} {2}".format(line, oldFunc[line][0], newFunc[line][0])
#        if line not in newFunc:
#            print line

def main():
    data = readPackets("hercules/src/map/packets.h", 20131223, 20131230)
    changed = findChangedPackets(data)
    showPlan(changed)

main()
