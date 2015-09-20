# -*- coding: utf8 -*-
#
# Copyright (C) 2015  Evol Online
# Author: Andrei Karas (4144)

import re
from sets import Set

from code.fileutils import *
from code.stringutils import *

from code.servertoclient.sprites import *

def getNpcIds(idtofile):
    for key1 in idtofile:
        key = int(key1)
        if 45 <= key <= 125 or 400 < key < 1000 or 10001 <= key < 10100:
            yield key1

def convertNpcsNonFree(idtofile):
    destDir = "clientdata/"
    templatesDir = "templates/"
    monstersDbFile = "serverdata/sql-files/mob_db_re.sql"
    fieldsSplit = re.compile(",")
    bracketsSplit = re.compile("[(]|[)]")
    makeDir(destDir)
    tpl = readFile(templatesDir + "npc.tpl")
    npcs = readFile(templatesDir + "npcs.xml")
    data = ""

    for key in getNpcIds(idtofile):
        npcSprite = "<sprite>sprites/{0}.xml</sprite>".format(idtofile[key])
        data = data + tpl.format(key, idtofile[key], npcSprite)
    saveFile(destDir + "npcs.xml", npcs.format(data))
