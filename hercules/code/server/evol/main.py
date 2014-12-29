#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

from code.server.consts import *
from code.server.evol.itemdb import *
from code.server.evol.mobdb import *
from code.server.mobskilldb import *
from code.server.evol.npcs import *
from code.server.utils import *
from code.server.questsdb import *
from code.serverutils import *

def serverEvolMain():
    cleanServerData()
    createMainScript()
    items = convertItemDb()
    convertNpcs(items)
    convertMobDb()
    quests = convertQuestsDb()
    convertConsts(quests)
    convertMobSkillDb()
