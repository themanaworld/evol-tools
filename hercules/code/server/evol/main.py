#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

from code.server.account import *
from code.server.db.char import *
from code.server.db.charregnumdb import *
from code.server.evol.athena import *
from code.server.evol.consts import *
from code.server.evol.itemdb import *
from code.server.evol.mobdb import *
from code.server.evol.mobskilldb import *
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

def dbEvolMain():
    convertAccount()
    users = readAthena()
    saveCharTable(users)
    saveCharRegNumDbTable(users)
