# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re
from sets import Set

from code.fileutils import *
from code.stringutils import *

def prepStat(val, text):
    if val != "0" and val != "":
        return "        {0}=\"{1}\"\n".format(text, val)
    return ""

def convertItems():
    destDir = "clientdata/"
    templatesDir = "templates/"
    itemsDbFile = "serverdata/sql-files/item_db_re.sql"
    fieldsSplit = re.compile(",")
    bracketsSplit = re.compile("[(]|[)]")
    makeDir(destDir)
    tpl = readFile(templatesDir + "item.tpl")
    items = readFile(templatesDir + "items.xml")
    data = ""
    ids = Set()
    with open(itemsDbFile, "r") as f:
        for line in f:
            if len(line) < 10 or line[0:2] == "//" or line[0:12] != "REPLACE INTO":
                continue
            rows = bracketsSplit.split(line)
            if len(rows) < 2:
                continue
            rows = fieldsSplit.split(rows[1])
            if len(rows) < 31:
                continue
            rows = stripQuotes2(rows)
            itemId = rows[0]
            name = rows[1]
            name2 = rows[2]
            itemType = rows[3]
            priceBuy = rows[4]
            priceSell = rows[5]
            weight = rows[6]
            atk = rows[7]
            matk = rows[8]
            defence = rows[9]
            attackRange = rows[10]
            slots = rows[11]
            equipJobs = rows[12]
            equipUpper = rows[12]
            equipGender = rows[14]
            equipLocations = rows[15]
            weaponLevel = rows[16]
            equipLevelMin = rows[17]
            equipLevelMax = rows[18]
            refinable = rows[19]
            view = rows[20]
            bindOnEquip = rows[21]
            buyInStore = rows[22]
            delay = rows[23]
            tradeFlag = rows[24]
            tradeGroup = rows[25]
            nouseFlag = rows[26]
            nouseGroup = rows[27]
            stackAmount = rows[28]
            stackFlag = rows[29]
            sprite = rows[30]

            name = name.replace("\\'", "'")
            image = ""

            statStr = prepStat(atk, "attack")
            statStr = statStr + prepStat(matk, "mattack")
            statStr = statStr + prepStat(defence, "defence")
            statStr = statStr + prepStat(weight, "weight")
            statStr = statStr + prepStat(attackRange, "range")
            statStr = statStr + prepStat(delay, "speed")
#            print itemId + "," + equipLocations
#            typeStr = "other"
            typeStr = "equip-legs"
            spriteStr = "equipment/legs/trousers-male.xml"
            image = "generic/box-fish.png"
            if itemType == 0 or itemType == 2 or itemType == 18: # usable
                image = "usable/bread.png"
                typeStr = "usable"
                spriteStr = "";
            elif equipLocations == "0":
                image = "usable/bread.png"
                typeStr = "usable"
                spriteStr = "";
            elif equipLocations == "1":
                image = "equipment/legs/shorts.png|S:#4d4d4d,514d47,686868,706662,919191,99917b,b6b6b6,c0b698,dfdfdf,e4dfca"
                typeStr = "equip-legs"
                spriteStr = "equipment/legs/shorts-male.xml|#4d4d4d,514d47,686868,706662,919191,99917b,b6b6b6,c0b698,dfdfdf,e0d5bf";
            elif equipLocations == "2":
                image = "equipment/weapons/knife.png"
                typeStr = "equip-1hand"
                spriteStr = "equipment/weapons/knife.xml";
            elif equipLocations == "4":
                image = "equipment/hands/armbands.png"
                typeStr = "equip-arms"
                spriteStr = "equipment/hands/armbands-male.xml";
            elif equipLocations == "16":
                image = "equipment/chest/cottonshirt.png|S:#3c3c3c,3e3c38,4d4d4d,514d47,686868,706662,919191,99917b,b6b6b6,c0b698,dfdfdf,e4dfca"
                typeStr = "equip-torso"
                spriteStr = "equipment/chest/cottonshirt-male.xml|#43413d,59544f,7a706c,8a8176,a69e88,d1c7a7,e0d5bf";
            elif equipLocations == "64":
                image = "equipment/feet/boots.png|S:#3c3c3c,40332d,4d4d4d,5e4a3d,686868,705740,919191,a1825d,b6b6b6,b59767,dfdfdf,dbbf88"
                typeStr = "equip-feet"
                spriteStr = "equipment/feet/boots-male.xml|#40332d,5e4a3d,705740,a1825d,b59767,dbbf88";
            elif equipLocations == "136":
                image = "equipment/chest/cottonshirt.png|S:#3c3c3c,3e3c38,4d4d4d,514d47,686868,706662,919191,99917b,b6b6b6,c0b698,dfdfdf,e4dfca"
                typeStr = "equip-torso"
                spriteStr = "equipment/chest/cottonshirt-male.xml|#43413d,59544f,7a706c,8a8176,a69e88,d1c7a7,e0d5bf";
            elif equipLocations == "256":
                image = "equipment/head/bandana.png"
                typeStr = "equip-head"
                spriteStr = "equipment/head/bandana-male.xml";
            elif equipLocations == "512":
                # no sprites in evol
                image = "equipment/chest/sailorshirt.png"
                typeStr = "equip-torso"
                spriteStr = "equipment/chest/shirt-male.xml|#131913,1b231d,233129,35433e,4e6059,6c8279;#72571e,836737,a5854d,b18f45";

            name = strToXml(name);

            if itemId not in ids:
                ids.add(itemId)
                data = data + tpl.format(itemId, name, 0,
                    statStr, image, typeStr, spriteStr)
            if view != "0" and view not in ids:
                ids.add(view)
                data = data + tpl.format(view, name, 0,
                    statStr, image, typeStr, spriteStr)

    saveFile(destDir + "items.xml", items.format(data))
