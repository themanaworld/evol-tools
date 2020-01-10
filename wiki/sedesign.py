#! /usr/bin/env python3
# -*- coding: utf8 -*-
#
# Copyright (C) 2010-2011  Evol Online
# Copyright (C) 2018  TMW-2
# Author: Andrei Karas (4144)
# Author: Jesusalva

import datetime
import sys

stgen=True

wikia=open("EleItems.html", "w")

# the TYPEs we use to determine where to pack things
IT_ARMOR={  'MISC': [],             # FOR FAILURE
            'EQP_ACC_L': [],        # ACCESSORY LEFT
            'EQP_ACC_R': [],        # ACCESSORT RIGHT
            'EQP_HEAD_MID': [],     # CHEST
            'EQP_SHOES': [],        # FEET
            'EQP_GARMENT': [],      # GLOVES
            'EQP_HEAD_LOW':[],      # PANTS
            '1024': [],             # NECKLACES (should be EQP_COSTUME_HEAD_TOP instead of number)
            '2048': [],             # RINGS (should be EQP_COSTUME_HEAD_MID instead of number)
            'EQP_MOUNT':[],         # MOUNTS (ie. EQP_SHADOW_SHOES)
            'EQP_HEAD_TOP':[],      # HATS/HELMETS
            'EQP_HAND_L': []}       # SHIELDS
IT_WEAPON={ 'RANGED': [],           # RANGED WEAPONS
            'HAND_2':[],            # TWO HAND (LR)
            'HAND_1':[]}            # WEAPONS (R)

def printSeparator():
    print("--------------------------------------------------------------------------------")

def showHeader():
    print("TMW2 EleItems Generator")
    print("Run at: " + datetime.datetime.now().isoformat())
    print("Usage: ./sedesign.py [info|level|none] [<path_to_serverdata>]")
    print("SeDesign determines the reference defense for every item.")
    print("Tweak as needed. Bonuses/Rarity/etc not taken in account.")
    print("Running this without Redesign (or vice versa) will break balance")
    printSeparator()
    print("Output is: EleItems.html")

def showFooter():
    #pass
    #printSeparator()
    print("Done.")







class It:
  def __init__(self):
    # Basic
    self.id="0"
    self.aegis="UnknownItem"
    self.name="Unknown Item Name"
    self.price="0" # Sell price, of course
    self.weight="0"
    self.type="IT_ETC" # default type
    self.loc=""
    self.fc=0.0

    # Offensive/Defensive
    self.atk="0"
    self.matk="0"
    self.range="0"
    self.defs="0"

    # Restrictions (EquipLv)
    self.lvl="0"
    self.drop=True
    self.trade=True
    self.sell=True
    self.store=True

    # Special settings
    self.rare=False         # DropAnnounce
    self.script=""

    # Visual
    self.sl="0" # Slots
    self.ac=False # Allow Cards

def ItAlloc(it):
    if (it.sl == "0" and it.ac) or (it.sl in ["1","2","3","4"] and not it.ac):
        print("WARNING, item id "+it.id+" invalid dye/card setting!")
    if (len(it.sl) > 1 and it.id != "ID(int"):
        print("WARNING, item id "+it.id+" bad slots length: %d (%s)" % (len(it.sl), it.sl))

    a=it.type
    if "IT_ARMOR" in a:
        if 'EQP_ACC_L' in it.loc:
            IT_ARMOR['EQP_ACC_L'].append(it)
            it.fc=0.00
        elif 'EQP_ACC_R' in it.loc:
            IT_ARMOR['EQP_ACC_R'].append(it)
            it.fc=0.00
        elif 'EQP_HEAD_MID' in it.loc:
            IT_ARMOR['EQP_HEAD_MID'].append(it)
            if ("bSpeedAddRate, -" in it.script or "bSpeedAddRate,-" in it.script):
                it.fc=0.40
            else:
                it.fc=0.30
        elif 'EQP_SHOES' in it.loc:
            IT_ARMOR['EQP_SHOES'].append(it)
            it.fc=0.08
        elif 'EQP_GARMENT' in it.loc:
            IT_ARMOR['EQP_GARMENT'].append(it)
            it.fc=0.07
        elif 'EQP_HEAD_LOW' in it.loc:
            IT_ARMOR['EQP_HEAD_LOW'].append(it)
            it.fc=0.10
        elif 'EQP_HEAD_TOP' in it.loc:
            IT_ARMOR['EQP_HEAD_TOP'].append(it)
            if ("bSpeedAddRate, -" in it.script or "bSpeedAddRate,-" in it.script):
                it.fc=0.15
            else:
                it.fc=0.10
        elif 'EQP_HAND_L' in it.loc:
            IT_ARMOR['EQP_HAND_L'].append(it)
            it.fc=0.25
        elif '1024' in it.loc:
            IT_ARMOR['1024'].append(it)
            it.fc=0.00
        elif '2048' in it.loc:
            IT_ARMOR['2048'].append(it)
            it.fc=0.00
        elif 'EQP_SHADOW_SHOES' in it.loc:
            IT_ARMOR['EQP_MOUNT'].append(it)
            it.fc=0.00
        elif 'EQP_SHADOW_ACC_R' in it.loc:
            IT_ARMOR['EQP_ACC_R'].append(it) # Not really
            it.fc=0.00
        else:
            raise Exception("Invalid Loc for ID %s: %s" % (it.id, it.loc))
    elif "IT_WEAPON" in a:
        if int(it.range) > 2:
            IT_WEAPON["RANGED"].append(it)
        elif "HAND_L" in it.loc or "EQP_ARMS" in it.loc:
            IT_WEAPON["HAND_2"].append(it)
        elif "HAND_R" in it.loc:
            IT_WEAPON["HAND_1"].append(it)
        else:
            raise Exception("Invalid location for weapon: %s" % it.loc)

