# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *
from code.stringutils import *

def convertConsts():
    dstFile = "newserverdata/db/const.txt"
    fieldsSplit = re.compile("\t+")
    fields = dict()
    with open(dstFile, "w") as w:
        srcFile = "serverdata/db/const.txt"
        with open(srcFile, "r") as r:
            for line in r:
                if len(line) < 2 or line[0:2] == "//":
                    continue
                line = line.replace(" ", "\t")
                rows = fieldsSplit.split(line)
                sz = len(rows)
                if sz < 2 or sz > 3:
                    continue

                fields[rows[0]] = rows[1][:-1]
                if sz == 2:
                    w.write("{0}\t{1}".format(rows[0], rows[1]))
                else:
                    w.write("{0}\t{1}\t{2}".format(rows[0], rows[1], rows[2]))

        srcFile = "oldserverdata/db/const.txt"
        w.write("// evol constants\n")
        with open(srcFile, "r") as r:
            for line in r:
                if len(line) < 2 or line[0:2] == "//":
                    continue
                line = line.replace(" ", "\t")
                rows = fieldsSplit.split(line)
                if len(rows) != 2:
                    continue

                if rows[0] in fields:
                    if fields[rows[0]] != rows[1][:-1]:
                        print "warning: different const values for {0} ({1}, {2})".format(rows[0], rows[1][:-1], fields[rows[0]])
                else:
                    w.write("{0}\t{1}".format(rows[0], rows[1]))
