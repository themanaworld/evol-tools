#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

from code.server.account import *
from code.server.accreg import *
from code.server.party import *
from code.server.storage import *
from code.server.db.char import *
from code.server.db.charregnumdb import *
from code.server.db.inventory import *
from code.server.db.skill import *
from code.server.tmw.athena import *
from code.server.tmw.consts import *
from code.server.tmw.itemdb import *
from code.server.tmw.mobdb import *
from code.server.tmw.mobskilldb import *
from code.server.tmw.npcs import *
from code.server.utils import *
from code.server.questsdb import *
from code.serverutils import *

def serverTmwMain(isNew):
    try:
        cleanServerData()
    except:
        print "Updating server"
    createMainScript()
    items = convertItemDb(isNew)
    npcIds = Set()
    convertNpcs(items, npcIds)
    convertMobDb(items)
    quests = dict()
    convertConsts(quests, npcIds)
    convertMobSkillDb()

def dbTmwMain():
    convertAccount()
    users = readAthena()
    saveCharTable(users)
    saveCharRegNumDbTable(users)
    saveSkillTable(users)
    saveInventoryTable(users)
    convertStorage()
    convertAccReg()
    convertParty(users)
