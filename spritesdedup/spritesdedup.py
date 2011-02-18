#! /usr/bin/env python2.6
# -*- coding: utf8 -*-
#
# Copyright (C) 2011  Evol Online
# Author: Andrei Karas (4144)

import os
import re

parentDir = "../../clientdata"
filt = re.compile(".+[.](xml|tmx)", re.IGNORECASE)
filtframe = re.compile(".+(<frame |<sequence )", re.IGNORECASE)
redelay = re.compile(".+delay=[\"](?P<delay>[^\"]+)[\"]")

def haveXml(dir):
	if not os.path.isdir(dir) or not os.path.exists(dir):
		return False
	for file in os.listdir(dir):
		if filt.search(file):
			return True
	return False


def detectClientData(dirs):
	global parentDir
	for dir in dirs:
		if haveXml(dir):
			print "Detected client data directory in: " + dir
			parentDir = dir
			return True
	print "Cant detect client data directory"
	exit(1)


def processXmls(spritesDir):
	files = os.listdir(spritesDir)
	for file1 in files:
		if file1[0] == ".":
			continue
		file2 = os.path.abspath(spritesDir + os.path.sep + file1)
		if not os.path.isfile(file2):
			processXmls(file2)
		elif filt.search(file1):
			processFile(file2, file1)


def processFile(file2, file1):
	arr = list()
	with open(file2, "r") as f:
		for line in f:
			arr.append(line)

	idx = 0
	firstIdx = 0
	lastLine = ""
	changed = False
	while idx < len(arr):
		if filtframe.search(arr[idx]):
			firstIdx = idx
			lastLine = arr[idx]
			dat = findOtherLine(arr, idx)

			idx = dat[0]
			delay = dat[1]
			if delay == 0 or firstIdx + 1 >= idx:
				idx = firstIdx + 1
				continue
			m = redelay.search(lastLine)
			string = lastLine[0:m.start(1)] + str(delay) + lastLine[m.end(1):len(lastLine)]
			arr[firstIdx:idx] = string
			changed = True
			idx = firstIdx

		idx = idx + 1

	if changed == True:
		print "Fixing: " + file1
		with open(file2, "w") as f:
			for line in arr:
				f.write(line)


def findOtherLine(arr, idx):
	firstIdx = idx
	delay = 0
	while idx < len(arr):
		if arr[idx] != arr[firstIdx]:
			return (idx, delay)
		else:
			m = redelay.search(arr[idx])
			if m is None:
				return (idx, delay)
			delay = delay + int(m.group("delay"))
		idx = idx + 1

	return (firstIdx, 0)


print "Detecting clientdata dir"
detectClientData([".", "..", parentDir])
processXmls(parentDir + "/graphics/sprites/")

