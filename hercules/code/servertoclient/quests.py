# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *
from code.stringutils import *

def convertQuests():
    print "quests disabled for now"
    return
    destDir = "clientdata/"
    templatesDir = "templates/"
    questsDbFile = "serverdata/db/quest_db.txt"
    fieldsSplit = re.compile(",")
    makeDir(destDir)
    tpl = readFile(templatesDir + "quest.tpl")
    quests = readFile(templatesDir + "quests.xml")
    data = ""
    with open(questsDbFile, "r") as f:
        for line in f:
            if line == "" or line[0:2] == "//":
                continue
            rows = fieldsSplit.split(line)
            if len(rows) < 9:
                continue
            questId = rows[0]
            text = rows[8]
            if text[-1] == "\n":
                text = text[:-1]
            text = strToXml(stripQuotes(text))
            name = text
            if len(name) > 20:
                name = name[:19]

            data = data + tpl.format(questId, name, text + ": " + str(questId))
    saveFile(destDir + "quests.xml", quests.format(data))
