# -*- coding: utf8 -*-
#
# Copyright (C) 2015  Evol Online
# Author: Andrei Karas (4144)

from code.fileutils import *
from code.stringutils import *

def saveInventoryTable(users):
    dstFile = "newdb/inventory.sql"
    firstLine = True
    tpl = readFile("templates/inventory.sql")
    with open(dstFile, "w") as w:
        w.write(tpl)
        w.write("INSERT INTO `inventory` VALUES ")
        for userId in users:
            user = users[userId]
            for item in user.inventory:

                if firstLine == False:
                    w.write(",\n")
                else:
                    firstLine = False

                w.write(("({id},{char_id},{nameid},{amount},{equip},{identify}," +
                    "{refine},{attribute},{card0},{card1},{card2},{card3}," +
                    "{expire_time},{favorite},{bound},{unique_id})").format(
                    id = 0,
                    char_id = user.char_id,
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
                    favorite = "0",
                    bound = "0",
                    unique_id = "0"
                ))
        w.write("\n")
