# -*- coding: utf8 -*-
#
# Copyright (C) 2015  Evol Online
# Author: Andrei Karas (4144)

import re
from sets import Set

from code.fileutils import *
from code.stringutils import *

comaSplit = re.compile(",")
equalSplit = re.compile("=")

def extractLuaArray(fileName, arrName):
    with open(fileName, "r") as f:
        for line in f:
            if line.find(arrName) == 0:
                line = line[line.find("{") + 1:]
                line = line[:line.find("}")]
                return line
    return ""

def convertJobName():
    jobs = dict()
    jobNameFile = "rodata/decompiled/jobname.lua"
    line = extractLuaArray(jobNameFile, "JobNameTable")
    arr = comaSplit.split(line)
    for itemStr in arr:
        parts = equalSplit.split(itemStr.strip())
        if parts[0].find("[jobtbl.") == 0:
            key = parts[0].strip()
            key = key[8:-1].strip()
            val = parts[1].strip()
            val = val[1:-1].strip()
            jobs[key] = val
    return jobs

def convertIdentity(jobs):
    idents = dict()
    npcIdentityFile = "rodata/decompiled/npcidentity.lua"
    line = extractLuaArray(npcIdentityFile, "jobtbl = ")
    arr = comaSplit.split(line)
    for itemStr in arr:
        parts = equalSplit.split(itemStr.strip())
        key = parts[0].strip()
        val = parts[1].strip()
        if key in jobs:
            idents[val] = jobs[key].lower()
    return idents

def convertLuas():
    jobs = convertJobName()
    idtofile = convertIdentity(jobs)
    return idtofile
