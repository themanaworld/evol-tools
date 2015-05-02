#! /usr/bin/env python2.7
# -*- coding: utf8 -*-
#
# Copyright (C) 2010-2015  Evol Online
# Author: Andrei Karas (4144)

import os
import re

defaultLang = "en"
filt = re.compile(".+[.]txt", re.IGNORECASE)

allStrings = set()
strComments = dict()
strre1 = re.compile("[\t +(]l[(][\"](?P<str>[^\"]+)[\"]")
strre3 = re.compile("[\t +(]getitemlink[(][\"](?P<str>[^\"]+)[\"][)]")
strre2 = re.compile("^[^/](.+)([^\t]+)[\t](script|shop)[\t](?P<str>[^\t]+)[\t]([\d]+),")
strre4 = re.compile("[\t +(]lg[(][\"](?P<str>[^\"]+)[\"][)]")
strre5 = re.compile("[\t +(]getitemname[(][\"](?P<str>[^\"]+)[\"][)]")
strre6 = re.compile("[\t ]mesn[ ][\"](?P<str>[^\"]+)[\"]")
strre7 = re.compile("[\t +(]lg[(][\"](?P<str1>[^\"]+)[\"],([ ]*)[\"](?P<str2>[^\"]+)[\"]")
itemsplit = re.compile(",")

langFiles = dict() 
oldLangFiles = dict()
langs = set()
itemNamesByName = dict()

def addStr(text, comment, fileName, lineNum, addNoC):
    allStrings.add(text)
    if comment[-1:] == "\n":
        comment = comment[:-1]
    if text not in strComments:
        strComments[text] = set()

    strComments[text].add("#. code: " + comment.strip() + "\n")
    strComments[text].add("#: " + fileName + ":" + str(lineNum) + "\n")
    if addNoC == True:
        strComments[text].add("#, no-c-format\n")

def collectScriptStrings(parentDir, relativeDir):
    global itemNamesByName
    files = os.listdir(parentDir) 
    for file1 in files:
        if file1[0] == ".":
            continue
        file2 = os.path.abspath(parentDir + os.path.sep + file1)
        relativeDir2 = relativeDir + os.path.sep + file1
        if not os.path.isfile(file2):
            collectScriptStrings(file2, relativeDir2)
        elif filt.search(file1):
            codeFile = relativeDir + os.path.sep + file1
            with open(file2, "r") as f:
                cnt = -1
                for line in f:
                    cnt = cnt + 1
                    m = strre1.findall(line)
                    if len(m) > 0:
                        for str in m:
                            addStr(str, line, codeFile, cnt, True)
                    m = strre4.findall(line)
                    if len(m) > 0:
                        for str in m:
                            addStr(str + "#0", line, codeFile, cnt, True)
                            addStr(str + "#1", line, codeFile, cnt, True)
                    m = strre2.search(line)
                    if m is not None and m.group("str")[0] != "#":
                        addStr(m.group("str"), line, codeFile, cnt, True)
                    m = strre3.findall(line)
                    if len(m) > 0:
                        for str in m:
                            if str.lower() in itemNamesByName:
                                addStr(itemNamesByName[str.lower()], line, codeFile, cnt, True)
                    m = strre5.findall(line)
                    if len(m) > 0:
                        for str in m:
                            if str.lower() in itemNamesByName:
                                addStr(itemNamesByName[str.lower()], line, codeFile, cnt, True)
                    m = strre6.findall(line)
                    if len(m) > 0:
                        for str in m:
                            addStr(str, line, codeFile, cnt, True)
                    m = strre7.findall(line)
                    if len(m) > 0:
                        for str in m:
                            addStr(str[0] + "#0", line, codeFile, cnt, True)
                            addStr(str[2] + "#1", line, codeFile, cnt, True)


