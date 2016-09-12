#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

from sets import Set

from code.server.account import convertAccount
from code.server.accreg import convertAccReg
from code.server.party import convertParty
from code.server.storage import convertStorage
from code.server.db.char import saveCharTableCustom
from code.server.db.charregnumdb import saveCharRegNumDbTable
from code.server.db.inventory import saveInventoryTable
from code.server.db.skill import saveSkillTable
from code.server.tmw.athena import readAthena
from code.server.tmw.consts import convertConsts
from code.server.tmw.itemdb import convertItemDb
from code.server.tmw.mobdb import convertMobDb
from code.server.tmw.mobskilldb import convertMobSkillDb
from code.server.tmw.npcs import createMainScript, convertNpcs
from code.serverutils import cleanServerData

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
#    saveCharTable(users)
    saveCharTableCustom(users)
    saveCharRegNumDbTable(users)
    saveSkillTable(users)
    saveInventoryTable(users)
    convertStorage()
    convertAccReg()
    convertParty(users)
