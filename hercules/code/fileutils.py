# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import array
import os
import struct
import shutil

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

def writeInt32(f, i):
    f.write(struct.pack("I", i))

def writeInt16(f, i):
    f.write(struct.pack("H", i))

def writeMapName(f, name):
    if len(name) > 12:
        name = name[:12]
    while len(name) < 12:
        name = name + '\x00'
    f.write(struct.pack("12s", name))

def writeData(f, data):
    f.write(data)

def copyFile(src, dst, name):
    shutil.copyfile(src + name, dst + name)

def saveFile(fileName, data):
    with open(fileName, "w") as w:
        w.write(data)

def makeDir(path):
    if not os.path.exists(path):
        os.makedirs(path)
