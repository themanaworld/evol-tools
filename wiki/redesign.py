#! /usr/bin/env python3
# -*- coding: utf8 -*-
#
# Copyright (C) 2010-2011  Evol Online
# Copyright (C) 2018  TMW-2
# Author: Andrei Karas (4144)
# Author: Jesusalva
#
# The use of the data

import datetime
import sys

stgen=True
aeros=False
bifs=False
skipCI=False

wikib=open("EleMonsters.html", "w")
wikib.write('<html><head><meta charset=utf8 /><title>EleGen File</title></head><body>')

exp=[			9,16,25,36,77,112,153,200,253,320,
				385,490,585,700,830,970,1120,1260,1420,1620,
				1860,1990,2240,2504,2950,3426,3934,4474,6889,7995,
				9174,10425,11748,13967,15775,17678,19677,21773,28543,34212,
				38065,42102,46323,53026,58419,64041,69892,75973,92468,115254,
				128692,142784,157528,178184,196300,215198,234879,255341,310188,365914,
				402508,442769,487051,535756,589342,648281,713112,784421,862867,949158,
				1044076,1148484,1263331,1389671,1528642,1681509,1849671,2034639,2238111,
				2461928,
				2708132,2978946,3276840,3604530,3964987,4361495,4797656,5277432,5805184,6095442,
				6400217,6720231,7056251,7409070,7779531,8168509,8576941,9005793,9456080,9928893,
				10425342,10946613,11493946,12068655,12672087,13305690,13970980,14669530,15403013,16173172,
				16981833,17830934,18722479,19658611,20641552,21673632,22757319,23895184,25089950,25591758,
				26103599,26625670,27158181,27701356,28255388,28820507,29396920,29984867,30584571,31196260,
				31820184,32456596,33105727,33767845,34443202,35132065,35834705,36551410,37282446,38028099,
				38788671,39564454,40355745,41162860,41986116,42825838,43682362,44556009,45447138,45901616,
				46360641,46824255,47292503,47765432,48243093,48725528,49212784,49704921,50201982,50704003,
				51211047,51723162,52240405,52762810,53290446,53823354,54361598,54905214,55454271,56008820,
				56568910,57134610,57705965,58283032,58865873,59454536,60049086,60649586,61256083,61868649,
				62487336,63112216,63743344,64380779,65024597,65674843,66331602,66994930,67664885,68341538,
				69024959,69715207,70412360,71116485,71827658,72545940,73271398,74004114,74744153,75491595,
				76246518,77008984,77779077,78556879,79342456,80135878,80937236,81746616,82564087,83389730,
				84223638,85065880,85916545,86775711,87643468,88519912,89405121,90299171,91202163,92114182,
				93035322,93965687,94905347,95854406,96812948,97781076,98758892,99746478,100743951,101751398,
				102768911,103796609,104834582,105882930,106941769,108011193,109091315,110182230,111284052,112396904,
				113520874,114656091,115802657,116960692,118130296,119311601,120504716,121709770,122926875,124156150,
				125397711,126651686,127918206,129197392,130489375,131794267,133112212,134443338,135787774,137145652,
				138517109,139902284,141301316,142714335,144141489,145582902,147038738,148509126,149994219,150894194,
				151799571,152710366,153626627,154548387,155475676,156408540,157346998,158291079,159240837,160196288,
				161157464,162124419,163097165,164075757,165060214,166050576,167046878,168049166,169057470,170071823,
				171092262,172118826,173151541,174190460,175235604,176287026,177344758,178408837,179479294,180556179,
				181639518,182729367,183825754,184928711,186038293,187154528,188277464,189407130,190543577,191686849,
				192836981,193994007,195157974,196328927,197506910,198691949,199884102,201083405,202289908,203503646,
				204724676,205953024,207188754,208431886,209682484,210940582,212206225,213479467,214760350,216048919,
				217345224,218649298,219961193,221280960,222608645,223944302,225287974,226639708,227999552,229367554,
				230743762,232128226,233520999,234922133,236331675,237749668,239176170,240611236,242054915,243507252,
				244968307,246438117,247916753,249404252,250900687,252406101,253920540,255444067,256976742,258518609,
				260069729,261630158,263199938,264779135,266367816,267966025,269573820,271191260,272818408,274455326,
				276102061,277758679,279425234,281101787,282788399,284485141,286192050,287909214,289636677,291374496,
				293122752,294881486,296650782,298430689,300221275,302022609,303834742,305657759,307491713,309336672,
				311192696,313059863,314938223,316827859,318728836,320641216,322565061,324500459,326447460,328406143,
				330376584,332358847,334353004,336359128,338377288,340407551,342449994,344504696,346571722,348651151,
				350743062,352847532,354964629,357094423,359236990,361392422,363560778,365742141,367936599,370144221,
				372365091,374599279,376846874,379107955,381382611,383670915,385972949,388288794,390618537,392962257,
				395320037,397691969,400078129,402478601,404893475,407322841,409766782,412225383,414698739,417186939,
				419690069,422208209,424741456,427289911,429853651,432432776,435027370,437637543,440263366,442024421,
				443792521,445567690,447349963,449139360,450935926,452739673,454550638,456368839,458194326,460027115,
				461867221,463714693,465569558,467431848,469301579,471178794,473063508,474955766,476855601,478763022,
				480678083,482600803,484531205,486469328,488415217,490368880,492330355,494299675,496276878,498261990,
				500255043,502256068,504265102,506282171,508307305,510340540,512381907,514431439,516489176,518555144,
				520629376,522711891,524802748,526901963,529009581,531125618,533250127,535383137,537524678,539674777,
				541833486,544000830,546176836,548361554,550555012,552757234,554968274,557188159,559416915,561654583,
				563901210,566156820,568421455,570695142,572977924,575269847,577570928,579881219,582200741,584529542,
				586867672,589215145,591572009,593938303,596314063,598699319,601094122,603498497,605912494,608336152,
				610769496,613212575,615665434,618128102,620600617,623083026,625575357,628077658,630589971,633112332,
				635644789,638187373,640740134,643303101,645876314,648459827,651053675,653657891,656272528,658897623,
				661533224,664179368,666836088,669503437,672181451,674870184,677569669,680279959,683001081,685733085,
				688476023,691229930,693994859,696770843,699557927,702356165,705165600,707986270,710818214,713661496,
				716516145,719382218,722259755,725148792,728049398,730961596,733885443,736820993,739768279,742727359,
				745698276,748681079,751675801,754682510,757701238,760732051,763774987,766830096,769897426,772977027,
				776068941,779173220,782289911,785419075,788560754,791714999,794881861,798061393,801253640,804458666,
				807676501,810907214,814150847,817407448,820677081,823959788,827255638,830564665,833886935,837222492
				]

