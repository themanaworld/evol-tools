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
    def reportManaplus(self, packetDir, hercules, manaplus):
        with open(packetDir + "/serverpackets.txt", "w") as w:
            for packet in hercules.serverpacketsSorted:
                data = packet
                while data[0] == "0":
                    data = data[1:]
                if packet in manaplus.clientPacketsManaPlus:
                    clientName = manaplus.clientPacketsManaPlus[packet][0]
    #                if clientName not in manaplus.manaplusUsedPacketsSet and clientName.find("_OUTDATED") <= 0:
    #                    w.write("UNIMPLIMENTED ")
                    w.write(data + " client name: " + clientName)
                else:
                    w.write(data)
                w.write("\n")

        funcDict = dict()
        for packet in hercules.clientpacketsSorted:
            data = packet
            while data[0] == "0":
                data = data[1:]
            if packet in hercules.clientPackets:
                funcDict[hercules.clientPackets[packet][1]] = packet

        with open(packetDir + "/uselesspackets.txt", "w") as w:
            for packet in manaplus.clientPacketsManaPlusClient:
                if packet not in hercules.clientPackets:
                    w.write("Useless packet {0}.\n".format(packet))

    #    manaplusFunc = set()
        rev = []

        with open(packetDir + "/clientpackets.txt", "w") as w:
            for packet in manaplus.clientPacketsManaPlusClient:
                clientName = manaplus.clientPacketsManaPlusClient[packet][0]
                if clientName not in manaplus.manaplusUsedPacketsSet and clientName.find("_OUTDATED") <= 0:
                    w.write("PSESENT BUT UNIMPLIMENTED {0}\n".format(clientName))

    #        for packet in manaplus.clientPacketsManaPlusClient:
    #            if packet in hercules.clientPackets:
    #                manaplusFunc.add(hercules.clientPackets[packet][1])
    #        for func in funcDict:
    #            if func not in manaplusFunc:
    #                packet = funcDict[func]
    #                rev.append("{0:4} {1:>4} {2}".format(packet, hercules.clientPackets[packet][0], hercules.clientPackets[packet][1]))

            clientSet = set()
            for packet in hercules.clientPackets:
                clientSet.add(hercules.clientPackets[packet][1])
            for packet in manaplus.clientPacketsManaPlusClient:
                if packet in hercules.clientPackets and hercules.clientPackets[packet][1] in clientSet:
                    if manaplus.clientPacketsManaPlusClient[packet][2] == hercules.clientPackets[packet][1]:
                        clientSet.remove(hercules.clientPackets[packet][1])
                    else:
                        if manaplus.clientPacketsManaPlusClient[packet][2] in clientSet:
                            clientSet.remove(manaplus.clientPacketsManaPlusClient[packet][2])

            allPackets = set()
            for packet in hercules.clientPackets:
                allPackets.add(packet)
            for packet in manaplus.clientPacketsManaPlusClient:
                allPackets.add(packet)

            for packet in clientSet:
                rev.append("{0:4} {1:33} {2}".format("?", "UNIMPLIMENTED", packet))

            for packet in allPackets:
                if packet not in manaplus.clientPacketsManaPlusClient:
                    continue
                data = "{0:4} {1:33} ".format(packet, manaplus.clientPacketsManaPlusClient[packet][0])
                if packet in hercules.clientPackets:
                    if manaplus.clientPacketsManaPlusClient[packet][2] == hercules.clientPackets[packet][1]:
                        data = data + hercules.clientPackets[packet][1]
                        rev.append(data)
                else:
                    data = data + "?"
                    rev.append(data)

            rev.sort()

            for data in rev:
                w.write(data)
                w.write("\n")

        rev = []
        with open(packetDir + "/clientwrongpacketsizes.txt", "w") as w:
            for name in manaplus.outMsgNameToId:
                packet = manaplus.outMsgNameToId[name]
    #        for packet in manaplus.clientPacketsManaPlusClient:
                if packet in hercules.clientPackets and manaplus.clientPacketsManaPlusClient[packet][1] != hercules.clientPackets[packet][0]:
                    packet1 = manaplus.clientPacketsManaPlusClient[packet]
                    packet2 = hercules.clientPackets[packet]
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
        with open(packetDir + "/clientbadpackets.txt", "w") as w:
            for name in manaplus.outMsgNameToId:
                packet = manaplus.outMsgNameToId[name]
    #        for packet in manaplus.clientPacketsManaPlusClient:
                if packet in hercules.clientPackets:
                    packet1 = manaplus.clientPacketsManaPlusClient[packet]
                    packet2 = hercules.clientPackets[packet]
                    if packet1[2] in hercules.serverFunctionToId:
                        data = hercules.serverFunctionToId[packet1[2]]
                        data2 = hercules.serverFunctionToId[packet2[1]]
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
        with open(packetDir + "/clientpreferredpackets.txt", "w") as w:
            with open(packetDir + "/clientbadpackets.txt", "a+") as w2:
                for name in manaplus.outMsgNameToId:
                    packet = manaplus.outMsgNameToId[name]
                    if packet in hercules.clientPackets:
                        packet1 = manaplus.clientPacketsManaPlusClient[packet]
                        packet2 = hercules.clientPackets[packet]
                        if packet1[0] != name:
                            # skip if same id used for other packet already
                            #print("{0}, {1}, {2}, {3}".format(name, packet, packet1, packet2))
                            w2.write("{0:4} {1:33} hidden by {2}\n".format(packet,
                                name,
                                packet1[2]))
                            continue
                        if packet1[2] in hercules.serverFunctionToId:
                            data = hercules.serverFunctionToId[packet1[2]]
                            if packet1[2] == packet2[1] and hercules.serverFunctionToId[packet1[2]] != packet:
                                rev.append("{0:4} -> {1:4}  {2:33} {3}".format(packet,
                                    data,
                                    packet1[0],
                                    packet1[2]))
                        else:
                            data = "unknown"
                            if packet1[2] == packet2[1] and hercules.serverFunctionToId[packet1[2]] != packet:
                                rev.append("{0:4} -> {1:4}  {2:33} {3}".format(packet,
                                    data,
                                    packet1[0],
                                    packet1[2]))
                rev.sort()
                for data in rev:
                    w.write(data)
                    w.write("\n")


    def reportHercules(self, packetDir, hercules):
        with open(packetDir + "/herculesissues.txt", "w") as w:
                for name in hercules.serverFunctionToId:
                    packet = hercules.serverFunctionToId[name]
                    if name != hercules.clientPackets[packet][1]:
                        found = False
                        oldId = ""
                        for packet in hercules.clientPackets:
                            if name == hercules.clientPackets[packet][1]:
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
    serverpacketsSorted = []
    clientpacketsSorted = []
    clientPackets = dict()
    serverFunctionToId = dict()
    loginPacketNameToId = dict()

    namedPacketre = re.compile(
        "((\t|[ ])*)(?P<name>[\w0-9_]+)([ ]*)=" +
        "([ ]*)0x(?P<value>[0-9a-fA-F]+)")
    serverpacketre = re.compile(
        "(WFIFOW|WBUFW)([ ]*)[(]([ ]*)([\w>_-]+),([ ]*)" +
        "(?P<offset>0)([ ]*)[)]([ ]*)=([ ]*)0x(?P<packet>[0-9a-fA-F]+)([ ]*)[;]")
    serverpacketre2 = re.compile("PacketType([ ]*)=([ ]*)(?P<name>[\w_]+);")
    serverpacketre3 = re.compile(
        "(WFIFOW|WBUFW)([ ]*)[(]([ ]*)([\w>_-]+),([ ]*)" +
        "(?P<offset>0)([ ]*)[)]([ ]*)=([ ]*)(?P<packet>[0-9\w]+)([ ]*)[;]")
    serverpacketre4 = re.compile("int cmd([ ]*)=([ ]*)0x(?P<packet>[0-9a-fA-F]+);")
    serverpacketLoginre = re.compile(
        "([ ]*)PACKET_ID_(?P<name>[A-Z0-9_]+)([ ]*)=" +
        "([ ]*)0x(?P<packet>[0-9a-fA-F]+),")
    serverpacketLoginOutre = re.compile("packet_id([ ]*)=([ ]*)(?P<name>[\w_]+);")
    clientpacketre = re.compile(
        "(\t*)packet[(]0x(?P<packet>[0-9a-fA-F]+),(?P<len>[\w-]+)" +
        ",(?P<function>[0-9a-zA-Z_>-]+)(,|[)])")
    lclifPacketre = re.compile(
        "([ ]*)[{][ ]PACKET_ID_CA_(?P<name>[A-Z0-9_]+),([^,]+)," +
        "([ ]*)[&](?P<function>[0-9a-zA-Z_>-]+)([ ]*)[}],")

    def collectServerNamedPackets(self, fileName):
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


    def collectServerPackets(self, parentDir):
        files = os.listdir(parentDir)
        for file1 in files:
            if file1[0] == ".":
                continue
            file2 = os.path.abspath(parentDir + os.path.sep + file1)
            if not os.path.isfile(file2):
                if file2.find("/src/evol") <= 0:
                    self.collectServerPackets(file2)
            elif filt.search(file1):
                with open(file2, "r") as f:
                    for line in f:
                        m = self.serverpacketre4.findall(line)
                        if len(m) > 0:
                            for str in m:
                                data = str[2]
                                while len(data) < 4:
                                    data = "0" + data
                                self.addServerPacket(data)
                        m = self.serverpacketLoginre.findall(line)
                        if len(m) > 0:
                            for str in m:
                                data = str[4]
                                while len(data) < 4:
                                    data = "0" + data
                                self.loginPacketNameToId["PACKET_ID_" + str[1]] = data
                        m = self.serverpacketre.findall(line)
                        if len(m) == 0:
                            m = self.serverpacketre3.findall(line)
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

                        m = self.serverpacketre2.findall(line)
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


    def sortServerPackets(self):
        for packet in self.packetsSet:
            self.serverpacketsSorted.append(packet)
        self.serverpacketsSorted.sort()


    def collectServerInPackets(self, packetsH, lclifPackets):
        with open(packetsH, "r") as f:
            for line in f:
                m = self.clientpacketre.search(line)
                if m is not None:
                    data = m.group("packet").lower()
                    while len(data) < 4:
                        data = "0" + data
                    self.clientPackets[data] = \
                        (int(m.group("len")), m.group("function"))
                    self.serverFunctionToId[m.group("function")] = data
        with open(lclifPackets, "r") as f:
            for line in f:
                m = self.lclifPacketre.search(line)
                if m is not None:
                    name = "PACKET_ID_CA_" + m.group("name")
                    if name not in self.loginPacketNameToId:
                        print "Wrong login packet name: " + name
                        continue
                    data = self.loginPacketNameToId[name]
                    self.clientPackets[data] = (0, m.group("function"))
                    self.serverFunctionToId[m.group("function")] = data


    def sortClientPackets(self):
        for packet in self.clientPackets:
            self.clientpacketsSorted.append(packet)
        self.clientpacketsSorted.sort()




