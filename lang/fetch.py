#! /usr/bin/env python2.7
# -*- coding: utf8 -*-
#
# Copyright (C) 2018  TMW-2
# Author: Jesusalva

from transifex.api import TransifexAPI

project='tmw'

# Load credentials from login.txt and password.txt
login=open('login.txt', 'r')
for i in login:
    username=i.replace('\n', '').replace('\r', '')

login.close()

passw=open('password.txt', 'r')
for i in passw:
    password=i.replace('\n', '').replace('\r', '')

passw.close()

t=TransifexAPI(username, password, 'https://www.transifex.com')

if (not t.ping):
    print("ERROR: Ping failed, this may be due incorrect username/password in login.txt and password.txt. Ensure there is NO newline at the end of file.")
    exit(1)

if (not t.project_exists(project)):
    print("ERROR: Invalid project name")
    exit(1)

# Load languages
langs=[]
vcx=open("../../server-data/langs/langs.txt", "r")
for i in vcx:
    if i != "en":
        langs.append(i.replace('\n', ''))
vcx.close()

# Fetch all translations and record them at in/
for i in langs:
  if i not in ['en']:
    print("Fetching %s..." %(i))
    t.get_translation(project, 'serverdata', i, 'in/'+str(i)+'.po')