def printSeparator():
    print("--------------------------------------------------------------------------------")

def showHeader():
    global stgen, aeros, bifs, skipCI
    print("TMW2 Ele Generator")
    print("Run at: " + datetime.datetime.now().isoformat())
    print("Usage: ./redesign.py [default|aeros|none|update|all] [<path_to_serverdata>]")
    if len(sys.argv) >= 2:
        if sys.argv[1] == "default":
            stgen=True
            aeros=False
            bifs=False
            skipCI=False
        elif sys.argv[1] == "aeros":
            stgen=False
            aeros=True
            bifs=False
            skipCI=False
        elif sys.argv[1] == "none":
            stgen=False
            aeros=False
            bifs=False
            skipCI=False
        elif sys.argv[1] == "update":
            stgen=True
            aeros=False
            bifs=True
            skipCI=True
        elif sys.argv[1] == "all":
            stgen=True
            aeros=True
            bifs=True
            skipCI=False
        else:
            exit(1)
    print("This stuff analyzes and sorts monsters and then create base stats for Moubootaur Legends.")
    print("Drops aren't calculated or taken in account, TWEAK AS NEEDED")
    printSeparator()
    print("Output is: EleMonsters.html")

def showFooter():
    #pass
    #printSeparator()
    print("Done.")



Mobs1=[]
Mobs2=[]
Mobs3=[]
Mobs4=[]
Mobs5=[]
Mobs6=[]
MobsA=[]

# This is for Aeros
Plants=[]
Level50=[]
Level100=[]
Aggressive=[]
Assistant=[]
Looter=[]
Boss=[]

SysDrops=[]

def fwalk(wmask):
    if wmask == 'WATER':
        return '<font color=#00f>%s</font>' % (wmask)
    elif wmask == 'AIR':
        return '<font color=#093>%s</font>' % (wmask)
    elif wmask == 'WALL':
        return '<font color=#f00>%s</font>' % (wmask)
    elif wmask == 'NORMAL' or wmask == 'DEFAULT':
        return '<font color=#111>%s</font>' % (wmask)
    else:
        print("Invalid walk mask: "+wmask)
        exit(1)

def WhatRace(rac):
    rc=rac.race
    if rc == 0:
        return "Formless"
    elif rc == 1:
        return "Undead"
    elif rc == 2:
        return "Brute"
    elif rc == 3:
        return "Plant"
    elif rc == 4:
        return "Insect"
    elif rc == 5:
        return "Fish"
    elif rc == 6:
        return "-"
    elif rc == 7:
        return "SemiHuman"
    elif rc == 8:
        return "Angel"
    elif rc == 9:
        return "Dragon"
    elif rc == 10:
        return "Player"
    elif rc == 11:
        return "Boss"
    elif rc == 12:
        return "NonBoss"
    elif rc == 14:
        return "NonSemiHuman"
    elif rc == 15:
        return "NonPlayer"
    elif rc == 16:
        return "SemiPlayer"
    elif rc == 17:
        return "NonSemiPlayer"
    else:
        print("ERROR, INVALID RACE ID: %d (ID: %s)" % (rc, rac.id))
        exit(1)

