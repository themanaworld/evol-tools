#! /usr/bin/env python2
# -*- coding: utf8 -*-
#
# Copyright (C) 2015-2016  Evol Online
# Author: Andrei Karas (4144)

import re

class Server:
    packetre = re.compile(
        "([ ]*)HEADER_(?P<type>[A-Z][A-Z])_(?P<name>[A-Z0-9_]+)([ ]*)=" +
        "([ ]*)0x(?P<packet>[0-9a-fA-F]+),")

    def __init__(self):
        self.outPackets = set()
        self.inPackets = set()
        self.outPacketsSorted = []
        self.inPacketsSorted = []
        self.idToName = dict()

    def collectPackets(self):
        with open("../links/" + self.dirName + "/packets.txt", "r") as f:
            for line in f:
                m = self.packetre.search(line)
                if m is not None:
                    data = m.group("packet").lower()
                    packetType = m.group("type")
                    partName = m.group("name")
                    if len(data) > 2 and data[:2] == "0x":
                        data = data[2:]
                    while len(data) < 4:
                        data = "0" + data
                    if packetType in ("CA", "CH", "CZ"):
                        self.inPackets.add(data)
                    if packetType in ("AC", "HC", "ZC"):
                        self.outPackets.add(data)
                    self.idToName[data] = "HEADER_{0}_{1}".format(packetType, partName)


    def sortOutPackets(self):
        for packet in self.outPackets:
            self.outPacketsSorted.append(packet)
        self.outPacketsSorted.sort()


    def sortInPackets(self):
        for packet in self.inPackets:
            self.inPacketsSorted.append(packet)
        self.inPacketsSorted.sort()


    def processPackets(self, dirName):
        self.dirName = dirName
        self.collectPackets()
        self.sortInPackets()
        self.sortOutPackets()
