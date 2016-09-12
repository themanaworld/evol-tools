# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.configutils import writeIntField, writeStartBlock, writeEndBlock, writeStartScript, writeEndScript, writeStrField, writeSubField
from code.fileutils import readFile

def convertItemDb():
    srcFile = "oldserverdata/db/item_db.txt"
    dstFile = "newserverdata/db/re/item_db.conf"
    constsFile = "newserverdata/db/const.txt"
    fieldsSplit = re.compile(",")
    scriptsSplit = re.compile("{")
    items = dict()
    with open(srcFile, "r") as r:
        with open(dstFile, "w") as w:
            with open(constsFile, "a") as c:
                c.write("// items\n");
                tpl = readFile("templates/item_db.tpl")
                w.write(tpl)
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
                    if rows[4] == "2":
                        rows[4] = "0"
                        rows[3] = str(int(rows[3]) | 4)

                    items[rows[1]] = rows[0]
                    w.write("{\n")
                    c.write("{0}\t{1}\n".format(rows[1], rows[0]))
                    writeIntField(w, "Id", rows[0])
                    writeStrField(w, "AegisName", rows[1])
                    writeStrField(w, "Name", rows[2])
                    writeIntField(w, "Type", rows[4])
                    writeIntField(w, "Buy", rows[5])
                    writeIntField(w, "Sell", rows[6])
                    writeIntField(w, "Weight", rows[7])
                    writeIntField(w, "Atk", rows[8])
                    writeIntField(w, "Matk", "0")
                    writeIntField(w, "Def", rows[9])
                    writeIntField(w, "Range", rows[10])
                    writeIntField(w, "Slots", "0")
                    writeIntField(w, "Job", "0xFFFFFFFF")
                    writeIntField(w, "Upper", "0x3F")
                    writeIntField(w, "Gender", rows[13])
                    writeIntField(w, "Loc", rows[14])
                    writeIntField(w, "WeaponLv", rows[15])
                    writeIntField(w, "EquipLv", rows[16])
                    writeIntField(w, "Refine", "false")
                    if rows[14] == "2":
                        writeIntField(w, "View", "1")
                    else:
                        writeIntField(w, "View", rows[0])
                    writeIntField(w, "BindOnEquip", "false")
                    writeIntField(w, "BuyingStore", "false")
                    writeIntField(w, "Delay", "0")
                    trade = int(rows[3])
                    if trade != 0:
                        writeStartBlock(w, "Trade")
                    if trade & 1 == 1:
                        writeSubField(w, "nodrop", "true")
                    if trade & 2 == 2:
                        writeSubField(w, "notrade", "true")
                    if trade & 4 == 4:
                        writeSubField(w, "nodelonuse", "true")
                    if trade & 8 == 8:
                        writeSubField(w, "nostorage", "true")
                    if trade & 256 == 256:
                        writeSubField(w, "nogstorage", "true")
                    if trade & 512 == 512:
                        writeSubField(w, "noselltonpc", "true")
                    if trade != 0:
                        writeEndBlock(w)
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
