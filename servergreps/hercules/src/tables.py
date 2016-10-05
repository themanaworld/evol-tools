#! /usr/bin/env python2
# -*- coding: utf8 -*-
#
# Copyright (C) 2015-2016  Evol Online
# Author: Andrei Karas (4144)

import re
import os

filt = re.compile(".+[.](c|h)", re.IGNORECASE)

class Tables:
    inPacketsSorted = []
    inPackets = dict()
    knownLenPackets = dict()

    clientpacketre = re.compile(
        "^(?P<packet>[0-9a-fA-F]+) (?P<len>[\w-]+)")

    def collectInPackets(self, packetsH):
        with open(packetsH, "r") as f:
            for line in f:
                m = self.clientpacketre.search(line)
                if m is not None:
                    data = m.group("packet").lower()
                    while len(data) < 4:
                        data = "0" + data
                    self.inPackets[data] = \
                        (int(m.group("len")), "")
                    self.knownLenPackets[data] = int(m.group("len"))

    def sortInPackets(self):
        for packet in self.inPackets:
            self.inPacketsSorted.append(packet)
        self.inPacketsSorted.sort()


    def findVersion(self, srcPath, packetDir):
        name = packetDir[:4] + "_" + packetDir[4:6] + "_" + packetDir[6:8]
        files = os.listdir(srcPath)
        for file1 in files:
            if file1[0] == ".":
                continue
            file2 = os.path.abspath(srcPath + os.path.sep + file1)
            if os.path.isdir(file2) and file1.find(name) > 0:
                self.collectInPackets(file2 + os.path.sep + "recvpackets.txt")
                self.sortInPackets()
                return

    def processPackets(self, codeDir, packetDir, packetVersion):
#        namedPacketsPath = packetDir + "/src/" + self.dirName + "/packets_struct.h"
        srcPath = "../links/" + self.dirName
#        packetsDbPath = "../links/" + codeDir + "/db/packet_db.txt"
#        serverInPacketsHPath = packetDir + "/src/" + self.dirName + "/packets.h"
#        serverLoginInPackets = packetDir + "/src/" + self.dirName + "/lclif.c"
#        serverCharPackets = packetDir + "/src/" + self.dirName + "/char.c"
#        self.collectNamedPackets(namedPacketsPath)
#        self.collectOutPackets(srcPath)
        self.findVersion(srcPath, packetDir)
#        self.collectCharInPackets(serverCharPackets);
#        self.sortOutPackets()
