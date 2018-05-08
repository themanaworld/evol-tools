#!/usr/bin/env python
# -*- encoding: utf-8 -*-

##    tmx_converter.py - Extract walkmap, warp, and spawn information from maps.
##
##    Copyright © 2012 Ben Longbons <b.r.longbons@gmail.com>
##    Copyright © 2016-2018 The Mana World Developers
##
##    This file is part of The Mana World
##
##    This program is free software: you can redistribute it and/or modify
##    it under the terms of the GNU General Public License as published by
##    the Free Software Foundation, either version 2 of the License, or
##    (at your option) any later version.
##
##    This program is distributed in the hope that it will be useful,
##    but WITHOUT ANY WARRANTY; without even the implied warranty of
##    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##    GNU General Public License for more details.
##
##    You should have received a copy of the GNU General Public License
##    along with this program.  If not, see <http://www.gnu.org/licenses/>.


from __future__ import print_function

import sys
import os
import posixpath
import xml.sax

dump_all = False # wall of text
check_mobs = False # mob_db.txt

# lower case versions of everything except 'spawn' and 'warp'
other_object_types = set([
    'particle_effect',
    'npc', # not interpreted by client
    'script', # for ManaServ
    'fixme', # flag for things that didn't have a type before
    'music',
])

# Somebody has put ManaServ fields in our data!
other_spawn_fields = (
    'spawn_rate',
)
other_warp_fields = (
)

TILESIZE = 32
SEPARATOR = ''
MESSAGE = 'This file is generated automatically. All manually added changes will be removed when running the Converter.'
CLIENT_MAPS = 'maps'
SERVER_WLK = 'data'
SERVER_NPCS = 'npc'
MOB_DB_CONF = 'db/re/mob_db.conf'
MAP_CONF = 'conf/map/maps.conf'
MAP_DB_CONF = 'db/map_index.txt'
NPC_MOBS = '_mobs.txt'
NPC_SAVES = '_savepoints.txt'
NPC_WARPS = '_warps.txt'
NPC_IMPORTS = '_import.txt'
NPC_MASTER_IMPORTS = NPC_IMPORTS
NPC_MASTER_ANCHORS = '_anchors.txt'

class State(object):
    pass
State.INITIAL = State()
State.LAYER = State()
State.DATA = State()
State.FINAL = State()

class Object(object):
    __slots__ = (
        'name',
        'x', 'y',
        'w', 'h',
        'ignore',
    )
class Mob(Object):
    __slots__ = (
        'monster_id',
        'max_beings',
        'spawn',
        'death',
        'script',
    ) + other_spawn_fields
    def __init__(self):
        self.max_beings = 1
        self.spawn = 0
        self.death = 0
        self.script = ''

class Save(Object):
    __slots__ = (
        'inn',
    )

class Anchor(Object):
    __slots__ = (
    )

class Warp(Object):
    __slots__ = (
        'dest_map',
        'dest_x',
        'dest_y',
        'npc_id',
        'trigger_x',
        'trigger_y',
    ) + other_warp_fields
    def __init__(self):
        self.npc_id = 'WARP'

