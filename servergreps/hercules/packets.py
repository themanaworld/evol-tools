#! /usr/bin/env python2.7
# -*- coding: utf8 -*-
#
# Copyright (C) 2015  Evol Online
# Author: Andrei Karas (4144)

import os
import re
import sys

filt = re.compile(".+[.](c|h)", re.IGNORECASE)

class Reporter:
    def reportManaplus(self, hercules, manaplus):
        with open(self.packetDir + "/serverpackets.txt", "w") as w:
            for packet in hercules.outPacketsSorted:
                data = packet
                while data[0] == "0":
                    data = data[1:]
                if packet in manaplus.inPackets:
                    clientName = manaplus.inPackets[packet][0]
    #                if clientName not in manaplus.manaplusUsedPacketsSet and clientName.find("_OUTDATED") <= 0:
    #                    w.write("UNIMPLIMENTED ")
                    w.write(data + " client name: " + clientName)
                else:
                    w.write(data)
                w.write("\n")

        funcDict = dict()
        for packet in hercules.inPacketsSorted:
            data = packet
            while data[0] == "0":
                data = data[1:]
            if packet in hercules.inPackets:
                funcDict[hercules.inPackets[packet][1]] = packet

        with open(self.packetDir + "/uselesspackets.txt", "w") as w:
            for packet in manaplus.outPackets:
                if packet not in hercules.inPackets:
                    w.write("Useless packet {0}.\n".format(packet))

    #    manaplusFunc = set()
        rev = []

        with open(self.packetDir + "/clientpackets.txt", "w") as w:
            for packet in manaplus.outPackets:
                clientName = manaplus.outPackets[packet][0]
                if clientName not in manaplus.manaplusUsedPacketsSet and clientName.find("_OUTDATED") <= 0:
                    w.write("PSESENT BUT UNIMPLIMENTED {0}\n".format(clientName))

    #        for packet in manaplus.outPackets:
    #            if packet in hercules.inPackets:
    #                manaplusFunc.add(hercules.inPackets[packet][1])
    #        for func in funcDict:
    #            if func not in manaplusFunc:
    #                packet = funcDict[func]
    #                rev.append("{0:4} {1:>4} {2}".format(packet, hercules.inPackets[packet][0], hercules.inPackets[packet][1]))

            clientSet = set()
            for packet in hercules.inPackets:
                clientSet.add(hercules.inPackets[packet][1])
            for packet in manaplus.outPackets:
                if packet in hercules.inPackets and hercules.inPackets[packet][1] in clientSet:
                    if manaplus.outPackets[packet][2] == hercules.inPackets[packet][1]:
                        clientSet.remove(hercules.inPackets[packet][1])
                    else:
                        if manaplus.outPackets[packet][2] in clientSet:
                            clientSet.remove(manaplus.outPackets[packet][2])

            allPackets = set()
            for packet in hercules.inPackets:
                allPackets.add(packet)
            for packet in manaplus.outPackets:
                allPackets.add(packet)

            for packet in clientSet:
                rev.append("{0:4} {1:33} {2}".format("?", "UNIMPLIMENTED", packet))

            for packet in allPackets:
                if packet not in manaplus.outPackets:
                    continue
                data = "{0:4} {1:33} ".format(packet, manaplus.outPackets[packet][0])
                if packet in hercules.inPackets:
                    if manaplus.outPackets[packet][2] == hercules.inPackets[packet][1]:
                        data = data + hercules.inPackets[packet][1]
                        rev.append(data)
                else:
                    data = data + "?"
                    rev.append(data)

            rev.sort()

            for data in rev:
                w.write(data)
                w.write("\n")

        rev = []
        with open(self.packetDir + "/clientwrongpacketsizes.txt", "w") as w:
            for name in manaplus.outMsgNameToId:
                packet = manaplus.outMsgNameToId[name]
    #        for packet in manaplus.outPackets:
                if packet in hercules.inPackets and manaplus.outPackets[packet][1] != hercules.inPackets[packet][0]:
                    packet1 = manaplus.outPackets[packet]
                    packet2 = hercules.inPackets[packet]
                    if packet2[0] != 0:
                        rev.append("{0:4} {1:33} {2:35} {3:4} vs {4:4}".format(
                            packet,
                            packet1[0],
                            packet2[1],
                            packet1[1],
                            packet2[0]))
            rev.sort()

            for data in rev:
                w.write(data)
                w.write("\n")

        rev = []
        with open(self.packetDir + "/clientbadpackets.txt", "w") as w:
            for name in manaplus.outMsgNameToId:
                packet = manaplus.outMsgNameToId[name]
    #        for packet in manaplus.outPackets:
                if packet in hercules.inPackets:
                    packet1 = manaplus.outPackets[packet]
                    packet2 = hercules.inPackets[packet]
                    if packet1[2] in hercules.functionToId:
                        data = hercules.functionToId[packet1[2]]
                        data2 = hercules.functionToId[packet2[1]]
                        if data2 == packet:
                            if packet1[2] != packet2[1]:
                                rev.append("{0:4} {1:33} client: {2:35} server: {3:35} Change id to {4}".format(packet,
                                    packet1[0],
                                    packet1[2],
                                    packet2[1],
                                    data))
                        else:
                            # here hidden or previous packet
                            pass
                    else:
                        data = "unknown"
                        if packet1[2] != packet2[1]:
                            rev.append("{0:4} {1:33} client: {2:35} server: {3:35} Change id to {4}".format(packet,
                                packet1[0],
                                packet1[2],
                                packet2[1],
                                data))

            rev.sort()

            for data in rev:
                w.write(data)
                w.write("\n")

        rev = []
        with open(self.packetDir + "/clientpreferredpackets.txt", "w") as w:
            with open(self.packetDir + "/clientbadpackets.txt", "a+") as w2:
                for name in manaplus.outMsgNameToId:
                    packet = manaplus.outMsgNameToId[name]
                    if packet in hercules.inPackets:
                        packet1 = manaplus.outPackets[packet]
                        packet2 = hercules.inPackets[packet]
                        if packet1[0] != name:
                            # skip if same id used for other packet already
                            #print("{0}, {1}, {2}, {3}".format(name, packet, packet1, packet2))
                            w2.write("{0:4} {1:33} hidden by {2}\n".format(packet,
                                name,
                                packet1[2]))
                            continue
                        if packet1[2] in hercules.functionToId:
                            data = hercules.functionToId[packet1[2]]
                            if packet1[2] == packet2[1] and hercules.functionToId[packet1[2]] != packet:
                                rev.append("{0:4} -> {1:4}  {2:33} {3}".format(packet,
                                    data,
                                    packet1[0],
                                    packet1[2]))
                        else:
                            data = "unknown"
                            if packet1[2] == packet2[1] and hercules.functionToId[packet1[2]] != packet:
                                rev.append("{0:4} -> {1:4}  {2:33} {3}".format(packet,
                                    data,
                                    packet1[0],
                                    packet1[2]))
                rev.sort()
                for data in rev:
                    w.write(data)
                    w.write("\n")


    def reportHercules(self, hercules):
        with open(self.packetDir + "/herculesissues.txt", "w") as w:
                for name in hercules.functionToId:
                    packet = hercules.functionToId[name]
                    if name != hercules.inPackets[packet][1]:
                        found = False
                        oldId = ""
                        for packet in hercules.inPackets:
                            if name == hercules.inPackets[packet][1]:
                                found = True
                                if oldId == "":
                                    oldId = str(packet)
                                else:
                                    oldId = oldId + "," + str(packet)

                        if found is False:
                            w.write("Server code error: function {0} hidden in server code\n".format(
                                name))
                        else:
                            w.write("Server code warning: function {0} hidden in server code but can be used older packets definition {1}\n".format(
                                name,
                                oldId))


