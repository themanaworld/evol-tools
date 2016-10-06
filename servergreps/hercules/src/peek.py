#! /usr/bin/env python2
# -*- coding: utf8 -*-
#
# Copyright (C) 2015-2016  Evol Online
# Author: Andrei Karas (4144)

import configparser
import os

class Peek:
    inPacketsSorted = []
    inPackets = dict()
    knownLenPackets = dict()

#    staticMap = {
#    }

    shuffleMap = {
        '0': 'clif->pActionRequest',
        '1': 'clif->pUseSkillToId',
        '2': 'clif->pWalkToXY',
        '3': 'clif->pTickSend',
        '4': 'clif->pChangeDir',
        '5': 'clif->pTakeItem',
        '6': 'clif->pDropItem',
        '7': 'clif->pMoveToKafra',
        '8': 'clif->pMoveFromKafra',
        '9': 'clif->pUseSkillToPos',
        '10': 'clif->pUseSkillToPosMoreInfo',
        '11': 'clif->pGetCharNameRequest',
        '12': 'clif->pSolveCharName',
        '13': 'clif->pSearchStoreInfoListItemClick',
        '14': 'clif->pSearchStoreInfoNextPage',
        '15': 'clif->pSearchStoreInfo',
        '16': 'clif->pReqTradeBuyingStore',
        '17': 'clif->pReqClickBuyingStore',
        '18': 'clif->pReqCloseBuyingStore',
        '19': 'clif->pReqOpenBuyingStore',
        '20': 'clif->pPartyBookingRegisterReq',
        '21': 'clif->pDull // CZ_JOIN_BATTLE_FIELD',  # CZ_JOIN_BATTLE_FIELD
        '22': 'clif->pItemListWindowSelected',
        '23': 'clif->pWantToConnection',
        '24': 'clif->pPartyInvite2',
        '25': 'clif->pDull // CZ_GANGSI_RANK',  # CZ_GANGSI_RANK
        '26': 'clif->pFriendsListAdd',
        '27': 'clif->pHomMenu',
        '28': 'clif->pStoragePassword'
    }

    def collectInPackets(self, packetsH):
        config = configparser.ConfigParser()
        config.read(packetsH)
        cfg = config["Packet_Lengths"]
        for key in cfg:
            data = key[2:].lower()
            while len(data) < 4:
                data = "0" + data
            self.inPackets[data] = \
                (int(cfg[key]), "")
            self.knownLenPackets[data] = int(cfg[key])
        cfg = config["Shuffle_Packets"]
        for key in cfg:
            data = key[2:].lower()
            while len(data) < 4:
                data = "0" + data
            shuffle = cfg[key]
            if shuffle in self.shuffleMap:
                packet = self.inPackets[data]
                self.inPackets[data] = (packet[0], self.shuffleMap[shuffle])
            else:
                print "Not found shuffle code {0}".format(shuffle)

    def sortInPackets(self):
        for packet in self.inPackets:
            self.inPacketsSorted.append(packet)
        self.inPacketsSorted.sort()


    def findVersion(self, srcPath, packetDir):
        name = packetDir[:4] + "-" + packetDir[4:6] + "-" + packetDir[6:8]
        files = os.listdir(srcPath)
        for file1 in files:
            if file1[0] == ".":
                continue
            file2 = os.path.abspath(srcPath + os.path.sep + file1)
            if os.path.isdir(file2) and file1.find(name) >= 0:
                srcPath = file2
                files = os.listdir(srcPath)
                for file1 in files:
                    if file1[0] == ".":
                        continue
                    file2 = os.path.abspath(srcPath + os.path.sep + file1)
                    if os.path.isfile(file2):
                        self.collectInPackets(file2)
                        self.sortInPackets()
                        return

    def processPackets(self, codeDir, packetDir, packetVersion):
#        namedPacketsPath = packetDir + "/src/" + self.dirName + "/packets_struct.h"
        srcPath = "../links/" + self.dirName
#        packetsDbPath = "../links/" + codeDir + "/db/packet_db.txt"
#        serverInPacketsHPath = packetDir + "/src/" + self.dirName + "/packets.h"
#        serverLoginInPackets = packetDir + "/src/" + self.dirName + "/lclif.c"
#        serverCharPackets = packetDir + "/src/" + self.dirName + "/char.c"
#        self.collectNamedPackets(namedPacketsPath)
#        self.collectOutPackets(srcPath)
        self.findVersion(srcPath, packetDir)
#        self.collectCharInPackets(serverCharPackets);
#        self.sortOutPackets()
