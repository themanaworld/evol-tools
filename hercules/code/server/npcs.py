# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *
from code.stringutils import *

mapsConfFile = "newserverdata/conf/maps.conf"
mapsIndexFile = "newserverdata/db/map_index.txt"
npcMainScript = "newserverdata/npc/re/scripts_main.conf"
mapsIndex = 1
scriptRe = re.compile("^(?P<map>[^/](.+))[.]gat,([ ]*)(?P<x>[\d]+),([ ]*)(?P<y>[\d]+),([ ]*)(?P<dir>[\d]+)(|,(?P<gender>[\d]+))" +
    "[\t](?P<tag>script)[\t](?P<name>[\w#' ]+)[\t]"
    "(?P<class>[\d]+)((,((?P<xs>[\d]+),(?P<ys>[\d]+)))|)(|;(?P<size>[\d]+))(|,|;){$")

shopRe = re.compile("^(?P<map>[^/](.+))[.]gat,([ ]*)(?P<x>[\d]+),([ ]*)(?P<y>[\d]+),([ ]*)(?P<dir>[\d]+)(|,(?P<gender>[\d]+))" +
    "[\t](?P<tag>shop)[\t](?P<name>[\w#' ]+)[\t]"
    "(?P<class>[\d]+),(?P<items>(.+))$")

mapFlagRe = re.compile("^(?P<map>[^/](.+))[.]gat" +
    "[ ](?P<tag>mapflag)[ ](?P<name>[\w#']+)(|[ ](?P<flag>.*))$")

class ScriptTracker:
    pass

def createMainScript():
    with open(npcMainScript, "w") as w:
        w.write("import: npc/scripts.conf\n")

def convertNpcs():
    processNpcDir("oldserverdata/npc/", "newserverdata/npc/")

def processNpcDir(srcDir, dstDir):
    makeDir(dstDir)
    files = os.listdir(srcDir)
    for file1 in files:
        if file1[0] == '.':
            continue
        srcPath = os.path.abspath(srcDir + os.path.sep + file1)
        dstPath = os.path.abspath(dstDir + os.path.sep + file1)
        if not os.path.isfile(srcPath):
            processNpcDir(srcPath, dstPath)
        else:
            if file1[-5:] == ".conf" or file1[-4:] == ".txt":
                processNpcFile(srcPath, dstPath)

def processNpcFile(srcFile, dstFile):
#    print "file: " + srcFile
    tracker = ScriptTracker()
    tracker.insideScript = False
    with open(srcFile, "r") as r:
        with open(dstFile, "w") as w:
            tracker.w = w
            for line in r:
                tracker.line = line
                res = convertTextLine(tracker)
                if res:
                    w.write(tracker.line)

def convertTextLine(tracker):
    line = tracker.line
    if line[:5] == "map: ":
        processScriptMapLine(line)
        return False

    idx = line.find("\tscript\t")
    if idx >= 0:
        processScript(tracker)
        return False
    idx = line.find("\tshop\t")
    if idx >= 0:
        processShop(tracker)
        return False
    idx = line.find(".gat mapflag ")
    if idx >= 0:
        processMapFlag(tracker)
        return False
    processStrReplace(tracker)
    return False

def processScriptMapLine(line):
    global mapsIndex
    line = stripNewLine(line)
    if line[-4:] == ".gat":
        line = line[:-4]
    with open(mapsConfFile, "a") as w:
        w.write(line + "\n")

    with open(mapsIndexFile, "a") as w:
        w.write("{0} {1}\n".format(line[5:], mapsIndex))
    mapsIndex = mapsIndex + 1

def writeScript(w, m):
    if m.group("gender") != None:
        w.write("// Gender = {0}\n".format(m.group("gender")));

    if m.group("x") == 0 and m.group("y") == 0 and m.group("class") == 0: # float npc
        w.write("-")
    else:
        w.write("{0},{1},{2},{3}".format(m.group("map"), m.group("x"), m.group("y"), m.group("dir")))
    w.write("\t{0}\t{1}\t{2}".format(m.group("tag"), m.group("name"), m.group("class")));

def processScript(tracker):
    line = tracker.line
    w = tracker.w
    if line[:9] == "function\t":
        tracker.w.write(line)
        return

    m = scriptRe.search(line)
    if m == None:
        print "error in parsing: " + line
        w.write("!!!error parsing line")
        w.write(line)
        return
#    print "source=" + line[:-1]
#    print "map={0} x={1} y={2} dir={3} gender={4} tag={5} name={6} class={7}, xs={8}, ys={9}, size={10}".format(
#        m.group("map"), m.group("x"), m.group("y"), m.group("dir"), m.group("gender"),
#        m.group("tag"), m.group("name"), m.group("class"), m.group("xs"), m.group("ys"), m.group("size"))

    if m.group("size") != None:
        w.write("// Size = {0}\n".format(m.group("size")));
    writeScript(w, m)
    if m.group("xs") != None:
        w.write(",{0},{1}".format(m.group("xs"), m.group("ys")));
    w.write(",{\n");


def processShop(tracker):
    line = tracker.line
    w = tracker.w

    m = shopRe.search(line)
    if m == None:
        print "error in parsing: " + line
        w.write("!!!error parsing line")
        w.write(line)
        return
#    print "source=" + line[:-1]
#    print "map={0} x={1} y={2} dir={3} gender={4} tag={5} name={6} class={7} items={8}".format(
#        m.group("map"), m.group("x"), m.group("y"), m.group("dir"), m.group("gender"),
#        m.group("tag"), m.group("name"), m.group("class"), m.group("items"))

    writeScript(w, m)
    w.write("," + m.group("items") + "\n")

def processMapFlag(tracker):
    line = tracker.line
    w = tracker.w

    m = mapFlagRe.search(line)
    if m == None:
        print "error in parsing: " + line
        w.write("!!!error parsing line")
        w.write(line)
        return
#    print "source=" + line[:-1]
#    print "map={0} tag={1} name={2} flag={3}".format(
#        m.group("map"), m.group("tag"), m.group("name"), m.group("flag"))

    if m.group("name") == "invisible":
        w.write("// {0}\n".format(line));
        return

    w.write("{0}\t{1}\t{2}".format(m.group("map"), m.group("tag"), m.group("name")))
    if m.group("flag") == None:
        w.write("\n")
    else:
        w.write("\t{0}\n".format(m.group("flag")))

def processStrReplace(tracker):
    line = tracker.line
    w = tracker.w
    line = line.replace("setskill ", "addtoskill ")
    line = line.replace("zeny", "Zeny")
    line = line.replace("countitem(", "countitemcolor(")
    idx = line.find("getmapmobs(")
    if idx >= 0:
        idx2 = line.find("\"", idx + len("getmapmobs(") + 1)
        idx3 = line.find(")", idx + len("getmapmobs(") + 1)
        if idx2 + 1 == idx3:
            line = line[:idx2 + 1] + ",\"all\"" + line[idx2 + 1:]

        line = line.replace("getmapmobs(", "mobcount(")
    w.write(line)