class Hercules:
    namedPackets = dict()
    packetsSet = set()
    outPacketsSorted = []
    inPacketsSorted = []
    inPackets = dict()
    functionToId = dict()
    loginPacketNameToId = dict()

    namedPacketre = re.compile(
        "((\t|[ ])*)(?P<name>[\w0-9_]+)([ ]*)=" +
        "([ ]*)0x(?P<value>[0-9a-fA-F]+)")
    ourPacketre = re.compile(
        "(WFIFOW|WBUFW)([ ]*)[(]([ ]*)([\w>_-]+),([ ]*)" +
        "(?P<offset>0)([ ]*)[)]([ ]*)=([ ]*)0x(?P<packet>[0-9a-fA-F]+)([ ]*)[;]")
    ourPacketre2 = re.compile("PacketType([ ]*)=([ ]*)(?P<name>[\w_]+);")
    ourPacketre3 = re.compile(
        "(WFIFOW|WBUFW)([ ]*)[(]([ ]*)([\w>_-]+),([ ]*)" +
        "(?P<offset>0)([ ]*)[)]([ ]*)=([ ]*)(?P<packet>[0-9\w]+)([ ]*)[;]")
    ourPacketre4 = re.compile("int cmd([ ]*)=([ ]*)0x(?P<packet>[0-9a-fA-F]+);")
    outPacketLoginre = re.compile(
        "([ ]*)PACKET_ID_(?P<name>[A-Z0-9_]+)([ ]*)=" +
        "([ ]*)0x(?P<packet>[0-9a-fA-F]+),")
    serverpacketLoginOutre = re.compile("packet_id([ ]*)=([ ]*)(?P<name>[\w_]+);")
    clientpacketre = re.compile(
        "(\t*)packet[(]0x(?P<packet>[0-9a-fA-F]+),(?P<len>[\w-]+)" +
        ",(?P<function>[0-9a-zA-Z_>-]+)(,|[)])")
    lclifPacketre = re.compile(
        "([ ]*)[{][ ]PACKET_ID_CA_(?P<name>[A-Z0-9_]+),([^,]+)," +
        "([ ]*)[&](?P<function>[0-9a-zA-Z_>-]+)([ ]*)[}],")

    def collectNamedPackets(self, fileName):
        with open(fileName, "r") as f:
            for line in f:
                m = self.namedPacketre.search(line)
                if m is not None:
                    if m.group("name") not in self.namedPackets:
                        self.namedPackets[m.group("name")] = []
                    data = m.group("value").lower()
                    while len(data) < 4:
                        data = "0" + data
                    self.namedPackets[m.group("name")].append(data)


    def addServerPacket(self, data):
        if data in self.namedPackets:
            for val in self.namedPackets[data]:
                self.packetsSet.add(val)
        else:
            self.packetsSet.add(data.lower())


    def collectOutPackets(self, parentDir):
        files = os.listdir(parentDir)
        for file1 in files:
            if file1[0] == ".":
                continue
            file2 = os.path.abspath(parentDir + os.path.sep + file1)
            if not os.path.isfile(file2):
                if file2.find("/src/evol") <= 0:
                    self.collectOutPackets(file2)
            elif filt.search(file1):
                with open(file2, "r") as f:
                    for line in f:
                        m = self.ourPacketre4.findall(line)
                        if len(m) > 0:
                            for str in m:
                                data = str[2]
                                while len(data) < 4:
                                    data = "0" + data
                                self.addServerPacket(data)
                        m = self.outPacketLoginre.findall(line)
                        if len(m) > 0:
                            for str in m:
                                data = str[4]
                                while len(data) < 4:
                                    data = "0" + data
                                self.loginPacketNameToId["PACKET_ID_" + str[1]] = data
                        m = self.ourPacketre.findall(line)
                        if len(m) == 0:
                            m = self.ourPacketre3.findall(line)
                        if len(m) > 0:
                            for str in m:
                                if str[9] == "0":
                                    continue
                                data = str[9]
                                if data == "cmd":
                                    continue
                                while len(data) < 4:
                                    data = "0" + data
                                self.addServerPacket(data)

                        m = self.ourPacketre2.findall(line)
                        if len(m) > 0:
                            for str in m:
                                if str[2] == "0":
                                    continue
                                data = str[2]
                                if len(data) > 2 and data[0:2] == "0x":
                                    data = data[2:]
                                while len(data) < 4:
                                    data = "0" + data
                                self.addServerPacket(data)
                        m = self.serverpacketLoginOutre.findall(line)
                        if len(m) > 0:
                            for str in m:
                                if str[2] in self.loginPacketNameToId:
                                    data = str[2]
                                    data = self.loginPacketNameToId[data]
                                    self.addServerPacket(data)


    def sortOutPackets(self):
        for packet in self.packetsSet:
            self.outPacketsSorted.append(packet)
        self.outPacketsSorted.sort()


    def collectInPackets(self, packetsH, lclifPackets):
        with open(packetsH, "r") as f:
            for line in f:
                m = self.clientpacketre.search(line)
                if m is not None:
                    data = m.group("packet").lower()
                    while len(data) < 4:
                        data = "0" + data
                    self.inPackets[data] = \
                        (int(m.group("len")), m.group("function"))
                    self.functionToId[m.group("function")] = data
        with open(lclifPackets, "r") as f:
            for line in f:
                m = self.lclifPacketre.search(line)
                if m is not None:
                    name = "PACKET_ID_CA_" + m.group("name")
                    if name not in self.loginPacketNameToId:
                        print "Wrong login packet name: " + name
                        continue
                    data = self.loginPacketNameToId[name]
                    self.inPackets[data] = (0, m.group("function"))
                    self.functionToId[m.group("function")] = data


    def sortInPackets(self):
        for packet in self.inPackets:
            self.inPacketsSorted.append(packet)
        self.inPacketsSorted.sort()




