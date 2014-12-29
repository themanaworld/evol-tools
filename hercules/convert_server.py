#! /usr/bin/env python
# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

from code.serverutils import *
from code.server.evol.main import *
from code.server.tmw.main import *

serverType = detectServerType()
if serverType == "evol":
    serverEvolMain();
else:
    serverTmwMain();
