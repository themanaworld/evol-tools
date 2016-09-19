#! /usr/bin/env python2
# -*- coding: utf8 -*-
#
# Copyright (C) 2015-2016  Evol Online
# Author: Andrei Karas (4144)

import re

class Utils:
    casere = re.compile("^case 0x(?P<packet>[0-9a-fA-F]+)[:]")
    charParseFunctionre = re.compile(
        "(?P<function>chr->[0-9a-zA-Z_>-]+)([(]|[ ][(])");
    ourPacketre = re.compile(
        "(WFIFOW|WBUFW)([ ]*)[(]([ ]*)([\w>_-]+),([ ]*)" +
        "(?P<offset>0)([ ]*)[)]([ ]*)=([ ]*)0x(?P<packet>[0-9a-fA-F]+)([ ]*)[;]")
    ourPacketre2 = re.compile("PacketType([ ]*)=([ ]*)(?P<name>[\w_]+);")
    ourPacketre3 = re.compile(
        "(WFIFOW|WBUFW)([ ]*)[(]([ ]*)([\w>_-]+),([ ]*)" +
        "(?P<offset>0)([ ]*)[)]([ ]*)=([ ]*)(?P<packet>[0-9\w]+)([ ]*)[;]")
    ourPacketre4 = re.compile(" cmd([ ]*)=([ ]*)0x(?P<packet>[0-9a-fA-F]+);")
    ourPacketre5 = re.compile(
        "(WFIFOW|WBUFW)([ ]*)[(]([ ]*)([\w>_-]+),([ ]*)" +
        "(count[*]p_len)([ ]*)[)]([ ]*)=([ ]*)(?P<packet>[0-9\w]+)([ ]*)[;]")
    ourPacketre6 = re.compile("int cmde([ ]*)=([ ]*)0x(?P<packet>[0-9a-fA-F]+);")
    ourPacketre7 = re.compile(" (packet|packet_num|PacketType|packet_type)([ ]*)=([ ]*)0x(?P<packet>[0-9a-fA-F]+);")

    @staticmethod
    def enumCasePackets(fileName, startCode):
        startCode = startCode + "\n"
        endCode = "}\n"
        breakCode = "break;"
        with open(fileName, "r") as f:
            for line in f:
                if line == startCode:
                    packets = []
                    for line in f:
                        line = line.strip()
                        m = Utils.casere.search(line)
                        if m is not None:
                            data = m.group("packet").lower()
                            while len(data) < 4:
                                data = "0" + data
                            if int(data, 16) < 4096:
                                packets.append(data)
                        if line == breakCode:
                            packets = []
                        if line == endCode:
                            break
                        if len(packets) > 0:
                            m = Utils.charParseFunctionre.search(line)
                            if m is not None:
                                func = m.group("function")
                                if len(packets) > 1:
                                    for packet in packets:
                                        fname = func + "_" + str(packet)
                                        yield (fname, packet)
                                else:
                                    yield (func, packets[0])
                    break


    @staticmethod
    def getOutPackets(line, server):
        packets = []
        m = Utils.ourPacketre4.findall(line)
        if len(m) > 0:
            for str in m:
                data = str[2]
                while len(data) < 4:
                    data = "0" + data
                server.addServerPacket(data)
        m = Utils.ourPacketre5.findall(line)
        if len(m) > 0:
            for str in m:
                data = str[9]
                while len(data) < 4:
                    data = "0" + data
                server.addServerPacket(data)
        m = Utils.ourPacketre.findall(line)
        if len(m) == 0:
            m = Utils.ourPacketre3.findall(line)
        if len(m) > 0:
            for str in m:
                if str[9] == "0":
                    continue
                data = str[9]
                if data == "cmd":
                    continue
                while len(data) < 4:
                    data = "0" + data
                server.addServerPacket(data)
        m = Utils.ourPacketre2.findall(line)
        if len(m) > 0:
            for str in m:
                if str[2] == "0":
                    continue
                data = str[2]
                if len(data) > 2 and data[0:2] == "0x":
                    data = data[2:]
                while len(data) < 4:
                    data = "0" + data
                server.addServerPacket(data)
        m = Utils.ourPacketre6.findall(line)
        if len(m) > 0:
            for str in m:
                data = str[2]
                while len(data) < 4:
                    data = "0" + data
                server.addServerPacket(data)
        m = Utils.ourPacketre7.findall(line)
        if len(m) > 0:
            for str in m:
                data = str[3]
                while len(data) < 4:
                    data = "0" + data
                server.addServerPacket(data)
