# -*- coding: utf8 -*-
#
# Copyright (C) 2015  Evol Online
# Author: Andrei Karas (4144)

from code.fileutils import readFile

def saveCharRegNumDbTable(users):
    dstFile = "newdb/char_reg_num_db.sql"
    firstLine = True
    tpl = readFile("templates/char_reg_num_db.sql")
    with open(dstFile, "w") as w:
        w.write(tpl)
        w.write("INSERT INTO `char_reg_num_db` VALUES ")
        for userId in users:
            user = users[userId]
            for varKey in user.variables:
                if varKey == "ShipQuests":
                    continue

                varValue = user.variables[varKey]

                if firstLine == False:
                    w.write(",\n")
                else:
                    firstLine = False

                w.write(("({char_id},'{key}',{index},{value})").format(
                    char_id = user.char_id,
                    key = varKey,
                    index = "0",
                    value = varValue
                ))
        w.write("\n")
