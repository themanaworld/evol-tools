# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import makeDir, readFile, saveFile

def convertHomunculuses():
    destDir = "clientdata/"
    templatesDir = "templates/"
    homunculusesDbFile = "serverdata/db/re/homunculus_db.txt"
    fieldsSplit = re.compile(",")
    makeDir(destDir)
    tpl = readFile(templatesDir + "homunculus.tpl")
    homunculuses = readFile(templatesDir + "homunculuses.xml")
    data = ""
    homunculusSprite = "<sprite>monsters/tortuga.xml</sprite>";
    with open(homunculusesDbFile, "r") as f:
        for line in f:
            if line == "" or line[0:2] == "//":
                continue
            rows = fieldsSplit.split(line)
            if len(rows) < 9:
                continue
            data = data + tpl.format(
                id = rows[0],
                sprite = homunculusSprite,
                name = rows[2])
    saveFile(destDir + "homunculuses.xml", homunculuses.format(data))