def collectMessages(messagesDir):
    with open(messagesDir, "r") as r:
        cnt = -1
        for line in r:
            cnt = cnt + 1
            if line[:2] == "//":
                continue
            idx = line.find(": ")
            if idx < 1:
                continue
            msgId = line[:idx]
            msgStr = line[idx + 2:]
            if msgStr[-1:] == "\n":
                msgStr = msgStr[:-1]
            addStr(msgStr, line, "conf/messages.conf", cnt, False)

def loadFiles(dir):
    with open(dir + "/langs.txt", "r") as f:
        for line in f:
            langs.add(line[:-1])

    for file in langs:
        langFiles[file] = parseFile(dir + "/lang_" + file + ".txt", True)
        oldLangFiles[file] = parseFile(dir + "/lang_" + file + ".old", False)

def parseFile(name, readFirstLine):
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
                trans[line1] = line2
                line1 = ""
                line2 = ""
    elif readFirstLine:
        firstLine = "Copyright (C) 2010-2015  Evol Online\n"
    return (trans, firstLine)


def loadPoFiles(podir):
    files = os.listdir(podir)
    for name in files:
        if name[-3:] == ".po":
            parsePoFile(name[:-3], podir + "/" + name)


def parsePoFile(name, path):
    langFile = langFiles[name][0]
    with open(path, "r") as f:
        flag = 0
        line1 = ""
        line2 = ""
        for line in f:
            if flag == 0:
                idx = line.find ("msgid ")
                if idx == 0:
                    line2 = ""
                    line1 = line[len("msgid "):]
                    line1 = line1[1:len(line1) - 2]
                    flag = 1
            elif flag == 1:
                idx = line.find ("msgstr ")
                if idx == 0:
                    line2 = line[len("msgstr "):]
                    line2 = line2[1:len(line2) - 2]
                    flag = 2
            if line == "\n":
                if flag == 2:
                    if line1 != "":
                        if line1 in langFile and line2 != "":
                            langFile[line1] = line2.replace("\\\"", "\"");
                    flag = 0

            idx = line.find ("\"")
            if idx == 0:
                line = line[1:len(line) - 2]
                if flag == 1:
                    line1 = line1 + line
                elif flag == 2:
                    line2 = line2 + line



def addMissingLines():
    for trans in langFiles:
        newFile = langFiles[trans][0]
        oldFile = oldLangFiles[trans][0]
        for str in newFile:
            if str not in allStrings:
#                if newFile[str] != "":
                oldFile[str] = newFile[str]
        for str in oldFile:
            if str in newFile:
                del newFile[str]
#                print trans + ":moved to old: " + str

    for str in allStrings:
        for trans in langFiles:
            newFile = langFiles[trans][0]
            oldFile = oldLangFiles[trans][0]
            if str not in newFile:
#                print "lang: " + trans + ", str: " + str
                if trans == defaultLang:
#                    print "newFile[str] = str"
                    newFile[str] = str
                elif str in oldFile:
                    newFile[str] = oldFile[str]
#                    print "newFile[str] = oldFile[str]: " + newFile[str]
                else:
#                    print "newFile[str] = """
                    newFile[str] = ""
#                print trans + ":new string: " + str


def sorting():
    for trans in langFiles:
        newFile = langFiles[trans]
        newFile = sortDict (newFile)
        langFiles[trans] = newFile
        oldFile = oldLangFiles[trans]
        oldFile = sortDict (oldFile)
        oldLangFiles[trans] = oldFile

def sortDict(adict):
    d2 = [] 
    keys = adict[0].keys()
    keys.sort()

    for key in keys:
        d2.append ((key, adict[0][key]))
    return (d2, adict[1])

def saveFiles(langDir, poDir):
    for trans in langFiles:
        writeLangFile (langDir + "/lang_" + trans + ".txt", langFiles[trans], trans, False)
        writeLangFile (langDir + "/lang_" + trans + ".old", oldLangFiles[trans], trans, True)
        writePoFile (poDir, langFiles[trans], trans)