def WhatElem(rac):
    rc=rac.elem
    tl="ERROR"
    cl="#F00"
    if rc == 0:
        tl,cl="Neutral","#000"
    elif rc == 1:
        tl,cl="Water","#00F"
    elif rc == 2:
        tl,cl="Earth","#7A0"
    elif rc == 3:
        tl,cl="Fire","#F00"
    elif rc == 4:
        tl,cl="Wind","#093"
    elif rc == 5:
        tl,cl="Nature","#040"
    elif rc == 6:
        tl,cl="Holy","#afa"
    elif rc == 7:
        tl,cl="Dark","#908"
    elif rc == 8:
        tl,cl="Ghost","#404"
    elif rc == 9:
        tl,cl="Undead","#440"
    else:
        print("ERROR, INVALID ELEM ID: %d (ID: %s)" % (rc, rac.id))
        exit(1)
    return "<font color=%s>%s</font>" % (cl, tl)

class Mob:
  def __init__(self):
    # Basic
    self.id="0"
    #self.aegis="UnknownMonster" # SpriteName is not used anywhere, we are using its ID
    self.name="Unknown Monster Name"
    self.view="1"
    self.boss=False
    self.plant=False

    # Defensive
    self.mobpt="0" # Mob Points “Level”
    self.hp="0"
    self.xp="Exp: 0"
    self.jp="JExp: 0"
    self.st=""
    self.dfn=0
    self.mdf=0

    # Offensive
    self.atk="[0, 0]"
    self.range="1"
    self.move="0"
    self.delay="0"
    self.drops=[]

    # New
    self.race=-1
    self.elem=-1
    self.elel=-1
    self.walk="NORMAL"

    # Stats
    self.str='0'
    self.agi='0'
    self.vit='0'
    self.int='0'
    self.dex='0'
    self.luk='0'

def MobAlloc(ab):
    try:
        maab=int(ab.mobpt)
    except:
        maab=9901

    if maab <= 20 or skipCI:
        Mobs1.append(ab)
    elif maab <= 40:
        Mobs2.append(ab)
    elif maab <= 60:
        Mobs3.append(ab)
    elif maab <= 80:
        Mobs4.append(ab)
    elif maab <= 100:
        Mobs5.append(ab)
    elif maab <= 150:
        Mobs6.append(ab)
    else:
        MobsA.append(ab)

    # Aeros allocation
    """Plants=[]
    Level50=[]
    Level100=[]
    Aggressive=[]
    Assistant=[]
    Looter=[]
    Boss=[]"""
    normie=True
    if ab.plant:
        Plants.append(ab.id)
        normie=False
    if ab.boss:
        Boss.append(ab.id)
        normie=False
    if normie:
        if "Agr" in ab.st:
            Aggressive.append(ab.id)
            normie=False
        if "Lot" in ab.st:
            Looter.append(ab.id)
            normie=False
        if "Ass" in ab.st:
            Assistant.append(ab.id)
            normie=False
    if normie:
        if maab <= 55:
            Level50.append(ab.id)
        else:
            Level100.append(ab.id)

