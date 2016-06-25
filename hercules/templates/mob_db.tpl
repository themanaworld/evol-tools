//================= Hercules Database =====================================
//=       _   _                     _
//=      | | | |                   | |
//=      | |_| | ___ _ __ ___ _   _| | ___  ___
//=      |  _  |/ _ \ '__/ __| | | | |/ _ \/ __|
//=      | | | |  __/ | | (__| |_| | |  __/\__ \
//=      \_| |_/\___|_|  \___|\__,_|_|\___||___/
//================= License ===============================================
//= This file is part of Hercules.
//= http://herc.ws - http://github.com/HerculesWS/Hercules
//=
//= Copyright (C) 2015  Hercules Dev Team
//=
//= Hercules is free software: you can redistribute it and/or modify
//= it under the terms of the GNU General Public License as published by
//= the Free Software Foundation, either version 3 of the License, or
//= (at your option) any later version.
//=
//= This program is distributed in the hope that it will be useful,
//= but WITHOUT ANY WARRANTY; without even the implied warranty of
//= MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//= GNU General Public License for more details.
//=
//= You should have received a copy of the GNU General Public License
//= along with this program.  If not, see <http://www.gnu.org/licenses/>.
//=========================================================================
//= Mobs Database
//=========================================================================

mob_db: (
//  Mobs Database
//
/******************************************************************************
 ************* Entry structure ************************************************
 ******************************************************************************
{
    // =================== Mandatory fields ===============================
    Id: ID                                (int)
    SpriteName: "SPRITE_NAME"             (string)
    Name: "Mob name"                      (string)
    // =================== Optional fields ================================
    JName: "Mob name"                     (string)
    Lv: level                             (int, defaults to 1)
    Hp: health                            (int, defaults to 1)
    Sp: mana                              (int, defaults to 0)
    Exp: basic experience                 (int, defaults to 0)
    JExp: job experience                  (int, defaults to 0)
    AttackRange: attack range             (int, defaults to 1)
    Attack: [attack1, attack2]            (int, defaults to 0)
    Def: defence                          (int, defaults to 0)
    Mdef: magic defence                   (int, defaults to 0)
    Stats: {
        Str: strength                 (int, defaults to 0)
        Agi: agility                  (int, defaults to 0)
        Vit: vitality                 (int, defaults to 0)
        Int: intelligence             (int, defaults to 0)
        Dex: dexterity                (int, defaults to 0)
        Luk: luck                     (int, defaults to 0)
    }
    ViewRange: view range                 (int, defaults to 1)
    ChaseRange: chase range               (int, defaults to 1)
    Size: size                            (int, defaults to 1)
    Race: race                            (int, defaults to 0)
    Element: (type, level)
    Mode: {
        CanMove: true/false           (bool, defaults to false)
        Looter: true/false            (bool, defaults to false)
        Aggressive: true/false        (bool, defaults to false)
        Assist: true/false            (bool, defaults to false)
        CastSensorIdle:true/false     (bool, defaults to false)
        Boss: true/false              (bool, defaults to false)
        Plant: true/false             (bool, defaults to false)
        CanAttack: true/false         (bool, defaults to false)
        Detector: true/false          (bool, defaults to false)
        CastSensorChase: true/false   (bool, defaults to false)
        ChangeChase: true/false       (bool, defaults to false)
        Angry: true/false             (bool, defaults to false)
        ChangeTargetMelee: true/false (bool, defaults to false)
        ChangeTargetChase: true/false (bool, defaults to false)
        TargetWeak: true/false        (bool, defaults to false)
        NoKnockback: true/false       (bool, defaults to false)
        SurviveWithoutMaster: true/false (bool, defaults to false)
    }
    MoveSpeed: move speed                 (int, defaults to 0)
    WalkMask: walk mask                   (int, defaults to 0)
    AttackDelay: attack delay             (int, defaults to 4000)
    AttackMotion: attack motion           (int, defaults to 2000)
    DamageMotion: damage motion           (int, defaults to 0)
    MvpExp: mvp experience                (int, defaults to 0)
    MvpDrops: {
        AegisName: chance             (string: int)
        ...
    }
    Drops: {
        AegisName: chance         (string: int)
        ...
    }

},
******************************************************************************/

