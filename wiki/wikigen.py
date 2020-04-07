#! /usr/bin/env python3
# -*- coding: utf8 -*-
#
# Copyright (C) 2010-2011  Evol Online
# Copyright (C) 2018  TMW-2
# Author: Andrei Karas (4144)
# Author: Jesusalva

import datetime
import sys

wikia=open("Items.md", "w")
wikib=open("Monsters.md", "w")
wikic=open("../../client-data/dyes.diff", "w") # Dye Report
wikid=open("../../server-data/changechase.diff", "w") # ChangeChase Report

# the TYPEs we use to determine where to pack things
IT_HEALING=[]
IT_ETC=[]
IT_USABLE=[]
IT_AMMO=[]
IT_CARD=[]
IT_PETEGG=[]
IT_WEAPON={ 'HAND_2': [],           # TWO HAND (LR)
            'HAND_1':[]}            # WEAPONS (R)
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

Mobs1=[]
Mobs2=[]
Mobs3=[]
Mobs4=[]
Mobs5=[]
Mobs6=[]
MobsA=[]

SysDrops=[]


def printSeparator():
    print("--------------------------------------------------------------------------------")

def showHeader():
    print("TMW2 Wiki Generator")
    ##print "Evol client data validator."
    print("Run at: " + datetime.datetime.now().isoformat())
    print("Usage: ./wikigen.py [<path_to_serverdata> <path_to_clientdata>]")
    ##print "https://gitlab.com/evol/evol-tools/blob/master/testxml/testxml.py"
    printSeparator()

def showFooter():
    #pass
    #printSeparator()
    print("Done.")






class Mob:
  def __init__(self):
    # Basic
    self.id="0"
    #self.aegis="UnknownMonster" # SpriteName is not used anywhere, we are using its ID
    self.name="Unknown Monster Name"
    self.view="1"
    self.chch=False
    self.boss=False

    # Defensive
    self.mobpt="0" # Mob Points “Level”
    self.hp="0"
    self.xp="0"
    self.jp="0"
    self.st=""
    self.df="0"
    self.mdf="0"

    # Offensive
    self.atk="[0, 0]"
    self.range="0"
    self.move="0"
    self.delay="0"
    self.drops=[]

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

    if maab <= 2000:
        Mobs1.append(ab)
    elif maab <= 4000:
        Mobs2.append(ab)
    elif maab <= 6000:
        Mobs3.append(ab)
    elif maab <= 8000:
        Mobs4.append(ab)
    elif maab <= 10000:
        Mobs5.append(ab)
    elif maab <= 15000:
        Mobs6.append(ab)
    elif maab != 9901:
        MobsA.append(ab)
    else:
        print("WARNING, Disregarding \"%s\" (ID: %s) as invalid mob" % (ab.name, ab.id))

