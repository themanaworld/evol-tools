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
scriptRe = re.compile("^(((?P<map>[^/](.+))([.]gat|),([ ]*)(?P<x>[\d]+),([ ]*)(?P<y>[\d]+),([ ]*)(?P<dir>[\d]+))|(?P<function>function)|-)" +
    "[|](?P<tag>script)[|](?P<name>[^|]+)([|]"
    "(?P<class>[\d-]+)((,((?P<xs>[\d]+),(?P<ys>[\d]+)))|)|)$")

shopRe = re.compile("^(?P<map>[^/](.+))[.]gat,([ ]*)(?P<x>[\d]+),([ ]*)(?P<y>[\d]+),([ ]*)(?P<dir>[\d]+)(|,(?P<gender>[\d]+))" +
    "[|](?P<tag>shop)[|](?P<name>[\w#' ]+)[|]"
    "(?P<class>[\d]+),(?P<items>(.+))$")

mapFlagRe = re.compile("^(?P<map>[^/](.+))[.]gat" +
    "[|](?P<tag>mapflag)[|](?P<name>[\w#']+)(|[|](?P<flag>.*))$")

warpRe = re.compile("^(?P<map>[^/](.+))[.]gat,([ ]*)(?P<x>[\d]+),([ ]*)(?P<y>[\d]+)[|]"
    "(?P<tag>warp)[|](?P<name>[^|]+)[|](?P<xs>[\d-]+),(?P<ys>[\d-]+),(?P<targetmap>[^/](.+))[.]gat,([ ]*)(?P<targetx>[\d]+),([ ]*)(?P<targety>[\d]+)$")

monsterRe = re.compile("^(?P<map>[^/](.+))[.]gat,([ ]*)(?P<x>[\d]+),([ ]*)(?P<y>[\d]+),([ ]*)(?P<xs>[\d-]+),(?P<ys>[\d-]+)[|]"
    "(?P<tag>monster)[|](?P<name>[\w#' ]+)[|]"
    "(?P<class>[\d]+),(?P<num>[\d]+),(?P<delay1>[\d]+)ms,(?P<delay2>[\d]+)ms(|,(?P<label>[\w+-:#]+))$")

setRe = re.compile("^(?P<space>[ ]+)set[ ](?P<var>[^,]+),([ ]*)(?P<val>[^;]+);$");

class ScriptTracker:
    pass

def createMainScript():
    with open(npcMainScript, "w") as w:
        w.write("npc: npc/functions/main.txt\n")
        w.write("import: npc/scripts.conf\n")

def convertNpcs(items):
    processNpcDir("oldserverdata/npc/", "newserverdata/npc/", items)

def processNpcDir(srcDir, dstDir, items):
    makeDir(dstDir)
    files = os.listdir(srcDir)
    for file1 in files:
        if file1[0] == '.':
            continue
        srcPath = os.path.abspath(srcDir + os.path.sep + file1)
        dstPath = os.path.abspath(dstDir + os.path.sep + file1)
        if not os.path.isfile(srcPath):
            processNpcDir(srcPath, dstPath, items)
        else:
            if file1[-5:] == ".conf" or file1[-4:] == ".txt":
                processNpcFile(srcPath, dstPath, items)

def processNpcFile(srcFile, dstFile, items):
#    print "file: " + srcFile
    tracker = ScriptTracker()
    tracker.insideScript = False
    tracker.items = items
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

    if len(line) >= 2 and line[0:2] == "//":
        return False

    idx = line.find("|script|")
    if idx >= 0:
        processScript(tracker)
        return False
    idx = line.find("|shop|")
    if idx >= 0:
        processShop(tracker)
        return False
    idx = line.find("|monster|")
    if idx >= 0:
        processMonster(tracker)
        return False
    idx = line.find("|warp|")
    if idx >= 0:
        processWarp(tracker)
        return False
    idx = line.find("|mapflag|")
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
    try:
        if m.group("function") != None:
            isFunction = True
        else:
            isFunction = False
    except:
        isFunction = False

    if isFunction:
        w.write("function");
    elif m.group("x") == None or (m.group("x") == 0 and m.group("y") == 0): # float npc
        w.write("-")
    else:
        w.write("{0},{1},{2},{3}".format(m.group("map"), m.group("x"), m.group("y"), m.group("dir")))
    if isFunction:
        funcName = m.group("name")
        if funcName == "DailyQuestPoints":
            funcName = "DailyQuestPointsFunc"
        w.write("\t{0}\t{1}\t".format(m.group("tag"), funcName));
    else:
        class_ = m.group("class")
        if class_ == "0": # hidden npc
            class_ = "32767"
        else:
            class_ = int(class_)
