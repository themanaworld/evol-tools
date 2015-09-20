# -*- coding: utf8 -*-
#
# Copyright (C) 2015  Evol Online
# Author: Andrei Karas (4144)

import os
from PIL import Image
from PIL import ImageDraw
from sets import Set

from code.fileutils import *
from code.stringutils import *

class ActClass:
    pass

class ActAnimationClass:
    pass

class ActSpriteClass:
    pass

class ActFrameClass:
    pass

class ActPivotClass:
    pass

class ActEventClass:
    pass

class SprClass:
    pass

class SprImageClass:
    pass

def readIndexedRLEImage(f, spr):
    spr.nimages = spr.indexedSpritesCount
    spr.images = dict()
    for imageN in range(0, spr.indexedSpritesCount):
        image = SprImageClass()
        spr.images[imageN] = image
        image.width = readInt16(f)
        image.height = readInt16(f)
        image.compressed = True
        data = array.array('B', (0 for _ in xrange(image.width * image.height)))
        image.data = data

        compressSize = readInt16(f)
        uncompressedSize = image.width * image.height
        #print "uncompressed size=" + str(uncompressedSize)
        #print "compressed size=" + str(compressSize)

        idx = 0
        readCnt = 0
        while readCnt < compressSize:
            c = readInt8(f)
            readCnt = readCnt + 1
            data[idx] = c;
            #print "{0:4}: {1}".format(idx, c)
            idx = idx + 1
            if c == 0:
                cnt = readInt8(f)
                readCnt = readCnt + 1
                if cnt == 0:
                    data[idx] = cnt
                    #print "{0:4}: {1}".format(idx, cnt)
                    idx = idx + 1
                else:
                    for j in range(1, cnt):
                        data[idx] = c
                        #print "{0:4} ({1} to {2}): {3}".format(idx, j, cnt - 1, c)
                        idx = idx + 1
        #print "read bytes: " + str(readCnt)

def readIndexedImage(f, spr):
    pass

def readRgbaImage(f, spr):
    for imageN in range(0, spr.rgbaSpritesCount):
        image = SprImageClass()
        spr.images[imageN + spr.indexedSpritesCount] = image
        image.width = readInt16(f)
        image.height = readInt16(f)
        data = array.array('I', (0 for _ in xrange(image.width * image.height)))
        image.compressed = False
        image.data = data
        for idx in range(0, image.width * image.height):
            data[idx] = readInt32(f)


def readPalette(f, spr):
    palette = array.array('I', (0 for _ in xrange(256)))
    spr.palette = palette
    for col in range(0, 256):
        palette[col] = readInt32(f)

def getSignedNumber(number, bitLength):
    mask = (2 ** bitLength) - 1
    if number & (1 << (bitLength - 1)):
        return number | ~mask
    else:
        return number & mask

def decodeSprite(spr):
    palette = spr.palette
    spr.maxwidth = 0
    spr.maxheight = 0
    alpha = False
    for imageN in range(0, spr.indexedSpritesCount):
        image = spr.images[imageN]
        indexed = image.data
        data = array.array('I', (0 for _ in xrange(image.width * image.height)))
        for idx in range(0, image.width * image.height):
            col = indexed[idx]
            if col == 0:
                data[idx] = 0
            else:
                if palette[col] > 0x00ffffff:
                    data[idx] = palette[col]
                    alpha = True
                else:
                    data[idx] = palette[col] + 0xff000000
        image.data = data
        if image.width > spr.maxwidth:
            spr.maxwidth = image.width
        if image.height > spr.maxheight:
            spr.maxheight = image.height

        # for debug
#        png = Image.new('RGBA', (image.width, image.height))
#        png.putdata(image.data)
#        png.save("test{0}.png".format(imageN))

    if alpha:
        print "detected alpha"

    for imageN in range(0, spr.rgbaSpritesCount):
        image = spr.images[imageN + spr.indexedSpritesCount]
        if image.width > spr.maxwidth:
            spr.maxwidth = image.width
        if image.height > spr.maxheight:
            spr.maxheight = image.height



def saveSpriteImage(act, spr, spriteDir, spriteName):
#    for imageN in range(0, spr.rgbaSpritesCount):
#        image = spr.images[imageN + spr.indexedSpritesCount]
#        print "{0} x {1}".format(image.width, image.height)
#        png = Image.new('RGBA', (image.width, image.height))
#        png.putdata(image.data)
#        png.save("test{0}.png".format(imageN + spr.indexedSpritesCount))