def testMobs():
    print("Generating Elem-Mob Wiki...")
    if len(sys.argv) >= 3:
        src=open(sys.argv[2]+"/db/re/mob_db.conf", "r")
    else:
        src=open("../../server-data/db/re/mob_db.conf", "r")

    wikib.write("<h1 id=#x>EleGen Monster Database</h1>\n")
    start=False
    dropper=False
    skip=0
    x=Mob() # Only for pyflakes2

    for a2 in src:
        a=a2.replace('    ', '\t');
        if a == "{\n":
            if skip:
                skip=0
            if start:
                MobAlloc(x)
            else:
                start=True
            x=Mob()

        if skip:
            start=False
            x=Mob()
            continue
        if "	Id:" in a:
            x.id=stp(a)
        if x.id == "ID":
            continue

        if "	Name:" in a:
            x.name=stp(a)
        elif "	Hp:" in a:
            x.hp=stp(a)
        elif "	Lv:" in a:
            x.mobpt=stp(a)
        elif "	Exp:" in a:
            x.xp=stp(a)
        elif "	JExp:" in a:
            x.jp=stp(a)
        elif "	Attack:" in a:
            x.atk=stp(a)
        elif "	AttackRange:" in a:
            x.range=stp(a)
        elif "	MoveSpeed:" in a:
            x.move=stp(a)
        elif "	ViewRange:" in a:
            x.view=stp(a)
        elif "	AttackDelay:" in a:
            x.delay=stp(a)

        elif "	Def:" in a:
            x.dfn=stp(a)
        elif "	Mdef:" in a:
            x.mdf=stp(a)

        elif "	Str:" in a:
            x.str=stp(a)
        elif "	Agi:" in a:
            x.agi=stp(a)
        elif "	Vit:" in a:
            x.vit=stp(a)
        elif "	Int:" in a:
            x.int=stp(a)
        elif "	Dex:" in a:
            x.dex=stp(a)
        elif "	Luk:" in a:
            x.luk=stp(a)


        elif "	Boss: true" in a:
            x.boss=True
        elif "	Plant: true" in a:
            x.plant=True
        elif "	Looter: true" in a:
            x.st+="<font color=#790>Lot</font>,"
        elif "	Assist: true" in a:
            x.st+="<font color=#0a0>Ass</font>,"
        elif "	Aggressive: true" in a:
            x.st+="<font color=#f00>Agr</font>,"
        elif "	WalkMask:" in a:
            x.walk=stp(a)
        elif "	Element:" in a:
            tmp=stp(a)
            tmp2=tmp.split(',')
            try:
                x.elem=int(tmp2[0])
                x.elel=int(tmp2[1])
            except:
                print("Invalid Element for mob %s: %s" % (x.id, tmp))
                exit(1)
        elif "	Race:" in a:
            try:
                x.race=int(stp(a))
            except:
                print("Invalid Race for mob %s: %s" % (x.id, a))
                exit(1)
        elif 'Drops: ' in a:
            dropper=True
        elif dropper and '}' in a:
            dropper=False
        elif dropper:
            x.drops.append(stp(a).split(": "))
        elif "Plant: true" in a:
            skip=1
    # Write last entry
    MobAlloc(x)

    writeMob()

    wikib.write('\n\n|Mode|Desc|\n|----|----|\n')
    wikib.write('|Lot|Looter|\n')
    wikib.write('|Ass|Assist|\n')
    wikib.write('|Agr|Aggressive|\n')

    src.close()

def stp(x):
    return x.replace('\n', '').replace('|', '').replace('(int, defaults to ', '').replace(')', '').replace('basic experience', '').replace('"','').replace("    ","").replace("\t","").replace('(string', '').replace('Name: ','').replace('Element: ','').replace('Race: ','').replace('AttackDelay: ', '').replace('WalkMask: ','').replace('MoveSpeed: ', '').replace('AttackRange: ', '').replace('ViewRange: ','').replace('Attack: ','').replace('ViewRange: ','').replace('Hp: ','').replace('Id: ','').replace('Lv: ','').replace('view range','').replace('attack range','').replace('move speed','').replace('health','').replace('(int','').replace('attack delay','atk.').replace('(','').replace(')','').replace('WALK_','').replace('Def: ','').replace('Mdef: ','')


def MonsterWrite(tbl):
    global skipCI
    # TODO: Check _mobs files to determine the usual monster density (a misc info to aid adding proper drop specs)
    wikib.write("<table border=1>\n")
    if stgen:
        wikib.write("<tr><th>ID</th><th>Name</th><th>Mob Info</th><th>Stgen</th><th>Elegen</th><th>Misc Info</th><th>Rewards</th><th>Stats</th><th>Drops</th></tr>\n")
    else:
        wikib.write("<tr><th>ID</th><th>Name</th><th>Mob Info</th><th>Elegen</th><th>Misc Info</th><th>Rewards</th><th>Stats</th><th>Drops</th></tr>\n")

    if not skipCI:
        tbl=sorted(tbl,  key=lambda tbl: int(tbl.mobpt))

    for i in tbl:
        if i.id == 'ID':
            continue

        # Special skips for REDESIGN
        #if (int(i.id) < 1187):
        #    continue
        if not bifs and ((int(i.hp) <= 50) or (i.race == 3)):
            continue

        if i.boss:
            i.name="<b>"+i.name+"</b>"
        if stgen:
            wikib.write('<tr><td><a name="' + i.id + '"></a>' +
                        i.id +"</td><td>"+
                        i.name +"</td><td>"+
                        mb_core(i) +"</td><td>"+
                        mbdt('advise',mb_stgen(i)) +"</td><td>"+
                        mb_eleg(i) +"</td><td>"+
                        mbdt('misc', mb_rdmisc(i)) +"</td><td>"+
                        mbdt('Exp\'s', mb_rdrw(i)) +"</td><td>"+
                        mbdt('stats', mb_rdstat(i)) +"</td><td>"+
                        mbdt('drops', mb_rddrop(i)) +"</td></tr>\n"
                        )
        else:
            wikib.write('<tr><td><a name="' + i.id + '"></a>' +
                        i.id +"</td><td>"+
                        i.name +"</td><td>"+
                        mb_core(i) +"</td><td>"+
                        mb_eleg(i) +"</td><td>"+
                        mbdt('misc', mb_rdmisc(i)) +"</td><td>"+
                        mbdt('Exp\'s', mb_rdrw(i)) +"</td><td>"+
                        mbdt('stats', mb_rdstat(i)) +"</td><td>"+
                        mbdt('drops', mb_rddrop(i)) +"</td></tr>\n"
                        )
    wikib.write("</table>\n")
    wikib.write("\n<a href=#x>(↑) Return to top</a><br/><br/>\n\n")

