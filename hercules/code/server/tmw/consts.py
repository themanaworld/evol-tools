# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *
from code.stringutils import *

def getConstsFile(srcDir):
    files = os.listdir(srcDir)
    for srcFile in files:
        if srcFile.find("const") == 0 and srcFile[-4:] == ".txt":
            yield srcDir + srcFile

def convertConsts(quests):
    dstFile = "newserverdata/db/const.txt"
    fieldsSplit = re.compile("\t+")
    fields = dict()
    vals = [("MF_NOTELEPORT", "mf_noteleport"),
        ("MF_NORETURN", "mf_noreturn"),
        ("MF_MONSTER_NOTELEPORT", "mf_monster_noteleport"),
        ("MF_NOSAVE", "mf_nosave"),
        ("MF_NOPENALTY", "mf_nopenalty"),
        ("MF_PVP", "mf_pvp"),
        ("MF_PVP_NOPARTY", "mf_pvp_noparty"),
        ("MF_PVP_NOCALCRANK", "mf_pvp_nocalcrank"),
        ("MF_NOWARP", "mf_nowarp"),
        ("MF_NOWARPTO", "mf_nowarpto"),
        ("MF_SNOW", "mf_snow"),
        ("MF_FOG", "mf_fog"),
        ("MF_SAKURA", "mf_sakura"),
        ("MF_LEAVES", "mf_leaves"),
        ("MF_TOWN", "mf_town"),
        ("sc_poison", "SC_POISON"),
        ("sc_slowpoison", "SC_SLOWPOISON")
    ]
    with open(dstFile, "w") as w:
        srcFile = "serverdata/db/const.txt"
        with open(srcFile, "r") as r:
            for line in r:
                if len(line) < 2 or line[0:2] == "//":
                    continue
                line = line.replace(" ", "\t")
                rows = fieldsSplit.split(line)
                sz = len(rows)
                if sz < 2 or sz > 3:
                    continue

                fields[rows[0]] = rows[1][:-1]
                if sz == 2:
                    w.write("{0}\t{1}".format(rows[0], rows[1]))
                else:
                    w.write("{0}\t{1}\t{2}".format(rows[0], rows[1], rows[2]))
        # build in parameters
        w.write("ClientVersion\t10000\t1\n");

        srcDir = "oldserverdata/world/map/db/"
        w.write("// tmw constants\n")
        for srcFile in getConstsFile(srcDir):
            with open(srcFile, "r") as r:
                for line in r:
                    if len(line) < 2 or line[0:2] == "//":
                        continue
                    line = line.replace(" ", "\t")
                    rows = fieldsSplit.split(line)
                    if len(rows) != 2:
                        continue

                    for val in vals:
                        if rows[0] == val[0]:
                            rows[0] = val[1]
                    if rows[0] in quests:
                        rows[1] = str(quests[rows[0]]) + "\n"
                    if rows[0] in fields:
                        if fields[rows[0]] != rows[1][:-1]:
                            print "warning: different const values for {0} ({1}, {2})".format(rows[0], rows[1][:-1], fields[rows[0]])
                    else:
                        w.write("{0}\t{1}".format(rows[0], rows[1]))
