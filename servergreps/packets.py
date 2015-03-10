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
protocolre = re.compile("#define[ ](?P<name>[A-Z0-9_]+)([ ]*)0x(?P<packet>[0-9a-fA-F]+)")

packetsSet = set()
packets = []
clientPackets = dict()

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

def sortServerPackets():
    for packet in packetsSet:
        packets.append(packet)
    packets.sort()

def collectManaPlusPackets(fileName):
    with open(fileName, "r") as f:
        for line in f:
            m = protocolre.search(line)
            if m is not None:
                clientPackets[m.group("packet")] = m.group("name")

def printPackets():
    for packet in packets:
        data = packet
        while data[0] == "0":
            data = data[1:]
        if packet in clientPackets:
            print data + " client name: " + clientPackets[packet]
        else:
            print data

srcPath = "../../server-code/src/"
protocolPath = "../../manaplus/src/net/eathena/protocol.h"

collectServerPackets(srcPath)
collectManaPlusPackets(protocolPath)
sortServerPackets()
printPackets()