def writeMob():
    wikib.write("<ul>\
<li><a href=#0>Starter</a></li>\n\
<li><a href=#1>Apprentice</a></li>\n\
<li><a href=#2>Intermediary</a></li>\n\
<li><a href=#3>Advanced</a></li>\n\
<li><a href=#4>Expert</a></li>\n\
<li><a href=#5>Master</a></li>\n\
<li><a href=#Nan>OoS</a></li>\n\
</ul>    ")

    wikib.write("<h1 id=0>Lv 0-20</h1>\n\n")
    MonsterWrite(Mobs1)
    wikib.write("<h1 id=1>Lv 21-40</h1>\n\n")
    MonsterWrite(Mobs2)
    wikib.write("<h1 id=2>Lv 41-60</h1>\n\n")
    MonsterWrite(Mobs3)
    wikib.write("<h1 id=3>Lv 61-80</h1>\n\n")
    MonsterWrite(Mobs4)
    wikib.write("<h1 id=4>Lv 81-100</h1>\n\n")
    MonsterWrite(Mobs5)
    wikib.write("<h1 id=5>Lv 101-150</h1>\n\n")
    MonsterWrite(Mobs6)

    wikib.write("<h1 id=NaN>Lv 101+</h1>\n\n")
    MonsterWrite(MobsA)


def mbdt(summary, content):
    return "<b>"+summary+"</b><br/><pre>"+content+"</pre>"
    return "<details>\
<summary>"+summary+"</summary>\
<pre>"+content+"</pre></details>"

def mb_core(mb):
    buff=""
    buff+="Lvl: %s<br/>\n" % (mb.mobpt)
    buff+="HP: <b><font color=#0a0>%s</font></b><br/>\n" % (mb.hp)
    buff+="ATK: <b><font color=#a00>%s</font></b><br/>\n" % (mb.atk)
    buff+="DEF: <b><font color=#775>%s/%s</font></b><br/>\n" % (mb.dfn, mb.mdf)
    if mb.st != "":
        buff+="Modes: <i>%s</i>" % (mb.st)
    return buff

def mb_eleg(mb):
    buff=""
    buff+="Race: %s<br/>\n" % (WhatRace(mb))
    buff+="Walk: %s<br/>\n" % (fwalk(mb.walk))
    buff+="Element: %s<br/>\n" % (WhatElem(mb))
    return buff

