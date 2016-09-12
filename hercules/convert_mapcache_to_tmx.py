#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import os

from code.fileutils import readInt32, readInt16
from code.servertoclient.maps import covertToTmx

def runFunction(path):
    with open(path, "rb") as f:
        size = readInt32(f)
        if os.path.getsize(path) != size:
            print "Map cache corrupted, wrong file size."
            exit(1)
        mapsCount = readInt16(f)
        print "Maps count: " + str(mapsCount)
        readInt16(f) # padding
        covertToTmx(f, mapsCount)


runFunction("serverdata/db/re/map_cache.dat")