def newItemDB():
    print("\nGenerating Item Wiki...")
    if len(sys.argv) >= 3:
        src=open(sys.argv[2]+"/db/re/item_db.conf", "r")
    else:
        src=open("../../server-data/db/re/item_db.conf", "r")

    lg=False
    x=It()
    for e3 in src:
        a=e3.replace('    ', '\t')
        if a == "{\n":
            ItAlloc(x)
            x=It()

        # sti() block
        if "	Id:" in a:
            x.id=sti(a)
        elif "	AegisName:" in a:
            x.aegis=sti(a)
        elif "	Name:" in a:
            x.name=stin(a)
        elif "	Sell:" in a:
            x.price=sti(a)
        elif "	Weight:" in a:
            x.weight=sti(a)
        elif "	Type:" in a:
            x.type=sti(a)
        elif "	Loc:" in a:
            x.loc=sti(a)
        elif "	Atk:" in a:
            x.atk=sti(a)
        elif "	Matk:" in a:
            x.matk=sti(a)
        elif "	Range:" in a:
            x.range=sti(a)
        elif "	Def:" in a:
            x.defs=sti(a)
        elif "	EquipLv:" in a:
            x.lvl=sti(a)
        elif "	Slots:" in a:
            x.sl=sti(a)
        elif "	AllowCards:" in a:
            x.ac=True
        # Write booleans
        elif "DropAnnounce: true" in a:
            x.rare=True
        elif "nodrop: true" in a:
            x.drop=False
        elif "notrade: true" in a:
            x.trade=False
        elif "noselltonpc: true" in a:
            x.sell=False
        elif "nostorage: true" in a:
            x.store=False
        elif "Script" in a:
            lg=True
            x.script+="<pre>"
        elif lg and "\">" in a:
            lg=False
            x.script+="</pre>"
        elif lg:
            if not "announce" in a and not "debugmes" in a and not "logmes" in a:
                x.script+=str(a.replace('\t', '').replace('getiteminfo(getequipid(', 'iteminfo((').replace('Flee2','Block'))

    # Write last entry
    ItAlloc(x)
    writeItems()

    src.close()

def sti(x):
    return x.replace('\n', '').replace('|', '').replace(')', '').replace('Id: ', '').replace('"','').replace("    ","").replace("\t","").replace('AegisName: ', '').replace('Name: ','').replace('Sell: ', '').replace('Weight: ', '').replace('Type: ', '').replace('Loc: ', '').replace('Atk: ', '').replace('Matk: ', '').replace('Range: ', '').replace('Def: ', '').replace('EquipLv: ', '').replace('Slots: ','').replace(" ", "").replace('@min=','').replace('@max=','').replace('@delay=','').replace(';','')

def stin(x):
    return x.replace('\n', '').replace('|', '').replace(')', '').replace('Id: ', '').replace('"','').replace("    ","").replace("\t","").replace('Name: ','').replace(';','')


