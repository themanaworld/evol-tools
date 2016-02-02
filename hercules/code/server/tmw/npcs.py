# -*- coding: utf8 -*-
#
# Copyright (C) 2014  Evol Online
# Author: Andrei Karas (4144)

import re

from code.fileutils import *
from code.stringutils import *

mapsConfFile = "newserverdata/conf/maps.conf"
if os.path.isfile(mapsConfFile):
    os.remove(mapsConfFile)
mapsIndexFile = "newserverdata/db/map_index.txt"
if os.path.isfile(mapsIndexFile):
    os.remove(mapsIndexFile)
npcMainScript = "newserverdata/npc/re/scripts_main.conf"
mapsIndex = 1
scriptRe = re.compile("^(((?P<map>[^/](.+)),([ ]*)(?P<x>[\d]+),([ ]*)(?P<y>[\d]+),([ ]*)(?P<dir>[\d]+))|(?P<function>function)|-)" +
    "[|](?P<tag>script)[|](?P<name>[^|]+)([|]"
    "(?P<class>[\d-]+)((,((?P<xs>[\d]+),(?P<ys>[\d]+)))|)|)$")

scriptRe2 = re.compile("^(((?P<map>[^/](.+))[.]gat,([ ]*)(?P<x>[\d]+),([ ]*)(?P<y>[\d]+),([ ]*)(?P<dir>[\d]+))|(?P<function>function)|-)" +
    "[\t](?P<tag>script)[\t](?P<name>[\w#'\\[\\]_ äü.-]+)[\t]"
    "(((?P<class>[\d-]+)((,((?P<xs>[\d-]+),(?P<ys>[\d-]+)))|)(|,)(|[ \t]))|){(|[ ])$")

shopRe = re.compile("^(?P<map>[^/](.+)),([ ]*)(?P<x>[\d]+),([ ]*)(?P<y>[\d]+),([ ]*)(?P<dir>[\d]+)(|,(?P<gender>[\d]+))" +
    "[|](?P<tag>shop)[|](?P<name>[\w#' ]+)[|]"
    "(?P<class>[\d]+),(?P<items>(.+))$")

shopRe2 = re.compile("^(?P<map>[^/](.+))[.]gat,([ ]*)(?P<x>[\d]+),([ ]*)(?P<y>[\d]+),([ ]*)(?P<dir>[\d]+)" +
    "[\t](?P<tag>shop)[\t](?P<name>[\w#'\\[\\] ]+)[\t]"
    "(?P<class>[\d]+),(?P<items>(.+))$")

mapFlagRe = re.compile("^(?P<map>[^/](.+))" +
    "[|](?P<tag>mapflag)[|](?P<name>[\w#']+)(|[|](?P<flag>.*))$")

mapFlagRe2 = re.compile("^(?P<map>[^/](.+))[.]gat" +
    "[ ](?P<tag>mapflag)[ ](?P<name>[\w#']+)(|[ ](?P<flag>.*))$")

warpRe = re.compile("^(?P<map>[^/](.+)),([ ]*)(?P<x>[\d]+),([ ]*)(?P<y>[\d]+)[|]"
    "(?P<tag>warp)[|](?P<name>[^|]+)[|](?P<xs>[\d-]+),(?P<ys>[\d-]+),(?P<targetmap>[^/](.+)),([ ]*)(?P<targetx>[\d]+),([ ]*)(?P<targety>[\d]+)$")

warpRe2 = re.compile("^(?P<map>[^/](.+))[.]gat,([ ]*)(?P<x>[\d]+),([ ]*)(?P<y>[\d]+)([\t]+)"
    "(?P<tag>warp)[\t](?P<name>[^\t]+)([\t]+)(?P<xs>[\d-]+),(?P<ys>[\d-]+),(?P<targetmap>[^/](.+))[.]gat,([ ]*)(?P<targetx>[\d]+),([ ]*)(?P<targety>[\d]+)$")

monsterRe = re.compile("^(?P<map>[^/](.+)),([ ]*)(?P<x>[\d]+),([ ]*)(?P<y>[\d]+),([ ]*)(?P<xs>[\d-]+),(?P<ys>[\d-]+)[|]"
    "(?P<tag>monster)[|](?P<name>[\w#' ]+)[|]"
    "(?P<class>[\d]+),(?P<num>[\d]+),(?P<delay1>[\d]+)ms,(?P<delay2>[\d]+)ms(|,(?P<label>[\w+-:#]+))$")

