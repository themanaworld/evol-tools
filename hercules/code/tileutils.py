# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import array

def getTileData(mapData, x, y, sx):
    data = mapData[y * sx + x]
    arr = array.array("B")
    arr.fromstring(data)
    data = arr[0]
    return data

def getTile(data):
    normal = 0
    collison = 0
    if data == 0:    # 000 normal walkable
        normal = 1
        collision = 5
    elif data == 1:  # 001 non walkable
        normal = 2
        collision = 6
    elif data == 2:  # 010 same with 0
        normal = 1
        collision = 5
    elif data == 3:  # 011 same with 0, but water
        normal = 3
        collision = 5
    elif data == 4:  # 100 same with 0
        normal = 1
        collision = 5
    elif data == 5:  # 101 same with 1, but shootable (for now not supported!!!)
        normal = 4
        collision = 6
    elif data == 6:  # 110 same with 0
        normal = 1
        collision = 5
    return (str(normal), str(collision))

def getGroundTile(flag):
    return str(flag + 1)

def getCollisionTile(flag):
    if flag == 0:
        return "0"
    return "4"