#    numTiles = spr.indexedSpritesCount + spr.rgbaSpritesCount

    counted = 0
    for animN in range(0, act.nanimations):
        anim = act.animations[animN]
        for spriteN in range(0, anim.nsprites):
            sprite = anim.sprites[spriteN]
            key = []
#            for frameN in range(0, sprite.nframes):
#                frame = sprite.frames[frameN]
#                idf = frame.frameIndex
#                if frame.mirror > 0:
#                    idf = - idf
#                key.append(idf)
            counted = counted + 1

    numTiles = counted
    #print "max: {0}x{1}".format(spr.maxwidth, spr.maxheight)

    # in row
    rowTiles = int(2048 / spr.maxwidth)
    colTiles = int(numTiles / rowTiles)
    if colTiles * rowTiles < numTiles:
        colTiles = colTiles + 1
    tilesetWidth = 2048
    tilesetHeight = colTiles * spr.maxheight
#    print "num {0} row {1}, col {2}".format(numTiles, rowTiles, colTiles)
#    print "size {0}x{1}".format(2048, colTiles * spr.maxheight)

#    tileset = array.array('I', (0 for _ in xrange(tilesetWidth * tilesetHeight)))
    tileset = Image.new('RGBA', (tilesetWidth, tilesetHeight))
#    png.putdata(tileset)
    #draw = ImageDraw.Draw(png)

    x = 0
    y = 0

    frameToIdx = dict()

    tile = 0
    for animN in range(0, act.nanimations):
        anim = act.animations[animN]
        for spriteN in range(0, anim.nsprites):
            sprite = anim.sprites[spriteN]
            frameToIdx[str(animN) + "_" + str(spriteN)] = tile
            for frameN in range(0, sprite.nframes):
                frame = sprite.frames[frameN]
                frm = frame.frameIndex
                if frame.mirror > 0:
                    frm = - frm

                if frm in frameToIdx:
                    continue

                if frame.frameIndex not in spr.images:
                    print "wrong frame index: {0}".format(frame.frameIndex)
                    continue
                image = spr.images[frame.frameIndex]
                png = Image.new('RGBA', (image.width, image.height))
                png.putdata(image.data)
                if frame.mirror > 0:
                    png = png.transpose(Image.FLIP_LEFT_RIGHT)
                offsetX = (spr.maxwidth - image.width) / 2
                offsetY = spr.maxheight - image.height
#                offsetX = (spr.maxwidth - image.width) / 2 + getSignedNumber(frame.offsetX, 32)
#                offsetY = spr.maxheight - image.height + getSignedNumber(frame.offsetY, 32)
                tileset.paste(png, (x + offsetX, y + offsetY))
            tile = tile + 1
            x = x + spr.maxwidth
            if x + spr.maxwidth > 2048:
                x = 0
                y = y + spr.maxheight

#    for imageN in range(0, spr.rgbaSpritesCount + spr.indexedSpritesCount):
#        image = spr.images[imageN]
#        png = Image.new('RGBA', (image.width, image.height))
#        png.putdata(image.data)
#        tileset.paste(png, (x, y))
#        x = x + spr.maxwidth
#        if x + spr.maxwidth > 2048:
#            x = 0
#            y = y + spr.maxheight

    spr.frameToIdx = frameToIdx
    spr.tilesetWidth = tilesetWidth
    spr.tilesetHeight = tilesetHeight
    makeDir(spriteDir)
    tileset.save(spriteDir + spriteName + ".png")

def extractSpriteAnimData(act, spr, actIndex, direction):
#    delay = anim.delay
    delay = 100
    data = "        <animation direction=\"" + direction + "\">\n"
    if actIndex not in act.animations:
        data = data + "            <frame index=\"{0}\" delay=\"{1}\" offsetX=\"{2}\" offsetY=\"{3}\"/>\n".format(
            0, delay, 0, 0)
        data = data + "        </animation>\n"
        return data

    anim = act.animations[actIndex]
    for spriteN in range(0, anim.nsprites):
        sprite = anim.sprites[spriteN]
        #for frameN in range(0, sprite.nframes):
            #frame = sprite.frames[frameN]
            #frm = frame.frameIndex
            #if frame.mirror > 0:
            #    frm = -frm
            #if frm not in spr.frameToIdx:
            #    continue

        idx = spr.frameToIdx[str(actIndex) + "_" + str(spriteN)]
        offsetX = 0
        offsetY = 0
