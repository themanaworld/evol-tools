#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import os
import re
import sys

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
        return (m.group("id").lower(), int(m.group("size")), m.group("func"))
    return None

def readPackets(path, oldVersion, newVersion):
    oldPackets = dict()
    newPackets = dict()
    with open(path, "r") as f:
        searchState = 0
        newBlock = False
        for line in f:
            if searchState == 0: # search for #if PACKETVER
                if line.find(defStart) == 0:
                    ver = line[len(defStart):]
                    idx = ver.find("//");
                    if idx > 0:
                        ver = ver[:idx]
                    ver = int(ver)
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
    ret = dict()
    for line in old.iteritems():
        if line[0] in new:
            ret[line[0]] = line[1]
    return (ret, new)

def showPlan(data):
    oldFunc = dict()
    newFunc = dict()

    for line in data[0].iteritems():
        if line[1][2] not in oldFunc:
            oldFunc[line[1][2]] = []
        oldFunc[line[1][2]].append(line[1])

    for line in data[1].iteritems():
        if line[1][2] not in newFunc:
            newFunc[line[1][2]] = []
        newFunc[line[1][2]].append(line[1])

    for line in oldFunc:
        if line in oldFunc and line in newFunc:
            for line2 in oldFunc[line]:
                id1 = line2[0]
                id2 = newFunc[line][0][0]
                if id1 != id2:
                    print "{0:30} {1:4}  ->  {2:4}".format(line, id1, id2)

def showHelp():
    print "Show difference between packet versions."
    print "Usage: {0} old new".format(sys.argv[0])

def main():
    if len(sys.argv) != 3:
        showHelp();
        exit();

    data = readPackets("hercules/src/map/packets.h", int(sys.argv[1]), int(sys.argv[2]))
    changed = findChangedPackets(data)
    showPlan(changed)

main()
