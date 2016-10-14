#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

from code.server.account import convertAccount
from code.server.accreg import convertAccReg
from code.server.party import convertParty
from code.server.storage import convertStorage
from code.server.db.char import saveCharTable
from code.server.db.charregnumdb import saveCharRegNumDbTable
from code.server.db.inventory import saveInventoryTable
from code.server.db.skill import saveSkillTable
from code.server.evol.athena import readAthena
from code.server.evol.consts import convertConsts
from code.server.evol.itemdb import convertItemDb
from code.server.evol.mobdb import convertMobDb
from code.server.evol.mobskilldb import convertMobSkillDb
from code.server.evol.npcs import createMainScript, convertNpcs
from code.server.questsdb import convertQuestsDb
from code.server.utils import cleanServerData

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
    saveSkillTable(users)
    saveInventoryTable(users)
    convertStorage()
    convertAccReg()
    convertParty(users)