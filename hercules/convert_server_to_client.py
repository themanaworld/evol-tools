#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

from code.servertoclient.homunculuses import *
from code.servertoclient.items import *
from code.servertoclient.luas import *
from code.servertoclient.mercenaries import *
from code.servertoclient.monsters import *
from code.servertoclient.pets import *
from code.servertoclient.quests import *
from code.servertoclient.skills import *

# non free data
idtofile = convertLuas()

convertHomunculuses()
convertItems()
convertMercenaries()
convertMonsters(True, idtofile)
convertPets()
convertSkillsToXml()
convertQuests()
