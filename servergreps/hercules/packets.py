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
reporter.packetDir = packetDir;

hercules.processPackets(packetDir, packetVersion)
manaplus.processPackets(packetVersion);
reporter.reportManaplus(hercules, manaplus)
reporter.reportHercules(hercules)