#        offsetX = frame.offsetX
#        offsetY = frame.offsetY
#        if offsetX > 4294900000:
#            offsetX = - (4294967296 - offsetX)
#        if offsetY > 4294000000:
#            offsetY = -(4294967296 - offsetY)

        data = data + "            <frame index=\"{0}\" delay=\"{1}\" offsetX=\"{2}\" offsetY=\"{3}\"/>\n".format(
            idx, delay, offsetX, offsetY)

    data = data + "        </animation>\n"
    return data

def extractSpriteDataAll(act, spr, actIndex, name):
    data = extractSpriteAnimData(act, spr, actIndex, "down")
    data = data + extractSpriteAnimData(act, spr, actIndex + 1, "leftdown")
    data = data + extractSpriteAnimData(act, spr, actIndex + 2, "left")
    data = data + extractSpriteAnimData(act, spr, actIndex + 3, "leftup")
    data = data + extractSpriteAnimData(act, spr, actIndex + 4, "up")
    data = data + extractSpriteAnimData(act, spr, actIndex + 5, "rightup")
    data = data + extractSpriteAnimData(act, spr, actIndex + 6, "right")
    data = data + extractSpriteAnimData(act, spr, actIndex + 6, "rightdown")
    return data

def saveSpriteXml(act, spr, spriteDir, spriteName):
    templatesDir = "templates/"
    dstFile = spriteDir + spriteName + ".xml"
    tpl = readFile(templatesDir + "sprite.xml")
    # 0, 8, 16, 24, 32, 40, 48
    # 0 - walk or attack or ?
    # 8 - walk
    # 16 - attack
    # 24 - dead
    # 32 - dead2 ?
    # no more
    standData = extractSpriteDataAll(act, spr, 0, "stand")
    walkData = extractSpriteDataAll(act, spr, 8, "walk")
    attackData = extractSpriteDataAll(act, spr, 16, "attack")
    deadData = extractSpriteDataAll(act, spr, 32, "dead")

    data = tpl.format(
        src = "graphics/sprites/sprites/" + spriteName + ".png",
        width = spr.maxwidth,
        height = spr.maxheight,
        stand = standData,
        walk = walkData,
        attack = attackData,
        dead = deadData
    )
    saveFile(dstFile, data)


def readAct(actFile):
    act = ActClass()
    with open(actFile, "r") as f:
        act.header = readInt16(f)
        if act.header != 17217:
            #print "Wrong header in file {0}".format(actFile)
            return None
        act.minorVersion = readInt8(f)
        act.majorVersion = readInt8(f)
        act.nanimations = readInt16(f)
        print "{0}, {1}.{2}, {1}".format(actFile, act.majorVersion, act.minorVersion, act.nanimations)
        #print " animations: " + str(act.nanimations)
        act.animations = dict()
        skipData(f, 10)
        for animN in range(0, act.nanimations):
            anim = ActAnimationClass()
            anim.delay = 30
            act.animations[animN] = anim
            anim.nsprites = readInt32(f)
            #print "  sprites: " + str(anim.nsprites)
            anim.sprites = dict()
            for spriteN in range(0, anim.nsprites):
                sprite = ActSpriteClass()
                anim.sprites[spriteN] = sprite
                sprite.left1 = readInt32(f)
                sprite.top1 = readInt32(f)
                sprite.right1 = readInt32(f)
                sprite.buttom1 = readInt32(f)
                sprite.left2 = readInt32(f)
                sprite.top2 = readInt32(f)
                sprite.right2 = readInt32(f)
                sprite.buttom2 = readInt32(f)
                sprite.nframes = readInt32(f)
                #print "sprite {0}, frames: {1}".format(spriteN, sprite.nframes)
                sprite.frames = dict()
                for frameN in range(0, sprite.nframes):
                    frame = ActFrameClass()
                    sprite.frames[frameN] = frame
                    frame.offsetX = readInt32(f)
                    frame.offsetY = readInt32(f)
                    frame.frameIndex = readInt32(f)
                    #print "   index: " + str(frame.frameIndex)
                    frame.mirror = readInt32(f)
                    if act.majorVersion >= 2:
                        frame.color = readInt32(f)
                        frame.scaleX = readInt32(f)
                        if act.majorVersion > 2 or (act.majorVersion == 2 and act.minorVersion >= 4):
                            frame.scaleY = readInt32(f)
                        else:
                            frame.scaleY = frame.scaleX
                        frame.angle = readInt32(f)
                        frame.spriteType = readInt32(f)
                        if act.majorVersion > 2 or (act.majorVersion == 2 and act.minorVersion >= 5):
                            frame.width = readInt32(f)
                            frame.height = readInt32(f)
                            #print "{0} x {1}".format(frame.width, frame.height)
                if act.majorVersion >= 2:
                    sprite.eventIndex = readInt32(f)
                    if act.majorVersion > 2 or (act.majorVersion == 2 and act.minorVersion >= 3):
                        sprite.npivots = readInt32(f)
                        sprite.pivots = dict()
                        #if sprite.npivots > 0:
                            #print "    pivotes: " + str(sprite.npivots)
                        for pivotN in range(0, sprite.npivots):
                            pivot = ActPivotClass()
                            sprite.pivots[pivotN] = pivot
                            pivot.unknown = readInt32(f)
                            pivot.centerX = readInt32(f)
                            pivot.centerY = readInt32(f)
                            pivot.nAttribute = readInt32(f)
        if act.majorVersion > 2 or (act.majorVersion == 2 and act.minorVersion >= 1):
            act.nevents = readInt32(f)
            act.events = dict()
            for eventN in range(0, act.nevents):
                event = ActEventClass()
                act.events[eventN] = event;
                event.name = readData(f, 40)
        if act.majorVersion > 2 or (act.majorVersion == 2 and act.minorVersion >= 2):
            for animN in range(0, act.nanimations):
                anim = act.animations[animN]
                anim.delay = readInt32(f)
    return act

