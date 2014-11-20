# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re
from sets import Set

from code.fileutils import *
from code.stringutils import *

def convertQuestsDb():
    srcFile = "oldserverdata/db/questvars.txt"
    dstFile = "newserverdata/db/quest_db.txt"
    fieldsSplit = re.compile(",")
    quests = dict()
    with open(srcFile, "r") as r:
        with open(dstFile, "w") as w:
            tpl = readFile("templates/quest_db.tpl")
            w.write(tpl)
            cnt = 0
            for line in r:
                if len(line) < 2 or line[0:2] == "//":
                    continue

                idx = line.find("// ")
                if idx < 3:
                    continue
                line = line[idx + 3:]
                idx = line.find(" ")
                if idx < 3:
                    continue
                line = line[:idx]

                w.write("{0},0,0,0,0,0,0,0,\"{1}\"\n".format(cnt, line))
                quests[line] = cnt
                cnt = cnt + 1
    return quests
