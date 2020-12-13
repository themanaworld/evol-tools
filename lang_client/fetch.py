#! /usr/bin/env python2.7
# -*- coding: utf8 -*-
#
# Copyright (C) 2018  TMW-2
# Author: Jesusalva

from transifex.api import TransifexAPI

project='tmw'

# Load credentials from login.txt and password.txt
login=open('../lang/login.txt', 'r')
for i in login:
    username=i.replace('\n', '').replace('\r', '')

login.close()

passw=open('../lang/password.txt', 'r')
for i in passw:
    password=i.replace('\n', '').replace('\r', '')

passw.close()

t=TransifexAPI(username, password, 'https://www.transifex.com')

if (not t.ping):
    print("ERROR: Ping failed, this may be due incorrect username/password in login.txt and password.txt. Ensure there is NO newline at the end of file. At lang/ folder.")
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
    # Disregarded languages
    if i in ['en', 'vls']:
        continue

    # People translated so we cannot override stuff
    #if i in ['pt_BR', 'vls']:
    #    print("Overriding %s..." %(i))
    #    t.new_translation(project, 'clientdata', i,'../../client-data/translations/'+str(i)+'.po')

    print("Fetching %s..." %(i))
    t.get_translation(project, 'clientdata', i, '../../client-data/translations/'+str(i)+'.po')

    print("Fetching %s dict..." %(i))
    t.get_translation(project, 'clientdata-dict', i, '../../client-data/translations/dict/'+str(i)+'.po')

