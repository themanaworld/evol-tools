#! /usr/bin/env python2
# -*- coding: utf8 -*-
#
# Copyright (C) 2015-2016  Evol Online
# Author: Andrei Karas (4144)

import os
import re

from src.preproc import PreProc

filt = re.compile(".+[.](c|h)", re.IGNORECASE)

class Threeceam:
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
    ourPacketre5 = re.compile("int cmde([ ]*)=([ ]*)0x(?P<packet>[0-9a-fA-F]+);")
    ourPacketre6 = re.compile(" (packet|packet_num|PacketType|packet_type)([ ]*)=([ ]*)0x(?P<packet>[0-9a-fA-F]+);")
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
        if data == "cmde" or data == "packet" or data == "PacketType" or data == "packet_type" or data == "packet_num":
            return
        if data in self.namedPackets:
            for val in self.namedPackets[data]:
                if int(val, 16) > 4096:
                    return
                self.packetsSet.add(val)
        else:
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
                        m = self.ourPacketre4.findall(line)
                        if len(m) > 0:
                            for str in m:
                                data = str[2]
                                while len(data) < 4:
                                    data = "0" + data
                                self.addServerPacket(data)
                        m = self.ourPacketre5.findall(line)
                        if len(m) > 0:
                            for str in m:
                                data = str[2]
                                while len(data) < 4:
                                    data = "0" + data
                                self.addServerPacket(data)
                        m = self.ourPacketre6.findall(line)
                        if len(m) > 0:
                            for str in m:
                                data = str[3]
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


    def processPackets(self, packetDir, packetVersion):
#        namedPacketsPath = packetDir + "/src/" + self.dirName + "/packets_struct.h"
        srcPath = packetDir + "/src/" + self.dirName
#        serverInPacketsHPath = packetDir + "/src/" + self.dirName + "/packets.h"
#        serverLoginInPackets = packetDir + "/src/" + self.dirName + "/lclif.c"
#        self.collectNamedPackets(namedPacketsPath)
        self.collectOutPackets(srcPath)
#        self.collectInPackets(serverInPacketsHPath, serverLoginInPackets)
#        self.sortInPackets()
        self.sortOutPackets()


    def prepareTempFiles(self, codeDir, packetDir, packetVersion):
        proc = PreProc()
        proc.init(packetDir + "/src/" + self.dirName)
        proc.defines = "-DPACKETVER=" + packetVersion + " -D_SOCKET_H_ -DWFIFOW\\(fd,pos\\)=WFIFOW\\(fd,pos\\) -DWBUFW\\(p,pos\\)=WBUFW\\(p,pos\\)"
        proc.includes = "-I../links/" + codeDir + "/src -I../links/" + codeDir + "/3rdparty"
        proc.inDir = "../links/" + codeDir + "/src/"
        proc.outDir = packetDir + "/src/" + self.dirName + "/"
        proc.run("char", "char.c");
        proc.run("char_sql", "char.c");
        proc.run("login", "login.c");
        proc.run("map", "clif.c");