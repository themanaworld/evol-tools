#! /usr/bin/env python2.7
# -*- coding: utf8 -*-
#
# Copyright (C) 2015  Evol Online
# Author: Andrei Karas (4144)

import os
import re
import sys

filt = re.compile(".+[.]c", re.IGNORECASE)
serverpacketre = re.compile("(WFIFOW|WBUFW)([ ]*)[(]([ ]*)([\w>_-]+),([ ]*)"
    + "(?P<offset>0)([ ]*)[)]([ ]*)=([ ]*)0x(?P<packet>[0-9a-fA-F]+)([ ]*)[;]")
serverpacketre2 = re.compile("PacketType([ ]*)=([ ]*)(?P<name>[\w_]+);")
serverpacketre3 = re.compile("(WFIFOW|WBUFW)([ ]*)[(]([ ]*)([\w>_-]+),([ ]*)"
    + "(?P<offset>0)([ ]*)[)]([ ]*)=([ ]*)(?P<packet>[0-9\w]+)([ ]*)[;]")
serverpacketre4 = re.compile("int cmd([ ]*)=([ ]*)0x(?P<packet>[0-9a-fA-F]+);")
protocolinre = re.compile("packet[(](?P<name>[A-Z0-9_]+),([ ]*)0x(?P<packet>[0-9a-fA-F]+),([ ]*)(?P<len>[\w-]+),([ ]*)")
protocolinverre = re.compile("^// (?P<ver>[0-9]+)$")
protocoloutre = re.compile("packet[(](?P<name>CMSG_[A-Z0-9_]+),([ ]*)0x(?P<packet>[0-9a-fA-F]+),([ ]*)(?P<len>[\w-]+),([ ]*)(?P<function>[0-9a-zA-Z_>-]+)[)];")
clientpacketre = re.compile("(\t*)packet[(]0x(?P<packet>[0-9a-fA-F]+),(?P<len>[\w-]+),(?P<function>[0-9a-zA-Z_>-]+)(,|[)])")
packetNameClientre = re.compile("(?P<name>(S|C)MSG_[A-Z0-9_]+)")
namedPacketre = re.compile("((\t|[ ])*)(?P<name>[\w0-9_]+)([ ]*)=([ ]*)0x(?P<value>[0-9a-fA-F]+)")

packetsSet = set()
serverpacketsSorted = []
clientpacketsSorted = []
clientPacketsManaPlus = dict()
clientPacketsManaPlusClient = dict()
clientPackets = dict()
sizes = dict()
manaplusUsedPacketsSet = set()
namedPackets = dict()
#idToServerFunction = dict()

def addServerPacket(data):
    if data in namedPackets:
        for val in namedPackets[data]:
            packetsSet.add(val)
    else:
        packetsSet.add(data.lower())

def collectServerPackets(parentDir):
    global itemNamesByName
    files = os.listdir(parentDir) 
    for file1 in files:
        if file1[0] == ".":
            continue
        file2 = os.path.abspath(parentDir + os.path.sep + file1)
        if not os.path.isfile(file2):
            if file2.find("/src/evol") <= 0:
                collectServerPackets(file2)
        elif filt.search(file1):
            with open(file2, "r") as f:
                for line in f:
                    m = serverpacketre4.findall(line)
                    if len(m) > 0:
                        for str in m:
                            data = str[2]
                            while len(data) < 4:
                                data = "0" + data
                            addServerPacket(data)
                    m = serverpacketre.findall(line)
                    if len(m) == 0:
                        m = serverpacketre3.findall(line)
                    if len(m) > 0:
                        for str in m:
                            if str[9] == "0":
                                continue
                            data = str[9]
                            if data == "cmd":
                                continue
                            while len(data) < 4:
                                data = "0" + data
                            addServerPacket(data)

                    m = serverpacketre2.findall(line)
                    if len(m) > 0:
                        for str in m:
                            if str[2] == "0":
                                continue
                            data = str[2]
                            if len(data) > 2 and data[0:2] == "0x":
                                data = data[2:]
                            while len(data) < 4:
                                data = "0" + data
                            addServerPacket(data)

def sortServerPackets():
    for packet in packetsSet:
        serverpacketsSorted.append(packet)
    serverpacketsSorted.sort()

def sortClientPackets():
    for packet in clientPackets:
        clientpacketsSorted.append(packet)
    clientpacketsSorted.sort()

def collectManaPlusInPackets(fileName, packetVersion):
    version = 0
    with open(fileName, "r") as f:
        for line in f:
            m = protocolinverre.search(line)
            if m is not None:
                version = int(m.group("ver"))
                continue
            # skip bigger versions than requested
            if version > packetVersion:
                continue
            m = protocolinre.search(line)
            if m is not None:
                packet = int(m.group("packet"), 16)
                if packet > 0xb00 or packet == 0:
                    continue
                clientPacketsManaPlus[m.group("packet").lower()] = m.group("name")
                sizes[m.group("packet").lower()] = m.group("len")

def collectManaPlusOutPackets(fileName, packetVersion):
    version = 0
    with open(fileName, "r") as f:
        for line in f:
            m = protocolinverre.search(line)
            if m is not None:
                version = int(m.group("ver"))
                continue
            # skip bigger versions than requested
            if version > packetVersion:
                continue
            m = protocoloutre.search(line)
            if m is not None:
                packet = int(m.group("packet"), 16)
                if packet > 0xb00 or packet == 0:
                    continue
                clientPacketsManaPlus[m.group("packet").lower()] = m.group("name")
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
                #idToServerFunction[data] = m.group("function")
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