############################################################
def mb_stgen(mb):
    lv=int(mb.mobpt)
    st=int(mb.str.replace(' ', '').replace('Str:',''))
    #ag=int(mb.agi.replace(' ', '').replace('Agi:',''))
    vi=int(mb.vit.replace(' ', '').replace('Vit:',''))
    #it=int(mb.int.replace(' ', '').replace('Int:',''))
    #dx=int(mb.dex.replace(' ', '').replace('Dex:',''))
    #lk=int(mb.luk.replace(' ', '').replace('Luk:',''))

    # Attack Range vs Attack Delay
    ar=int(mb.range)
    ad=int(mb.delay)
    mv=int(mb.move)
    magr=False
    mass=False
    if ('Agr' in mb.st):
        magr=True
    if ('Ass' in mb.st):
        mass=True

    if (not ar):
        ar=1    

    # HP: Each 10 levels give you 100 extra weapon damage
    # I expect from 6 to 14 hits to kill
    # You deliver in average two hits per second
    # Mobs deliver one hit each four seconds (and that's 1hand advantage)
    lhp=lv*20*6+lv*(vi/100)
    hhp=lv*20*14+lv*(vi/100)
    if mb.boss:
        lhp*=1.45
        hhp*=1.81
    """if "slime" in mb.name.lower():
        lhp*=0.6
        hhp*=0.6
    """
    if ar > 1:
        lhp*=0.9
        hhp*=0.9

    # WildX Final Tweaks
    lhp*=0.9
    hhp*=0.9

    # Damage formula:
    # Based on the time you should take to kill
    # Based on the HP you have
    # Fórmula da HPTable: 400+(x*50)
    # Estimate Player HP and DMG
    t_hp=400+(lv*49.5)
    t_dg=6.5+((100-lv)/100.0)-((lv/15.0)/10.0)
    if lv > 45:
        t_dg-=(lv-45)/90.0
    t_dg*=lv

    # Now we take how many hits you need
    t_hc1=lhp/t_dg
    t_hc2=hhp/t_dg

    # Now we define the base attack as:
    # Enough to deplete at least 20% of HP bar (except boss)
    if lv < 50:
        t_dp=0.2+(lv*1.1/100.0)
        #print("Lv %d HP Bar Consume %.2f (HP %d HC %d, to deplete %d)" % (lv, t_dp, t_hp, t_hc1, t_hp/t_hc1))
    else:
        # Slow down! After 75% HP depletion we can go slow
        # If you don't have defense to mitigate, even same level monsters will...
        # Mop the floor with you.
        t_dp=0.75+((lv-50)*0.35/100.0)
        #print("Lv %d HP Bar Consume %.2f (HP %d HC %d, to deplete %d)*" % (lv, t_dp, t_hp, t_hc1, t_hp/t_hc1))
    lat=(t_hp*t_dp)/t_hc1
    hat=(t_hp*t_dp)/t_hc2

    #lat=(lv-lv/40.0)*40
    # Str bonus (1 damage per str)
    lat=lat+st
    hat=hat+st

    # Attack speed consideration (based on *player* average ASPD)
    f=ad/580.0
    lat*=f
    hat*=f
    #print("%s attack factor: %.2f x" % (mb.name, f));
    # Consider Aggressive and Assist mobs (surrounded!)
    # Also consider boss (tough fight!) and slimes (weak!)
    if magr:
        lat*=0.91
        hat*=0.91
    if mass:
        lat*=0.97
        hat*=0.97
    if mb.boss:
        lat*=1.2
        hat*=1.21
    """
    if "slime" in mb.name.lower():
        lat*=0.8
        hat*=0.8
    """

    # Experience is way too non-linear and I prefer to do it with reference formula
    # like I was doing before
    # But let's use a formula based on mobs-to-lvl-up where you must kill 1580 lv 60 mobs
    # to raise from lv 60 (you can kill lv 50 mobs easier - but then I expect 3700 kills)
    # mobs to kill to raise level

    # This is the current mob-lvl-exp-table generated by this software
    # As you see, it is somewhat similar to TMW Org.
    # Remember aggressive, fast, and assistant mobs give even more exp

    # Level 1: total 1 mobs individual 3 xp (1.450)
    # Level 2: total 3 mobs individual 5 xp (1.450)
    # Level 3: total 8 mobs individual 5 xp (1.450)
    # Level 4: total 16 mobs individual 4 xp (1.450)
    # Level 5: total 26 mobs individual 7 xp (1.450)
    # Level 6: total 39 mobs individual 8 xp (1.450)
    # Level 7: total 56 mobs individual 9 xp (1.450)
    # Level 8: total 77 mobs individual 9 xp (1.450)
    # Level 9: total 101 mobs individual 10 xp (1.450)
    # Level 10: total 129 mobs individual 11 xp (1.450)
    # Level 20: total 667 mobs individual 21 xp (1.450)
    # Level 30: total 1767 mobs individual 57 xp (1.450)
    # Level 31: total 1912 mobs individual 63 xp (1.450)
    # Level 32: total 2064 mobs individual 68 xp (1.450)
    # Level 33: total 2223 mobs individual 73 xp (1.450)
    # Level 34: total 2390 mobs individual 84 xp (1.450)
    # Level 35: total 2563 mobs individual 91 xp (1.450)
    # Level 36: total 2747 mobs individual 96 xp (1.455)
    # Level 37: total 2942 mobs individual 101 xp (1.460)
    # Level 38: total 3148 mobs individual 105 xp (1.465)
    # Level 39: total 3366 mobs individual 130 xp (1.470)
    # Level 40: total 3597 mobs individual 148 xp (1.475)
    # Level 41: total 3841 mobs individual 156 xp (1.480)
    # Level 42: total 4098 mobs individual 163 xp (1.485)
    # Level 43: total 4369 mobs individual 170 xp (1.490)
    # Level 44: total 4656 mobs individual 185 xp (1.495)
    # Level 45: total 4958 mobs individual 193 xp (1.500)
    # Level 46: total 5276 mobs individual 201 xp (1.505)
    # Level 47: total 5611 mobs individual 208 xp (1.510)
    # Level 48: total 5963 mobs individual 215 xp (1.515)
    # Level 49: total 6334 mobs individual 249 xp (1.520)
    # Level 50: total 6724 mobs individual 295 xp (1.525)
    # Level 51: total 7133 mobs individual 314 xp (1.530)
    # Level 52: total 7564 mobs individual 331 xp (1.535)
    # Level 53: total 8016 mobs individual 348 xp (1.540)
    # Level 54: total 8491 mobs individual 375 xp (1.545)
    # Level 55: total 8990 mobs individual 393 xp (1.550)
    # Level 56: total 9512 mobs individual 411 xp (1.555)
    # Level 57: total 10061 mobs individual 428 xp (1.560)
    # Level 58: total 10636 mobs individual 443 xp (1.565)
    # Level 59: total 11239 mobs individual 514 xp (1.570)
    # Level 60: total 11871 mobs individual 579 xp (1.575)
    # Level 61: total 12533 mobs individual 608 xp (1.580)
    # Level 62: total 13226 mobs individual 638 xp (1.585)
    # Level 63: total 13952 mobs individual 670 xp (1.590)
    # Level 64: total 14712 mobs individual 704 xp (1.595)
    # Level 65: total 15508 mobs individual 740 xp (1.600)
    # Level 66: total 16340 mobs individual 778 xp (1.605)
    # Level 67: total 17211 mobs individual 818 xp (1.610)
    # Level 68: total 18122 mobs individual 861 xp (1.615)
    # Level 69: total 19075 mobs individual 905 xp (1.620)
    # Level 70: total 20071 mobs individual 952 xp (1.625)
    # Level 80: total 32389 mobs individual 1783 xp (1.650)
    # Level 90: total 47806 mobs individual 3635 xp (1.650)
    # Level 100: total 66308 mobs individual 4976 xp (1.650)

    hxp=exp[lv]
    if lv > 35:
        fx=1.45+((lv-35)/200.0)
    else:
        fx=1.45
    if fx > 1.65:
        fx=1.65

    # Aggressive, assistant and fast mobs yield more exp
    # Slow monsters yield less exp, because they're easier to kill on any playstyle
    if magr:
        fx-=0.09
    else:
        fx-=0.04
    if mass:
        fx-=0.08
    if mv < 200:
        fx-=0.02
    if mv > 500:
        fx+=0.02

    # 1 ^ anything = 1, so we need a better rule
    if lv != 1:
        lxp=exp[lv-1]/(lv**fx)
    else:
        lxp=3 # 3~5 is fine
    # Boss are BOSS. It gives roughly 0.1% ~ 10.0% from lvlup xp.
    if mb.boss:
        hxp=exp[lv]/10
        lxp=min(lxp*2, hxp)

    # Evol bonus
    #print("%d / %d" % (lxp, hxp))
    #print("%.2f then %.2f" % (lv/250.0, min(0.3, lv/250.0)))
    lxp*=1.3-min(0.3, lv/250.0)
    hxp*=1.3-min(0.3, lv/250.0)
    #print("%d / %d" % (lxp, hxp))

    # Defense follows the same player formula
    dfn=((lv**1.255)*2.5)
    dfn=dfn*350.0/810.0
    mdf=max(0, lv-5)+(lv/10.0)
    if not mb.boss:
        mdf/=2

    # Force HP to be higher
    # It'll only start applying from level 40 onwards
    # It gives a bonus of 0.5% HP per mob level
    # This means a level 100 mob got 60 times that stronger: 30%
    if lv > 40:
        lhp=lhp*(1.0+((lv-40)/210.0))
        lhp=int(lhp)

    # Norm
    lhp=int(lhp)
    hhp=int(hhp)
    lat=int(lat)
    hat=int(hat)
    lxp=int(lxp)
    hxp=int(hxp)
    dfn=int(dfn)
    mdf=int(mdf)

    buff="<pre><font size=-2px>"
    buff+="HP Range: %s ~ %s<br/>\n" % (lhp, hhp)
    buff+="Maximum XP: %s ~ %s<br/>\n" % (lxp, hxp)
    buff+="ATK Range: %s > %s<br/>\n" % (lat, hat)
    buff+="DEF: %s / %s<br/>\n" % (dfn, mdf)
    buff+="<b>Drop, Move, Elegen, aspd<br/>\n"
    buff+="</b></font></pre>"
    return buff

