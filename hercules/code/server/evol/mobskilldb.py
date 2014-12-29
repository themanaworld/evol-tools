# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *
from code.stringutils import *

def convertMobSkillDb():
    srcFile = "oldserverdata/db/mob_skill_db.txt"
    dstFile = "newserverdata/db/re/mob_skill_db.txt"
    fieldsSplit = re.compile(",")
    with open(srcFile, "r") as r:
        with open(dstFile, "w") as w:
            tpl = readFile("templates/mob_skill_db.tpl")
            w.write(tpl)
            for line in r:
                if len(line) < 2:
                    w.write(line)
                    continue
                rows = fieldsSplit.split(line)
                if len(rows) < 10:
                    w.write(line)
                    continue

                for f in xrange(0, len(rows)):
                    rows[f] = rows[f].strip()

                w.write("{0},{1},{2},{3},{4},{5},{6},"
                        "{7},{8},{9},{10},{11},{12},{13},"
                        "{14},{15},,,\n".format(
                    rows[0],
                    rows[1],
                    rows[2],
                    rows[3],
                    rows[4],
                    rows[5],
                    rows[6],
                    rows[7],
                    rows[8],
                    rows[9],
                    rows[10],
                    rows[11],
                    rows[13],
                    rows[14],
                    rows[15],
                    rows[16]
                ))

