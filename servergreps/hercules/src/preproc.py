#! /usr/bin/env python2
# -*- coding: utf8 -*-
#
# Copyright (C) 2015-2016  Evol Online
# Author: Andrei Karas (4144)

import os
import shutil

class PreProc:
    def init(self, tmpDir):
        if os.path.exists(tmpDir):
            shutil.rmtree(tmpDir)
        os.makedirs(tmpDir)


    def run(self, subDir, outFile):
        os.system(
            "cpp {defines} {includes} {subDir}/{inFile} {outFile}".format(
            defines = self.defines,
            includes = self.includes,
            subDir = self.inDir + subDir,
            inFile = outFile,
            outFile = self.outDir + outFile))