def mb_rdstat(mb):
    buff="<pre><font size=-4px>"
    buff+="%s\n" % (mb.str)
    buff+="%s\n" % (mb.agi)
    buff+="%s\n" % (mb.vit)
    buff+="%s\n" % (mb.int)
    buff+="%s\n" % (mb.dex)
    buff+="%s\n" % (mb.luk)
    buff+="</font></pre>"
    return buff

def mb_rdmisc(mb):
    buff=""
    if "agr" in mb.st.lower():
        buff+="View Range: %s\n" % (mb.view)
    buff+="Attack Range: %s\n" % (mb.range)
    buff+="AtkDelay: %s ms\n" % (mb.delay)
    buff+="Move speed: %s ms\n" % (mb.move)
    buff+="Element Level: %d\n" % (mb.elel)
    return buff

def mb_rdrw(mb):
    buff=""
    buff+="<font color=#060><u>%s</b></u></font>\n" % (mb.xp.replace(' ', ' <b>'))
    buff+="<font color=#006><u>%s</b></u></font>\n" % (mb.jp.replace(' ', ' <b>'))
    try:
        raise Exception; buff+="MobPoints: %d\n" % (int(mb.mobpt)*11/10)
    except:
        pass
    return buff

def mb_rddrop(mb):
    buff=""
    for ax in mb.drops:
        # Ignore disabled drops
        if ax[0].startswith("//"):
            continue

        # Write drop
        try:
            buff+=ax[0]+': ' + str(int(ax[1])/100.0) + ' %\n'
        except IndexError:
            print("Fatal: invalid %s mob with %s drops" % (mb.name, str(ax)))
            exit(1)
        except:
            print("[Warning] %s incorrect drop: %s" % (mb.name, str(ax)))
            buff+=ax[0]+': ' + ax[1] + ' ppm\n'

        # Save to SysDrops
        SysDrops.append([ax[0], ax[1], mb.name])

    return buff



