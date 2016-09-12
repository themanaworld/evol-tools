#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import sys

from code.server.evol.main import serverEvolMain
from code.server.tmw.main import serverTmwMain

def showHelp():
    print "Usage: ./convert_server.py evol"
    print "       ./convert_server.py tmwold"
    print "       ./convert_server.py tmwnew"
    exit(1)

if len(sys.argv) != 2:
    showHelp()
    exit(1)

serverType = sys.argv[1]
if serverType == "evol":
    serverEvolMain();
elif serverType == "tmwold":
    serverTmwMain(False);
elif serverType == "tmwnew":
    serverTmwMain(True);
else:
    print "Wrong parameter"