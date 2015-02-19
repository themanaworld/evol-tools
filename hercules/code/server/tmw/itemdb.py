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
    scriptsSplit = re.compile("},")
    scriptsTextClean = re.compile('([{}])')
    scriptsTextComma = re.compile('^,')
    scriptsTextColon = re.compile('; ')
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
                        # set all values then write
                        w.write("{\n")
                        c.write("{0}\t{1}\n".format(rows[1], rows[0]))
                        writeIntField(w, "Id", rows[0])
                        writeStrField(w, "AegisName", rows[1])
                        writeStrField(w, "Name", rows[2])
                        if rows[3] == "0":
                            writeIntField(w, "Type", "2")
                        else:
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
                        if rows[13] == "2":
                            writeIntField(w, "View", "1")
                        elif rows[13] == "34":
                            writeIntField(w, "View", "11")
                        elif rows[13] == "32768":
                            writeIntField(w, "View", "1")
                        else:
                            writeIntField(w, "View", rows[0])
                        writeIntField(w, "BindOnEquip", "false")
                        writeIntField(w, "BuyingStore", "false")
                        writeIntField(w, "Delay", "0")
                        writeIntField(w, "Sprite", "0")

                        scripts = ""
                        for f in xrange(17, len(rows)):
                            scripts = scripts + ", " + rows[f]
                        rows = scriptsSplit.split(scripts)
                        # Needs .split(';') and \n each 
                        UseScript = scriptsTextColon.sub(';',scriptsTextComma.sub('', scriptsTextClean.sub('', rows[0]))).strip().split(';')
                        EquipScript = scriptsTextColon.sub(';',scriptsTextComma.sub('', scriptsTextClean.sub('', rows[1]))).strip().split(';')
                        # move to for stmt
                        if len(UseScript) > 1:
                            writeStartScript(w, "Script")
                            for uline in UseScript:
                                if len(uline) > 0:
                                    w.write("        {0};\n".format(uline))
                            writeEndScript(w)
                        if len(EquipScript) > 1:
                            writeStartScript(w, "OnEquipScript")
                            for eline in EquipScript:
                                if len(eline) > 0:
                                    w.write("        {0};\n".format(eline))
                            writeEndScript(w)

                        w.write("},\n")
        w.write(")\n")
    return items
