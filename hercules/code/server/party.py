# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *
from code.stringutils import *
from code.server.dbitem import *

def findLeaderId(name, users):
    for userId in users:
        user = users[userId]
        if user.char_name == name:
            return user.char_id
    return 0

def convertParty(users):
    srcFile = "olddb/party.txt"
    dstFile = "newdb/party.sql"
    fieldsSplit = re.compile("\t")
    comaSplit = re.compile(",")
    tpl = readFile("templates/party.sql")
    firstLine = True
    with open(dstFile, "w") as w:
        w.write(tpl)
        w.write("INSERT INTO `party` VALUES ")
        with open(srcFile, "r") as r:
            for line in r:
                if line[:2] == "//":
                    continue
                line = stripNewLine(line)
                rows = fieldsSplit.split(line)
                if len(rows) == 2:
                    continue
                if len(rows) < 3:
                    print "wrong party.txt line: " + line
                    continue

                partyId = rows[0]
                partyName = rows[1]

                tmp = comaSplit.split(rows[2])
                partyExp = tmp[0]
                partyItem = tmp[1]

                leaderId = 0
                leaderName = ""
                accountId = ""

                for f in xrange(3, len(rows), 2):

                    if rows[f] == "0,0" or rows[f] == "":
                        continue

                    tmp = comaSplit.split(rows[f])
                    accountId = tmp[0]
                    leader = tmp[1]
                    charName = rows[f + 1]
                    if leader == "1":
                        leaderId = accountId
                        leaderName = charName

                if firstLine == False:
                    w.write(",\n")
                else:
                    firstLine = False

                leaderCharId = findLeaderId(leaderName, users)

                w.write(("({party_id},'{name}',{exp},{item}," +
                    "{leader_id},{leader_char})").format(
                    party_id = partyId,
                    name = escapeSqlStr(partyName),
                    exp = partyExp,
                    item = partyItem,
                    leader_id = leaderId,
                    leader_char = leaderCharId
                ))
        w.write("\n")
