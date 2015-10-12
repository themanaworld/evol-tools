#! /usr/bin/env python2.6
# -*- coding: utf8 -*-

import os
import re

def calcSize(str):
	sz = 0
	for chr in str:
		if chr != '\t':
			sz = sz + 1
	return sz + 1



strre = re.compile(",")
with open ("item_db.txt", "r") as r:
	with open ("item_db2.txt", "w") as w:
		lines = [];
		for line in r:
			arr = strre.split(line)
			if line[0] == '#':
				lines.append(line)
				continue
			text = []
		
			for item in arr:
				text.append(item.strip())

			lines.append(text)

		maxSize = 0
		minSize = 100
		for line in lines:
			if len(line[1]) > 1:
				if len(line) > maxSize:
					maxSize = len(line)
				if len(line) < minSize:
					minSize = len(line)

		minSize = 19
		sizes = []
		for k in range(0, minSize):
			sz = 6
			for line in lines:
				if len(line[k]) > sz:
					sz = len(line[k])
			if sz < 3:
				sz = 4
			elif sz > 6:
				sz = 24
			sizes.append(sz + 1)
	
		print sizes
		for k in range(0, minSize):
			for line in lines:
				if len(line[1]) > 1:
					line[k] = line[k] + ","
					while len(line[k]) < sizes[k]:
						line[k] = line[k] + " "

		for line in lines:
			if len(line[1]) == 1:
				w.write(line)
			else:
				for item in line:
					w.write(item)
				w.write("\n")

		print minSize
		print maxSize

