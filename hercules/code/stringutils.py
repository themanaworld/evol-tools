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
    if data[-1] == "\r":
        data = data[:-1]
    if len(data) > 0 and data[-1] == "\n":
        data = data[:-1]
    return data

def stripWindows(data):
    if len(data) == 0:
        return data
    if data[-1] == "\r":
        data = data[:-1]
    if len(data) > 1 and data[-2] == "\r":
        data = data[:-2] + data[-1]
    return data

def escapeSqlStr(data):
    data = data.replace("\\", "\\\\");
    data = data.replace("'", "\\'");
    data = data.replace("`", "\\`");
    data = data.replace("{", "\\{");
    data = data.replace("}", "\\}");
    return data

def removeGat(data):
    if len(data) >= 4 and data[-4:] == ".gat":
        data = data[:-4]
    return data
