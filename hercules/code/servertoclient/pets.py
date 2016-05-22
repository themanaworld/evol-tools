# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *

def convertPets():
    destDir = "clientdata/"
    templatesDir = "templates/"
    petsDbFile = "serverdata/db/re/pet_db.txt"
    fieldsSplit = re.compile(",")
    makeDir(destDir)
    tpl = readFile(templatesDir + "pet.tpl")
    pets = readFile(templatesDir + "pets.xml")
    data = ""
    petSprite = "<sprite>monsters/tortuga.xml</sprite>";
    with open(petsDbFile, "r") as f:
        for line in f:
            if line == "" or line[0:2] == "//":
                continue
            rows = fieldsSplit.split(line)
            if len(rows) < 9:
                continue
            data = data + tpl.format(
                id = rows[0],
                sprite = petSprite,
                name = rows[2])
    saveFile(destDir + "pets.xml", pets.format(data))
