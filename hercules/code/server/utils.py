# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

from code.fileutils import *

def cleanServerData():
    removeAllFiles("newserverdata")
    makeDir("newserverdata/conf")
    makeDir("newserverdata/db")