class ManaPlus:
    inPackets = dict()
    outPackets = dict()
    sizes = dict()
    manaplusUsedPacketsSet = set()
    outMsgNameToId = dict()
    protocolinre = re.compile(
        "packet[(](?P<name>[A-Z0-9_]+),([ ]*)0x(?P<packet>[0-9a-fA-F]+)" +
        ",([ ]*)(?P<len>[\w-]+),([ ]*)")
    protocolinverre = re.compile("^// (?P<ver>[0-9]+)$")
    protocoloutre = re.compile(
        "packet[(](?P<name>CMSG_[A-Z0-9_]+),([ ]*)0x(?P<packet>[0-9a-fA-F]+)," +
        "([ ]*)(?P<len>[\w-]+),([ ]*)(?P<function>[0-9a-zA-Z_>-]+)[)];")
    packetOutNametre = re.compile("(?P<name>(S|C)MSG_[A-Z0-9_]+)")

    def collectInPackets(self, fileName, packetVersion):
        version = 0
        with open(fileName, "r") as f:
            for line in f:
                m = self.protocolinverre.search(line)
                if m is not None:
                    version = int(m.group("ver"))
                    continue
                # skip bigger versions than requested
                if version > packetVersion:
                    continue
                m = self.protocolinre.search(line)
                if m is not None:
                    packet = int(m.group("packet"), 16)
                    if packet > 0xb00 or packet == 0:
                        continue
                    self.inPackets[m.group("packet").lower()] = \
                        (m.group("name"), int(m.group("len")), "nullptr")
                    self.sizes[m.group("packet").lower()] = m.group("len")


    def collectOutPackets(self, fileName, packetVersion):
        version = 0
        with open(fileName, "r") as f:
            for line in f:
                m = self.protocolinverre.search(line)
                if m is not None:
                    version = int(m.group("ver"))
                    continue
                # skip bigger versions than requested
                if version > packetVersion:
                    continue
                m = self.protocoloutre.search(line)
                if m is not None:
                    packet = int(m.group("packet"), 16)
                    if packet > 0xb00 or packet == 0:
                        continue
                    self.inPackets[m.group("packet").lower()] = \
                        (m.group("name"), int(m.group("len")), m.group("function"))
                    self.outPackets[m.group("packet").lower()] = \
                        (m.group("name"), int(m.group("len")), m.group("function"))
                    self.outMsgNameToId[m.group("name").strip()] = \
                        m.group("packet").lower()
                    # print "{0} = {1}".format(
                    #    m.group("name").strip(), m.group("packet").lower())


    def processCppFiles(self, parentDir):
        files = os.listdir(parentDir)
        for file1 in files:
            if file1[0] == ".":
                continue
            file2 = os.path.abspath(parentDir + os.path.sep + file1)
            if not os.path.isfile(file2):
                self.processCppFiles(file2)
            elif file1[-4:] == ".cpp":
                self.collectManaPlusUsedPackets(file2)


    def collectManaPlusUsedPackets(self, fileName):
        with open(fileName, "r") as f:
            for line in f:
                m = self.packetOutNametre.search(line)
                if m is not None:
                    self.manaplusUsedPacketsSet.add(m.group("name"))



