# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import makeDir, readFile, saveFile

def convertMercenaries():
    destDir = "clientdata/"
    templatesDir = "templates/"
    mercenariesDbFile = "serverdata/db/mercenary_db.txt"
    fieldsSplit = re.compile(",")
    makeDir(destDir)
    tpl = readFile(templatesDir + "mercenary.tpl")
    mercenaries = readFile(templatesDir + "mercenaries.xml")
    data = ""
    mercenarySprite = "<sprite>monsters/croc.xml</sprite>";
    with open(mercenariesDbFile, "r") as f:
        for line in f:
            if line == "" or line[0:2] == "//":
                continue
            rows = fieldsSplit.split(line)
            if len(rows) < 9:
                continue
            data = data + tpl.format(
                id = rows[0],
                sprite = mercenarySprite,
                name = rows[2])
    saveFile(destDir + "mercenaries.xml", mercenaries.format(data))