def readSpr(sprFile):
    spr = SprClass()
    with open(sprFile, "r") as f:
        spr.header1 = readInt8(f)
        spr.header2 = readInt8(f)
        if spr.header1 != 0x53 or spr.header2 != 0x50:
            return None
        spr.minorVersion = readInt8(f)
        spr.majorVersion = readInt8(f)
        spr.indexedSpritesCount = readInt16(f)
        if spr.majorVersion > 1 or (spr.majorVersion == 1 and spr.minorVersion >= 1):
            spr.rgbaSpritesCount = readInt16(f)
        else:
            spr.rgbaSpritesCount = 0
        print "{0}, {1}.{2}, {3}, {4}".format(sprFile, spr.majorVersion, spr.minorVersion, spr.indexedSpritesCount, spr.rgbaSpritesCount)
        spr.frames = spr.indexedSpritesCount + spr.rgbaSpritesCount

        if spr.majorVersion > 2 or (spr.majorVersion == 2 and spr.minorVersion >= 1):
            readIndexedRLEImage(f, spr)
        else:
            readIndexedImage(f, spr)
        readRgbaImage(f, spr)

        if spr.majorVersion > 1 or (spr.majorVersion == 1 and spr.minorVersion >= 1):
            readPalette(f, spr)

    return spr

def convertSprite(spritePath, spriteName):
    actFile = "{0}.act".format(spritePath + spriteName)
    sprFile = "{0}.spr".format(spritePath + spriteName)
    if os.path.exists(actFile) == False or os.path.exists(sprFile) == False:
        return None
    act = readAct(actFile)
    spr = readSpr(sprFile)
    decodeSprite(spr)
    saveSpriteImage(act, spr, "clientdata/graphics/sprites/sprites/", spriteName)
    saveSpriteXml(act, spr, "clientdata/graphics/sprites/sprites/", spriteName)
#    if actFile.find("wolf") > 0:
#        exit(0)
#    exit(0)

def findSpritePath(spriteName):
    testName = spriteName + ".act"
    testName2 = spriteName.upper() + ".act"
    path = findFileIn((testName, testName2),
        ("rodata/data/sprite/ёуЅєЕН/",
        "rodata/data/sprite/npc/",
        "rodata/data/sprite/homun/"))
    return path

def convertSpritesNonFree(idtofile):
    processed = []
    for spriteid in idtofile:
        spriteName = idtofile[spriteid]
        if spriteName in processed:
            print "skipping " + spriteName
            continue

        path = findSpritePath(spriteName)
        if path is None:
            print "not found " + spriteName
            continue
        print spriteName
        convertSprite(path, spriteName)
        processed.append(spriteName)
