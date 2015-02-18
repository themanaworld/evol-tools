# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

def stripQuotes(data):
    if len(data) == 0:
        return data
    if data[-1] == "\"":
        data = data[:-1]
    if data[0] == "\"":
        data = data[1:]
    if data[-1] == "'":
        data = data[:-1]
    if data[0] == "'":
        data = data[1:]
    return data

def stripQuotes2(data):
    for idx in xrange(0, len(data)):
        data[idx] = stripQuotes(data[idx])
    return data

def strToXml(data):
    data = data.replace("&", "&amp;");
    data = data.replace("<", "&lt;");
    data = data.replace(">", "&gt;");
    return data

def stripNewLine(data):
    if len(data) == 0:
        return data
    if data[-1] == "\n":
        data = data[:-1]
    return data

def escapeSqlStr(data):
    data = data.replace("'", "\\'");
    data = data.replace("`", "\\`");
    data = data.replace("{", "\\{");
    data = data.replace("}", "\\}");
    return data
