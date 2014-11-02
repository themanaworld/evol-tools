# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

def writeIntField(w, name, value):
    if value == "":
        value = "0"
    w.write("    {0}: {1}\n".format(name, value))

def writeStrField(w, name, value):
    w.write("    {0}: \"{1}\"\n".format(name, value))

def writeSubField(w, name, value):
    w.write("        {0}: {1}\n".format(name, value));

def writeStartBlock(w, text):
    w.write("    {0}: {{\n".format(text));

def writeEndBlock(w):
    w.write("    }\n");

def writeStartScript(w, name):
    w.write("    {0}: <\"\n".format(name))

def writeEndScript(w):
    w.write("    \">\n")
