# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *
from code.stringutils import *

fieldsSplit = re.compile(":")

def getConstsFile(srcDir):
    files = os.listdir(srcDir)
    for srcFile in files:
        if srcFile.find("const") == 0 and srcFile[-4:] == ".txt":
            yield srcDir + srcFile

def readOneConst(r, line):
    key = ""
    val = ""
    depr = 0
    if line.find(": {") > 0:
        rows = fieldsSplit.split(line)
        key = rows[0].strip()
        line = r.next().strip()
        rows = fieldsSplit.split(line)
        if len(rows) != 2:
            print "error"
            return ("", "", 0)
        if rows[0] == "Value":
            val = rows[1]
        line = r.next().strip()
        rows = fieldsSplit.split(line)
        if len(rows) != 2:
            print "error"
            return ("", "", 0)
        rows[1] = rows[1].strip()
        if rows[0] == "Deprecated" and rows[1].find("true") == 0:
            depr = 1
    else:
        rows = fieldsSplit.split(line)
        if len(rows) != 2:
            return ("", "", 0)
        key = rows[0];
        val = rows[1]
    return (key, val, depr)

def writeConst(w, const):
    if const[2] == 1:
        w.write("\t{0}: {{\n\t\tValue:{1}\n\t\tDeprecated: true\n\t}}\n".format(const[0], const[1]))
    else:
        w.write("\t{0}:{1}\n".format(const[0], const[1]))

def convertConsts(quests, npcIds):
    dstFile = "newserverdata/db/constants.conf"
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
        tpl = readFile("templates/constants.tpl")
        w.write(tpl);
        srcFile = "serverdata/db/constants.conf"
        with open(srcFile, "r") as r:
            for line in r:
                if line.find("**************************************************************************/") >= 0:
                    break

            for line in r:
                line = line.strip()
                if len(line) < 2 or line[0:2] == "//" or line[0:2] == "/*":
                    continue
                const = readOneConst(r, line)
                if const[0] == "comment__":
                    continue
                fields[const[0]] = const[1].strip()
                writeConst(w, const)

        # build in parameters
        writeConst(w, ("ClientVersion", " 10000", 1));

        srcDir = "oldserverdata/world/map/db/"
        w.write("// tmw constants\n")

        fieldsSplit = re.compile("\t+")

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
                        writeConst(w, (rows[0], stripNewLine(rows[1]), 0))
        w.write("// tmw npcs\n")
        for npc in npcIds:
            if npc == -1:
                key = "MINUS1"
            else:
                key = str(npc)
            writeConst(w, ("NPC" + key, npc, 0))
        w.write("}")