def writeLangFile(langDir, texts, trans, isold):
    with open (langDir, "w") as f:
        if texts[1] is not None:
            f.write(texts[1])
        for line in texts[0]:
            if not isold or (line[1] is not None and len(line[1]) > 0):
                f.write (line[0] + "\n")
                trLine = line[1]
                if trans == "en":
                    if len(trLine) > 2 and (trLine[-2:] == "#0" or trLine[-2:] == "#1"):
                        trLine = trLine[:-2]
                f.write (trLine + "\n\n")

def writePoComments(w, comments):
    for line in comments:
        if line[:3] == "#. ":
            w.write (line)
    for line in comments:
        if line[:3] == "#: ":
            w.write (line)

    for line in comments:
        if line[:3] == "#, ":
            w.write (line)
            break

def writePoFile(poDir, texts, trans):
    if trans == "en":
        langDir = poDir + "/" + trans + ".pot"
    else:
        langDir = poDir + "/" + trans + ".po"

    print langDir
    with open (langDir, "w") as w:
        w.write ("# " + texts[1] + "")
        w.write ("#\n\n")
        w.write ("msgid \"\"\n")
        w.write ("msgstr \"\"\n")
        w.write ("\"Project-Id-Version: EvolOnline\\n\"\n")
        w.write ("\"MIME-Version: 1.0\\n\"\n")
        w.write ("\"Content-Type: text/plain; charset=UTF-8\\n\"\n")
        w.write ("\"Content-Transfer-Encoding: 8bit\\n\"\n")
        w.write ("\n")
        for line in texts[0]:
            if line[0] in strComments.keys():
                writePoComments(w, strComments[line[0]])

            w.write ("msgid \"" + line[0].replace("\"", "\\\"") + "\"\n")
            trLine = line[1]
            if trans == "en":
                if len(trLine) > 2 and (trLine[-2:] == "#0" or trLine[-2:] == "#1"):
                    trLine = trLine[:-2]
            trLine = trLine.replace("\"", "\\\"")
            w.write ("msgstr \"" + trLine + "\"\n\n")

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

def loadItemDb(dir):
    global itemNamesByName
    with open(dir + "/item_db.conf", "r") as f:
        for line in f:
            line = line.strip()
            if line == "{":
                itemId = ""
                itemName = ""
                for line in f:
                    line = line.strip()
                    if line[0] == "}":
                        if itemId != "" and itemName != "":
                            itemNamesByName[itemName.lower()] = itemName
                        break
                    if len(line) > 6 and line[:5] == "Name:":
                        itemName = stripQuotes(line[5:].strip())
                    if len(line) > 4 and line[:3] == "Id:":
                        itemId = stripQuotes(line[3:].strip())

def dumpTranslations():
    for trans in oldLangFiles:
        print "old lang: " + trans
        newFile = oldLangFiles[trans][0]
        for line in newFile:
            print line
            if line in newFile:
                print newFile[line]
            print "\n"
    for trans in langFiles:
        print "new lang: " + trans
        newFile = langFiles[trans][0]
        for line in newFile:
            print line
            if line in newFile:
                print newFile[line]
            print "\n"


def loadMobNames(dir):
    with open(dir + "/mob_db.txt", "r") as r:
        cnt = -1
        for line in r:
            cnt = cnt + 1
            if len(line) < 1 or line[0:2] == "//":
                continue
            parts = itemsplit.split(line)
            if len(parts) < 3:
                continue
            addStr(parts[2].strip(), line, "mob_db.txt", cnt, True)

rootPath = "../../server-data/"

loadItemDb(rootPath + "db/re")
loadMobNames(rootPath + "db/re")
collectScriptStrings(rootPath + "/npc", "npc")
collectMessages(rootPath + "/conf/messages.conf")
loadFiles(rootPath + "/langs")
addMissingLines()
loadPoFiles("in");
#dumpTranslations();
sorting()
saveFiles(rootPath + "/langs", "out")
