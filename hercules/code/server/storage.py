# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *
from code.stringutils import *
from code.server.dbitem import *

def convertStorage():
    srcFile = "olddb/storage.txt"
    dstFile = "newdb/storage.sql"
    fieldsSplit = re.compile("\t")
    comaSplit = re.compile(",")
    spaceSplit = re.compile(" ")
    tpl = readFile("templates/storage.sql")
    firstLine = True
    with open(dstFile, "w") as w:
        w.write(tpl)
        w.write("INSERT INTO `storage` VALUES ")
        with open(srcFile, "r") as r:
            for line in r:
                if line[:2] == "//":
                    continue
                rows = fieldsSplit.split(line)
                if len(rows) == 2:
                    continue
                if len(rows) != 3:
                    print "wrong storage.txt line: " + stripNewLine(line)
                    continue

                tmp = comaSplit.split(rows[0])
                accountId = tmp[0]
                storage_amount = tmp[1]

                data = spaceSplit.split(rows[1])
                for itemStr in data:
                    if itemStr == "":
                        continue

                    tmp = comaSplit.split(itemStr)
                    item = Item()
                    item.unknownId = tmp[0]
                    item.itemId = tmp[1]
                    item.amount = tmp[2]
                    item.equip = tmp[3]
                    item.color = tmp[4]
                    item.refine = tmp[5]
                    item.attribute = tmp[6]
                    item.card0 = tmp[7]
                    item.card1 = tmp[8]
                    item.card2 = tmp[9]
                    item.card3 = "0"

                    if firstLine == False:
                        w.write(",\n")
                    else:
                        firstLine = False

                    w.write(("({id},{account_id},{nameid},{amount},{equip},{identify}," +
                        "{refine},{attribute},{card0},{card1},{card2},{card3}," +
                        "{expire_time},{bound},{unique_id})").format(
                        id = 0,
                        account_id = accountId,
                        nameid = item.itemId,
                        amount = item.amount,
                        equip = item.equip,
                        identify = "1",
                        refine = item.refine,
                        attribute = item.attribute,
                        card0 = "0",
                        card1 = "0",
                        card2 = "0",
                        card3 = "0",
                        expire_time = "0",
                        bound = "0",
                        unique_id = "0"
                    ))
        w.write("\n")
