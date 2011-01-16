#! /usr/bin/env python2.6
# -*- coding: utf8 -*-

import os
import re
import xml
from xml.dom import minidom
from PIL import Image

filt = re.compile(".+[.]xml", re.IGNORECASE)
dyesplit1 = re.compile(";")
dyesplit2 = re.compile(",")
parentDir = "../../clientdata"
iconsDir = "graphics/items/"
spritesDir = "graphics/sprites/"
errors = 0
warnings = 0
errDict = set()

def printErr(err):
	errDict.add(err)
	print err

def showFileErrorById(id, rootDir, fileDir):
	print "error: id=" + id + ", file not found: " + fileDir + " (" + rootDir + fileDir + ")"

def showFileWarningById(id, rootDir, fileDir):
	print "warn: id=" + id + ", file not found: " + fileDir + " (" + rootDir + fileDir + ")"

def showError(id, text):
	print "error: id=" + id + " " + text

def showWarning(id, text):
	print "warn: id=" + id + " " + text

def showMsg(id, text, iserr):
	global errors, warnings
	if iserr == True:
		if text not in errDict:
			showError(id, text)
			errDict.add(text)
			errors = errors + 1
	else:
		if text not in errDict:
			showWarning(id, text)
			errDict.add(text)
			warnings = warnings + 1

def showMsgSprite(file, text, iserr):
	global errors, warnings
	if iserr == True:
		err = "error: sprite=" + file + " " + text
		if err not in errDict:
			printErr(err)
			errors = errors + 1
	else:
		err = "warn: sprite=" + file + " " + text
		if err not in errDict:
			printErr(err)
			warnings = warnings + 1

def showMsgFile(file, text, iserr):
	global errors, warnings
	if iserr == True:
		err = "error: file=" + file + " " + text
		if err not in errDict:
			printErr(err)
			errors = errors + 1
	else:
		err = "warn: file=" + file + " " + text
		if err not in errDict:
			printErr(err)
			warnings = warnigs + 1
	

def showFileMsgById(id, rootDir, fileDir, iserr):
	global errors, warnings
	if iserr == True:
		showFileErrorById(id, rootDir, fileDir)
		errors = errors + 1
	else:
		showFileWarningById(id, rootDir, fileDir)
		warnings = warnings + 1

def printSeparator():
	print "--------------------------------------------------------------------------------"

def showHeader():
	print "Evol client data validator"
	printSeparator()

def showFooter():
	printSeparator()
	print "Total:"
	print " Warnings: " + str(warnings)
	print " Errors:   " + str(errors)

def enumDirs(parentDir):
	global warnings, errors
	files = os.listdir(parentDir) 
	for file1 in files:
		if file1[0] == ".":
			continue
		file2 = os.path.abspath(parentDir + os.path.sep + file1)
		if not os.path.isfile(file2):
			enumDirs(file2)
		elif filt.search(file1):
			try:
				minidom.parse(file2)
			except xml.parsers.expat.ExpatError as err:
				print "error: " + file2 + ", line=" + str(err.lineno) + ", char=" + str(err.offset)
				errors = errors + 1

def loadPaths():
	try:
		dom = minidom.parse(parentDir + "/paths.xml")
		for node in dom.getElementsByTagName("option"):
			if node.attributes["name"].value == "itemIcons":
				iconsDir = node.attributes["value"].value
			elif node.attributes["name"].value == "sprites":
				spritesDir = node.attributes["value"].value
	except:
		print "warn: paths.xml not found"
		warnings = warnings + 1

def splitImage(image):
	try:
		idx = image.find("|")
		if idx > 0:
			imagecolor = image[idx + 1:]
			image = image[0:idx]
		else:
			imagecolor = ""
	except:
		image = ""
		imagecolor = ""
	return [image, imagecolor]

def testDye(id, color, text, iserr):
	if len(color) < 4:
		showMsg(id, "dye to small size: " + text, iserr)
		return
	colors = dyesplit1.split(color)
	for col in colors:
		if len(col) < 4:
			showMsg(id, "dye to small size: " + text, iserr)
			continue

		c = col[0];
		if col[1] != ":":
			showMsg(id, "incorrect dye string: " + text, iserr)
			continue

		if c != "R" and c != "G" and c != "B" and c != "Y" and c != "M" \
			and c != "C" and c != "W":
				showMsg(id, "incorrect dye color: " + c + " in " + text, iserr)
				continue
		if testDyeInternal(id, col[2:], text, iserr) == False:
			continue


