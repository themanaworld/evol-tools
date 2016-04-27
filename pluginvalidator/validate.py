#! /usr/bin/env python2.7
# -*- coding: utf8 -*-
#
# Copyright (C) 2015  Evol Online
# Author: Andrei Karas (4144)

import os
import re

serverSrcPath = "../../server-code/src/"
pluginSrcPath = "../../server-plugin/src/"
filtC = re.compile(".+[.]c", re.IGNORECASE)
filtH = re.compile(".+[.]h", re.IGNORECASE)
comaSplit = re.compile(",")

class Session:
    pass

class Status:
    exitCode = 0

def walkFiles(parentDir, session, filt):
    files = os.listdir(parentDir) 
    for file1 in files:
        if file1[0] == ".":
            continue
        file2 = os.path.abspath(parentDir + os.path.sep + file1)
        if not os.path.isfile(file2):
            walkFiles(file2, session, filt)
        elif filt.search(file1):
            session.func(file2, session)


def extractPlugFuncions(path, session):
    with open(path, "r") as f:
        for line in f:
            for s in session.funcList:
                idx = line.find(" " + s)
                if idx < 0:
                    idx = line.find("*" + s)
                if idx > 0 and line.find("__attribute__((nonnull") < 0:
                    if len(line) < idx + len(s) + 1:
                        continue
                    ch = line[idx + len(s) + 1]
                    if ch != '(' and ch != ' ' and ch != '\t':
                        continue
                    data = line
                    if data.find(");") < 0:
                        for line in f:
                            data = data + line
                            if data.find(");") > 1:
                                session.decls[s] = data
                                break
                    else:
                        session.decls[s] = data

def extractFuncFuncions(path, session):
    with open(path, "r") as f:
        for line in f:
            for s in session.funcList:
                idx = line.find(" " + s)
                if idx < 0:
                    idx = line.find("*" + s)
                if idx > 0 and line.find("__attribute__((nonnull") < 0:
                    if len(line) < idx + len(s) + 1:
                        continue
                    ch = line[idx + len(s) + 1]
                    if ch != '(' and ch != ' ' and ch != '\t':
                        continue
                    data = line
                    line2 = line.strip()
                    if len(line2) > 2 and line2[:2] == "//":
                        continue
                    if data.find(")") < 0:
                        for line in f:
                            data = data + line
                            if data.find(")") > 1:
                                session.decls[s] = data
#                                print "'{0}'".format(data)
                                break
                    else:
                        session.decls[s] = data
#                        print "'{0}'".format(data)

def loadHookedList(name):
    funcToPlug = dict()
    plugToFunc = dict()
    with open(name, "r") as f:
        for line in f:
            idx = line.find("addHook")
            if idx > 0:
                idx = line.find(",")
                idx2 = line.find(")")
                plug = line[idx + 1 : idx2].strip()
                func = plug[1:]
                if func[-5:] == "_post":
                    func = func[:-5]
                if func[-4:] == "_pre":
                    func = func[:-4]
                if func not in funcToPlug:
                    funcToPlug[func] = set()
                funcToPlug[func].add(plug);
                if plug not in plugToFunc:
                    plugToFunc[plug] = set()
                plugToFunc[plug].add(func);
    return (funcToPlug, plugToFunc)

def checkMissingFunctions(session):
    for f in session.funcList:
        if f not in session.decls:
            # ignore false positive
            if f != "login_parse_ping":
                print "Missing function {0} and {1}".format(f, session.funcList[f])
                Status.exitCode = 1

def decodeTypes(funcs):
    arr = dict()
    for f in funcs:
        #print "{0}: {1}".format(f, funcs[f])
        fstr = funcs[f]
        idx = fstr.find("(")
        fstr = fstr[fstr.find("(") + 1 : fstr.rfind(")")]
        parts = comaSplit.split(fstr)
        lst = []
        cnt = 0
        if funcs[f][:5] == "void " and f[-5:] == "_post":
            lst.append(("-", "-"))
            cnt = cnt + 1
        for part in parts:
            part = part.strip()
            idx1 = part.rfind(" ")
            idx2 = part.rfind("*")
            if idx2 > idx1:
                idx1 = idx2
            if idx1 < 0:
                old = part
            else:
                # skip retVal first parameters
                if cnt == 0 and part[idx1 + 1:].lower() == "retval" and f[-5:] == "_post":
                    lst.append(("-", "-"))
                    continue
                old = part[:idx1 + 1]
            old = old.replace("\r", "")
            old = old.replace("\n", "")
            part = old.replace(" ", "")
            lst.append((old, part))
            cnt = cnt + 1
            #print "'{0}' -> '{1}'".format(old, part)
        arr[f] = lst
    return arr

def fixParam(param):
    if param[-6:] == "*const":
        param = param[:-5]
    if param == "structmap_session_data*":
        param = "TBL_PC*"
    if param == "structflooritem_data*":
        param = "TBL_ITEM*"
    return param

def compareFuncs(session):
    for func in session.plugDecls:
        pfunc = session.plugDecls[func]
        for func2 in session.plugToFunc[func]:
            if func2 not in session.funcDecls:
                if func2 != "login_parse_ping":
                    print "Error: function {0} not found".format(func2)
                    Status.exitCode = 1
                continue
            ffunc = session.funcDecls[func2]
#            print "{0} - {1}".format(func, func2)
#            print pfunc
#            print ffunc
            if func[-5:] == "_post":
                if pfunc[0][1] != "-":
                    print "Error: missing first retVal parameter in function {0}.".format(func)
                    Status.exitCode = 1
                else:
                    pfunc = pfunc[1:]
            sz1 = len(pfunc)
            sz2 = len(ffunc)
#            print "{0} - {1}".format(sz1, sz2)
            if sz1 != sz2:
                print "Error: wrong number of parameters in function {0}.".format(func)
                Status.exitCode = 1
                continue
            for idx in range(0, sz1):
                pf = pfunc[idx][1]
                ff = ffunc[idx][1]
                pf = fixParam(pf)
                ff = fixParam(ff)
                if ff[-1] != "*" and ff != "void" and ff != "va_list":
                    ff = ff + "*"
#                print pf
#                print ff
                if pf != ff:
                    print "Error: wrong parameters in function {0}.".format(func)
                    Status.exitCode = 1
##                    print "{0} vs {1}".format(pf, ff);
                    break

def processServer(name1, name2):
    (funcToPlug, plugToFunc) = loadHookedList(pluginSrcPath + name2 + "/init.c")
    session = Session()
    session.func = extractPlugFuncions
    session.funcList = plugToFunc
    session.altList = funcToPlug
    session.funcToPlug = funcToPlug
    session.plugToFunc = plugToFunc
    session.decls = dict()
    walkFiles(pluginSrcPath + name2, session, filtH)
    checkMissingFunctions(session)
    session.plugDecls = session.decls
    session.plugDecls = decodeTypes(session.plugDecls)
    #print session.plugDecls

    pluginfunctions = session.decls
    session.func = extractFuncFuncions
    session.funcList = funcToPlug
    session.altList = plugToFunc
    session.decls = dict()
    walkFiles(serverSrcPath + name1, session, filtC)
    checkMissingFunctions(session)
    session.funcDecls = session.decls
    session.funcDecls = decodeTypes(session.funcDecls)
    #print session.funcDecls

    compareFuncs(session)

processServer("login", "elogin")
processServer("char", "echar")
processServer("map", "emap")

exit(Status.exitCode)
