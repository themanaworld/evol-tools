#! /usr/bin/env python2.6
# -*- coding: utf8 -*-
#
# Copyright (C) 2011  Evol Online
# Author: Andrei Karas (4144)

import os
import re

defaultLang = "en"
filt = re.compile(".+[.]txt", re.IGNORECASE)

allStrings = set()
strre1 = re.compile("[\t +(]l[(][\"](?P<str>[^\"]+)[\"]")
strre3 = re.compile("[\t +(]getitemlink[(][\"](?P<str>[^\"]+)[\"][)]")
strre2 =  re.compile("^[^/](.+)[.]gat([^\t]+)[\t](script|shop)[\t](?P<str>[\w ]+)[\t]([\d]+),")

langFiles = dict() 
oldLangFiles = dict()
langs = set()
itemNamesByName = dict()


def loadFiles(dir):
    with open(dir + "/langs.txt", "r") as f:
        for line in f:
            langs.add(line[:-1])

    for file in langs:
        if file == "en":
            langFiles[file] = parseFile(dir + "/lang_" + file + ".txt", True, True)
        else:
            langFiles[file] = parseFile(dir + "/lang_" + file + ".txt", True, False)

def parseFile(name, readFirstLine, isBaseLang):
    trans = dict()
    firstLine = None
    if os.path.exists(name):
        with open(name, "r") as f:
            line1 = "";
            line2 = "";
            for line in f:
                if readFirstLine is True and firstLine is None:
                    firstLine = line
                    continue

                if (line == ""):
                    line1 = ""
                    line2 = ""
                    continue
                elif (line1 == ""):
                    line1 = line[:-1]
                    continue

                line2 = line[:-1]
                if isBaseLang:
                    trans[line1] = line1
                else:
                    trans[line1] = line2
                line1 = ""
                line2 = ""
    return (trans, firstLine)


def saveFiles(name):
    for filen in langFiles:
        saveFile(name, filen)


def saveFile(path, name):
    print str(name) 
    with open (path + "/" + name + ".po", "w") as w:
        lang = langFiles[name]
        w.write ("# " + lang[1] + "")
        w.write ("#\n\n")
        w.write ("msgid \"\"\n")
        w.write ("msgstr \"\"\n")
        w.write ("\"Project-Id-Version: EvolOnline\\n\"\n")
        w.write ("\"MIME-Version: 1.0\\n\"\n")
        w.write ("\"Content-Type: text/plain; charset=UTF-8\\n\"\n")
        w.write ("\"Content-Transfer-Encoding: 8bit\\n\"\n")
        w.write ("\n")
        for line in lang[0].keys():
            line2 = line.replace("\"", "\\\"")
            w.write ("msgid \"" + line2 + "\"\n")
            line2 = lang[0][line].replace("\"", "\\\"")
            w.write ("msgstr \"" + line2 + "\"\n\n")


rootPath = "../../server-data"

loadFiles(rootPath + "/langs")
saveFiles("out")