def testMobs():
    print("\nGenerating Mob Wiki...")
    if len(sys.argv) >= 2:
        src=open(sys.argv[1]+"/db/re/mob_db.conf", "r")
    else:
        src=open("../../server-data/db/re/mob_db.conf", "r")

    #wikib.write("# Monster Database\n")
    start=False
    dropper=False
    x=Mob() # Only for pyflakes2

    for a in src:
        if a == "{\n":
            if start:
                MobAlloc(x)
            else:
                start=True
            x=Mob()
        a=a.replace('\t', '    ')

        if "    Id:" in a:
            x.id=stp(a)
        elif "    Name:" in a:
            x.name=stp(a)
        elif "    Hp:" in a:
            x.hp=stp(a)
        elif "    Lv:" in a:
            x.mobpt=stp(a)
        elif "    Exp:" in a:
            x.xp=stp(a)
        elif "    JExp:" in a:
            x.jp=stp(a)
        elif "    Attack:" in a:
            x.atk=stp(a)
        elif "    AttackRange:" in a:
            x.range=stp(a)
        elif "    Def:" in a:
            x.df=stp(a)
        elif "    Mdef:" in a:
            x.mdf=stp(a)
        elif "    MoveSpeed:" in a:
            x.move=stp(a)
        elif "    ViewRange:" in a:
            x.view=stp(a)
        elif "    AttackDelay:" in a:
            x.delay=stp(a)
        elif "    Boss: true" in a:
            x.boss=True
        elif "    Str:" in a:
            x.str=stp(a)
        elif "    Agi:" in a:
            x.agi=stp(a)
        elif "    Vit:" in a:
            x.vit=stp(a)
        elif "    Int:" in a:
            x.int=stp(a)
        elif "    Dex:" in a:
            x.dex=stp(a)
        elif "    Luk:" in a:
            x.luk=stp(a)
        elif "    Looter: true" in a:
            x.st+="Looter,"
        elif "    Assist: true" in a:
            x.st+="Assist,"
        elif "    Aggressive: true" in a:
            x.st+="Aggro,"
        elif "    ChangeChase: true" in a:
            x.chch=True
        elif 'Drops: ' in a:
            dropper=True
        elif dropper and '}' in a:
            dropper=False
        elif dropper:
            x.drops.append(stp(a).split(": "))
    # Write last entry
    MobAlloc(x)

    writeMob()

    """
    wikib.write('\n\n|Mode|Desc|\n|----|----|\n')
    wikib.write('|Lot|Looter|\n')
    wikib.write('|Ass|Assist|\n')
    wikib.write('|Agr|Aggressive|\n')
    """

    src.close()

def stp(x):
    return x.replace('\n', '').replace('|', '').replace('(int, defaults to ', '').replace(')', '').replace('basic experience', '').replace('"','').replace("    ","").replace("\t","").replace('(string', '').replace('Name: ','').replace('AttackDelay: ', '').replace('MoveSpeed: ', '').replace('AttackRange: ', '').replace('ViewRange: ','').replace('Attack: ','').replace('ViewRange: ','').replace('Hp: ','').replace('Def: ','').replace('Mdef: ','').replace('Id: ','').replace('Lv: ','').replace('view range','').replace('attack range','').replace('move speed','').replace('health','').replace('(int','').replace('attack delay','atk.').replace('Str: ', '').replace('Dex: ', '').replace('Agi: ', '').replace('Vit: ', '').replace('Int: ', '').replace('Luk: ', '')


def MonsterWrite(tbl):
    # TODO: Check _mobs files to determine the usual monster density (a misc info to aid adding proper drop specs)
    for i in tbl:
        if not i.chch:
            wikid.write("%s:%s\n" % (i.id, i.name))

        aegis2=i.name.replace(" ", "_")

        if i.boss:
            i.name="'''"+i.name+"'''"
        if i.st == "":
            i.st="Normal"

        wikib.write('|-\n')
        wikib.write('| align="center" | [[Image:%s.png]]\n' % (aegis2))
        wikib.write("""| height="82px;" | [[%s|%s]] ''<span style="color:#969696;"> (%s) </span>''<br />''<span style="color:#007700;font-size:12px;"> Level: %s -  %s/%s/%s/%s/%s/%s </span>'' - ''<span style="color:#ad1818"> %s </span>''\n""" % (aegis2, i.name, i.id, i.mobpt, i.str, i.agi, i.vit, i.int, i.dex, i.luk, i.st))
        wikib.write("""| align="center" | %s\n| align="center" | %s / %s\n""" % (i.hp, i.df, i.mdf))
        try:
            dps=str(int(i.atk)*1000/int(i.delay))
        except:
            dps="over %s ms" % i.delay
        wikib.write("""| align="center" | %s (%s)<br />''<span style="color:#ad1818">DPS %s</span>''\n""" % (i.atk, i.range, dps))
        wikib.write("""| align="center" | %s (%s)\n""" % (i.xp, i.jp))
        wikib.write("""| ''<div style="-moz-column-count: 2;-moz-column-gap: 3px;column-count: 2;column-gap: 3px;font-size:12px;">%s</div>''\n""" % (mb_rddrop(i)))
        wikib.write("""|-\n""")

    wikib.write("""|-\n|}\n""")

