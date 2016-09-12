#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

from code.servertoclient.homunculuses import convertHomunculuses
from code.servertoclient.items import convertItems
from code.servertoclient.luas import convertLuas
from code.servertoclient.mercenaries import convertMercenaries
from code.servertoclient.monsters import convertMonsters
from code.servertoclient.npcs import convertNpcsNonFree
from code.servertoclient.pets import convertPets
from code.servertoclient.quests import convertQuests
from code.servertoclient.skills import convertSkillsToXml
from code.servertoclient.sprites import convertSpritesNonFree

# non free data
idtofile = convertLuas()
convertSpritesNonFree(idtofile)
convertNpcsNonFree(idtofile)

convertHomunculuses()
convertItems()
convertMercenaries()
convertMonsters(True, idtofile)
convertPets()
convertSkillsToXml()
convertQuests()