#            if class_ > 125 and class_ <= 400:
#                class_ = class_ + 100
        w.write("\t{0}\t{1}\t{2}".format(m.group("tag"), m.group("name"), class_));

def processScript(tracker):
    line = tracker.line[:-1]
    w = tracker.w
    m = scriptRe.search(line)
    if m == None:
        print "error in parsing: " + line
        w.write("!!!error parsing line")
        w.write(line)
        return
#    print "source=" + line
#    print "map={0} x={1} y={2} dir={3} tag={4} name={5} class={6}, xs={7}, ys={8}".format(
#        m.group("map"), m.group("x"), m.group("y"), m.group("dir"),
#        m.group("tag"), m.group("name"), m.group("class"), m.group("xs"), m.group("ys"))

    try:
        if m.group("function") != None:
            isFunction = True
        else:
            isFunction = False
    except:
        isFunction = False

    writeScript(w, m)

    if m.group("xs") != None:
        w.write(",{0},{1}".format(m.group("xs"), m.group("ys")));

    if isFunction == False:
        w.write(",{\n");
    else:
        w.write("{\n");

def itemsToShop(tracker, itemsStr):
    itemsSplit = re.compile(",")
    itemsSplit2 = re.compile(":")
    itemsDict = tracker.items
    outStr = ""
    items = itemsSplit.split(itemsStr)
    for str2 in items:
        parts = itemsSplit2.split(str2)
        if parts[1][0] == "*":
            parts[1] = parts[1][1:]
        if outStr != "":
            outStr = outStr + ","
        outStr = outStr + itemsDict[parts[0].strip()] + ":" + parts[1]
    return outStr

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
#    print "map={0} x={1} y={2} dir={3} tag={4} name={5} class={6} items={7}".format(
#        m.group("map"), m.group("x"), m.group("y"), m.group("dir"),
#        m.group("tag"), m.group("name"), m.group("class"), m.group("items"))

    writeScript(w, m)
    w.write("," + itemsToShop(tracker, m.group("items")) + "\n")

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

    if m.group("name") == "town" or m.group("name") == "resave":
        w.write("//")
    w.write("{0}\t{1}\t{2}".format(m.group("map"), m.group("tag"), m.group("name")))
    if m.group("flag") == None:
        w.write("\n")
    else:
        w.write("\t{0}\n".format(m.group("flag")))

def processWarp(tracker):
    line = tracker.line
    w = tracker.w
    m = warpRe.search(line)
    if m == None:
        print "error in parsing: " + line
        w.write("!!!error parsing line")
        w.write(line)
        return

#    print "source=" + line[:-1]
#    print "map={0} xy={1},{2} tag={3} name={4} xs={5} ys={6}  target: map={7} xy={8},{9}".format(
#        m.group("map"), m.group("x"), m.group("y"), m.group("tag"), m.group("name"), m.group("xs"), m.group("ys"), m.group("targetmap"), m.group("targetx"), m.group("targety"))

    xs = int(m.group("xs"))
    ys = int(m.group("ys"))
    if xs < 0:
        xs = 0
    if ys < 0:
        ys = 0
    w.write("{0},{1},{2},{3}\t{4}\t{5}\t{6},{7},{8},{9},{10}\n".format(
        m.group("map"), m.group("x"), m.group("y"), "0", m.group("tag"), m.group("name"),
        xs, ys, m.group("targetmap"), m.group("targetx"), m.group("targety")))


def processMonster(tracker):
    line = tracker.line
    w = tracker.w
    m = monsterRe.search(line)
    if m == None:
        print "error in parsing: " + line
        w.write("!!!error parsing line")
        w.write(line)
        return

