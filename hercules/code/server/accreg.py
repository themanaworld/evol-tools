# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *
from code.stringutils import *
from code.server.dbitem import *

def convertAccReg():
    srcFile = "olddb/accreg.txt"
    dstFile = "newdb/acc_reg_num_db.sql"
    fieldsSplit = re.compile("\t")
    comaSplit = re.compile(",")
    spaceSplit = re.compile(" ")
    tpl = readFile("templates/acc_reg_num_db.sql")
    firstLine = True
    with open(dstFile, "w") as w:
        w.write(tpl)
        w.write("INSERT INTO `acc_reg_num_db` VALUES ")
        with open(srcFile, "r") as r:
            for line in r:
                if line[:2] == "//":
                    continue
                line = stripNewLine(line)
                rows = fieldsSplit.split(line)
                if len(rows) != 2:
                    print "wrong accreg.txt line: " + line
                    continue

                accountId = rows[0]

                data = spaceSplit.split(rows[1])
                for varStr in data:
                    if varStr == "":
                        continue

                    tmp = comaSplit.split(varStr)

                    if firstLine == False:
                        w.write(",\n")
                    else:
                        firstLine = False

                    w.write(("({account_id},'{key}',{index},{value})").format(
                        account_id = accountId,
                        key = tmp[0],
                        index = "0",
                        value = tmp[1]
                    ))
        w.write("\n")