monsterRe2 = re.compile("^(?P<map>[^/](.+))[.]gat,([ ]*)(?P<x>[\d]+),([ ]*)(?P<y>[\d]+),([ ]*)(?P<xs>[\d-]+),(?P<ys>[\d-]+)\t"
    "(?P<tag>monster)[\t](?P<name>[\w#' ]+)([\t]+)"
    "(?P<class>[\d]+),(?P<num>[\d]+),(?P<delay1>[\d]+),(?P<delay2>[\d]+)(|,(?P<label>[\w+-:#]+))$")

setRe = re.compile("^(?P<space>[ ]+)set[ ](?P<var>[^,]+),([ ]*)(?P<val>[^;]+);$");

class ScriptTracker:
    pass

def createMainScript():
    with open(npcMainScript, "w") as w:
        w.write("npc: npc/functions/main.txt\n")
        w.write("import: npc/scripts.conf\n")

def convertNpcs(items, npcIds):
    processNpcDir("oldserverdata/world/map/npc/", "newserverdata/npc/", items, npcIds)

def processNpcDir(srcDir, dstDir, items, npcIds):
    makeDir(dstDir)
    files = os.listdir(srcDir)
    for file1 in files:
        if file1[0] == '.':
            continue
        srcPath = os.path.abspath(srcDir + os.path.sep + file1)
        dstPath = os.path.abspath(dstDir + os.path.sep + file1)
        if not os.path.isfile(srcPath):
            processNpcDir(srcPath, dstPath, items, npcIds)
        else:
            if file1[-5:] == ".conf" or file1[-4:] == ".txt":
                processNpcFile(srcPath, dstPath, items, npcIds)

def processNpcFile(srcFile, dstFile, items, npcIds):
#    print "file: " + srcFile
    tracker = ScriptTracker()
    tracker.insideScript = False
    tracker.items = items
    tracker.npcIds = npcIds
    with open(srcFile, "r") as r:
        with open(dstFile, "w") as w:
            tracker.w = w
            for line in r:
                line = stripWindows(line)
                tracker.line = line
                res = convertTextLine(tracker)
                if res:
                    w.write(tracker.line)

def convertTextLine(tracker):
    line = tracker.line
    if line[:5] == "map: ":
        processScriptMapLine(line)
        return False

    if len(line) >= 2 and line[0:2] == "//":
        return False

    if line == "};\n":
        tracker.w.write("}\n");
        return False

    idx = line.find("|script|")
    if idx <= 0:
        idx = line.find("\tscript\t")
    if idx >= 0:
        processScript(tracker)
        return False
    idx = line.find("|shop|")
    if idx <= 0:
        idx = line.find("\tshop\t")
    if idx >= 0:
        processShop(tracker)
        return False
    idx = line.find("|monster|")
    if idx <= 0:
        idx = line.find("\tmonster\t")
    if idx >= 0:
        processMonster(tracker)
        return False
    idx = line.find("|warp|")
    if idx <= 0:
        idx = line.find("\twarp\t")
    if idx >= 0:
        processWarp(tracker)
        return False
    idx = line.find("|mapflag|")
    if idx <= 0:
        idx = line.find(".gat mapflag ")
    if idx >= 0:
        processMapFlag(tracker)
        return False
    processStrReplace(tracker)
    return False

def processScriptMapLine(line):
    global mapsIndex
    line = stripNewLine(line)
    if line[-4:] == ".gat":
        line = line[:-4]
    with open(mapsConfFile, "a") as w:
        w.write(line + "\n")

    with open(mapsIndexFile, "a") as w:
        w.write("{0} {1}\n".format(line[5:], mapsIndex))
    mapsIndex = mapsIndex + 1

def writeScript(w, m, npcIds):
    try:
        if m.group("function") != None:
            isFunction = True
        else:
            isFunction = False
    except:
        isFunction = False

    if isFunction:
        w.write("function");
    elif m.group("x") == None or (m.group("x") == 0 and m.group("y") == 0): # float npc
        w.write("-")
    else:
        w.write("{0},{1},{2},{3}".format(m.group("map"), m.group("x"), m.group("y"), m.group("dir")))
    if isFunction:
        funcName = m.group("name")
        if funcName == "DailyQuestPoints":
            funcName = "DailyQuestPointsFunc"
        w.write("\t{0}\t{1}\t".format(m.group("tag"), funcName));
    else:
        class_ = m.group("class")
        if class_ == "0": # hidden npc
            class_ = 32767
        else:
            class_ = int(class_)