#    print "source=" + line[:-1]
#    print ("map={0} xy={1},{2} xs={3} ys={4} tag={5} name={6} class={7} " +
#        "num={8} delays={9},{10}, label={11}").format(
#        m.group("map"), m.group("x"), m.group("y"), m.group("xs"), m.group("ys"),
#        m.group("tag"), m.group("name"), m.group("class"),
#        m.group("num"), m.group("delay1"), m.group("delay2"), m.group("label"))

    if m.group("label") != None:
        label = "," + m.group("label")
    else:
        label = ""
    w.write("{0},{1},{2},{3},{4}\t{5}\t{6}\t{7},{8},{9},{10}{11}\n".format(m.group("map"),
        m.group("x"), m.group("y"), m.group("xs"), m.group("ys"),
        m.group("tag"), m.group("name"),
        m.group("class"), m.group("num"), m.group("delay1"), m.group("delay2"), label))


def processStrReplace(tracker):
    line = tracker.line
    w = tracker.w
    if line == "{\n":
        return
    line = line.replace("setskill ", "addtoskill ")
    line = line.replace("zeny", "Zeny")
    line = line.replace("sc_poison", "SC_POISON")
    line = line.replace("sc_slowpoison", "SC_SLOWPOISON")
    line = line.replace("countitem(", "countitemcolor(")

    line = line.replace(".gat", "")
    line = line.replace("Bugleg", "BugLeg")
    line = line.replace("set BugLeg, 0;", "//set BugLeg, 0;")
    line = line.replace("set CaveSnakeLamp, 0;", "//set CaveSnakeLamp, 0;")
    line = line.replace("set Class, @BaseClass;", "//set Class, @BaseClass;")
    line = line.replace("goto_Exit;", "goto L_Exit;")
    line = line.replace("if @spants_state < 7 goto", "if(@spants_state < 7) goto")

    line = line.replace("getmap()", "getmapname()")
    line = line.replace("L_end", "L_End")
    line = line.replace("gmcommand", "atcommand")
    line = line.replace("MF_NOSAVE", "mf_nosave")
    line = line.replace("S_update_var", "S_Update_Var")
    line = line.replace("L_teach", "L_Teach")
    line = line.replace("L_focus", "L_Focus")
    line = line.replace("L_unfocus", "L_Unfocus")
    line = line.replace("L_main", "L_Main")
    line = line.replace("L_next", "L_Next")
    line = line.replace("L_close", "L_Close")
    line = line.replace("@NpcName$", "@npcname$")
    line = line.replace("@cost", "@Cost")
    line = line.replace("@TEMP", "@temp")
    line = line.replace("L_Menuitems", "L_MenuItems")
    line = line.replace("L_no_item", "L_No_Item")
    line = line.replace("L_no_water", "L_No_Water")
    line = line.replace("L_NOT_ENOUGH", "L_No_Water")
    line = line.replace("L_bye", "L_Bye")
    line = line.replace("L_NOHELP", "L_NoHelp")
    line = line.replace("L_Eyepatch", "L_EyePatch")
    line = line.replace("@PC_STAMINA", "@pc_stamina")
    line = line.replace("L_magic", "L_Magic")
    line = line.replace("L_cont", "L_Cont")
    line = line.replace("L_accept", "L_Accept")
    line = line.replace("L_no_event", "L_No_Event")
    line = line.replace("L_event_done", "L_Event_Done")
    line = line.replace("L_nobeer", "L_NoBeer")

    # fix at same time usage with same name function and variable
    line = line.replace("\"DailyQuestPoints\"", "\"DailyQuestPointsFunc\"")

    idx = line.find("getmapmobs(")
    if idx >= 0:
        idx2 = line.find("\"", idx + len("getmapmobs(") + 1)
        idx3 = line.find(")", idx + len("getmapmobs(") + 1)
        if idx2 + 1 == idx3:
            line = line[:idx2 + 1] + ",\"all\"" + line[idx2 + 1:]

        line = line.replace("getmapmobs(", "mobcount(")

    m = setRe.search(line);
    if m != None:
        line = "{0}{1} = {2};\n".format(m.group("space"), m.group("var"), m.group("val"))

    w.write(line)

