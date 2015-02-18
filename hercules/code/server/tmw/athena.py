# -*- coding: utf8 -*-
#
# Copyright (C) 2015  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *
from code.stringutils import *
from code.server.dbitem import *
from code.server.dbskill import *
from code.server.dbuser import *

comaSplit = re.compile(",")
spaceSplit = re.compile(" ")

def parseInventory(line, data):
    items = []

    if data == "":
        return items

    rows = spaceSplit.split(data)
    if len(rows) < 1:
        return items

    for data2 in rows:
        if data2 == "":
            continue

        rows2 = comaSplit.split(data2)

        if len(rows2) != 12:
            print "wrong inventory in account.txt line: " + stripNewLine(line)
            continue

        item = Item()

        item.uknownId = rows2[0]
        item.itemId = rows2[1]
        item.amount = rows2[2]
        item.equip = rows2[3]
        item.color = rows2[4]
        item.refine = rows2[5]
        item.attribute = rows2[6]
        item.card0 = rows2[7]
        item.card1 = rows2[8]
        item.card2 = rows2[9]
        item.card3 = rows2[10]
        item.broken = rows2[11]

        items.append(item)

    return items

def parseSkills(line, data):
    skills = []

    if data == "":
        return skills

    rows = spaceSplit.split(data)
    if len(rows) < 1:
        return skills

    for data2 in rows:
        if data2 == "":
            continue

        rows2 = comaSplit.split(data2)

        if len(rows2) != 2:
            print "wrong skills in account.txt line: " + stripNewLine(line)
            continue

        skill = Skill()
        skill.skillId = rows2[0]
        skill.level = int(rows2[1]) & 0xffff
        skill.flags = (int(rows2[1]) * 0xffff) & 0xffff

        skills.append(skill)

    return skills

def parseVars(line, data):
    variables = {}

    if data == "":
        return variables

    rows = spaceSplit.split(data)
    if len(rows) < 1:
        return skills

    for data2 in rows:
        if data2 == "":
            continue

        rows2 = comaSplit.split(data2)

        if len(rows2) != 2:
            print "wrong variables in account.txt line: " + stripNewLine(line)
            continue

        variables[rows2[0]] = rows2[1]

    return variables

def readAthena():
    srcFile = "olddb/athena.txt"
    fieldsSplit = re.compile("\t")

    users = {}
    with open(srcFile, "r") as r:
        for line in r:
            if line[:2] == "//":
                continue
            rows = fieldsSplit.split(line)
            if len(rows) == 2:
                continue
            if len(rows) != 20:
                print "wrong account.txt line: " + stripNewLine(line)
                continue

            user = User()

            user.char_id = rows[0]
            tmp = comaSplit.split(rows[1])
            user.account_id = tmp[0]
            user.char_num = tmp[1]
            user.char_name = rows[2]

            tmp = comaSplit.split(rows[3])
            user.char_class = tmp[0]
            user.base_level = tmp[1]
            user.job_level = tmp[2]

            tmp = comaSplit.split(rows[4])
            user.base_exp = tmp[0]
            user.job_exp = tmp[1]
            user.zeny = tmp[2]

            tmp = comaSplit.split(rows[5])
            user.hp = tmp[0]
            user.max_hp = tmp[1]
            user.sp = tmp[2]
            user.max_sp = tmp[3]

            tmp = comaSplit.split(rows[6])
            user.stat_str = tmp[0]
            user.stat_agi = tmp[1]
            user.stat_vit = tmp[2]
            user.stat_int = tmp[3]
            user.stat_dex = tmp[4]
            user.stat_luk = tmp[5]

            tmp = comaSplit.split(rows[7])
            user.status_point = tmp[0]
            user.skill_point = tmp[1]

            tmp = comaSplit.split(rows[8])
            user.option = tmp[0]
            user.karma = tmp[1]
            user.manner = tmp[2]

            tmp = comaSplit.split(rows[9])
            user.party_id = tmp[0]
            user.guild_id = tmp[1]
            user.pet_id = tmp[2]

            tmp = comaSplit.split(rows[10])
            user.hair = tmp[0]
            user.hair_color = tmp[1]
            user.clothes_color = tmp[2]

            tmp = comaSplit.split(rows[11])
            user.weapon = tmp[0]
            user.shield = tmp[1]
            user.head_top = tmp[2]
            user.head_mid = tmp[3]
            user.head_bottom = tmp[4]

            tmp = comaSplit.split(rows[12])
            user.last_map = tmp[0]
            user.last_x = tmp[1]
            user.last_y = tmp[2]

            tmp = comaSplit.split(rows[13])
            user.save_map = tmp[0]
            user.save_x = tmp[1]
            user.save_y = tmp[2]

            user.partner_id = "0"

            # skip 14

            user.inventory = parseInventory(line, rows[15])

            # skip 16

            user.skills = parseSkills(line, rows[17])

            user.variables = parseVars(line, rows[18])

            users[user.char_id] = user

    return users