#            if class_ > 125 and class_ <= 400:
#                class_ = class_ + 100
        npcIds.add(int(class_))
        if class_ == -1:
            class_ = "MINUS1"
        w.write("\t{0}\t{1}\tNPC{2}".format(m.group("tag"), m.group("name"), class_));

def processScript(tracker):
    line = tracker.line[:-1]
    w = tracker.w

    m = scriptRe.search(line)
    if m == None:
        m = scriptRe2.search(line)
    if m == None:
        print "error in parsing: " + line
        w.write("!!!error parsing line")
        w.write(line)
        return
#    print "source=" + line
#    print "map={0} x={1} y={2} dir={3} tag={4} name={5} class={6}, xs={7}, ys={8}".format(
#        m.group("map"), m.group("x"), m.group("y"), m.group("dir"),
#        m.group("tag"), m.group("name"), m.group("class"), m.group("xs"), m.group("ys"))
    # debug

    try:
        if m.group("function") != None:
            isFunction = True
        else:
            isFunction = False
    except:
        isFunction = False

    writeScript(w, m, tracker.npcIds)

    if m.group("xs") != None:
        w.write(",{0},{1}".format(m.group("xs"), m.group("ys")));

    if isFunction == False:
        w.write(",{\n");
    else:
        w.write("{\n");

def itemsToShop(tracker, itemsStr):
    itemsSplit = re.compile(",")
    itemsSplit2 = re.compile(":")
    itemsDict = tracker.items
    outStr = ""
    items = itemsSplit.split(itemsStr)
    for str2 in items:
        parts = itemsSplit2.split(str2)
        if len(parts) != 2:
            print "Wrong shop item name {0}: {1}".format(str2, itemsStr)
            continue
        if parts[1][0] == "*":
            parts[1] = str((int(parts[1][1:]) * int(itemsDict[parts[0].strip()]['buy'])))
        if outStr != "":
            outStr = outStr + ","
        itemName = parts[0].strip()
        if itemName in itemsDict:
            outStr = outStr + itemsDict[itemName]['id'] + ":" + parts[1]
        else:
            print "Wrong item name in shop: {0}".format(itemName)
    return outStr

def processShop(tracker):
    line = tracker.line
    w = tracker.w

    m = shopRe.search(line)
    if m == None:
        m = shopRe2.search(line)
    if m == None:
        print "error in parsing: " + line
        w.write("!!!error parsing line")
        w.write(line)
        return

#    print "source=" + line[:-1]
#    print "map={0} x={1} y={2} dir={3} tag={4} name={5} class={6} items={7}".format(
#        m.group("map"), m.group("x"), m.group("y"), m.group("dir"),
#        m.group("tag"), m.group("name"), m.group("class"), m.group("items"))

    writeScript(w, m, tracker.npcIds)
    w.write("," + itemsToShop(tracker, m.group("items")) + "\n")

def processMapFlag(tracker):
    line = tracker.line
    w = tracker.w

    m = mapFlagRe.search(line)
    if m == None:
        m = mapFlagRe2.search(line)
    if m == None:
        print "error in parsing: " + line
        w.write("!!!error parsing line")
        w.write(line)
        return
#    print "source=" + line[:-1]
#    print "map={0} tag={1} name={2} flag={3}".format(
#        m.group("map"), m.group("tag"), m.group("name"), m.group("flag"))

    if m.group("name") == "town" or m.group("name") == "resave":
        w.write("//")
    w.write("{0}\t{1}\t{2}".format(m.group("map"), m.group("tag"), m.group("name")))
    if m.group("flag") == None:
        w.write("\n")
    else:
        w.write("\t{0}\n".format(m.group("flag")))

def processWarp(tracker):
    line = tracker.line
    w = tracker.w
    m = warpRe.search(line)
    if m == None:
        m = warpRe2.search(line)
    if m == None:
        print "error in parsing: " + line
        w.write("!!!error parsing line")
        w.write(line)
        return

