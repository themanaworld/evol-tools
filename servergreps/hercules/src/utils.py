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