def writeMob():
    wikib.write("""{{Meta}}{{I18n}}
{{Category playerinfo}}
{{Status_green}}

This is for '''THE MANA WORLD: REVOLT'''. If you're interested in the Legacy game, see instead: [[Legacy:Monsters]]

The monsters are sorted roughly by their fighting strength, calculated solely by their level. For more information on the drops please see the [[Items]].

'''Key:''' HP is health points, DEF is defense, ATT is attack, EXP is the calculated base experience, JEXP is the job experience. The others are self-explanatory. Traits (such as aggressive) are written in ''<span style="color:#ad1818">italics</span>''.

{| border="1" cellspacing="0" cellpadding="5" class="responsive" align="center"
! style="background:#efdead;" | Image
! style="background:#efdead;" | Name (ID)
! style="background:#efdead;" | HP
! style="background:#efdead;" | DEF/MDEF
! style="background:#efdead;" | ATK<br/>MIN/MAX (RANGE)
! style="background:#efdead;" | EXP/(JEXP)
! style="background:#efdead;" | Drops (Rate %)
""")
    MonsterWrite(Mobs1)

def mbdt(summary, content):
    return "<details>\
<summary>"+summary+"</summary>\
<pre>"+content+"</pre></details>"

def mb_rdmisc(mb):
    buff=""
    if "agr" in mb.st.lower():
        buff+="View Range: %s\n" % (mb.view)
    buff+="Attack Range: %s\n" % (mb.range)
    buff+="Move speed: %s ms\n" % (mb.move)
    return buff

def mb_rdrw(mb):
    buff=""
    buff+="MobPoints: %s\n" % (mb.mobpt)
    buff+="%s\n" % (mb.xp)
    buff+="%s\n" % (mb.jp)
    return buff

def mb_rddrop(mb):
    buff=""
    # sorted
    for ax in sorted(mb.drops, key=lambda xcv: float(xcv[1]), reverse=True):
        # Ignore disabled drops
        if ax[0].startswith("//"):
            continue

        # Write drop
        try:
            url=ax[0].replace(" ", "_")
            ctr=str(int(ax[1])/100.0)
            buff+="[[%s|%s]] (%s%%)<br>" % (url, ax[0], ctr)
            #buff+=ax[0]+': ' +  + ' %\n'
        except IndexError:
            print("Fatal: invalid %s mob with %s drops" % (mb.name, str(ax)))
            exit(1)
        except:
            print("[Warning] %s incorrect drop: %s" % (mb.name, str(ax)))
            buff+=ax[0]+': ' + ax[1] + ' ppm\n'

        # Save to SysDrops
        SysDrops.append([ax[0], ax[1], mb.name])

    return buff


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
    self.script=False

    # Visual
    self.sl="0" # Slots
    self.ac=False # Allow Cards

    # Script settings
    self.minheal="0"
    self.maxheal="0"
    self.delheal="0"

