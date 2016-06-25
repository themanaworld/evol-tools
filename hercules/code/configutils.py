# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

def writeIntField(w, name, value):
    if value == "":
        value = "0"
    w.write("    {0}: {1}\n".format(name, value))

def writeIntField2(w, name, value):
    if value == "":
        value = "0"
    w.write("        {0}: {1}\n".format(name, value))

def writeStrField(w, name, value):
    w.write("    {0}: \"{1}\"\n".format(name, value))

def writeCondField2(w, cond, name):
    if cond != 0:
        w.write("        {0}: true\n".format(name))

def writeSubField(w, name, value):
    w.write("        {0}: {1}\n".format(name, value))

def writeFieldArr(w, name, value, value2):
    w.write("    {0}: [{1}, {2}]\n".format(name, value, value2))

def writeFieldList(w, name, value, value2):
    w.write("    {0}: ({1}, {2})\n".format(name, value, value2))

def writeStartBlock(w, text):
    w.write("    {0}: {{\n".format(text))

def writeEndBlock(w):
    w.write("    }\n")

def writeStartScript(w, name):
    w.write("    {0}: <\"\n".format(name))

def writeEndScript(w):
    w.write("    \">\n")

def isHaveData(fields, start, cnt):
    for f in range(0, cnt):
        value = fields[start + f * 2]
        chance = fields[start + f * 2]
        if value == "" or value == "0" or chance == "" or chance == "0":
            continue
        return True
    return False
