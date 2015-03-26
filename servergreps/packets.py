#! /usr/bin/env python2.7
# -*- coding: utf8 -*-
#
# Copyright (C) 2015  Evol Online
# Author: Andrei Karas (4144)

import os
import re

filt = re.compile(".+[.]c", re.IGNORECASE)
serverpacketre = re.compile("(WFIFOW|WBUFW)([ ]*)[(]([ ]*)([\w>_-]+),([ ]*)"
    + "(?P<offset>0)([ ]*)[)]([ ]*)=([ ]*)0x(?P<packet>[0-9a-fA-F]+)([ ]*)[;]")
serverpacketre2 = re.compile("[.]PacketType([ ]*)=([ ]*)(?P<name>[\w]+);")
protocolre = re.compile("#define[ ](?P<name>[A-Z0-9_]+)([ ]*)0x(?P<packet>[0-9a-fA-F]+)")
protocolClientre = re.compile("#define[ ](?P<name>CMSG_[A-Z0-9_]+)([ ]*)0x(?P<packet>[0-9a-fA-F]+)")
clientpacketre = re.compile("(\t*)packet[(]0x(?P<packet>[0-9a-fA-F]+),(?P<len>[\w-]+),(?P<function>[0-9a-zA-Z_>-]+)(,|[)])")

packetsSet = set()
serverpacketsSorted = []
clientpacketsSorted = []
clientPacketsManaPlus = dict()
clientPacketsManaPlusClient = dict()
clientPackets = dict()
sizes = dict()

def collectServerPackets(parentDir):
    global itemNamesByName
    files = os.listdir(parentDir) 
    for file1 in files:
        if file1[0] == ".":
            continue
        file2 = os.path.abspath(parentDir + os.path.sep + file1)
        if not os.path.isfile(file2):
            collectServerPackets(file2)
        elif filt.search(file1):
            with open(file2, "r") as f:
                for line in f:
                    m = serverpacketre.findall(line)
                    if len(m) > 0:
                        for str in m:
                            data = str[9]
                            while len(data) < 4:
                                data = "0" + data
                            packetsSet.add(data.lower())
                    m = serverpacketre2.findall(line)
                    if len(m) > 0:
                        for str in m:
                            packetsSet.add(str[2].lower())

def sortServerPackets():
    for packet in packetsSet:
        serverpacketsSorted.append(packet)
    serverpacketsSorted.sort()

def sortClientPackets():
    for packet in clientPackets:
        clientpacketsSorted.append(packet)
    clientpacketsSorted.sort()

def collectManaPlusPackets(fileName):
    with open(fileName, "r") as f:
        for line in f:
            m = protocolre.search(line)
            if m is not None:
                clientPacketsManaPlus[m.group("packet").lower()] = m.group("name")
            m = protocolClientre.search(line)
            if m is not None:
                clientPacketsManaPlusClient[m.group("packet").lower()] = m.group("name")

def collectClientPackets(fileName):
    with open(fileName, "r") as f:
        for line in f:
            m = clientpacketre.search(line)
            if m is not None:
                data = m.group("packet").lower()
                while len(data) < 4:
                    data = "0" + data
                clientPackets[data] = (int(m.group("len")), m.group("function"));
                #print "{0},{1},{2}".format(m.group("packet"), m.group("len"), m.group("function"))

def collectManaPlusSizes(fileName):
    cnt = 0
    comaSplit = re.compile(",")
    with open(fileName, "r") as f:
        for line in f:
            line = line.strip()
            if len(line) < 2 or ((line[0] < "0" or line[0] > "9") and line[0] != "-"):
                continue
            cols = comaSplit.split(line)
            for col in cols:
                if col == "" or col == "\\":
                    continue
                data = hex(cnt).split('x')[1]
                while len(data) < 4:
                    data = "0" + data
                sizes[data] = int(col)
                cnt = cnt + 1
#    for d in range(0, 30):
#        s = ""
#        for f in range(0, 15):
#            s = s + "{0:>4},".format(sizes[f + d * 16])
#        print s

def printPackets():
    with open("serverpackets.txt", "w") as w:
        for packet in serverpacketsSorted:
            data = packet
            while data[0] == "0":
                data = data[1:]
            if packet in clientPacketsManaPlus:
                w.write(data + " client name: " + clientPacketsManaPlus[packet])
            else:
                w.write(data)
            w.write("\n")

    funcDict = dict()
    forRemove = []
    for packet in clientpacketsSorted:
        data = packet
        while data[0] == "0":
            data = data[1:]
        if packet in clientPackets:
            funcDict[clientPackets[packet][1]] = packet

    with open("uselesspackets.txt", "w") as w:
        for packet in clientPacketsManaPlusClient:
            if packet not in clientPackets:
                w.write("Useless packet {0}.\n".format(packet))

    manaplusFunc = set()
    rev = []
    with open("clientpackets.txt", "w") as w:
        for packet in clientPacketsManaPlusClient:
            if packet in clientPackets:
                manaplusFunc.add(clientPackets[packet][1])
        for func in funcDict:
            if func not in manaplusFunc:
                packet = funcDict[func]
                rev.append("{0:4} {1:>4} {2}".format(packet, clientPackets[packet][0], clientPackets[packet][1]))
        rev.sort()

        for data in rev:
            w.write(data)
            w.write("\n")

#    with open("wrongpackersizes.txt", "w") as w:
#        for packet in sizes:
#            if packet == "0000":
#                continue
#            data = packet
#            while data[0] == "0":
#                data = data[1:]
#            if packet in serverpacketsSorted:
#                if sizes[packet] != clientPackets[packet][0]:
#                    w.write("{0:>4} {1:4} -> {2:4}\n".format(data, sizes[packet], clientPackets[packet][0]))

srcPath = "../../server-code/src/"
manaplusPath = "../../manaplus/src/"
protocolPath = manaplusPath + "net/eathena/protocol.h"
clientPacketsPath = srcPath + "map/packets.h"
packetsPath = manaplusPath + "net/eathena/packets.h"

collectServerPackets(srcPath)
collectClientPackets(clientPacketsPath)
collectManaPlusPackets(protocolPath)
collectManaPlusSizes(packetsPath);
sortClientPackets()
sortServerPackets()
printPackets()
