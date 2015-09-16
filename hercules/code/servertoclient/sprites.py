# -*- coding: utf8 -*-
#
# Copyright (C) 2015  Evol Online
# Author: Andrei Karas (4144)

import os

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

def readIndexedRLEImage(f, spr):
    

def readIndexedImage(f, spr):
    pass

def readRgbaImage(f, spr):
    pass

def readAct(actFile):
    act = ActClass()
    with open(actFile, "r") as f:
        act.header = readInt16(f)
        if act.header != 17217:
            #print "Wrong header in file {0}".format(actFile)
            return None
        act.minorVersion = readInt8(f)
        act.majorVersion = readInt8(f)
        #print "file: {0}, version: {1}.{2}".format(actFile, act.majorVersion, act.minorVersion)
        act.nanimations = readInt16(f)
        #print " animations: " + str(act.nanimations)
        act.animations = dict()
        skipData(f, 10)
        for animN in range(0, act.nanimations):
            anim = ActAnimationClass()
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
                sprite.frames = dict()
                #print "   frames: " + str(sprite.nframes)
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
                            #print "   width: " + str(frame.width)
                            #print "   height: " + str(frame.height)
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


def convertSprite(spriteName):
    actFile = "{0}.act".format(spriteName)
    sprFile = "{0}.spr".format(spriteName)
    if os.path.exists(actFile) == False or os.path.exists(sprFile) == False:
        return None
    #readAct(actFile)
    readSpr(sprFile)
