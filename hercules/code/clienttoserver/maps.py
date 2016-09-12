# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import array
import csv
import os
import zlib
import struct
import StringIO
from xml.dom import minidom

from code.fileutils import makeDir, writeInt16, writeInt32, writeMapName, writeData

def getTmxFiles(srcDir):
    names = []
    for name in os.listdir(srcDir):
        names.append(name)
    names.sort()
    for name in names:
        fileName = srcDir + name
        if os.path.isfile(fileName) == False:
            continue
        if name.endswith(".tmx") == False:
            continue
        yield fileName

def findFirstGid(tilesets, tile):
    found = -1
    for t in tilesets:
        if t <= tile:
            found = t
            break
    return found

# client
# 0 - walkable ground
# 1 - non walkable wall
# 2 - air allowed            shootable too
# 3 - water allowed          water, shootable too
# 4 - sit, walkable ground
# 5 - player walk not allowed
# 6 - monster walk not allowed

# server
# 0 - walkable ground
# 1 - non walkable wall
# 2 - air allowed            shootable too
# 3 - water allowed          water, shootable too
# 4 - sit, walkable ground
# 5 - none
# 6 - monster walk not allowed
def convertTileType(tile):
    if tile == 5:
        tile = 0;
    if tile > 128 or tile < 0:
        tile = 1
    return tile

def recreateMapCache():
    destDir = "../../server-data/db/re/"
    srcDir = "../../client-data/maps/"
    makeDir(destDir)
    sz = 0L
    mapsCount = 0
    collisionLayerName = "collision"
    with open(destDir + "map_cache.dat", "wb") as w:
        writeInt32(w, 0)  # file size
        writeInt16(w, 0)  # maps count
        writeInt16(w, 0)  # padding
        sz = sz + 8
        for fileName in getTmxFiles(srcDir):
            dom = minidom.parse(fileName)
            root = dom.documentElement
            tilesets = []
            for tileset in root.getElementsByTagName("tileset"):
                tilesets.append(int(tileset.attributes["firstgid"].value))

            tilesets.sort(reverse = True)

            found = False
            for layer in root.getElementsByTagName("layer"):
                if layer.attributes["name"].value.lower() == collisionLayerName:
                    data = layer.getElementsByTagName("data")
                    if data is None or len(data) != 1:
                        continue
                    data = data[0]
                    width = int(layer.attributes["width"].value)
                    height = int(layer.attributes["height"].value)
                    encoding = data.attributes["encoding"].value
                    try:
                        compression = data.attributes["compression"].value
                    except:
                        compression = ""

                    tiles = []
                    if encoding == "base64":
                        binData = data.childNodes[0].data.strip()
                        binData = binData.decode('base64')
                        if compression == "gzip":
                            dc = zlib.decompressobj(16 + zlib.MAX_WBITS)
                        else:
                            dc = zlib.decompressobj()
                        layerData = dc.decompress(binData)
                        arr = array.array("I")
                        arr.fromstring(layerData)
                        for tile in arr:
                            if tile == 0:
                                tileType = 0
                            else:
                                firstgid = findFirstGid(tilesets, tile)
                                tileType = convertTileType(tile - firstgid);
                            tiles.append(tileType)
                    elif encoding == "csv":
                        binData = data.childNodes[0].data.strip()
                        f = StringIO.StringIO(binData)
                        arr = list(csv.reader(f, delimiter=',', quotechar='|'))
                        for row in arr:
                            for item in row:
                                if item != "":
                                    tile = int(item)
                                    if tile == 0:
                                        tileType = 0
                                    else:
                                        firstgid = findFirstGid(tilesets, tile)
                                        tileType = convertTileType(tile - firstgid);
                                    # tmx collision format
                                    # 0 - walkable ground
                                    # 1 - non walkable wall
                                    # 2 - air allowed            shootable too
                                    # 3 - water allowed          water, shootable too
                                    # 4 - sit, walkable ground
                                    # 5 - none

                                    # server collision format
                                    # 000 0 - walkable, shootable
                                    # 001 1 - wall
                                    # 010 2 - same with 0
                                    # 011 3 - walkable, shootable, water
                                    # 100 4 - same with 0
                                    # 101 5 - shootable
                                    # 110 6 - same with 0
                                    # 111 7 - none
                                    if tileType > 128 or tileType < 0:
                                        tileType = 1
                                    tiles.append(tileType)
                        f.close()
                    else:
                        print "map format not supported: " + fileName
                        continue

                    #comp = zlib.compressobj()
                    binData = struct.pack(str(len(tiles))+"B", *tiles)
                    binData = zlib.compress(binData)
                    idx = fileName.rfind("/") + 1
                    mapName = fileName[idx:-4]
                    writeMapName(w, mapName)
                    writeInt16(w, width)
                    writeInt16(w, height)
                    writeInt32(w, len(binData))
                    writeData(w, binData)
                    print fileName
                    mapsCount = mapsCount + 1
                    sz = sz + 12 + 8 + len(binData)
                    found = True
                    break
            if found == False:
                print "Error: missing collision layer in file: {0}".format(fileName)
        w.seek(0);
        writeInt32(w, sz)
        writeInt16(w, mapsCount)
