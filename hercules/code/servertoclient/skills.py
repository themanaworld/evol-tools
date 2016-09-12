# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import makeDir, readFile, saveFile

def convertSkillsToXml():
    destDir = "clientdata/"
    templatesDir = "templates/"
    skillsDbFile = "serverdata/db/re/skill_db.txt"
    fieldsSplit = re.compile(",")
    makeDir(destDir)
    tpl = readFile(templatesDir + "skill.tpl")
    skills = readFile(templatesDir + "skills.xml")
    data = ""
    with open(skillsDbFile, "r") as f:
        for line in f:
            if line == "" or line[0:2] == "//":
                continue
            rows = fieldsSplit.split(line)
            if len(rows) < 9:
                continue
            skillId = rows[0]
            name = rows[15].strip()
            description = rows[16].strip()
            idx = description.find ("//")
            if idx > 1:
                description = description[:idx]
            data = data + tpl.format(skillId, name, description)
    saveFile(destDir + "skills.xml", skills.format(data))
