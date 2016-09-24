#! /usr/bin/env python2
# -*- coding: utf8 -*-
#
# Copyright (C) 2015-2016  Evol Online
# Author: Andrei Karas (4144)

import sys

from src.brathena import Brathena
from src.hercules import Hercules
from src.idathena import Idathena
from src.manaplus import ManaPlus
from src.ragemu import Ragemu
from src.rathena import Rathena
from src.reporter import Reporter
from src.server import Server
from src.threeceam import Threeceam


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
threeceam = Threeceam()
threeceam.dirName = "3ceam"
threeceam.reportName = "3ceam"
idathena = Idathena()
idathena.dirName = "idathena"
idathena.reportName = "idathena"
server2013 = Server()
server2014 = Server()

manaplus = ManaPlus()
reporter = Reporter()
reporter.packetDir = packetDir;

hercules.prepareTempFiles(codeDir, packetDir, packetVersion)
hercules.processPackets(packetDir, packetVersion)
rathena.prepareTempFiles("rathena", packetDir, packetVersion)
rathena.processPackets("rathena", packetDir, packetVersion)
brathena.prepareTempFiles("brathena", packetDir, packetVersion)
brathena.processPackets(packetDir, packetVersion)
ragemu.prepareTempFiles("ragemu", packetDir, packetVersion)
ragemu.processPackets(packetDir, packetVersion)
threeceam.prepareTempFiles("3ceam", packetDir, packetVersion)
threeceam.processPackets("3ceam", packetDir, packetVersion)
idathena.prepareTempFiles("idathena", packetDir, packetVersion)
idathena.processPackets("idathena", packetDir, packetVersion)
server2013.processPackets("server2013")
server2014.processPackets("server2014")

manaplus.processPackets(packetVersion);
reporter.reportManaplus(hercules, manaplus)
reporter.reportHercules(hercules)
reporter.reportHerculesFork(hercules, rathena, "rAthena")
reporter.reportHerculesFork(hercules, brathena, "brAthena")
reporter.reportHerculesFork(hercules, ragemu, "RagEmu")
reporter.reportHerculesFork(hercules, threeceam, "3CeaM")
reporter.reportHerculesFork(hercules, idathena, "idAthena")
reporter.reportServer(hercules, server2013)
reporter.reportServer(hercules, server2014)
