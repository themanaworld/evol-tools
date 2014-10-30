# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *

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
            mercenaryId = rows[0]
            data = data + tpl.format(mercenaryId, mercenarySprite)
    saveFile(destDir + "mercenaries.xml", mercenaries.format(data))
