# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *
from code.stringutils import *

def convertSex(sex):
    if sex == "M" or sex == "F" or sex == "S":
        return sex
    return "M"

def convertAccount():
    srcFile = "olddb/account.txt"
    dstFile = "newdb/login.sql"
    fieldsSplit = re.compile("\t")
    tpl = readFile("templates/login.sql")
    firstLine = True
    with open(dstFile, "w") as w:
        w.write(tpl)
        w.write("INSERT INTO `login` VALUES ")
        with open(srcFile, "r") as r:
            for line in r:
                if line[:2] == "//":
                    continue
                rows = fieldsSplit.split(line)
                if len(rows) == 2:
                    continue
                if len(rows) != 14:
                    print "wrong account.txt line: " + stripNewLine(line)
                    continue

                if firstLine == False:
                    w.write(",\n")
                else:
                    firstLine = False

                w.write(("({account_id},'{userid}','{user_pass}','{sex}'," +
                    "'{email}',{group_id},{state},{unban_time}," +
                    "{expiration_time},{logincount},'{lastlogin}'," +
                    "'{last_ip}','{birthdate}',{character_slots}," +
                    "'{pincode}',{pincode_change})").format(
                    account_id = rows[0],
                    userid = escapeSqlStr(rows[1]),
                    user_pass = escapeSqlStr(rows[2]),
                    sex = convertSex(rows[4]),
                    email = escapeSqlStr(rows[7]),
                    group_id = 0,
                    state = 0,
                    unban_time = rows[12],
                    expiration_time = rows[9],
                    logincount = rows[5],
                    lastlogin = rows[3],
                    last_ip = rows[10],
                    birthdate = '0000-00-00',
                    character_slots = 0,
                    pincode = '',
                    pincode_change = 0
                ))
        w.write("\n")