class ContentHandler(xml.sax.ContentHandler):
    __slots__ = (
        'locator',       # keeps track of location in document
        'state',         # state of height info
        'tilesets',      # first gid of each tileset
        'buffer',        # characters within a section
        'width',         # width of the height layer
        'height',        # height of the height layer
        'firstgid',      # first gid of height layer
        'heightmap',     # height map
        'base',          # base name of current map
        'npc_dir',       # world/map/npc/<base>
        'mobs',          # open file to _mobs.txt
        'warps',         # open file to _warps.txt
        'imports',       # open file to _import.txt
        'name',          # name property of the current map
        'object',        # stores properties of the latest <object> tag
        'mob_ids',       # set of all mob types that spawn here
        'anchor_master', # list of all anchors
    )
    def __init__(self, npc_dir, mobs, saves, warps, imports, anchor_master):
        xml.sax.ContentHandler.__init__(self)
        self.locator = None
        self.state = State.INITIAL
        self.tilesets = set([0]) # consider the null tile as its own tileset
        self.buffer = bytearray()
        self.width = None
        self.height = None
        self.firstgid = 0
        self.heightmap = ''
        self.base = posixpath.basename(npc_dir)
        self.npc_dir = npc_dir
        self.mobs = mobs
        self.saves = saves
        self.warps = warps
        self.imports = imports
        self.anchor_master = anchor_master
        self.object = None
        self.mob_ids = set()
        self.mob_cnt = False
        self.save_cnt = False
        self.warp_cnt = False
        self.name = None
        self.layer_name = u''
        self.layers = set()

    def setDocumentLocator(self, loc):
        self.locator = loc

    # this method randomly cuts in the middle of a line; thus funky logic
    def characters(self, s):
        if not s.strip():
            return
        if self.state is State.DATA:
            self.buffer += s.encode('ascii')

    def startDocument(self):
        pass

    def startElement(self, name, attr):
        if dump_all:
            attrs = ' '.join('%s="%s"' % (k,v) for k,v in attr.items())
            if attrs:
                print('<%s %s>' % (name, attrs))
            else:
                print('<%s>' % name)

        if self.state is State.INITIAL:
            if name == u'property':
                if (attr[u'name'] == u'name'):
                    self.name = attr[u'value']
                    self.mobs.write('// %s\n' % MESSAGE)
                    self.mobs.write('// Map %s: %s mobs\n' % (self.base, self.name))
                    self.saves.write('// %s\n' % MESSAGE)
                    self.saves.write('// Map %s: %s saves\n' % (self.base, self.name))
                    self.warps.write('// %s\n' % MESSAGE)
                    self.warps.write('// Map %s: %s warps\n' % (self.base, self.name))
                elif attr[u'name'] == u'ignore':
                    print("\n\nIgnore flag detected on map %s. Skipping..." % self.base)
                    raise Exception

            if name == u'tileset':
                self.tilesets.add(int(attr[u'firstgid']))
                if 'name' in attr.__dict__['_attrs'].keys():
                  if attr[u'name'] == u'Height Numbers':
                    self.firstgid = int(attr[u'firstgid'])

            if name == u'layer':
                self.width = int(attr[u'width'])
                self.height = int(attr[u'height'])
                self.layers.add(attr[u'name'].lower())
                self.layer_name = attr[u'name'].lower()
                self.state = State.LAYER
        elif self.state is State.LAYER:
            if name == u'layer':
                self.layers.add(attr[u'name'].lower())
                self.layer_name = attr[u'name'].lower()
            elif name == u'data':
                if self.layer_name.startswith(u'height'):
                    if attr.get(u'encoding','') not in (u'', u'csv'):
                        print('Bad encoding:', attr.get(u'encoding',''))
                        return
                    if attr.get(u'compression','') not in (u'', u'none'):
                        print('Bad compression:', attr.get(u'compression',''))
                        return
                    self.state = State.DATA
            elif name == u'properties' or name == u'property':
                pass
            else:
                self.state = State.FINAL
                if not u'collision' in self.layers:
                    print("\n\nERROR: missing Collision layer on map %s." % (self.base))
                    raise AttributeError('collision')
                if not u'fringe' in self.layers:
                    print("\n\nERROR: missing Fringe layer on map %s." % (self.base))
                    raise AttributeError('fringe')
                for layer in self.layers:
                    if layer.startswith(u'height'):
                        return
                print("\n\nERROR: missing Heights layer on map %s." % (self.base))
                raise AttributeError('heights')
        elif self.state is State.FINAL:
            if self.name is None:
                print("\n\nERROR: missing property on map %s: name is mandatory on a map." % (self.base))
                raise AttributeError('name')

            if name == u'object':
                obj_type = attr[u'type'].lower()
                x = int(int(attr[u'x']) / TILESIZE)
                y = int(int(attr[u'y']) / TILESIZE)
                w = int(int(attr.get(u'width', 0)) / TILESIZE)
                h = int(int(attr.get(u'height', 0)) / TILESIZE)
                # I'm not sure exactly what the w/h shrinking is for,
                # I just copied it out of the old converter.
                # I know that the x += w/2 is to get centers, though.
                if obj_type == 'spawn':
                    self.object = Mob()
                    w =  int((w - 1) / 2)
                    h =  int((h - 1) / 2)
                    if w < 0:
                        w = 0
                    else:
                        x += w
                    if h < 0:
                        h = 0
                    else:
                        y += h
                elif obj_type == 'save':
                    self.object = Save()
                    x += w/2
                    y += h/2
                    w -= 2
                    h -= 2
                elif obj_type == 'anchor':
                    self.object = Anchor()
                    x += w/2
                    y += h/2
                    w -= 2
                    h -= 2
                elif obj_type == 'warp':
                    self.object = Warp()
                    x += w/2
                    y += h/2
                    w -= 1
                    h -= 1
                else:
                    if obj_type not in other_object_types:
                        print('Unknown object type:', obj_type, file=sys.stderr)
                    self.object = None
                    return
                obj = self.object
                obj.x = x
                obj.y = y
                obj.w = w
                obj.h = h
                obj.name = attr[u'name']
            elif name == u'property':
                obj = self.object
                if obj is None:
                    return
                key = attr[u'name'].lower()
                value = attr[u'value']
                # Not true due to defaulting
                #assert not hasattr(obj, key)
                try:
                    value = int(value)
                except ValueError:
                    pass
                try:
                    setattr(obj, key, value)
                except AttributeError:
                    print("\n\nERROR: extraneous property on object \"%s\": %s is not allowed on a %s object." % (obj.name, key, obj.__class__.__name__.lower()))
                    raise

    def add_warp_line(self, line):
        self.warps.write(line)

    def endElement(self, name):
        if dump_all:
            print('</%s>' % name)

        if name == u'object':
            if hasattr(self.object, 'ignore'):
                return
            obj = self.object
            try:
                if isinstance(obj, Mob):
                    mob_id = obj.monster_id
                    if check_mobs:
                        try:
                            name = mob_names[mob_id]
                        except KeyError:
                            print('Warning: unknown mob ID: %d (%s)' % (mob_id, obj.name))
                        else:
                            if name != obj.name:
                                print('Warning: wrong mob name: %s (!= %s)' % (obj.name, name))
                                obj.name = name
                    self.mob_ids.add(mob_id)
                    if obj.script:
                        obj.script = ",%s" % (obj.script)
                    self.mobs.write(
                        SEPARATOR.join([
                            '%s,%d,%d,%d,%d\t' % (self.base, obj.x, obj.y, obj.w, obj.h),
                            'monster\t',
                            obj.name,
                            '\t%d,%d,%d,%d%s\n' % (mob_id, obj.max_beings, obj.spawn, obj.death, obj.script),
                        ])
                    )
                    self.mob_cnt = True
                elif isinstance(obj, Save):
                    obj_name = "%s_%s_%s" % (self.base, obj.x, obj.y)
                    self.saves.write(
                        SEPARATOR.join([
                            '%s,%d,%d,0\tscript\t#save_%s\tNPC_SAVE_POINT,{\n' % (self.base, obj.x, obj.y, obj_name),
                            '    savepointparticle .map$, .x, .y, %s;\n    close;\n\nOnInit:\n    .distance = 2;\n    .sex = G_OTHER;\n    end;\n}\n' % (obj.inn),
                        ])
                    )
                    self.save_cnt = True
                elif isinstance(obj, Anchor):
                    self.anchor_master.append('    htput(.ht, "%s", "%s %d %d");\n' % (obj.name.upper(), self.base, obj.x, obj.y))
                elif isinstance(obj, Warp):
                    if (obj.npc_id == u'WARP'):
                        obj_name = "#%s_%s_%s" % (self.base, obj.x, obj.y)
                        y_offset = int(self.heightmap[((obj.y * self.width) + obj.x)])/2
                        self.warps.write(
                            SEPARATOR.join([
                                '%s,%d,%d,0\t' % (self.base, obj.x, (obj.y + y_offset)),
                                'warp\t',
                                '%s\t%s,%s,%s,%d,%d\n' % (obj_name, obj.w, obj.h, obj.dest_map, obj.dest_x, obj.dest_y),
                            ])
                        )
                        self.warp_cnt = True
                    elif (not obj.npc_id == u'SCRIPT'):
                        obj_name = "#%s_%s_%s" % (self.base, obj.x, obj.y)
                        self.warps.write(
                            SEPARATOR.join([
                                '%s,%d,%d,0\tscript\t%s_h\tNPC_HIDDEN,0,0,{\n' % (self.base, obj.x, obj.y, obj_name),
                                'OnTouch:\n    warp "%s", %d, %d;\nclose;\n\nOnUnTouch:\n    doevent "%s::OnUnTouch";\n}\n' % (obj.dest_map, obj.dest_x, obj.dest_y, obj_name),
                                '%s,%d,%d,0\tscript\t%s\t%s,%d,%d,{\n    close;\nOnTouch:\n    doorTouch;\n\nOnUnTouch:\n    doorUnTouch;\n\nOnTimer340:\n    doorTimer;\n\nOnInit:\n    doorInit;\n}\n\n' % (self.base, obj.x, obj.y, obj_name, obj.npc_id, obj.trigger_x, obj.trigger_y),
                            ])
                        )
                        self.warp_cnt = True
            except AttributeError, prop:
                print("\n\nERROR: missing property on object \"%s\": %s is mandatory on a %s object." % (obj.name, prop, obj.__class__.__name__.lower()));
                raise

        if name == u'data':
            if self.state is State.DATA:
                for x in self.buffer.split(','):
                    if int(x) > 0:
                        self.heightmap += str((int(x) - int(self.firstgid)) + 1)
                    else:
                        self.heightmap += str(x)
                self.state = State.LAYER

    def endDocument(self):
        if not self.mob_cnt:
            os.remove(posixpath.join(main.this_map_npc_dir, NPC_MOBS))
        if not self.save_cnt:
            os.remove(posixpath.join(main.this_map_npc_dir, NPC_SAVES))
        if not self.warp_cnt:
            os.remove(posixpath.join(main.this_map_npc_dir, NPC_WARPS))

        imp_cnt = (len(os.walk(self.npc_dir).next()[2]))

        if imp_cnt > 0:
            self.imports.write('// Map %s: %s\n' % (self.base, self.name))
            self.imports.write('// %s\n' % MESSAGE)

            npcs = os.listdir(self.npc_dir)
            npcs.sort()
            for x in npcs:
                if x == NPC_IMPORTS:
                    continue
                if x.startswith('.'):
                    continue
                if x.endswith('.txt'):
                    self.imports.write('"%s",\n' % posixpath.join(SERVER_NPCS, self.base, x))
        else:
            os.remove(posixpath.join(main.this_map_npc_dir, NPC_IMPORTS))