showHeader()

testMobs()

wikib.write('<br/><hr/>')
wikib.write("Run at: " + datetime.datetime.now().isoformat())
wikib.write('<hr/>')

wikib.write("""
<b>Player Stats (melee warrior)</b>
<table border=1>
<tr><th>Level</th><th>Stats 1</th><th>Stats 2</th><th>Average</th></tr>

<tr><th>00</th>
<td>str: 2 agi: 5 vit: 7 int:1 dex: 6 luk: 3</td>
<td>str: 2 agi: 5 vit: 7 int:1 dex: 6 luk: 3</td>
<th>str: 2 agi: 5 vit: 7 int:1 dex: 6 luk: 3</th></tr>

<tr><th>10</th>
<td>str:15 agi:10 vit: 5 int:1 dex:10 luk: 4</td>
<td>str:11 agi:11 vit: 6 int:1 dex:11 luk: 7</td>
<th>str:13 agi:11 vit: 5 int:1 dex:10 luk: 6</th></tr>

<tr><th>20</th>
<td>str:19 agi:10 vit:10 int:1 dex:20 luk:10</td>
<td>str:14 agi:19 vit: 8 int:1 dex:17 luk:11</td>
<th>str:17 agi:14 vit: 9 int:1 dex:18 luk:11</th></tr>

<tr><th>30</th>
<td>str:25 agi:30 vit:10 int:1 dex:20 luk:10</td>
<td>str:22 agi:28 vit:12 int:1 dex:21 luk:15</td>
<th>str:24 agi:29 vit:11 int:1 dex:20 luk:13</th></tr>

<tr><th>40</th>
<td>str:38 agi:30 vit:20 int:1 dex:25 luk:17</td>
<td>str:28 agi:35 vit:14 int:1 dex:32 luk:21</td>
<th>str:33 agi:33 vit:17 int:1 dex:28 luk:19</th></tr>

<tr><th>50</th>
<td>str:50 agi:40 vit:30 int:1 dex:25 luk:18</td>
<td>str:41 agi:41 vit:15 int:1 dex:41 luk:26</td>
<th>str:46 agi:41 vit:22 int:1 dex:33 luk:27</th></tr>

<tr><th>60</th>
<td>str:54 agi:50 vit:40 int:1 dex:35 luk:20</td>
<td>str:52 agi:52 vit:16 int:1 dex:45 luk:32</td>
<th>str:53 agi:51 vit:28 int:1 dex:40 luk:26</th></tr>

<tr><th>70</th>
<td>str:60 agi:60 vit:43 int:1 dex:50 luk:20</td>
<td>str:61 agi:61 vit:22 int:1 dex:51 luk:38</td>
<th>str:60 agi:61 vit:33 int:1 dex:50 luk:29</th></tr>

<tr><th>80</th>
<td>str:80 agi:60 vit:50 int:1 dex:50 luk:25</td>
<td>str:65 agi:71 vit:32 int:1 dex:60 luk:41</td>
<th>str:72 agi:66 vit:41 int:1 dex:55 luk:33</th></tr>

<tr><th>90</th>
<td>str:80 agi:70 vit:60 int:1 dex:60 luk:31</td>
<td>str:71 agi:71 vit:41 int:1 dex:71 luk:51</td>
<th>str:76 agi:70 vit:50 int:1 dex:66 luk:41</th></tr>

<tr><th>100</th>
<td>str:90 agi:80 vit:69 int:1 dex:60 luk:31</td>
<td>str:71 agi:81 vit:42 int:1 dex:81 luk:61</td>
<th>str:81 agi:80 vit:56 int:1 dex:70 luk:46</th></tr>

<tr><th>110</th>
<td>str:90 agi:90 vit:69 int:1 dex:70 luk:35</td>
<td>str:82 agi:82 vit:50 int:1 dex:82 luk:65</td>
<th>str:86 agi:86 vit:60 int:1 dex:76 luk:50</th></tr>

<tr><th>120</th>
<td>str:99 agi:90 vit:69 int:1 dex:70 luk:45</td>
<td>str:86 agi:86 vit:51 int:1 dex:86 luk:68</td>
<th>str:93 agi:88 vit:60 int:1 dex:78 luk:56</th></tr>

<tr><th>130</th>
<td>str:99 agi:91 vit:75 int:1 dex:70 luk:55</td>
<td>str:91 agi:90 vit:51 int:1 dex:90 luk:68</td>
<th>str:95 agi:91 vit:63 int:1 dex:80 luk:61</th></tr>

</table>
""")
wikib.write('<hr/>')

wikib.write('</body></html>')
wikib.close()
#print(str(SysDrops))

showFooter()
exit(0)