class ManaPlus:
    clientPacketsManaPlus = dict()
    clientPacketsManaPlusClient = dict()
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
    packetNameClientre = re.compile("(?P<name>(S|C)MSG_[A-Z0-9_]+)")

    def collectManaPlusInPackets(self, fileName, packetVersion):
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
                    self.clientPacketsManaPlus[m.group("packet").lower()] = \
                        (m.group("name"), int(m.group("len")), "nullptr")
                    self.sizes[m.group("packet").lower()] = m.group("len")


    def collectManaPlusOutPackets(self, fileName, packetVersion):
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
                    self.clientPacketsManaPlus[m.group("packet").lower()] = \
                        (m.group("name"), int(m.group("len")), m.group("function"))
                    self.clientPacketsManaPlusClient[m.group("packet").lower()] = \
                        (m.group("name"), int(m.group("len")), m.group("function"))
                    self.outMsgNameToId[m.group("name").strip()] = \
                        m.group("packet").lower()
                    # print "{0} = {1}".format(
                    #    m.group("name").strip(), m.group("packet").lower())


    def processManaPlusCppFiles(self, parentDir):
        files = os.listdir(parentDir)
        for file1 in files:
            if file1[0] == ".":
                continue
            file2 = os.path.abspath(parentDir + os.path.sep + file1)
            if not os.path.isfile(file2):
                self.processManaPlusCppFiles(file2)
            elif file1[-4:] == ".cpp":
                self.collectManaPlusUsedPackets(file2)


    def collectManaPlusUsedPackets(self, fileName):
        with open(fileName, "r") as f:
            for line in f:
                m = self.packetNameClientre.search(line)
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

srcPath = packetDir + "/src"
namedPacketsPath = packetDir + "/src/packets_struct.h"
manaplusPath = "../../../manaplus/src/"
protocolPath = manaplusPath + "net/eathena/packets"
serverInPacketsHPath = packetDir + "/src/packets.h"
serverLoginInPackets = packetDir + "/src/lclif.c"
packetsPath = manaplusPath + "net/eathena/packetsin.inc"
eathenaPath = manaplusPath + "net/eathena/"

hercules.collectServerNamedPackets(namedPacketsPath)
hercules.collectServerPackets(srcPath)
hercules.collectServerInPackets(serverInPacketsHPath, serverLoginInPackets)
manaplus.collectManaPlusInPackets(protocolPath + "in.inc", int(packetVersion))
manaplus.collectManaPlusOutPackets(protocolPath + "out.inc", int(packetVersion))
manaplus.processManaPlusCppFiles(eathenaPath)
hercules.sortClientPackets()
hercules.sortServerPackets()
reporter.reportManaplus(packetDir, hercules, manaplus)
reporter.reportHercules(packetDir, hercules)
