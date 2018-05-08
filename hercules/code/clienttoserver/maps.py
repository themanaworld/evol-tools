# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import array
import csv
import hashlib
import os
import zlib
import struct
import StringIO
from xml.dom import minidom

from code.fileutils import makeDir, writeInt16, writeInt32, writeData, removeDir

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
        yield (fileName, name)

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

# map file format
#
# int16 version;
# uint8 md5_checksum[16];
# int16 xs;
# int16 ys;
# int32 len;
# ...data...

def recreateMap(names):
    collisionLayerName = "collision"
    destDir = "../../server-data/maps/re/"
    tmxName = names[0]
    mCaheName = destDir + names[1][:-3] + "mcache"
    with open(mCaheName, "wb") as w:
        dom = minidom.parse(tmxName)
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
                    print "map format not supported: " + tmxName
                    continue

                #comp = zlib.compressobj()
                binData = struct.pack(str(len(tiles))+"B", *tiles)
                binData = zlib.compress(binData)
                writeInt16(w, 1)
                writeData(w, hashlib.md5(binData).digest())  # 16 bytes
                writeInt16(w, width)
                writeInt16(w, height)
                writeInt32(w, len(binData))
                writeData(w, binData)
                #print tmxName
                found = True
                break
        if found == False:
            print "Error: missing collision layer in file: {0}".format(tmxName)



def recreateMapCache():
    destDir = "../../server-data/maps/re/"
    srcDir = "../../client-data/maps/"
    removeDir(destDir)
    makeDir(destDir)
    for names in getTmxFiles(srcDir):
        recreateMap(names)