#    print "source=" + line[:-1]
#    print "map={0} xy={1},{2} tag={3} name={4} xs={5} ys={6}  target: map={7} xy={8},{9}".format(
#        m.group("map"), m.group("x"), m.group("y"), m.group("tag"), m.group("name"), m.group("xs"), m.group("ys"), m.group("targetmap"), m.group("targetx"), m.group("targety"))

    xs = int(m.group("xs"))
    ys = int(m.group("ys"))
    if xs < 0:
        xs = 0
    if ys < 0:
        ys = 0
    w.write("{0},{1},{2},{3}\t{4}\t{5}\t{6},{7},{8},{9},{10}\n".format(
        m.group("map"), m.group("x"), m.group("y"), "0", m.group("tag"), m.group("name"),
        xs, ys, m.group("targetmap"), m.group("targetx"), m.group("targety")))


def processMonster(tracker):
    line = tracker.line
    w = tracker.w
    m = monsterRe.search(line)
    if m == None:
        m = monsterRe2.search(line)
    if m == None:
        print "error in parsing: " + line
        w.write("!!!error parsing line")
        w.write(line)
        return

#    print "source=" + line[:-1]
#    print ("map={0} xy={1},{2} xs={3} ys={4} tag={5} name={6} class={7} " +
#        "num={8} delays={9},{10}, label={11}").format(
#        m.group("map"), m.group("x"), m.group("y"), m.group("xs"), m.group("ys"),
#        m.group("tag"), m.group("name"), m.group("class"),
#        m.group("num"), m.group("delay1"), m.group("delay2"), m.group("label"))

    if m.group("label") != None:
        label = "," + m.group("label")
    else:
        label = ""
    w.write("{0},{1},{2},{3},{4}\t{5}\t{6}\t{7},{8},{9},{10}{11}\n".format(m.group("map"),
        m.group("x"), m.group("y"), m.group("xs"), m.group("ys"),
        m.group("tag"), m.group("name"),
        m.group("class"), m.group("num"), m.group("delay1"), m.group("delay2"), label))