def collectManaPlusUsedPackets(fileName):
    with open(fileName, "r") as f:
        for line in f:
            m = packetNameClientre.search(line)
            if m is not None:
                manaplusUsedPacketsSet.add(m.group("name"))
                #print m.group("name")

def collectNamedPackets(fileName):
    with open(fileName, "r") as f:
        for line in f:
            m = namedPacketre.search(line)
            if m is not None:
                if m.group("name") not in namedPackets:
                    namedPackets[m.group("name")] = []
                data = m.group("value").lower()
                while len(data) < 4:
                    data = "0" + data
                namedPackets[m.group("name")].append(data)
                #print "named: {0} = {1}".format(m.group("name"), m.group("value"))

def processManaPlusCppFiles(parentDir):
    files = os.listdir(parentDir)
    for file1 in files:
        if file1[0] == ".":
            continue
        file2 = os.path.abspath(parentDir + os.path.sep + file1)
        if not os.path.isfile(file2):
            processManaPlusCppFiles(file2)
        elif file1[-4:] == ".cpp":
            collectManaPlusUsedPackets(file2)

def printPackets(packetDir):
    with open(packetDir + "/serverpackets.txt", "w") as w:
        for packet in serverpacketsSorted:
            data = packet
            while data[0] == "0":
                data = data[1:]
            if packet in clientPacketsManaPlus:
                clientName = clientPacketsManaPlus[packet]
#                if clientName not in manaplusUsedPacketsSet and clientName.find("_OUTDATED") <= 0:
#                    w.write("UNIMPLIMENTED ")
                w.write(data + " client name: " + clientName)
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

    with open(packetDir + "/uselesspackets.txt", "w") as w:
        for packet in clientPacketsManaPlusClient:
            if packet not in clientPackets:
                w.write("Useless packet {0}.\n".format(packet))

    manaplusFunc = set()
    rev = []

    with open(packetDir + "/clientpackets.txt", "w") as w:
        for packet in clientPacketsManaPlusClient:
            clientName = clientPacketsManaPlusClient[packet]
            if clientName not in manaplusUsedPacketsSet and clientName.find("_OUTDATED") <= 0:
                w.write("PSESENT BUT UNIMPLIMENTED {0}\n".format(clientName))

#        for packet in clientPacketsManaPlusClient:
#            if packet in clientPackets:
#                manaplusFunc.add(clientPackets[packet][1])
#        for func in funcDict:
#            if func not in manaplusFunc:
#                packet = funcDict[func]
#                rev.append("{0:4} {1:>4} {2}".format(packet, clientPackets[packet][0], clientPackets[packet][1]))

        clientSet = set()
        for packet in clientPackets:
            clientSet.add(clientPackets[packet][1])
        for packet in clientPacketsManaPlusClient:
            if packet in clientPackets and clientPackets[packet][1] in clientSet:
#                print "removing {0}, function: {1}".format(packet, clientPackets[packet][1])
                clientSet.remove(clientPackets[packet][1])

        allPackets = set()
        for packet in clientPackets:
            allPackets.add(packet)
        for packet in clientPacketsManaPlusClient:
            allPackets.add(packet)

        for packet in clientSet:
            rev.append("{0:4} {1:33} {2}".format("?", "UNIMPLIMENTED", packet))
#            rev.append("{0:4} {1:>4} {2} UNIMPLIMENTED".format(packet, clientPackets[packet][0], clientPackets[packet][1]))

        for packet in allPackets:
            if packet not in clientPacketsManaPlusClient:
                continue
            data = "{0:4} {1:33} ".format(packet, clientPacketsManaPlusClient[packet])
            if packet in clientPackets:
                data = data + clientPackets[packet][1]
            else:
                data = data + "?"
            rev.append(data)

        rev.sort()

        for data in rev:
            w.write(data)
            w.write("\n")

#    with open(packetDir + "/wrongpackersizes.txt", "w") as w:
#        for packet in sizes:
#            if packet == "0000":
#                continue
#            data = packet
#            while data[0] == "0":
#                data = data[1:]
#            if packet in serverpacketsSorted:
#                if sizes[packet] != clientPackets[packet][0]:
#                    w.write("{0:>4} {1:4} -> {2:4}\n".format(data, sizes[packet], clientPackets[packet][0]))

def showHelp():
    print("Usage: packets.py version");
    exit(1)

if len(sys.argv) != 2:
    showHelp()

packetVersion = sys.argv[1]
packetDir = packetVersion
while len(packetDir) < 8:
    packetDir = "0" + packetDir

#srcPath = "../../../server-code/src/"
srcPath = packetDir + "/src"
namedPacketsPath = packetDir + "/src/packets_struct.h"
manaplusPath = "../../../manaplus/src/"
protocolPath = manaplusPath + "net/eathena/packets"
clientPacketsPath = packetDir + "/src/packets.h"
packetsPath = manaplusPath + "net/eathena/packetsin.inc"
eathenaPath = manaplusPath + "net/eathena/"

collectNamedPackets(namedPacketsPath);
collectServerPackets(srcPath)
collectClientPackets(clientPacketsPath)
collectManaPlusInPackets(protocolPath + "in.inc", int(packetVersion))
collectManaPlusOutPackets(protocolPath + "out.inc", int(packetVersion))
#collectManaPlusSizes(packetsPath);
processManaPlusCppFiles(eathenaPath);
sortClientPackets()
sortServerPackets()
printPackets(packetDir)
