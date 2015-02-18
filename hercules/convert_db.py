#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2015  Evol Online
# Author: Andrei Karas (4144)

import sys

from code.server.evol.main import *
from code.server.tmw.main import *

def showHelp():
    print "Usage: ./convert_db.py evol"
    print "       ./convert_db.py tmw"
    exit(1)

if len(sys.argv) != 2:
    showHelp()

if sys.argv[1] == "evol":
    dbEvolMain()
elif sys.argv[1] == "tmw":
    dbTmwMain()
else:
    showHelp()
