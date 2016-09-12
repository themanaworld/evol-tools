# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import math
import os
import re

from code.configutils import isHaveData, writeCondField2, writeStartBlock, writeEndBlock, writeIntField, writeStrField, writeFieldArr, writeIntField2, writeFieldList, writeSubField
from code.fileutils import readFile

def getMobDbFile(srcDir):
    files = os.listdir(srcDir)
    for srcFile in files:
        if srcFile.find("mob_db") >= 0:
            yield srcFile

def replaceStr(line):
    vals = [
        ("lanternaJack", "LanternaJack"),
        ("foice", "Foice"),
        ("BlueFairy", "BlueFairyMob"),
        ("RedFairy", "RedFairyMob"),
        ("GreenFairy", "GreenFairyMob"),
        ("Scorpion", "ScorpionMob"),
        ("Tritan", "TritanMob"),
        ("Ukar", "UkarMob"),
    ];

    for val in vals:
        line = line.replace(val[0], val[1]);
    return line

def convertMobDb(items):
    srcDir = "oldserverdata/world/map/db/"
    dstFile = "newserverdata/db/re/mob_db.conf"
    fieldsSplit = re.compile(",")
    tpl = readFile("templates/mob_db.tpl")
    with open(dstFile, "w") as w:
        w.write(tpl)
        for srcFile in getMobDbFile(srcDir):
            with open(srcDir + srcFile, "r") as r:
                for line in r:
                    if len(line) < 2 or line[:2] == "//" or line[:1] == "#":
                        w.write(line)
                        continue
                    line = replaceStr(line)
                    rows = fieldsSplit.split(line)
                    for f in xrange(0, len(rows)):
                        rows[f] = rows[f].strip()
                    try:
                        val = int(rows[23])
                        if val < 20:
                            rows[23] = "20"
                    except:
                        None

                    # Experience and Job experience, following *tmw-eathena*/src/map/mob.c
                    calc_exp = 0

                    if rows[6] == "0":
                        if int(rows[4]) <= 1:
                            calc_exp = 1

                        mod_def = 100 - int(rows[11])

                        if mod_def == 0:
                            mod_def = 1

                        effective_hp = ((50 - int(rows[18])) * int(rows[4]) / 50) + (2 * int(rows[18]) * int(rows[4]) / mod_def)
                        attack_factor = (int(rows[9]) + int(rows[10]) + int(rows[13]) / 3 + int(rows[17]) / 2 + int(rows[18])) * (1872 / int(rows[26])) / 4
                        dodge_factor = (int(rows[3]) + int(rows[14]) + int(rows[18]) / 2)**(4 / 3)
                        persuit_factor = (3 + int(rows[8])) * (int(rows[24]) % 2) * 1000 / int(rows[25])
                        aggression_factor = 1

                        if False:
                            aggression_factor = 10 / 9

                        base_exp_rate = 100 # From *tmw-eathena-data*/conf/battle_athena.conf

                        calc_exp = int(math.floor(effective_hp * (math.sqrt(attack_factor) + math.sqrt(dodge_factor) + math.sqrt(persuit_factor) + 55)**3 * aggression_factor / 2000000 * base_exp_rate / 100))

                        if calc_exp < 1:
                            calc_exp = 1
                    else:
                        calc_exp = rows[6]

                    w.write("{\n")
                    writeIntField(w, "Id", rows[0])
                    writeStrField(w, "SpriteName", rows[1])
                    writeStrField(w, "Name", rows[2])
                    writeIntField(w, "Lv", rows[3])
                    writeIntField(w, "Hp", rows[4])
                    writeIntField(w, "Sp", rows[5])
                    writeIntField(w, "Exp", calc_exp)
                    writeIntField(w, "JExp", rows[7])
                    writeIntField(w, "AttackRange", rows[8])
                    writeFieldArr(w, "Attack", rows[9], rows[10])
                    writeIntField(w, "Def", rows[11])
                    writeIntField(w, "Mdef", rows[12])
                    writeStartBlock(w, "Stats")
                    writeIntField2(w, "Str", rows[13])
                    writeIntField2(w, "Agi", rows[14])
                    writeIntField2(w, "Vit", rows[15])
                    writeIntField2(w, "Int", rows[16])
                    writeIntField2(w, "Dex", rows[17])
                    writeIntField2(w, "Luk", rows[18])
                    writeEndBlock(w)
                    writeIntField(w, "ViewRange", rows[19])
                    writeIntField(w, "ChaseRange", 10)
                    writeIntField(w, "Size", rows[21])
                    writeIntField(w, "Race", rows[22])
                    writeFieldList(w, "Element", int(rows[23]) % 10, int(rows[23]) / 20)
                    mode = int(rows[24], 0)
                    if mode != 0:
                        writeStartBlock(w, "Mode")
                        writeCondField2(w, mode & 0x0001, "CanMove")
                        writeCondField2(w, mode & 0x0002, "Looter")
                        writeCondField2(w, mode & 0x0004, "Aggressive")
                        writeCondField2(w, mode & 0x0008, "Assist")
                        writeCondField2(w, mode & 0x0010, "CastSensorIdle")
                        writeCondField2(w, mode & 0x0020, "Boss")
                        writeCondField2(w, mode & 0x0040, "Plant")
                        writeCondField2(w, mode & 0x0080, "CanAttack")
                        writeCondField2(w, mode & 0x0100, "Detector")
                        writeCondField2(w, mode & 0x0200, "CastSensorChase")
                        writeCondField2(w, mode & 0x0400, "ChangeChase")
                        writeCondField2(w, mode & 0x0800, "Angry")
                        writeCondField2(w, mode & 0x1000, "ChangeTargetMelee")
                        writeCondField2(w, mode & 0x2000, "ChangeTargetChase")
                        writeCondField2(w, mode & 0x4000, "TargetWeak")
                        writeCondField2(w, mode & 0x8000, "LiveWithoutMaster")
                        writeEndBlock(w)
                    writeIntField(w, "MoveSpeed", rows[25])
                    writeIntField(w, "AttackDelay", rows[26])
                    writeIntField(w, "AttackMotion", rows[27])
                    writeIntField(w, "DamageMotion", rows[28])
                    writeIntField(w, "MvpExp", rows[45])

                    if isHaveData(rows, 47, 3):
                        writeStartBlock(w, "MvpDrops")
                        for f in range(0, 3):
                            value = rows[47 + f * 2]
                            chance = rows[47 + f * 2]
                            if value == "" or value == "0" or chance == "" or chance == "0":
                                continue
                            value = int(value)
                            if value not in items:
                                w.write("// Error: mvp drop with id {0} not found in item db\n".format(value))
                                print("Error: mvp drop with id {0} not found in item db".format(value))
                            else:
                                writeSubField(w, items[value]["name"], chance)
                        writeEndBlock(w)
                    if isHaveData(rows, 29, 10):
                        writeStartBlock(w, "Drops")
                        for f in range(0, 10):
                            value = rows[29 + f * 2]
                            chance = rows[30 + f * 2]
                            if value == "" or value == "0" or chance == "" or chance == "0":
                                continue
                            value = int(value)
                            if value not in items:
                                w.write("// Error: drop with id {0} not found in item db\n".format(value))
                                print("Error: drop with id {0} not found in item db".format(value))
                            else:
                                writeSubField(w, items[value]["name"], chance)
                        writeEndBlock(w)
                    w.write("},\n")
        w.write(")\n")
