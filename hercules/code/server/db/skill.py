# -*- coding: utf8 -*-
#
# Copyright (C) 2015  Evol Online
# Author: Andrei Karas (4144)

from code.fileutils import *
from code.stringutils import *

def saveSkillTable(users):
    dstFile = "newdb/skill.sql"
    firstLine = True
    tpl = readFile("templates/skill.sql")
    with open(dstFile, "w") as w:
        w.write(tpl)
        w.write("INSERT INTO `skill` VALUES ")
        for userId in users:
            user = users[userId]
            for skill in user.skills:

                if firstLine == False:
                    w.write(",\n")
                else:
                    firstLine = False

                w.write(("({char_id},{id},{lv},{flag})").format(
                    char_id = user.char_id,
                    id = skill.skillId,
                    lv = skill.level,
                    flag = skill.flags
                ))
        w.write("\n")
