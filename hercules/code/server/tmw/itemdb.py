# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.configutils import *
from code.fileutils import *
from code.stringutils import *

def getItemDbFile(srcDir):
    files = os.listdir(srcDir)
    for srcFile in files:
        if srcFile.find("item_db") >= 0:
            yield srcFile

def convertItemDb():
    srcDir = "oldserverdata/world/map/db/"
    dstFile = "newserverdata/db/re/item_db.conf"
    if os.path.isfile(dstFile):
        os.remove(dstFile)
    constsFile = "newserverdata/db/const.txt"
    if os.path.isfile(constsFile):
        os.remove(constsFile)
    fieldsSplit = re.compile(",")
    scriptsSplit = re.compile("{")
    items = dict()

    tpl = readFile("templates/item_db.tpl")
    with open(dstFile, "w") as w:
        w.write(tpl)
        with open(constsFile, "a") as c:
            c.write("// items\n");
            for srcFile in getItemDbFile(srcDir):
                with open(srcDir + srcFile, "r") as r:
                    for line in r:
                        if len(line) < 2 or line[0] == "#" or line[0:2] == "//":
                            continue
                        rows = fieldsSplit.split(line)
                        if len(rows) < 5 or rows[0] == "0":
                            continue

                        sz = len(rows)
                        if sz > 19:
                            sz = 19
                        for f in xrange(0, sz):
                            rows[f] = rows[f].strip()

                        items[rows[1]] = {'id':rows[0],'buy':rows[4]}
                        w.write("{\n")
                        c.write("{0}\t{1}\n".format(rows[1], rows[0]))
                        writeIntField(w, "Id", rows[0])
                        writeStrField(w, "AegisName", rows[1])
                        writeStrField(w, "Name", rows[2])
                        writeIntField(w, "Type", rows[3])
                        writeIntField(w, "Buy", rows[4])
                        writeIntField(w, "Sell", rows[5])
                        writeIntField(w, "Weight", rows[6])
                        writeIntField(w, "Atk", rows[7])
                        writeIntField(w, "Matk", "0")
                        writeIntField(w, "Def", rows[8])
                        writeIntField(w, "Range", rows[9])
                        writeIntField(w, "Slots", "0")
                        writeIntField(w, "Job", "0xFFFFFFFF")
                        writeIntField(w, "Upper", "0x3F")
                        writeIntField(w, "Gender", rows[12])
                        writeIntField(w, "Loc", rows[13])
                        writeIntField(w, "WeaponLv", rows[14])
                        writeIntField(w, "EquipLv", rows[15])
                        writeIntField(w, "Refine", "false")
                        if rows[14] == "2":
                            writeIntField(w, "View", "1")
                        else:
                            writeIntField(w, "View", rows[0])
                        writeIntField(w, "BindOnEquip", "false")
                        writeIntField(w, "BuyingStore", "false")
                        writeIntField(w, "Delay", "0")
                        writeIntField(w, "Sprite", "0")

                        scripts = ""
                        for f in xrange(sz, len(rows)):
                            scripts = scripts + ", " + rows[f]
                        rows = scriptsSplit.split(scripts)
                        cnt = len(rows)
                        if cnt > 1:
                            text = rows[1].strip()
                            if len(text) > 1:
                                text = text[:-2]
                                if text != "":
                                    writeStartScript(w, "Script")
                                    w.write("        {0}\n".format(text))
                                    writeEndScript(w)

                        w.write("},\n")
        w.write(")\n")
    return items
