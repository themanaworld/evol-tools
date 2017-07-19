# -*- coding: utf8 -*-
#
# Copyright (C) 2017  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import makeDir, readFile, saveFile

nameSplit = re.compile(":")
comaSplit = re.compile(",")

class Groups:
    pass

def readLine(f):
    for line in f:
        if len(line) == 0:
            continue
        if line[-1:] == "\n":
            line = line[:-1]
        idx = line.find("/*")
        if idx >= 0:
            line = line[:idx]
        line = line.strip()
        yield line

def skipFor(data, f):
    for line in readLine(f):
        if line == data or line == data + "\n":
            return True
    return False

def readCommands(f):
    commands = dict()
    for line in readLine(f):
        if line == "}":
            return commands
        parts = nameSplit.split(line)
        if len(parts) != 2:
            continue
        name = parts[0].strip()
        value = parts[1].strip()
        idx1 = value.find("[")
        if idx1 < 0:
            commands[name] = (value, "false")
        else:
            idx2 = value.find("]")
            value = value[idx1 + 1: idx2 - idx1]
            parts = comaSplit.split(value)
            commands[name] = (parts[0].strip(), parts[1].strip())
        print "command: {0}, {1}".format(name, commands[name])
    return commands

def readPermissions(f):
    permissions = dict()
    for line in readLine(f):
        if line == "}":
            return permissions
        parts = nameSplit.split(line)
        if len(parts) != 2:
            continue
        name = parts[0].strip()
        value = parts[1].strip()
        permissions[name] = value
        print "permission: {0}, {1}".format(name, value)
    return permissions

def readInherit(data):
    inherit = set()
    idx1 = data.find("(")
    idx2 = data.find(")")
    data = data[idx1 + 1: idx2 - idx1]
    parts = comaSplit.split(data)
    for field in parts:
        field = field.strip()
        if field == "":
            continue
        inherit.add(field)
    return inherit

def readGroup(groups, f):
    fields = dict()
    commands = dict()
    permissions = dict()
    for line in readLine(f):
        if line == "}" or line == "},":
            groups.nameToId[fields["name"]] = fields["id"]
            groups.idToFields[fields["id"]] = fields
            groups.idToCommands[fields["id"]] = commands
            groups.idToPermissions[fields["id"]] = permissions
            groups.idToInherit[fields["id"]] = inherit
            groups.idToNames[fields["id"]] = fields["name"]
            return
        parts = nameSplit.split(line)
        if len(parts) != 2:
            continue
        name = parts[0].strip()
        value = parts[1].strip()
        print "line: {0}, {1}".format(name, value)
        if name == "id":
            fields["id"] = value
        elif name == "name":
            fields["name"] = value
        elif name == "commands":
            commands = readCommands(f)
            print "Commands: {0}".format(commands)
        elif name == "permissions":
            permissions = readPermissions(f)
            print "Permissions: {0}".format(permissions)
        elif name == "inherit":
            inherit = readInherit(value)
            print "Inherit: {0}".format(inherit)

def getCommandType(data):
    if data[0] == "false" and data[1] == "false":
        return "false"
    elif data[0] == "false" and data[1] == "true":
        return "other";
    elif data[0] == "true" and data[1] == "false":
        return "self"
    elif data[0] == "true" and data[1] == "true":
        return "both"

def getCommandsStr(commands):
    data = ""
    commandFormat = "\n            <command name=\"{0}\" use=\"{1}\" />"
    for command in commands:
        data = data + commandFormat.format(
            command,
            getCommandType(commands[command])
        )
    return data

def getPermissionsStr(permissions):
    data = ""
    permissionFormat = "\n            <permission name=\"{0}\" />"
    for permission in permissions:
        data = data + permissionFormat.format(
            permission
        )
    return data

def getInheritStr(inherits, names):
    data = ""
    if len(inherits) == 0:
        return ""
    for name in inherits:
        if data != "":
            data = data + ","
        data += names[name]
    return "\n        inherit=\"{0}\"".format(data)

def convertGroups():
    destDir = "clientdata/"
    templatesDir = "templates/"
    groupsConfFile = "serverdata/conf/groups.conf"
    makeDir(destDir)
    tpl = readFile(templatesDir + "group.tpl")
    groupsTpl = readFile(templatesDir + "groups.xml")
    groups = Groups()
    groups.nameToId = dict()
    groups.idToFields = dict()
    groups.idToCommands = dict()
    groups.idToPermissions = dict()
    groups.idToNames = dict()
    groups.idToInherit = dict()

    with open(groupsConfFile, "r") as f:
        skipFor("groups: (", f)
        while (skipFor("{", f) == True):
            readGroup(groups, f)

    data = ""
    for ids in sorted(groups.idToFields):
        data = data + tpl.format(
            id = ids,
            name = groups.idToNames[ids],
            inherit = getInheritStr(groups.idToInherit[ids], groups.nameToId),
            commands = getCommandsStr(groups.idToCommands[ids]),
            permissions = getPermissionsStr(groups.idToPermissions[ids]),
        )

    saveFile(destDir + "groups.xml", groupsTpl.format(data))
