# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import zlib

from code.fileutils import *
from code.tileutils import *

def covertToTmx(f, mapsCount):
    destDir = "clientdata/"
    mapsDir = destDir + "maps/"
    tilesetsDir = destDir + "graphics/tilesets/"
    templatesDir = "templates/"
    makeDir(mapsDir)
    makeDir(tilesetsDir)
    copyFile(templatesDir, tilesetsDir, "collision.png")
    copyFile(templatesDir, tilesetsDir, "tileset.png")
    tmx = readFile("templates/template.tmx")
    for i in xrange(0, mapsCount):
        name = readMapName(f)
        print "converting map [{0:4}/{1:4}]: {2}".format(i, mapsCount + 1, name)
        sx = readInt16(f)
        sy = readInt16(f)
        sz = readInt32(f)
        mapData = readData(f, sz)
        dc = zlib.decompressobj()
        mapData = dc.decompress(mapData)
        ground = ""
        collision = ""
        fringe = ""
        for y in xrange(0, sy):
            for x in xrange(0, sx):
                tileData = getTileData(mapData, x, y, sx)
                tile = getTile(tileData)
                if x + 1 == sx and y + 1 == sy:
                    ground = ground + tile[0]
                    collision = collision + tile[1]
                    fringe = fringe + "0";
                else:
                    ground = ground + tile[0] + ","
                    collision = collision + tile[1] + ","
                    fringe = fringe + "0,";
            ground = ground + "\n"
            collision = collision + "\n"
            fringe = fringe + "\n"
        saveFile(mapsDir + name + ".tmx", tmx.format(sx, sy, ground, collision, fringe))