def testDyeInternal(id, col, text, iserr):
	if col[0] != "#":
		showMsg(id, "incorrect dye colors: " + text, iserr)
		return False

	paletes = dyesplit2.split(col[1:])
	for palete in paletes:
		if len(palete) != 6:
			showMsg(id, "incorrect dye palete: " + text, iserr)
			return False
		
		for char in palete.lower():
			if (char < '0' or char > '9') and (char < 'a' or char > 'f'):
				showMsg(id, "incorrect dye palete: " + text, iserr)
				return False
	return True


def testDyeColors(id, color, text, iserr):
	if len(color) < 4:
		showMsg(id, "dye to small size: " + text, iserr)
		return
	colors = dyesplit1.split(color)
	for col in colors:
		if len(col) < 4:
			showMsg(id, "dye to small size: " + text, iserr)
			continue
		if testDyeInternal(id, col, text, iserr) == False:
			continue


def testSprites(id, node, iserr):
	try:
		tmp = node.getElementsByTagName("nosprite")
		if tmp is not None and len(tmp) > 1:
			showMsg(id, "more than one nosprite tag found", iserr)
		nosprite = True
	except:
		nosprite = False

	try:
		sprites = node.getElementsByTagName("sprite")
	except:
		sprites = None
		if nosprite == False:
			showMsg(id, "no sprite tag found", iserr)

	if sprites is not None:
		if len(sprites) == 0:
			if nosprite == False:
				showMsg(id, "no sprite tags found", iserr)
		elif len(sprites) > 3:
			showMsg(id, "incorrect number of sprite tags", iserr)
		elif len(sprites) == 1:
			file = sprites[0].childNodes[0].data
			try:
				gender = sprites[0].attributes["gender"].value
			except:
				gender = ""

			if gender != "" and gender != "unisex":
				showMsg(id, "gender tag in alone sprite", iserr)

			testSprite(id, file, iserr)
		else:
			male = False
			female = False
			for sprite in sprites:
				file = sprite.childNodes[0].data
				try:
					gender = sprite.attributes["gender"].value
				except:
					gender = ""
				if gender == "male":
					if male == True:
						showMsg(id, "double male sprite tag", iserr)
					male = True
				elif gender == "female":
					if female == True:
						showMsg(id, "double female sprite tag", iserr)
					female = True
				elif gender == "unisex":
					if female == True or male == True:
						showMsg(id, "gender sprite tag with unisex tag", False)
					male = True
					female = True
				testSprite(id, file, iserr)
			if male == False:
				showMsg(id, "no male sprite tag", iserr)
			if female == False:
				showMsg(id, "no female sprite tag", iserr)


def testSprite(id, file, iserr):
	tmp = splitImage(file)
	color = tmp[1]
	file2 = tmp[0]
	if color != "":
		testDyeColors(id, color, file, iserr)

	fullPath = os.path.abspath(parentDir + "/" + spritesDir + file2)
	if not os.path.isfile(fullPath) or os.path.exists(fullPath) == False:
		showFileMsgById(id, spritesDir, file2, iserr)
	else:
		testSpriteFile(id, fullPath, file, spritesDir + file2, iserr)

def testSpriteFile(id, fullPath, file, fileLoc, iserr):
	#todo check src dye
	try:
		dom = minidom.parse(fullPath)
	except:
		return

	if len(dom.childNodes) < 1:
		return

	root = dom.childNodes[0];
	imagesets = dom.getElementsByTagName("imageset")
	if imagesets is None or len(imagesets) != 1:
		showMsgSprite(fileLoc, "incorrect number of imageset tags", iserr)
	imageset = imagesets[0]
	
	try:
		image = imageset.attributes["src"].value
		image0 = image
		img = splitImage(image)
		image = img[0]
		imagecolor = img[1]
	except:
		showMsgSprite(fileLoc, "image attribute not exist: " + image, iserr)
		return

	try:
		width = imageset.attributes["width"].value
	except:
		showMsgSprite(fileLoc, "no width attribute", iserr)
		return

	try:
		height = imageset.attributes["height"].value
	except:
		showMsgSprite(fileLoc, "no height attribute", iserr)
	

	fullPath = os.path.abspath(parentDir + "/" + image)
	if not os.path.isfile(fullPath) or os.path.exists(fullPath) == False:
		showMsgSprite(fileLoc, "image file not exist: " + image, iserr)
		return
	sizes = testImageFile(image, fullPath, 0, iserr)
	s = int(sizes[0] / int(width)) * int(width)
	if sizes[0] != s:
		showMsgSprite(fileLoc, "image width " + str(sizes[0]) + \
		" (need " + str(s) + ") is not multiply to frame size " + width + ", image:" + image, False)
	s = int(sizes[1] / int(height)) * int(height)
	if sizes[1] != s:
		showMsgSprite(fileLoc, "image height " + str(sizes[1]) + \
		" (need " + str(s) + ") is not multiply to frame size " + height + ", image:" + image, False)