def processStrReplace(tracker):
    line = tracker.line
    w = tracker.w
    if line == "{\n":
        return
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
        ("getpartnerid2(0)", "getpartnerid()"),
        ("getgmlevel(0)", "getgmlevel()"),
        ("if @beer_count > 4", "if (@beer_count > 4)"),
        ("if !(@Q_status)", "if (!(@Q_status))"),
        ("if isin(\"021-1\", 130, 120, 140, 125) ", "if (isin(\"021-1\", 130, 120, 140, 125)) "),
        ("if divorce(0) goto L_", "if (divorce()) goto L_"),

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
        ("@npcName$", "@npcname$"),
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
        ("L_no_ash", "L_No_Ash"),
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
        ("L_MENU", "L_Menu"),
        ("L_potion", "L_Potion"),
        ("L_fertig", "L_Fertig"),
        ("L_exit", "L_Exit"),
        ("L_fight", "L_Fight"),
        ("L_start", "L_Start"),
        ("L_unvollst", "L_Unvollst"),
        ("L_no_room_for_rings", "L_No_Room_For_Rings"),
        ("@mask", "@Mask"),
        ("@MAP$", "@map$"),
        ("baselevel", "BaseLevel"),
        ("L_Lifestones_Trade_Missing", "L_Lifestones_TM"),
        ("L_Caretaker_first_reward", "L_Caretaker_fr"),
        ("L_NohMask_TravelingTroupe", "L_NohMask_TravT"),
        ("L_listen_to_a_story_first", "L_listen_to_sf"),
        ("L_post_ironpowder_option", "L_post_ip_op"),
        ("L_Sulphur_teach_spell_no", "L_Sulphur_tspell"),
        ("L_Lifestones_MakeSelf_yes", "L_Lifestones_MSy"),
        ("L_Lifestones_MakeSelf_no", "L_Lifestones_MSn"),
        ("L_Caretaker_later_rewards", "L_Caretaker_lr"),
        ("L_boneknife_quest_completed", "L_boneknife_qc"),
        ("L_boneknife_quest_tooweak", "L_boneknife_qtw"),
        ("L_tanktop_insufficient_cloth", "L_tanktop_ic"),
        ("L_dark_green_q_toolittle", "L_dark_greenqtit"),
        ("L_about_schools_minimenu", "L_about_sch_mm"),
        ("L_insufficient_BaseLevel", "L_insuf_BL"),
        ("L_Teach_Initial_nonature", "L_Teach_Ininn"),
        ("L_Teach_CheckAdvanceTo2_fail", "L_Teach_CATo2f"),
        ("L_Levelup2_must_practice", "L_Levelup2_mpr"),
        ("L_Airlia_intro_mana_loss", "L_Airlia_iml"),
        ("L_knife_quest_completecheck", "L_knife_q_cc"),
        ("L_Magic_purify_explained", "L_Magic_pur_exp"),
        ("L_tanktop_insufficient_Zeny", "L_tanktop_ins_Z"),
        ("L_monster_oil_knows_recipe", "L_monsteroil_kn_r"),
        ("L_Teach_CheckAdvanceToLOH", "L_TeachChATLOH"),
        ("L_knife_quest_missing_stingers", "L_knife_qm_sti"),
        ("L_Magic_train_tree_backgd", "L_Mag_tr_tr_ba"),
        ("SUB_pick_one_of_many_items", "SUB_pick_1_m_it"),
        ("L_about_other_prerequisites", "L_a_o_prereq"),
        ("L_monster_oil_why_dangerous", "L_monstero_w_dang"),
        ("L_Teach_LOH_advance_abort0", "L_Teach_LOH_a_a0"),
        ("L_Teach_LOH_advance_abort1", "L_Teach_LOH_a_a1"),
        ("L_knife_quest_missing_mushrooms", "L_knife_q_m_mushr"),
        ("L_Magic_train_sagatha_fail", "L_Magic_tsag_f"),
        ("L_Q_manaseed_touched_short", "L_Q_manas_tou_sh"),
        ("L_monster_oil_ingredients", "L_monsoil_ingr"),
        ("L_snakeskins_completecheck", "L_snakes_comc"),
        ("L_Magic_train_sagatha_lvl1", "L_Mag_tr_sag_lvl1"),
        ("L_make_mana_potion_missing", "L_make_m_p_mis"),
        ("L_monster_oil_where_gold", "L_monoil_wg"),
        ("L_golden_scorpion_wrestle_intro", "L_gold_scor_wr_i"),
        ("L_component_quest_missing", "L_comp_q_mis"),
        ("L_monster_oil_start_brew", "L_monsto_st_br"),
        ("L_golden_requires_knife_quest_done", "L_gold_req_kn_q_d"),
        ("LL_student_4_wrong_potion", "L_stud_4_wrong_p"),
        ("L_monster_oil_missing_gold", "L_monsto_mis_g"),
        ("L_golden_requires_knife_quest", "L_gold_req_kn_q"),
        ("LL_Magic_skill_insufficient", "L_Mag_sk_insuf"),
        ("L_monster_oil_out_of_leaves", "L_monso_oo_lea"),
        ("L_too_lowlevel_for_stinger", "L_too_lol_f_sti"),
        ("L_monster_oil_leaf_color", "L_monso_le_co"),
        ("L_golden_scorpion_over_ask", "L_gold_scor_ov_a"),
        ("S_monster_oil_random_move", "L_monso_rand_mo"),
        ("L_golden_scorpion_ask_again", "L_gold_scor_as_ag"),
        ("L_monster_oil_random_0_lighten", "L_monso_rand_0_li"),
        ("L_golden_scorpion_wrestle_again", "L_gold_scorp_wre_ag"),
        ("L_monster_oil_explode_dodge", "L_monso_expl_dod"),
        ("L_golden_scorpion_wrestle", "L_gold_scorp_wre"),
        ("L_monster_oil_no_gold_end", "L_monso_no_go_e"),
        ("L_mopox_cure_", "L_moc_"),
        ("L_mopox_failed_", "L_mof_"),
        # fix at same time usage with same name function and variable
        ("\"DailyQuestPoints\"", "\"DailyQuestPointsFunc\""),
    ];

    for val in vals:
        line = line.replace(val[0], val[1]);

    idx = line.find("getmapmobs(")
    if idx >= 0:
        idx2 = line.find("\"", idx + len("getmapmobs(") + 1)
        idx3 = line.find(")", idx + len("getmapmobs(") + 1)
        if idx2 + 1 == idx3:
            line = line[:idx2 + 1] + ",\"all\"" + line[idx2 + 1:]

        line = line.replace("getmapmobs(", "mobcount(")

    m = setRe.search(line);
    if m != None:
        line = "{0}{1} = {2};\n".format(m.group("space"), m.group("var"), m.group("val"))

    w.write(line)