def writeItems():
    wikia.write("<h1>Armors</h1>\n\
<ul>\
<li><a href=#armors>Armors</a></li>\n\
<li><a href=#left-accessory>Left Accessory</a></li>\n\
<li><a href=#right-accessory>Right Accessory</a></li>\n\
<li><a href=#headgear>Headgear</a></li>\n\
<li><a href=#chest>Chest</a></li>\n\
<li><a href=#pants>Pants</a></li>\n\
<li><a href=#shoes>Shoes</a></li>\n\
<li><a href=#necklaces>Necklaces</a></li>\n\
<li><a href=#rings>Rings</a></li>\n\
<li><a href=#gloves>Gloves</a></li>\n\
<li><a href=#shields>Shields</a></li>\n\
</ul>\n\n")
    wikia.write("<u>Restrictions Reference</u><br/>\n")
    wikia.write("<ul>\n\
<li>   *  - Rare item with drop announce.</li>\n\
<li> (dp) - This item cannot be dropped.</li>\n\
<li> (tr) - This item cannot de traded.</li>\n\
<li> (sl) - This item cannot be sold.</li>\n\
<li> (gg) - This item cannot go to storage.</li>\n\
</ul><br/>\n")

    ####################################################################
    wikia.write("<h2>Armors</h2>\n")

    ArmorWrite("Left Accessory",'EQP_ACC_L')
    ArmorWrite("Right Accessory",'EQP_ACC_R')
    ArmorWrite("Headgear",'EQP_HEAD_TOP')
    ArmorWrite("Chest",'EQP_HEAD_MID')
    ArmorWrite("Pants",'EQP_HEAD_LOW')
    ArmorWrite("Shoes",'EQP_SHOES')
    ArmorWrite("Necklaces",'1024')
    ArmorWrite("Rings",'2048')
    ArmorWrite("Gloves",'EQP_GARMENT')
    ArmorWrite("Shields",'EQP_HAND_L')
    #for i in sorted(IT_ARMOR['EQP_HEAD_TOP'],  key=lambda xcv: int(xcv.lvl)):
    #    # Name | Level | Location | Specification
    #    print("`%s`|%d| :grey_question: | " % (i.name, int(i.lvl)))

    ####################################################################
    wikia.write("<hr/><h2>Weapons</h2>\n")

    # 1 Hand Items
    wikia.write("<h3>1H Weapons</h3>\n")
    ItemWrite(IT_WEAPON['HAND_1'], ID=True, AEGIS=True, PRICE=True, WEIGHT=True, ATK=True, LVL=True)

    # 2 Hand Items
    wikia.write("<h3>2H Weapons</h3>\n")
    ItemWrite(IT_WEAPON['HAND_2'], ID=True, AEGIS=True, PRICE=True, WEIGHT=True, ATK=True, LVL=True, RANGE=True)

    # Ranged Items
    wikia.write("<h3>Ranged Weapons</h3>\n")
    ItemWrite(IT_WEAPON['RANGED'], ID=True, AEGIS=True, PRICE=True, WEIGHT=True, ATK=True, LVL=True, RANGE=True)

# Write AegisName with restrictions
def hl(it):
    buff=""
    if it.rare:
        buff+="*"
    buff+=it.aegis
    buff+=" "
    if not it.drop:
        buff+="<a href='#restrictions-reference'>(dp)</a>"
    if not it.trade:
        buff+="<a href='#restrictions-reference'>(tr)</a>"
    if not it.sell:
        buff+="<a href='#restrictions-reference'>(sl)</a>"
    if not it.store:
        buff+="<a href='#restrictions-reference'>(gg)</a>"
    return buff

#    wikia.write("Id|Aegis|Name|Weight|Atk|Matk|\n")
#    wikia.write("Id|Aegis|Name|Price|Weight|\n")