def showHelp():
    print("Usage: packets.py version")
    exit(1)


if len(sys.argv) != 2:
    showHelp()

packetVersion = sys.argv[1]
packetDir = packetVersion
while len(packetDir) < 8:
    packetDir = "0" + packetDir

hercules = Hercules()
manaplus = ManaPlus()
reporter = Reporter()
reporter.packetDir = packetDir;

srcPath = packetDir + "/src"
namedPacketsPath = packetDir + "/src/packets_struct.h"
manaplusPath = "../../../manaplus/src/"
protocolPath = manaplusPath + "net/eathena/packets"
serverInPacketsHPath = packetDir + "/src/packets.h"
serverLoginInPackets = packetDir + "/src/lclif.c"
packetsPath = manaplusPath + "net/eathena/packetsin.inc"
eathenaPath = manaplusPath + "net/eathena/"

hercules.collectNamedPackets(namedPacketsPath)
hercules.collectOutPackets(srcPath)
hercules.collectInPackets(serverInPacketsHPath, serverLoginInPackets)
manaplus.collectInPackets(protocolPath + "in.inc", int(packetVersion))
manaplus.collectOutPackets(protocolPath + "out.inc", int(packetVersion))
manaplus.processCppFiles(eathenaPath)
hercules.sortInPackets()
hercules.sortOutPackets()
reporter.reportManaplus(hercules, manaplus)
reporter.reportHercules(hercules)
