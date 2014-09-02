#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import array
import base64
import gzip
import os
import re
import datetime
import xml
import csv
import ogg.vorbis
import StringIO
import sys
import zlib
import struct
import shutil

def detectCommand():
    if sys.argv[0][-8:] == "/list.py":
        return "list"
    elif sys.argv[0][-11:] == "/extract.py":
        return "extract"
    elif sys.argv[0][-14:] == "/cachetotmx.py":
        return "cachetotmx"
    return "help"

def makeDir(path):
    if not os.path.exists(path):
        os.makedirs(path)

def readInt32(f):
    data = f.read(4)
    arr = array.array("I")
    arr.fromstring(data)
    return arr[0]

def readInt16(f):
    data = f.read(2)
    arr = array.array("H")
    arr.fromstring(data)
    return arr[0]

def readMapName(f):
    data = f.read(12)
    data = str(data)
    while data[-1] == '\x00':
        data = data[:-1]
    return data

def readData(f, sz):
    return f.read(sz)

def readFile(path):
    with open(path, "r") as f:
        return f.read()

def getTile(mapData, x, y, sx):
    data = mapData[y * sx + x]
    arr = array.array("B")
    arr.fromstring(data)
    return arr[0]

def getGroundTile(flag):
    return str(flag + 1)

def getCollisionTile(flag):
    if flag == 0:
        return "0"
    return "4"

def copyFile(src, dst, name):
    shutil.copyfile(src + name, dst + name)

def saveFile(fileName, data):
    with open(fileName, "w") as w:
        w.write(data)

def printHelp():
    print "Unknown options selected."
    print ""
    print "Use list.py for list maps in cache"
    print "Use extract.py to extract maps from cache"
    exit(0)

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
        for y in xrange(0, sy):
            for x in xrange(0, sx):
                tile = getTile(mapData, x, y, sx)
                if x + 1 == sy and y + 1 == sy:
                    ground = ground + getGroundTile(tile)
                    collision = collision + getCollisionTile(tile)
                else:
                    ground = ground + getGroundTile(tile) + ","
                    collision = collision + getCollisionTile(tile) + ","
            ground = ground + "\n"
            collision = collision + "\n"
        saveFile(mapsDir + name + ".tmx", tmx.format(sx, sy, ground, collision))

def readMapCache(path, cmd):
    if cmd == "help":
        printHelp()
    with open(path, "rb") as f:
        size = readInt32(f)
        if os.path.getsize(path) != size:
            print "Map cache corrupted, wrong file size."
            exit(1)
        mapsCount = readInt16(f)
        print "Maps count: " + str(mapsCount)
        readInt16(f) # padding
        if cmd == "list":
            listMapCache(f, mapsCount)
        elif cmd == "extract":
            extractMaps(f, mapsCount)
        elif cmd == "cachetotmx":
            covertToTmx(f, mapsCount)


readMapCache("serverdata/db/re/map_cache.dat", detectCommand())