def main(argv):
    _, client_data, server_data = argv
    tmx_dir = posixpath.join(client_data, CLIENT_MAPS)
    npc_dir = posixpath.join(server_data, SERVER_NPCS)
    if check_mobs:
        global mob_names
        mob_names = {}
        with open(posixpath.join(server_data, MOB_DB_CONF)) as mob_db:
            for line in mob_db:
                if not line.strip():
                    continue
                if line.startswith('//'):
                    continue

    npc_master = []
    anchor_master = []
    map_basenames = []

    map_conf = open(posixpath.join(server_data,MAP_CONF), 'w')
    map_db = open(posixpath.join(server_data,MAP_DB_CONF), 'w')
    map_conf.write("map_removed: (\n)\nmap_list: (\n")
    map_count = 1
    for arg in sorted(os.listdir(tmx_dir)):
        base, ext = posixpath.splitext(arg)

        if ext == '.tmx':
            map_basenames.append(base)
            tmx = posixpath.join(tmx_dir, arg)
            main.this_map_npc_dir = posixpath.join(npc_dir, base)
            os.path.isdir(main.this_map_npc_dir) or os.mkdir(main.this_map_npc_dir)
            sys.stdout.write('\033[2K\rConverting: %s' % (tmx))
            sys.stdout.flush()
            try:
                with open(posixpath.join(main.this_map_npc_dir, NPC_MOBS), 'w') as mobs:
                    with open(posixpath.join(main.this_map_npc_dir, NPC_SAVES), 'w') as saves:
                        with open(posixpath.join(main.this_map_npc_dir, NPC_WARPS), 'w') as warps:
                            with open(posixpath.join(main.this_map_npc_dir, NPC_IMPORTS), 'w') as imports:
                                xml.sax.parse(tmx, ContentHandler(main.this_map_npc_dir, mobs, saves, warps, imports, anchor_master))
                if os.path.isfile(posixpath.join(main.this_map_npc_dir, NPC_IMPORTS)):
                    npc_master.append('@include "%s"\n' % posixpath.join(SERVER_NPCS, base, NPC_IMPORTS))

                map_db.write('%s %d\n' % (arg.split('.')[0], map_count))
                map_conf.write('    "%s",\n' % (arg.split('.')[0]))
                map_count += 1
            except Exception:
                if 'CI' in os.environ:
                    raise # re-raise to make CI jobs fail
                else:
                    print("map %s has been ignored." % base)
    map_conf.write(")\n")
    sys.stdout.write('\033[2K\nDone: %i maps converted.\n' % map_count)
    sys.stdout.flush()
    with open(posixpath.join(npc_dir, NPC_MASTER_ANCHORS), 'w') as out:
        out.write('// %s\n\n' % MESSAGE)
        out.write('-\tscript\t__anchors__\t32767,{\n')
        out.write('OnInit:\n')
        out.write('    .ht = htnew();\n')
        anchor_master.sort()
        for line in anchor_master:
            out.write(line)
        out.write('}\n')
    with open(posixpath.join(npc_dir, NPC_MASTER_IMPORTS), 'w') as out:
        out.write('// %s\n\n' % MESSAGE)
        npc_master.sort()
        for line in npc_master:
            out.write(line)
        out.write('"%s",\n' % posixpath.join(SERVER_NPCS, NPC_MASTER_ANCHORS))

if __name__ == '__main__':
    main(sys.argv)
