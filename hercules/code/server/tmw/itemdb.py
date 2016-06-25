# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.configutils import *
from code.fileutils import *
from code.stringutils import *

def getItemDbFile(srcDir):
    files = os.listdir(srcDir)
    for srcFile in files:
        if srcFile.find("item_db") >= 0:
            yield srcFile

def replaceStr(line):
    vals = [
        ("setskill ", "addtoskill "),
        ("zeny", "Zeny"),
        ("sc_poison", "SC_POISON"),
        ("sc_slowpoison", "SC_SLOWPOISON"),
        ("sex", "Sex"),
        ("SEX", "Sex"),

        (".gat", ""),
        ("Bugleg", "BugLeg"),
        ("set BugLeg, 0;", "//set BugLeg, 0;"),
        ("set CaveSnakeLamp, 0;", "//set CaveSnakeLamp, 0;"),
        ("set Class, @BaseClass;", "//set Class, @BaseClass;"),
        ("goto_Exit;", "goto L_Exit;"),
        ("if @spants_state < 7 goto", "if(@spants_state < 7) goto"),
        ("isdead()", "ispcdead()"),
        ("changeSex", "changecharsex()"),
        ("getpartnerid2()", "getpartnerid()"),

        ("getmap()", "getmapname()"),
        ("L_end", "L_End"),
        ("gmcommand", "atcommand"),
        ("MF_NOSAVE", "mf_nosave"),
        ("S_update_var", "S_Update_Var"),
        ("L_teach", "L_Teach"),
        ("L_focus", "L_Focus"),
        ("L_unfocus", "L_Unfocus"),
        ("L_main", "L_Main"),
        ("L_next", "L_Next"),
        ("L_close", "L_Close"),
        ("@NpcName$", "@npcname$"),
        ("@cost", "@Cost"),
        ("@TEMP", "@temp"),
        ("L_Menuitems", "L_MenuItems"),
        ("L_no_item", "L_No_Item"),
        ("L_no_water", "L_No_Water"),
        ("L_NOT_ENOUGH", "L_No_Water"),
        ("L_bye", "L_Bye"),
        ("L_NOHELP", "L_NoHelp"),
        ("L_Eyepatch", "L_EyePatch"),
        ("@PC_STAMINA", "@pc_stamina"),
        ("L_magic", "L_Magic"),
        ("L_cont", "L_Cont"),
        ("L_accept", "L_Accept"),
        ("L_no_event", "L_No_Event"),
        ("L_event_done", "L_Event_Done"),
        ("L_nobeer", "L_NoBeer"),
        ("L_iron", "L_Iron"),
        ("L_sulphur", "L_Sulphur"),
        ("L_red", "L_Red"),
        ("L_yellow", "L_Yellow"),
        ("L_green", "L_Green"),
        ("L_orange", "L_Orange"),
        ("L_pink", "L_Pink"),
        ("L_purple", "L_Purple"),
        ("L_question", "L_Question"),
        ("L_quest", "L_Quest"),
        ("L_dead", "L_Dead"),
        ("L_menu", "L_Menu"),
        ("L_give", "L_Give"),
        ("@Items$", "@items$"),
        ("@menuItems$", "@menuitems$"),
        ("L_Teach_initial", "L_Teach_Initial"),
        ("L_finish", "L_Finish"),
        ("L_No_ash", "L_No_Ash"),
        ("L_No_water", "L_No_Water"),
        ("L_cave", "L_Cave"),
        ("L_farewell", "L_Farewell"),
        ("@Q_forestbow_", "@Q_Forestbow_"),
        ("L_game", "L_Game"),
        ("L_good", "L_Good"),
        ("L_abort", "L_Abort"),
        ("@menuID", "@menuid"),
        ("L_NO_ITEM", "L_No_Item"),
        ("L_HELP", "L_Help"),
        ("L_Noitem", "L_NoItem"),
        ("L_No_fur", "L_No_Fur"),
        ("@EXP", "@Exp"),
        ("L_water", "L_Water"),
        ("L_get", "L_Get"),
        ("L_happy", "L_Happy"),
        ("L_cheat", "L_Cheat"),
        ("@Reward_EXP", "@Reward_Exp"),
        ("@REWARD_EXP", "@Reward_Exp"),
        ("L_no_money", "L_No_Money"),
        ("@MinLevel", "@minLevel"),
        ("L_return", "L_Return"),
        ("L_intro", "L_Intro"),
        ("L_full", "L_Full"),
        ("@minlevel", "@minLevel"),
        ("@MinLevel", "@minLevel"),
        ("L_Cleanup", "L_CleanUp"),
        ("L_Alreadystarted", "L_AlreadyStarted"),
        ("@amount", "@Amount"),
        ("L_again", "L_Again"),
        ("L_no_potion", "L_No_Potion"),
        ("L_wizard_hat", "L_Wizard_Hat"),
        ("L_notenough", "L_NotEnough"),
        ("L_offer", "L_Offer"),
        ("L_giveup", "L_GiveUp"),
        ("L_not_ready", "L_Not_Ready"),
        ("@MobID", "@mobId"),
        ("@mobID", "@mobId"),
        ("L_naked", "L_Naked"),
        ("L_shortcut", "L_Shortcut"),
        ("L_shirt", "L_Shirt"),
        ("L_goodjob", "L_GoodJob"),
        ("L_kill", "L_Kill"),
        ("L_nothing", "L_Nothing"),
        ("L_lowlevel", "L_LowLevel"),
        ("@mask", "@Mask"),
        ("Foice", "FoiceItem"),
        ("LanternaJack", "LanternaJackItem"),
        # fix at same time usage with same name function and variable
        ("\"DailyQuestPoints\"", "\"DailyQuestPointsFunc\""),
    ];

    for val in vals:
        line = line.replace(val[0], val[1]);
    return line