def ItAlloc(it):
    if (it.sl == "0" and it.ac) or (it.sl in ["1","2","3","4"] and not it.ac):
        print("WARNING, item id "+it.id+" invalid dye/card setting!")
    if (len(it.sl) > 1):
        print("WARNING, item id "+it.id+" bad slots length: %d (%s)" % (len(it.sl), it.sl))
    if it.ac:
        wikic.write(it.id + ": " + it.name + "\n")

    a=it.type
    if "IT_HEALING" in a:
        IT_HEALING.append(it)
    elif "IT_ETC" in a:
        IT_ETC.append(it)
    elif "IT_USABLE" in a:
        IT_USABLE.append(it)
    elif "IT_AMMO" in a:
        IT_AMMO.append(it)
    elif "IT_CARD" in a:
        IT_CARD.append(it)
    elif "IT_PETEGG" in a:
        IT_PETEGG.append(it)

    elif "IT_WEAPON" in a:
        if "HAND_L" in it.loc or "EQP_ARMS" in it.loc:
            IT_WEAPON["HAND_2"].append(it)
        elif "HAND_R" in it.loc:
            IT_WEAPON["HAND_1"].append(it)
        else:
            raise Exception("Invalid location for weapon: %s" % it.loc)

    elif "IT_ARMOR" in a:
        if 'EQP_ACC_L' in it.loc:
            IT_ARMOR['EQP_ACC_L'].append(it)
        elif 'EQP_ACC_R' in it.loc:
            IT_ARMOR['EQP_ACC_R'].append(it)
        elif 'EQP_HEAD_MID' in it.loc:
            IT_ARMOR['EQP_HEAD_MID'].append(it)
        elif 'EQP_SHOES' in it.loc:
            IT_ARMOR['EQP_SHOES'].append(it)
        elif 'EQP_GARMENT' in it.loc:
            IT_ARMOR['EQP_GARMENT'].append(it)
        elif 'EQP_HEAD_LOW' in it.loc:
            IT_ARMOR['EQP_HEAD_LOW'].append(it)
        elif 'EQP_HEAD_TOP' in it.loc:
            IT_ARMOR['EQP_HEAD_TOP'].append(it)
        elif 'EQP_HAND_L' in it.loc:
            IT_ARMOR['EQP_HAND_L'].append(it)
        elif '1024' in it.loc:
            IT_ARMOR['1024'].append(it)
        elif '2048' in it.loc:
            IT_ARMOR['2048'].append(it)
        elif 'EQP_SHADOW_SHOES' in it.loc:
            IT_ARMOR['EQP_MOUNT'].append(it)
        elif 'EQP_SHADOW_ACC_R' in it.loc:
            IT_ARMOR['EQP_ACC_R'].append(it) # Not really
        else:
            raise Exception("Invalid Loc for ID %s: %s" % (it.id, it.loc))

def newItemDB():
    print("\nGenerating Item Wiki...")
    if len(sys.argv) >= 2:
        src=open(sys.argv[1]+"/db/re/item_db.conf", "r")
    else:
        src=open("../../server-data/db/re/item_db.conf", "r")

    x=It()
    for a in src:
        a=a.replace("\t", "    ")
        if a == "{\n":
            ItAlloc(x)
            x=It()

        # sti() block
        if "    Id:" in a:
            x.id=sti(a)
        elif "    AegisName:" in a:
            x.aegis=sti(a)
        elif "    Name:" in a:
            x.name=stin(a)
        elif "    Sell:" in a:
            x.price=sti(a)
        elif "    Weight:" in a:
            x.weight=sti(a)
        elif "    Type:" in a:
            x.type=sti(a)
        elif "    Loc:" in a:
            x.loc=sti(a)
        elif "    Atk:" in a:
            x.atk=sti(a)
        elif "    Matk:" in a:
            x.matk=sti(a)
        elif "    Range:" in a:
            x.range=sti(a)
        elif "    Def:" in a:
            x.defs=sti(a)
        elif "    EquipLv:" in a:
            x.lvl=sti(a)
        elif "    Slots:" in a:
            x.sl=sti(a)
        elif "    AllowCards:" in a:
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
            x.script=True
        # For healing items
        elif "@min " in a:
            x.minheal=sti(a)
        elif "@max " in a:
            x.maxheal=sti(a)
        elif "@delay" in a:
            x.delheal=sti(a)

    # Write last entry
    ItAlloc(x)
    writeItems()

    src.close()

def sti(x):
    return x.replace('\n', '').replace('|', '').replace(')', '').replace('Id: ', '').replace('"','').replace("    ","").replace("\t","").replace('AegisName: ', '').replace('Name: ','').replace('Sell: ', '').replace('Weight: ', '').replace('Type: ', '').replace('Loc: ', '').replace('Atk: ', '').replace('Matk: ', '').replace('Range: ', '').replace('Def: ', '').replace('EquipLv: ', '').replace('Slots: ','').replace(" ", "").replace('@min=','').replace('@max=','').replace('@delay=','').replace(';','')

def stin(x):
    return x.replace('\n', '').replace('|', '').replace(')', '').replace('Id: ', '').replace('"','').replace("    ","").replace("\t","").replace('Name: ','').replace(';','')


