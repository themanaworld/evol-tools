#! /usr/bin/env python2
# -*- coding: utf8 -*-
#
# Copyright (C) 2015-2016  Evol Online
# Author: Andrei Karas (4144)

import sys

from src.brathena import Brathena
from src.hercules import Hercules
from src.manaplus import ManaPlus
from src.ragemu import Ragemu
from src.rathena import Rathena
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
hercules.dirName = "hercules"
hercules.reportName = "hercules"
rathena = Rathena()
rathena.dirName = "rathena"
rathena.reportName = "rathena"
brathena = Brathena()
brathena.dirName = "brathena"
brathena.reportName = "brathena"
ragemu = Ragemu()
ragemu.dirName = "ragemu"
ragemu.reportName = "ragemu"

manaplus = ManaPlus()
reporter = Reporter()
reporter.packetDir = packetDir;

hercules.prepareTempFiles(codeDir, packetDir, packetVersion)
hercules.processPackets(packetDir, packetVersion)
rathena.prepareTempFiles("rathena", packetDir, packetVersion)
rathena.processPackets(packetDir, packetVersion)
brathena.prepareTempFiles("brathena", packetDir, packetVersion)
brathena.processPackets(packetDir, packetVersion)
ragemu.prepareTempFiles("ragemu", packetDir, packetVersion)
ragemu.processPackets(packetDir, packetVersion)

manaplus.processPackets(packetVersion);
reporter.reportManaplus(hercules, manaplus)
reporter.reportHercules(hercules)
reporter.reportRathena(hercules, rathena)
reporter.reportHerculesFork(hercules, brathena, "brAthena")
reporter.reportHerculesFork(hercules, ragemu, "RagEmu")
