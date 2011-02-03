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
strre1 = re.compile("[\t +]l[(][\"](?P<str>[^\"]+)[\"][)]")
strre2 =  re.compile("^[^/](.+)[.]gat([^\t]+)[\t](script|shop)[\t](?P<str>[\w ]+)[\t]([\d]+),")

langFiles = dict() 
oldLangFiles = dict()
langs = set()

def collectStrings(parentDir):
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


def loadFiles(dir):
	with open(dir + "/langs.txt", "r") as f:
		for line in f:
			langs.add(line[:-1])

	for file in langs:
		#print dir + "/lang_" + file + ".txt"
		langFiles[file] = parseFile(dir + "/lang_" + file + ".txt")
		oldLangFiles[file] = parseFile(dir + "/lang_" + file + ".old")

def parseFile(name):
	trans = dict()
	if os.path.exists(name):
		with open(name, "r") as f:
			line1 = "";
			line2 = "";
			for line in f:
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
	return trans


def addMissingLines():
	for trans in langFiles:
		newFile = langFiles[trans]
		oldFile = oldLangFiles[trans]
		for str in newFile:
			if str not in allStrings:
				oldFile[str] = newFile[str]
		for str in oldFile:
			if str in newFile:
				del newFile[str]
				print trans + ":moved to old: " + str

	for str in allStrings:
		for trans in langFiles:
			newFile = langFiles[trans]
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
	keys = adict.keys()
	keys.sort()

	for key in keys:
		d2.append ((key, adict[key]))
	return d2

def saveFiles(dir):
	for trans in langFiles:
		writeFile (dir + "/lang_" + trans + ".txt", langFiles[trans])
		writeFile (dir + "/lang_" + trans + ".old", oldLangFiles[trans])

def writeFile(dir, texts):
	with open (dir, "w") as f:
		for line in texts:
			f.write (line[0] + "\n")
			f.write (line[1] + "\n\n")


collectStrings("../../serverdata/npc")
loadFiles("../../serverdata/langs")
addMissingLines()
sorting()
saveFiles("../../serverdata/langs")
