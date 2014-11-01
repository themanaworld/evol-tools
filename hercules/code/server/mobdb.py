# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *
from code.stringutils import *

def convertMobDb():
    srcFile = "oldserverdata/db/mob_db.txt"
    dstFile = "newserverdata/db/re/mob_db.txt"
    fieldsSplit = re.compile(",")
    with open(srcFile, "r") as r:
        with open(dstFile, "w") as w:
            for line in r:
#                if len(line) < 2 or line[0] == "#":
                if len(line) < 2:
                    w.write(line)
                    continue
                rows = fieldsSplit.split(line)
                for f in xrange(0, len(rows)):
                    rows[f] = rows[f].strip()
                w.write("{0:<5} {1:<15} {2:<16} {3:<16} {4:<5} {5:<5} {6:<5} "
                        "{7:<5} {8:<5} {9:<7} {10:<5} {11:<5} {12:<5} {13:<5} "
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
                    rows[6] + ",",
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
                    rows[20] + ",",
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

