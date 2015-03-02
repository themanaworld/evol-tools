# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re, math

from code.fileutils import *
from code.stringutils import *

def getMobDbFile(srcDir):
    files = os.listdir(srcDir)
    for srcFile in files:
        if srcFile.find("mob_db") >= 0:
            yield srcFile

def convertMobDb():
    srcDir = "oldserverdata/world/map/db/"
    dstFile = "newserverdata/db/re/mob_db.txt"
    fieldsSplit = re.compile(",")
    with open(dstFile, "w") as w:
        for srcFile in getMobDbFile(srcDir):
            with open(srcDir + srcFile, "r") as r:
                for line in r:
                    if len(line) < 2 or line[:2] == "//":
                        w.write(line)
                        continue
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

                    w.write("{0:<5} {1:<23} {2:<23} {3:<23} {4:<5} {5:<6} {6:<3} "
                            "{7:<7} {8:<6} {9:<7} {10:<5} {11:<5} {12:<5} {13:<5} "
                            "{14:<5} {15:<5} {16:<5} {17:<5} {18:<5} {19:<5} {20:<7}"
                            " {21:<7} {22:<6} {23:<5} {24:<8} {25:<8} {26:<6} "
                            "{27:<8} {28:<9} {29:<8} {30:<5} {31:<7} {32:<8} {33:<7}"
                            " {34:<8} {35:<7} {36:<8} {37:<8} {38:<9} {39:<8} "
                            "{40:<9} {41:<8} {42:<9} {43:<8} {44:<9} {45:<8} {46:<9}"
                            " {47:<8} {48:<9} {49:<8} {50:<9} {51:<8} {52:<9} "
                            "{53:<8} {54:<9} {55:<8} {56:<8} \n".format(
                        rows[0] + ",",
                        rows[1] + ",",
                        rows[2] + ",",
                        rows[2] + ",",
                        rows[3] + ",",
                        rows[4] + ",",
                        rows[5] + ",",
                        str(calc_exp) + ",",
                        rows[7] + ",",
                        rows[8] + ",",
                        rows[9] + ",",
                        rows[10] + ",",
                        rows[11] + ",",
                        rows[12] + ",",
                        rows[13] + ",",
                        rows[14] + ",",
                        rows[15] + ",",
                        rows[16] + ",",
                        rows[17] + ",",
                        rows[18] + ",",
                        rows[19] + ",",
                        "10,",
                        rows[21] + ",",
                        rows[22] + ",",
                        rows[23] + ",",
                        rows[24] + ",",
                        rows[25] + ",",
                        rows[26] + ",",
                        rows[27] + ",",
                        rows[28] + ",",
                        rows[45] + ",",
                        rows[47] + ",",
                        rows[48] + ",",
                        rows[49] + ",",
                        rows[50] + ",",
                        rows[51] + ",",
                        rows[52] + ",",
                        rows[29] + ",",
                        rows[30] + ",",
                        rows[31] + ",",
                        rows[32] + ",",
                        rows[33] + ",",
                        rows[34] + ",",
                        rows[35] + ",",
                        rows[36] + ",",
                        rows[37] + ",",
                        rows[38] + ",",
                        rows[39] + ",",
                        rows[40] + ",",
                        rows[41] + ",",
                        rows[42] + ",",
                        rows[43] + ",",
                        rows[44] + ",",
                        "0,",
                        "0,",
                        "0,",
                        "0"
                    ))