def writeItems():
    wikia.write("# Items\n\
+ [Healing Items](#healing-items)\n\
+ [Usable Items](#usable-items)\n\
+ [Generic Items](#generic-items)\n\
+ [Ammo](#ammo)\n\
+ [Cards](#cards)\n\
+ [Pet Eggs](#pet-eggs)\n\
+ [Mounts](#mounts)\n\
+ [Weapons](#weapons)\n\
  + [1H Weapons](#1h-weapons)\n\
  + [2H Weapons](#2h-weapons)\n\
+ [Armors](#armors)\n\
  + [Left Accessory](#left-accessory)\n\
  + [Right Accessory](#right-accessory)\n\
  + [Headgear](#headgear)\n\
  + [Chest](#chest)\n\
  + [Pants](#pants)\n\
  + [Shoes](#shoes)\n\
  + [Necklaces](#necklaces)\n\
  + [Rings](#rings)\n\
  + [Gloves](#gloves)\n\
  + [Shields](#shields)\n\
\n\n")
    wikia.write("#### Restrictions Reference\n")
    wikia.write("Special Aegis Name Markers:\n\
+ * - Rare item with drop announce.\n\
+ (dp) - This item cannot be dropped.\n\
+ (tr) - This item cannot de traded.\n\
+ (sl) - This item cannot be sold.\n\
+ (gg) - This item cannot go to storage.\n\n")

    # Healing Items
    wikia.write("## Healing Items\n\n")
    ItemWrite(IT_HEALING, ID=True, AEGIS=True, PRICE=True, WEIGHT=True, HEALING=True, DROPPER=True)

    # Usable Items
    wikia.write("## Usable Items\n")
    ItemWrite(IT_USABLE, ID=True, AEGIS=True, NAME=True, PRICE=True, WEIGHT=True, DROPPER=True)

    # Generic Items
    wikia.write("## Generic Items\n")
    ItemWrite(IT_ETC, ID=True, AEGIS=True, NAME=True, PRICE=True, WEIGHT=True, DROPPER=True)

    # Ammo Items
    wikia.write("## Ammo\n")
    ItemWrite(IT_AMMO, ID=True, AEGIS=True, NAME=True, WEIGHT=True, ATK=True)

    # Card Items
    wikia.write("## Cards\n")
    ItemWrite(IT_CARD, ID=True, AEGIS=True, NAME=True, PRICE=True, WEIGHT=True)

    # Pet Egg Items
    wikia.write("## Pet Eggs\n")
    ItemWrite(IT_PETEGG, ID=True, AEGIS=True, NAME=True, WEIGHT=True)

    # Mount Items
    wikia.write("## Mounts\n")
    ItemWrite(IT_ARMOR['EQP_MOUNT'], ID=True, AEGIS=True, NAME=True, WEIGHT=True)

    ####################################################################
    wikia.write("# Weapons\n")

    # 1 Hand Items
    wikia.write("## 1H Weapons\n")
    ItemWrite(IT_WEAPON['HAND_1'], ID=True, AEGIS=True, PRICE=True, WEIGHT=True, ATK=True, LVL=True, DROPPER=True)

    # 2 Hand Items
    wikia.write("## 2H Weapons\n")
    ItemWrite(IT_WEAPON['HAND_2'], ID=True, AEGIS=True, PRICE=True, WEIGHT=True, ATK=True, LVL=True, RANGE=True)


    ####################################################################
    wikia.write("# Armors\n")

    ArmorWrite("Left Accessory",'EQP_ACC_L', False)
    ArmorWrite("Right Accessory",'EQP_ACC_R', False)
    ArmorWrite("Headgear",'EQP_HEAD_TOP')
    ArmorWrite("Chest",'EQP_HEAD_MID')
    ArmorWrite("Pants",'EQP_HEAD_LOW')
    ArmorWrite("Shoes",'EQP_SHOES')
    ArmorWrite("Necklaces",'1024', False)
    ArmorWrite("Rings",'2048', False)
    ArmorWrite("Gloves",'EQP_GARMENT')
    ArmorWrite("Shields",'EQP_HAND_L')

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