def ItemWrite(tbl, ID=False, AEGIS=False, NAME=False, PRICE=False, WEIGHT=False, DEF=False, LVL=False, ATK=False, RANGE=False, HEALING=False, SCRIPT=False, DROPPER=False):
    global stgen
    wikia.write("<table border=1>\n")
    wikia.write("<tr>")
    if ID:
        wikia.write("<th>ID</th>")
    if AEGIS:
        wikia.write("<th>Aegis</th>")
    if NAME:
        wikia.write("<th>Name</th>")
    if PRICE:
        wikia.write("<th>Price</th>")
    if WEIGHT:
        wikia.write("<th>Weight</th>")
    if DEF:
        wikia.write("<th>Def</th>")
        if stgen:
            wikia.write("<th>Adj.Def</th>")
    if LVL:
        wikia.write("<th>Lvl</th>")
    if ATK:
        wikia.write("<th>Atk</th>")
        if stgen:
            wikia.write("<th>Adj. Atk.</th>")
        wikia.write("<th>Matk</th>")
    if RANGE:
        wikia.write("<th>Range</th>")
    if HEALING:
        wikia.write("<th>Min</th>")
        wikia.write("<th>Max</th>")
        wikia.write("<th>Delay</th>")
    if SCRIPT:
        wikia.write("<th>Script</th>")
    if DROPPER:
        wikia.write("<th>Mobs</th>")

    wikia.write("</tr>\n")

    try:
        if (sys.argv[1] in ["level", "info"]):
            sort=sorted(tbl,  key=lambda xcv: int(xcv.lvl))
        elif (sys.argv[1] == "none"):
            sort=tbl
        else:
            print("Syntax: ./sedesign.py [info|level|none]")
            sort=tbl

        if (sys.argv[1] == "info"):
            stgen=False
    except:
        sort=tbl

    for i in sort:
        wikia.write('<tr>')

        if ID:
            wikia.write("<td><a name=\"%s\"></a>%s</td>" % (i.id,i.id))
        if AEGIS:
            wikia.write("<td>%s</td>" % hl(i))
        if NAME:
            wikia.write("<td>%s</td>" % i.name)
        if PRICE:
            wikia.write("<td>%s GP</td>" % i.price)
        if WEIGHT:
            wikia.write("<td>%s g</td>" % i.weight)
        if DEF:
            wikia.write("<td>Def: %s</td>" % i.defs)
            if stgen:
                lv=int(i.lvl)

                bb=(lv**1.255)*2.5*i.fc
                hc=bb*350.0/810.0 # Hercules value: Capped at 350

                # Magic penalty
                if ("bMatk," in i.script):
                    hc=hc/2.0

                # Precise rounding
                if (hc % 1 >= 0.5):
                    hc+=1
                wikia.write("<td>Adj. Df: %d</td>" % int(hc))
        if LVL:
            wikia.write("<td>Lv: %s</td>" % i.lvl)
        if ATK:
            wikia.write("<td>Atk: %s</td>" % i.atk)
            if stgen:
                lv=int(i.lvl)
                #at=int(i.atk)
                fc=7.5
                ## Two hand swords are stronger
                if i in IT_WEAPON['HAND_2']:
                    fc+=0.62
                ## Calculate guns
                if int(i.id) == 6010 or int(i.id) == 6050:
                    lv+=20
                if int(i.id) == 6020:
                    lv=0
                if int(i.id) == 6040:
                    fc/=2.5

                ## Progression
                fc-=1.0
                fc+=((100-lv)/100.0)

                ## Even slower progression (note bows doesn't gets the 0.8 2hand bonus)
                if not i in IT_WEAPON['RANGED']:
                    fc-=(lv/15.0)/10.0

                ## After level 50 weapons progression is slowed down
                if lv > 45:
                    fc-=(lv-45)/90.0

                ## This is because mob HP scaling is buggy
                if lv > 45 and not i in IT_WEAPON['RANGED']:
                    fc-=(lv-45)/100.0

                ## HAT is for craft or rare items.
                lat=lv*fc
                hat=lv*(fc+max(0.01, 1.0-(lv/100.0)))

                # Edge Cases
                ## Don't calculate magic weapons
                if int(i.matk) > 0:
                    lat=hat=0
                ## Don't recalculate noob weapon
                #if lv <= 20:
                #    lat=hat=at

                wikia.write("<th>%d ~ %d <i>(%.2f)</i></th>" % (lat, hat, fc))
            wikia.write("<td>%s</td>" % i.matk)
        if RANGE:
            wikia.write("<td>%s</td>" % i.range)
        if HEALING:
            wikia.write("<td>%s</td>" % i.minheal)
            wikia.write("<td>%s</td>" % i.maxheal)
            wikia.write("<td>%s s</td>" % i.delheal)
        if SCRIPT:
            wikia.write("<td>%s</td>" % i.script)
        if DROPPER:
            wikia.write("<td>-</td>")

        wikia.write("</tr>")

    wikia.write("</table><br/>\n")
    wikia.write("\n<br/><a href=#items>(↑) Return to top</a><Br/><br/>\n\n")

def ArmorWrite(name,scope):
    wikia.write("<h3>"+name+"</h3>\n")
    ItemWrite(IT_ARMOR[scope], ID=True, AEGIS=True, PRICE=True, WEIGHT=True, DEF=True, LVL=True, SCRIPT=True)











showHeader()

wikia.write("<html><head>")
wikia.write('<title>SeDesign</title><meta charset=utf8 />\n')
wikia.write("<body>")
newItemDB()

wikia.write('<hr/>')

# Ending
wikia.write("<hr/>")
wikia.write("Run at: " + datetime.datetime.now().isoformat())
wikia.write("</body></html>")
wikia.close()

# Print for reference the landmarks
i=0
while i < 100:
    i+=10
    bb=(i**1.255)*2.5
    hc=bb*350.0/810.0 # Hercules value: Capped at 350
    df=(100.0 - hc / (hc + 400.0) * 90.0) / 100.0 * 100
    print("%d Level %d Defense (%.2f%% DMG)" % (i, hc, df) );

showFooter()
exit(0)