def convertItemDb(isNew):
    srcDir = "oldserverdata/world/map/db/"
    dstFile = "newserverdata/db/re/item_db.conf"
    if os.path.isfile(dstFile):
        os.remove(dstFile)
    constsFile = "newserverdata/db/const.txt"
    if os.path.isfile(constsFile):
        os.remove(constsFile)
    fieldsSplit = re.compile(",")
    scriptsSplit = re.compile("},")
    scriptsTextClean = re.compile('([{}])')
    scriptsTextComma = re.compile('^,')
    scriptsTextColon = re.compile('; ')
    items = dict()

    tpl = readFile("templates/item_db.tpl")
    with open(dstFile, "w") as w:
        w.write(tpl)
        with open(constsFile, "a") as c:
            c.write("// items\n");
            for srcFile in getItemDbFile(srcDir):
                with open(srcDir + srcFile, "r") as r:
                    for line in r:
                        if len(line) < 2 or line[0] == "#" or line[0:2] == "//":
                            continue
                        line = replaceStr(line)
                        rows = fieldsSplit.split(line)
                        if len(rows) < 5 or rows[0] == "0":
                            continue

                        sz = len(rows)
                        if sz > 19:
                            sz = 19
                        for f in xrange(0, sz):
                            rows[f] = rows[f].strip()

                        items[rows[1]] = {'id':rows[0],'buy':rows[4],'name':rows[1]}
                        items[rows[0]] = {'id':rows[0],'buy':rows[4],'name':rows[1]}
                        items[int(rows[0])] = {'id':rows[0],'buy':rows[4],'name':rows[1]}
                        # set all values then write
                        w.write("{\n")
                        c.write("{0}\t{1}\n".format(rows[1], rows[0]))
                        writeIntField(w, "Id", rows[0])
                        writeStrField(w, "AegisName", rows[1])
                        if isNew == True:
                            offset = -1
                        else:
                            offset = 0
                        writeStrField(w, "Name", rows[offset + 2])
                        if rows[offset + 3] == "0":
                            itemType = "2"
                        else:
                            itemType = rows[offset + 3]
                        writeIntField(w, "Type", itemType)

                        writeIntField(w, "Buy", rows[offset + 4])
                        if int(rows[offset + 4])*.75 <= int(rows[offset + 5])*1.24:
                            writeIntField(w, "Sell", str(int(rows[offset + 4])*.75))
                        else:
                            writeIntField(w, "Sell", rows[offset + 5])
                        writeIntField(w, "Weight", rows[offset + 6])
                        writeIntField(w, "Atk", rows[offset + 7])
                        writeIntField(w, "Matk", "0")
                        writeIntField(w, "Def", rows[offset + 8])
                        writeIntField(w, "Range", rows[offset + 9])
                        writeIntField(w, "Slots", "0")
                        writeIntField(w, "Job", "0xFFFFFFFF")
                        writeIntField(w, "Upper", "0x3F")
                        writeIntField(w, "Gender", rows[offset + 12])
                        writeIntField(w, "Loc", rows[offset + 13])
                        writeIntField(w, "WeaponLv", rows[offset + 14])
                        writeIntField(w, "EquipLv", rows[offset + 15])
                        writeIntField(w, "Refine", "false")
                        if isNew == True:
                            offset = 2
                        else:
                            offset = 0
                        if rows[offset + 13] == "2":
                            writeIntField(w, "View", "1")
                        elif rows[offset + 13] == "34":
                            writeIntField(w, "View", "11")
                        elif rows[offset + 13] == "32768":
                            writeIntField(w, "View", "1")
                        elif itemType == "4": # weapon
                            writeIntField(w, "View", "1")
                        else:
                            writeIntField(w, "View", rows[0])
                        writeIntField(w, "BindOnEquip", "false")
                        writeIntField(w, "BuyingStore", "false")
                        writeIntField(w, "Delay", "0")
                        writeIntField(w, "Sprite", "0")

                        scripts = ""
                        if isNew == True:
                            offset = -1
                        else:
                            offset = 0
                        for f in xrange(offset + 17, len(rows)):
                            scripts = scripts + ", " + rows[f]
                        rows = scriptsSplit.split(scripts)
                        # Needs .split(';') and \n each 
                        if len(rows) > 1:
                            UseScript = scriptsTextColon.sub(';',scriptsTextComma.sub('', scriptsTextClean.sub('', rows[0]))).strip().split(';')
                            EquipScript = scriptsTextColon.sub(';',scriptsTextComma.sub('', scriptsTextClean.sub('', rows[1]))).strip().split(';')
                        else:
                            UseScript = ""
                            EquipScript = ""
                        # move to for stmt
                        if len(UseScript) > 1:
                            writeStartScript(w, "Script")
                            for uline in UseScript:
                                if len(uline) > 0:
                                    w.write("        {0};\n".format(uline))
                            writeEndScript(w)
                        if len(EquipScript) > 1:
                            writeStartScript(w, "OnEquipScript")
                            for eline in EquipScript:
                                if len(eline) > 0:
                                    w.write("        {0};\n".format(eline))
                            writeEndScript(w)

                        w.write("},\n")
        w.write(")\n")
    return items
