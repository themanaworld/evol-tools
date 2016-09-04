#! /usr/bin/env python2
# -*- coding: utf8 -*-
#
# Copyright (C) 2015-2016  Evol Online
# Author: Andrei Karas (4144)

import os
import re

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
