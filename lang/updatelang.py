#! /usr/bin/env python2.6
# -*- coding: utf8 -*-
#
# Copyright (C) 2010-2013  Evol Online
# Author: Andrei Karas (4144)

import os
import re
#from sets import Set

defaultLang = "en"
filt = re.compile(".+[.]txt", re.IGNORECASE)

allStrings = set()
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

def collectStrings(parentDir):
	global itemNamesByName
	files = os.listdir(parentDir) 
	for file1 in files:
		if file1[0] == ".":
			continue
		file2 = os.path.abspath(parentDir + os.path.sep + file1)
		if not os.path.isfile(file2):
			collectStrings(file2)
		elif filt.search(file1):
			with open(file2, "r") as f:
				for line in f:
					m = strre1.findall(line)
					if len(m) > 0:
						for str in m:
							allStrings.add(str)
					m = strre4.findall(line)
					if len(m) > 0:
						for str in m:
							allStrings.add(str + "#0")
							allStrings.add(str + "#1")
					m = strre2.search(line)
					if m is not None and m.group("str")[0] != "#":
						allStrings.add(m.group("str"))
					m = strre3.findall(line)
					if len(m) > 0:
						for str in m:
							if str.lower() in itemNamesByName:
								allStrings.add(itemNamesByName[str.lower()])
					m = strre5.findall(line)
					if len(m) > 0:
						for str in m:
							if str.lower() in itemNamesByName:
								allStrings.add(itemNamesByName[str.lower()])
					m = strre6.findall(line)
					if len(m) > 0:
						for str in m:
							allStrings.add(str)
					m = strre7.findall(line)
					if len(m) > 0:
						for str in m:
							allStrings.add(str[0] + "#0")
							allStrings.add(str[2] + "#1")




def loadFiles(dir):
	with open(dir + "/langs.txt", "r") as f:
		for line in f:
			langs.add(line[:-1])

	for file in langs:
		#print dir + "/lang_" + file + ".txt"
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
		firstLine = "Copyright (C) 2010-2012  Evol Online\n"
	return (trans, firstLine)


def loadPoFiles(podir):
    files = os.listdir(podir)
    for name in files:
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
						if line1 in langFile:
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
#				if newFile[str] != "":
				oldFile[str] = newFile[str]
		for str in oldFile:
			if str in newFile:
				del newFile[str]
				print trans + ":moved to old: " + str

	for str in allStrings:
		for trans in langFiles:
			newFile = langFiles[trans][0]
			oldFile = oldLangFiles[trans][0]
			if str not in newFile:
				if trans == defaultLang:
					newFile[str] = str
				elif str in oldFile:
					newFile[str] = oldFile[str]
				else:
					newFile[str] = ""
				print trans + ":new string: " + str


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

def saveFiles(dir):
	for trans in langFiles:
		writeFile (dir + "/lang_" + trans + ".txt", langFiles[trans], trans, False)
		writeFile (dir + "/lang_" + trans + ".old", oldLangFiles[trans], trans, True)

def writeFile(dir, texts, trans, isold):
	with open (dir, "w") as f:
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

rootPath = "../../server-data/"

loadItemDb(rootPath + "db/re")
collectStrings(rootPath + "/npc")
loadFiles(rootPath + "/langs")
addMissingLines()
loadPoFiles("new");
sorting()
saveFiles(rootPath + "/langs")
