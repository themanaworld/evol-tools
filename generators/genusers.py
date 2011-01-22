#! /usr/bin/env python2.6
# -*- coding: utf8 -*-

import os
import re

with open ("save/account.txt", "w") as w:
	w.write("0\ts1\tp1\t2011-01-21 00:08:54.247\tS\t905\t0\ta@a.com\t-\t0\t127.0.0.1\t!\t0\t")
	for f in range(2000000, 2010000):
		w.write(str(f))
		w.write("\t")
		w.write("u" + str(f) + "aaa\t")
		w.write("!aaaaa$aaaaaaaaaaaaaaaaaaaaaaaa")
		w.write("\t2011-01-20 01:09:48.708\tM\t1\t0\t")
		w.write("a@a.com\t-\t0\t127.0.0.1\t!\t0\t\n")
	w.write("2010000\t%newid%\n")

with open ("athena_template.txt") as r:
	template = r.read()
	num = 2 
	with open ("save/athena.txt", "w") as w:
		for f in range(150000, 155000):
			for d in range(0, num):
				w.write(str((f-150000)*num*10 + d + 150000))
				w.write("\t")
				w.write(str(f-150000+2000000))
				w.write(",")
				w.write(str(d))
				w.write("\t")
				w.write("u" + str(f) + "aaa" + str(d))
				w.write(template)
		w.write(str((f-150000)*num*10 + d + 150000 + 1))
		w.write("\t%newid%\n")