def testImageFile(file, fullPath, sz, iserr):
	try:
		img = Image.open(fullPath, "r")
		img.load()
	except:
		showMsgFile(file, "incorrect image format", iserr)
		return

	if img.format != "PNG":
		showMsgFile(file, "image format is not png", False)

	sizes = img.size
	if sz != 0:
		if sizes[0] > sz or sizes[1] > sz:
			showMsgFile(file, "image size incorrect (" + str(sizes[0]) \
			+ "x" + str(sizes[1]) + ") should be (" + str(sz) + "x" \
			+ str(sz) + ")", iserr)
	
	return sizes	


def testItems(fileName, imgDir):
	global warnings, errors
	print "Checking items.xml"
	dom = minidom.parse(parentDir + fileName)
	idset = set()
	for node in dom.getElementsByTagName("item"):
		id = node.attributes["id"].value
		if id in idset:
			print "error: duplicated id=" + id
			errors = errors + 1
		else:
			idset.add(id)
			
		idI = int(id)
		try:
			type = node.attributes["type"].value
		except:
			type = ""
			print "warn: no type attribute for id=" + id
			warnings = warnings + 1
		try:
			image = node.attributes["image"].value
			image0 = image
			img = splitImage(image)
			image = img[0]
			imagecolor = img[1]
		except:
			image = ""
			image0 = ""
			imagecolor = ""

		if type == "hairsprite":
			if idI >= 0:
				print "error: hairsprite with id=" + id
				errors = errors + 1
			elif idI < -100:
				print "error: hairsprite override player sprites"
				errors = errors + 1

			testSprites(id, node, True)

		elif type == "racesprite":
			if idI >= 0:
				print "error: racesprite with id=" + id
				errors = errors + 1
			elif idI > -100:
				print "error: racesprite override player hair"
				errors = errors + 1
		elif type == "usable" or type == "unusable" or type == "generic" \
		or type == "equip-necklace" or type == "equip-torso" or type == "equip-feet" \
		or type == "equip-arms" or type == "equip-legs" or type == "equip-head" \
		or type == "equip-shield" or type == "equip-1hand" or type == "equip-2hand" \
		or type == "equip-charm" or type == "equip-ammo" or type == "equip-neck" \
		or type == "equip-ring":
			if image == "":
				print "error: missing image attribute on id=" + id
				errors = errors + 1
				continue
			elif len(imagecolor) > 0:
				testDye(id, imagecolor, "image=" + image0, True)


			fullPath = os.path.abspath(parentDir + "/" + imgDir + image)
			if not os.path.isfile(fullPath) or os.path.exists(fullPath) == False:
				showFileErrorById (id, imgDir, image)
				errors = errors + 1
			else:
				testImageFile(imgDir + image, fullPath, 32, True)

			if type != "usable" and type != "unusable" and type != "generic" \
			and type != "equip-necklace" and type != "equip-1hand" \
			and type != "equip-2hand" and type != "equip-ammo" \
			and type != "equip-charm" and type != "equip-neck":
				err = type != "equip-shield"
				testSprites(id, node, err)
		elif type == "other":
			None
		elif type != "":
			print "warn: unknown type '" + type + "' for id=" + id
			warnings = warnings + 1

showHeader()
print "Checking xml file syntax"
enumDirs("../../clientdata")
loadPaths()
testItems("/items.xml", iconsDir)
showFooter()