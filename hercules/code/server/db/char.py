# -*- coding: utf8 -*-
#
# Copyright (C) 2015  Evol Online
# Author: Andrei Karas (4144)

from code.fileutils import *
from code.stringutils import *

def saveCharTable(users):
    dstFile = "newdb/char.sql"
    firstLine = True
    tpl = readFile("templates/char.sql")
    with open(dstFile, "w") as w:
        w.write(tpl)
        w.write("INSERT INTO `char` VALUES ")
        for userId in users:
            user = users[userId]

            if firstLine == False:
                w.write(",\n")
            else:
                firstLine = False

            w.write(("({char_id},{account_id},{char_num},'{name}',{CLASS}," +
                "{base_level},{job_level},{base_exp},{job_exp},{zeny}," +
                "{str},{agi},{vit},{INT},{dex},{luk},{max_hp},{hp},{max_sp}," +
                "{sp},{status_point},{skill_point},{option},{karma},{manner}," +
                "{party_id},{guild_id},{pet_id},{homun_id},{elemental_id}," +
                "{hair},{hair_color},{clothes_color},{body},{weapon},{shield}," +
                "{head_top},{head_mid},{head_bottom},{robe}," +
                "'{last_map}',{last_x},{last_y},'{save_map}',{save_x},{save_y}," +
                "{partner_id},{online},{father},{mother},{child},{fame}," +
                "{rename},{delete_date},{slotchange},{char_opt},{font}," +
                "{unban_time},{uniqueitem_counter},'{sex}',{hotkey_rowshift})").format(
                char_id = user.char_id,
                account_id = user.account_id,
                char_num = user.char_num,
                name = escapeSqlStr(user.char_name),
                CLASS = user.char_class,
                base_level = user.base_level,
                job_level = user.job_level,
                base_exp = user.base_exp,
                job_exp = user.job_exp,
                zeny = user.zeny,
                str = user.stat_str,
                agi = user.stat_agi,
                vit = user.stat_vit,
                INT = user.stat_int,
                dex = user.stat_dex,
                luk = user.stat_luk,
                max_hp = user.max_hp,
                hp = user.hp,
                max_sp = user.max_sp,
                sp = user.sp,
                status_point = user.status_point,
                skill_point = user.skill_point,
                option = user.option,
                karma = user.karma,
                manner = user.manner,
                party_id = user.party_id,
                guild_id = user.guild_id,
                pet_id = user.pet_id,
                homun_id = "0",
                elemental_id = "0",
                hair = user.hair,
                hair_color = user.hair_color,
                clothes_color = user.clothes_color,
                body = 0,
                weapon = user.weapon,
                shield = user.shield,
                head_top = user.head_top,
                head_mid = user.head_mid,
                head_bottom = user.head_bottom,
                robe = "0",
                last_map = escapeSqlStr(user.last_map),
                last_x = user.last_x,
                last_y = user.last_y,
                save_map = escapeSqlStr(user.save_map),
                save_x = user.save_x,
                save_y = user.save_y,
                partner_id = user.partner_id,
                online = "0",
                father = "0",
                mother = "0",
                child = "0",
                fame = "0",
                rename = "0",
                delete_date = "0",
                slotchange = "0",
                char_opt = "0",
                font = "0",
                unban_time = "0",
                uniqueitem_counter = len(user.inventory),
                sex = "U",
                hotkey_rowshift = 0
            ))
        w.write("\n")

def saveCharTableCustom(users):
    dstFile = "newdb/char.sql"
    firstLine = True
    tpl = readFile("templates/char.sql")
    with open(dstFile, "w") as w:
        w.write(tpl)
        w.write("INSERT INTO `char` VALUES ")
        for userId in users:
            user = users[userId]

            if firstLine == False:
                w.write(",\n")
            else:
                firstLine = False

            w.write(("({char_id},{account_id},{char_num},'{name}',{CLASS}," +
                "{base_level},{job_level},{base_exp},{job_exp},{zeny}," +
                "{str},{agi},{vit},{INT},{dex},{luk},{max_hp},{hp},{max_sp}," +
                "{sp},{status_point},{skill_point},{option},{karma},{manner}," +
                "{party_id},{guild_id},{pet_id},{homun_id},{elemental_id}," +
                "{hair},{hair_color},{clothes_color},{body},{weapon},{shield}," +
                "{head_top},{head_mid},{head_bottom},{robe}," +
                "'{last_map}',{last_x},{last_y},'{save_map}',{save_x},{save_y}," +
                "{partner_id},{online},{father},{mother},{child},{fame}," +
                "{rename},{delete_date},{slotchange},{char_opt},{font}," +
                "{unban_time},{uniqueitem_counter},'{sex}',{hotkey_rowshift})").format(
                char_id = user.char_id,
                account_id = user.account_id,
                char_num = user.char_num,
                name = escapeSqlStr(user.char_name),
                CLASS = 0,
                base_level = user.base_level,
                job_level = user.job_level,
                base_exp = user.base_exp,
                job_exp = user.job_exp,
                zeny = user.zeny,
                str = user.stat_str,
                agi = user.stat_agi,
                vit = user.stat_vit,
                INT = user.stat_int,
                dex = user.stat_dex,
                luk = user.stat_luk,
                max_hp = user.max_hp,
                hp = user.hp,
                max_sp = user.max_sp,
                sp = user.sp,
                status_point = user.status_point,
                skill_point = user.skill_point,
                option = user.option,
                karma = user.karma,
                manner = user.manner,
                party_id = 0,
                guild_id = 0,
                pet_id = 0,
                homun_id = "0",
                elemental_id = "0",
                hair = user.hair,
                hair_color = user.hair_color,
                clothes_color = user.clothes_color,
                body = 0,
                weapon = user.weapon,
                shield = user.shield,
                head_top = user.head_top,
                head_mid = user.head_mid,
                head_bottom = user.head_bottom,
                robe = "0",
                last_map = "000-2-1",
                last_x = 50,
                last_y = 37,
                save_map = "00-2-1",
                save_x = 50,
                save_y = 37,
                partner_id = user.partner_id,
                online = "0",
                father = "0",
                mother = "0",
                child = "0",
                fame = "0",
                rename = "0",
                delete_date = "0",
                slotchange = "0",
                char_opt = "0",
                font = "0",
                unban_time = "0",
                uniqueitem_counter = len(user.inventory),
                sex = "U",
                hotkey_rowshift = 0
            ))
        w.write("\n")
