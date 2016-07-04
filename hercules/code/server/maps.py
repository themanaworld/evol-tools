# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import zlib

from code.fileutils import *

def listMapCache(f, mapsCount):
    print "Known maps:"
    print "{0:12} {1:<4}x {2:<4} {3:<10}".format("Map name", "sx", "sy", "compressed size")
    for i in xrange(0, mapsCount):
        name = readMapName(f)
        sx = readInt16(f)
        sy = readInt16(f)
        sz = readInt32(f)
        print "{0:12} {1:<4}x {2:<4} {3:<10}".format(name, sx, sy, sz)
        f.seek(sz, 1)

def extractMaps(f, mapsCount):
    destDir = "maps/"
    makeDir(destDir)
    for i in xrange(0, mapsCount):
        name = readMapName(f)
        sx = readInt16(f)
        sy = readInt16(f)
        sz = readInt32(f)
        data = readData(f, sz)
        dc = zlib.decompressobj()
        data = dc.decompress(data)
        with open(destDir + name, "wb") as w:
            w.write(struct.pack("H", sx))
            w.write(struct.pack("H", sy))
            w.write(data)
            with open(destDir + name + ".txt", "wb") as w:
                arr = array.array("B")
                arr.fromstring(data)
                for x in xrange(0, sx):
                    for y in xrange(0, sy):
                        w.write("{0},{1}:{2}\n".format(x, y, arr[x + y * sx]))
