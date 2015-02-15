# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import os

def detectServerType():
    if os.path.exists("oldserverdata/world/map/news.d"):
        return "tmw"
    else:
        return "evol"