def ItemWrite(tbl, ID=False, AEGIS=False, NAME=False, PRICE=False, WEIGHT=True, DEF=False, LVL=False, ATK=False, RANGE=False, HEALING=False, SCRIPT=False, DROPPER=False):
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
    if LVL:
        wikia.write("<th>Lvl</th>")
    if ATK:
        wikia.write("<th>Atk</th>")
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

    for i in tbl:
        try:
            zt=int(i.weight)
        except:
            tbl.remove(i)

    for i in sorted(tbl, key=lambda xcv: int(xcv.weight), reverse=True):
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
        if LVL:
            wikia.write("<td>Lv: %s</td>" % i.lvl)
        if ATK:
            wikia.write("<td>Atk: %s</td>" % i.atk)
            wikia.write("<td>%s</td>" % i.matk)
        if RANGE:
            wikia.write("<td>%s</td>" % i.range)
        if HEALING:
            wikia.write("<td>%s</td>" % i.minheal)
            wikia.write("<td>%s</td>" % i.maxheal)
            wikia.write("<td>%s s</td>" % i.delheal)
        if SCRIPT:
            wikia.write("<td>%s</td>" % i.script)
        # TODO: Check for item Aegis in npc/ folder too, to determine shops and quests.
        if DROPPER:
            tmp_droppers=""
            tmp_drpalign=[]
            for ax in SysDrops:
                if ax[0] == i.aegis:
                    tmp_drpalign.append([ax[2], ax[1]])
            if len(tmp_drpalign) > 0:
                for a in sorted(tmp_drpalign,  key=lambda xcv: float(xcv[1]), reverse=True):
                    try:
                        ppm=int(a[1])/100.0
                        tmp_droppers+=("%s: %.2f %% \n" % (a[0], ppm))
                    except:
                        print("[Warning] %s whodrop error: %s" % (i.name, str(a)))
                wikia.write("<td>%s</td>" % mbdt("monsters", tmp_droppers))
            else:
                wikia.write("<td>-</td>")

        wikia.write("</tr>")

    wikia.write("</table>\n")
    wikia.write("\n[(↑) Return to top](#items)\n\n")

def ArmorWrite(name,scope,defitem=True):
    wikia.write("## "+name+"\n")
    ItemWrite(IT_ARMOR[scope], ID=True, AEGIS=True, PRICE=True, WEIGHT=True, DEF=defitem, LVL=True, DROPPER=True)











class Quest:
  def __init__(self, ide):
    # Basic
    self.id=ide
    self.name="Unknown Quest Name"
    self.group="Unknown"
    self.ent=[]


class QuestEntry:
  def __init__(self):
    # Basic
    self.complete=False
    self.entry=[] # collection of <text>
    self.giver=""
    self.reward=""
    self.loc=""

def qnt(string):
    return string.replace(' ','').replace('"','').replace("'","").replace('<','').replace('>','').replace('nowiki=1', '').replace('nowiki', '')

def qnt2(string):
    return string.replace('##B','**').replace('##b','**').replace('##0','*').replace('##1','*').replace('##2','*').replace('##3','*').replace('##','*')

