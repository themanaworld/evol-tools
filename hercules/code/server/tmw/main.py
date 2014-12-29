#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

from code.server.tmw.consts import *
from code.server.tmw.itemdb import *
from code.server.tmw.mobdb import *
from code.server.tmw.mobskilldb import *
from code.server.tmw.npcs import *
from code.server.utils import *
from code.server.questsdb import *
from code.serverutils import *

def serverTmwMain():
    cleanServerData()
    createMainScript()
    items = convertItemDb()
    convertNpcs(items)
    convertMobDb()
    quests = dict()
    convertConsts(quests)
    convertMobSkillDb()
