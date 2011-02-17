#! /usr/bin/env python2.6
# -*- coding: utf8 -*-
#
# Copyright (C) 2010-2011  Evol Online

import os
import re
#from sets import Set

defaultLang = "en"
filt = re.compile(".+[.]txt", re.IGNORECASE)

allStrings = set()
strre1 = re.compile("[\t +(]l[(][\"](?P<str>[^\"]+)[\"]")
strre3 = re.compile("[\t +(]getitemlink[(][\"](?P<str>[^\"]+)[\"][)]")
strre2 =  re.compile("^[^/](.+)[.]gat([^\t]+)[\t](script|shop)[\t](?P<str>[\w ]+)[\t]([\d]+),")
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
					m = strre2.search(line)
					if m is not None:
						 allStrings.add(m.group("str"))
					m = strre3.findall(line)
					if len(m) > 0:
						for str in m:
							allStrings.add(itemNamesByName[str.lower()])
							

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
	return (trans, firstLine)


def addMissingLines():
	for trans in langFiles:
		newFile = langFiles[trans][0]
		oldFile = oldLangFiles[trans][0]
		for str in newFile:
			if str not in allStrings:
				if newFile[str] != "":
					oldFile[str] = newFile[str]
		for str in oldFile:
			if str in newFile:
				del newFile[str]
				print trans + ":moved to old: " + str

	for str in allStrings:
		for trans in langFiles:
			newFile = langFiles[trans][0]
			if str not in newFile:
				if trans == defaultLang:
					newFile[str] = str
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
		writeFile (dir + "/lang_" + trans + ".txt", langFiles[trans])
		writeFile (dir + "/lang_" + trans + ".old", oldLangFiles[trans])

def writeFile(dir, texts):
	with open (dir, "w") as f:
		if texts[1] is not None:
			f.write(texts[1])
		for line in texts[0]:
			f.write (line[0] + "\n")
			f.write (line[1] + "\n\n")


def loadItemDb(dir):
	global itemNamesByName
	with open(dir + "/item_db.txt", "r") as f:
		for line in f:
			rows = itemsplit.split(line)
			if len(rows) < 5:
				continue
			itemNamesByName[rows[1].lower().strip()] = rows[2].strip()


loadItemDb("../../privserverdata/db")
collectStrings("../../privserverdata/npc")
loadFiles("../../privserverdata/langs")
addMissingLines()
sorting()
saveFiles("../../privserverdata/langs")