def DoQuest():
    print("\nGenerating Quest Wiki...")
    if len(sys.argv) >= 3:
        src=open(sys.argv[2]+"/quests.xml", "r")
    else:
        src=open("../../client-data/quests.xml", "r")

    qlog=[]
    q=Quest(-1)
    qe=QuestEntry()
    ig=False
    nw=False

    for e in src:
        # Handle Comments and Ignored lines
        if '<!--' in e and '-->' in e:
            continue
        elif '<!--' in e:
            ig=True
        elif '-->' in e:
            ig=False
        if '<effect' in e:
            continue

        if ig:
            continue

        # Handle Quest Headers
        if '</var' in e:
            if (nw):
                nw=False
            else:
                qlog.append(q)
        elif '<var' in e:
            if 'nowiki' in e:
                nw=True
            g=qnt(e)
            try:
                q=Quest(int(  g.replace('varid=','')  ))
            except:
                print("Invalid quest: %s" % g)
                exit(1)

        # Handle quest entries
        if '</quest>' in e:
            q.ent.append(qe)
        elif '<quest ' in e:
            qe=QuestEntry()
            l=e.split('"')
            rc=[False, ""]
            for arg in l:
                if not rc[0]:
                    if "name" in arg:
                        rc=[True, 'name']
                    elif "group" in arg:
                        rc=[True, 'group']
                    elif "complete" in arg:
                        rc=[True, arg.replace('=','').replace(' ','')]
                else:
                    if rc[1] == "name":
                        q.name=arg
                    elif rc[1] == "group":
                        q.group=arg
                    elif rc[1] == "complete":
                        qe.complete=True
                    elif rc[1] == "incomplete":
                        qe.complete=False
                    else:
                        print("Invalid <quest> tag: %s (arg was %s) (line was %s)" % (e, rc[1], l))
                        exit(1)
                    rc=[False, ""]

        # Fill stuff in Quest Entry
        if '<text' in e:
            a=qnt2(e)
            qe.entry.append(  a.replace('<text>','').replace('</text>','').replace('<text ','<').replace("@@1", "text").replace("@@", "").strip()  )
        elif '<wiki' in e:
            a=qnt2(e)
            qe.entry.append(  a.replace('<wiki>','').replace('</wiki>','').replace('<wiki ','<').replace("@@1", "text").replace("@@", "").strip()  )
        elif '<questgiver' in e:
            a=qnt2(e)
            qe.giver=a.replace('<questgiver>','').replace('</questgiver>','').strip()
        elif '<reward' in e:
            a=qnt2(e)
            qe.reward=a.replace('<reward>','').replace('</reward>','').replace("@@", "text").replace('<reward ','<').strip()
        elif '<coord' in e:
            a=qnt2(e)
            b=a.split('>')
            qe.loc=b[1].replace('</coordinates','').strip()
        elif '<level' in e:
            a=qnt2(e)
            qe.entry.append(  "Required Level: " + a.replace('<level>','').replace('</level>','').strip()  )

    # Done reading file
    src.close()
    aktbl={}
    aksort=[]
    print("\033[32;1mTotal quests: %d\033[0m" % len(qlog))
    for i in qlog:
        if i.name=="Unknown Quest Name":
            print("Warning, invalid quest: %d" % (i.id))
            qlog.remove(i)
            continue
        # Total Table
        #print(str(i.id)+": "+i.name)
        try:
            aktbl[i.group].append("[%s](q/%d)" % (i.name, i.id))
        except:
            aktbl[i.group]=["[%s](q/%d)" % (i.name, i.id)]
            aksort.append(i.group)

        # Individual file
        f=open("../../wiki/q/"+str(i.id)+'.md', "w")
        f.write("<!-- --- title: %d: %s -->\n\n" % (i.id, i.name))
        f.write("# %s\n" % i.name)
        f.write('\n')

        totalcnt=0
        for a in i.ent:
            totalcnt+=1
            f.write('\n### %d Stage\n\n' % totalcnt)
            if a.complete:
                f.write('*This completes quest*\n\n')

            if a.giver != "" or a.reward != "" or a.loc != "":
                f.write('```\n')
                if a.giver != "":
                    f.write('Quest Giver: %s\n' % a.giver)
                if a.reward != "":
                    f.write('Reward: %s\n' % a.reward.replace('@@', ''))
                if a.loc != "":
                    f.write('Location: %s\n' % a.loc)
                f.write('```\n\n')

            for line in a.entry:
                f.write('%s\n' % line)

        f.write('\n\n****\nThis file is generated automatically. Editing it will have no effect.\n')
        f.close()

    # Write total table
    f=open("Quests.txt", "w")
    f.write("***Total quests: %d***\n" % len(qlog))
    for key in aksort:
        f.write('\n## %s\n\n' % key)
        for a in aktbl[key]:
            f.write('+ '+a+'\n')
    f.close()

showHeader()

testMobs()
newItemDB()
DoQuest()

wikia.close()
wikib.close()
wikic.close()
wikid.close()
#print(str(SysDrops))

showFooter()
exit(0)
