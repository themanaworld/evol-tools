# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re
from sets import Set

from code.fileutils import *
from code.stringutils import *

def convertMonsters():
    destDir = "clientdata/"
    templatesDir = "templates/"
    monstersDbFile = "serverdata/sql-files/mob_db_re.sql"
    fieldsSplit = re.compile(",")
    bracketsSplit = re.compile("[(]|[)]")
    makeDir(destDir)
    tpl = readFile(templatesDir + "monster.tpl")
    monsters = readFile(templatesDir + "monsters.xml")
    data = ""
    ids = Set()
    monsterSprite = """<sprite>monsters/blub.xml</sprite>
        <sprite>accessories/blub-tentacle.xml|#3e4164,3a3968,544a82,64437a,7d6db4,a26392,8f99c4,d294ab,b3cdcd,e7b8b8,d9ecd1,f0e8c5</sprite>""";
    with open(monstersDbFile, "r") as f:
        for line in f:
            if len(line) < 10 or line[0:2] == "//" or line[0:12] != "REPLACE INTO":
                continue
            rows = bracketsSplit.split(line)
            if len(rows) < 2:
                continue
            rows = fieldsSplit.split(rows[1])
            if len(rows) < 5:
                continue
            monsterId = rows[0]
            name = strToXml(stripQuotes(rows[2]))
            data = data + tpl.format(monsterId, name, monsterSprite)

    saveFile(destDir + "monsters.xml", monsters.format(data))
