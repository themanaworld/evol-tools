#! /usr/bin/env python2
# -*- coding: utf8 -*-
#
# Copyright (C) 2015-2016  Evol Online
# Author: Andrei Karas (4144)

import sys

from src.hercules import Hercules
from src.manaplus import ManaPlus
from src.reporter import Reporter


def showHelp():
    print("Usage: packets.py hercules dir version")
    exit(1)


if len(sys.argv) != 4:
    showHelp()

codeDir = sys.argv[1]
packetDir = sys.argv[2]
packetVersion = sys.argv[3]

hercules = Hercules()
manaplus = ManaPlus()
reporter = Reporter()
reporter.packetDir = packetDir;

hercules.prepareTempFiles(codeDir, packetDir, packetVersion)
hercules.processPackets(packetDir, packetVersion)
manaplus.processPackets(packetVersion);
reporter.reportManaplus(hercules, manaplus)
reporter.reportHercules(hercules)
