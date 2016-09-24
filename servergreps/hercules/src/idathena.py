#! /usr/bin/env python2
# -*- coding: utf8 -*-
#
# Copyright (C) 2015-2016  Evol Online
# Author: Andrei Karas (4144)

import os
import re

from src.packetdb import PacketDb
from src.preproc import PreProc
from src.utils import Utils

filt = re.compile(".+[.](c|h)", re.IGNORECASE)

class Idathena:
    namedPackets = dict()
    packetsSet = set()
    outPacketsSorted = []
    inPacketsSorted = []
    inPackets = dict()
    functionToId = dict()
    loginPacketNameToId = dict()
    getLenPackets = set()
    knownLenPackets = dict()

    namedPacketre = re.compile(
        "((\t|[ ])*)(?P<name>[\w0-9_]+)([ ]*)=" +
        "([ ]*)0x(?P<value>[0-9a-fA-F]+)")
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
    packetLenre = re.compile(
        "packet_db[\\[]0[\\]][\\[]0x(?P<packet>[0-9a-fA-F]+)[\\]].len")

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
        if data == "000j":
            return
        if data == "cmde":
            return
        if data in self.namedPackets:
            for val in self.namedPackets[data]:
                if int(val, 16) > 4096:
                    return
                self.packetsSet.add(val)
        else:
            if len(data) > 2 and data[:2] == "0x":
                data = data[2:]
                while len(data) < 4:
                    data = "0" + data
            try:
                if int(data, 16) > 4096:
                    return
            except:
                pass
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
                        Utils.getOutPackets(line, self)
                        m = self.outPacketLoginre.findall(line)
                        if len(m) > 0:
                            for str in m:
                                data = str[4]
                                while len(data) < 4:
                                    data = "0" + data
                                self.loginPacketNameToId["PACKET_ID_" + str[1]] = data
                        m = self.serverpacketLoginOutre.findall(line)
                        if len(m) > 0:
                            for str in m:
                                if str[2] in self.loginPacketNameToId:
                                    data = str[2]
                                    data = self.loginPacketNameToId[data]
                                    self.addServerPacket(data)
                        m = self.packetLenre.findall(line)
                        if len(m) > 0:
                            for str in m:
                                data = str.lower()
                                if len(data) > 2 and data[0:2] == "0x":
                                    data = data[2:]
                                while len(data) < 4:
                                    data = "0" + data
                                self.getLenPackets.add(data)


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


    def collectCharInPackets(self, charFilePackets):
        for packets in Utils.enumCasePackets(charFilePackets, "int char_parse_char(int fd)"):
            self.inPackets[packets[1]] = (0, packets[0])
            self.functionToId[packets[0]] = packets[1]


    def sortInPackets(self):
        for packet in self.inPackets:
            self.inPacketsSorted.append(packet)
        self.inPacketsSorted.sort()


    def processPackets(self, codeDir, packetDir, packetVersion):
#        namedPacketsPath = packetDir + "/src/" + self.dirName + "/packets_struct.h"
        srcPath = packetDir + "/src/" + self.dirName
        packetsDbPath = "../links/" + codeDir + "/db/packet_db.txt"
#        serverInPacketsHPath = packetDir + "/src/" + self.dirName + "/packets.h"
#        serverLoginInPackets = packetDir + "/src/" + self.dirName + "/lclif.c"
#        serverCharPackets = packetDir + "/src/" + self.dirName + "/char.c"
#        self.collectNamedPackets(namedPacketsPath)
        self.collectOutPackets(srcPath)
        PacketDb.getInPackets(packetsDbPath, packetVersion, self)
#        self.collectCharInPackets(serverCharPackets);
        self.sortInPackets()
        self.sortOutPackets()


    def prepareTempFiles(self, codeDir, packetDir, packetVersion):
        proc = PreProc()
        proc.init(packetDir + "/src/" + self.dirName)
        proc.defines = "-DPACKETVER=" + packetVersion + " -D_SOCKET_H_ -DWFIFOW\\(fd,pos\\)=WFIFOW\\(fd,pos\\) -DWBUFW\\(p,pos\\)=WBUFW\\(p,pos\\)"
        proc.includes = "-I../links/" + codeDir + "/src -I../links/" + codeDir + "/3rdparty"
        proc.inDir = "../links/" + codeDir + "/src/"
        proc.outDir = packetDir + "/src/" + self.dirName + "/"
        proc.run("char", "char.c");
        proc.run("login", "login.c");
        proc.run("map", "clif.c");
