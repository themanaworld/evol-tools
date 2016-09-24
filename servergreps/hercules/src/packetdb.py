#! /usr/bin/env python2
# -*- coding: utf8 -*-
#
# Copyright (C) 2015-2016  Evol Online
# Author: Andrei Karas (4144)

import re

class PacketDb:
    packetVersionRe = re.compile("^//(?P<v1>[\d][\d][\d][\d])-(?P<v2>[\d][\d])-(?P<v3>[\d][\d])")
    clientpacketre = re.compile(
        "^0x(?P<packet>[0-9a-fA-F]+),(?P<len>[\w-]+)" +
        ",(?P<function>[0-9a-zA-Z_]+),")
    serverpacketre = re.compile(
        "^0x(?P<packet>[0-9a-fA-F]+),(?P<len>[\w-]+)")

    nameMap = {
#3CeAm
        'guildinvite': 'clif->pGuildInvite',
        'createparty': 'clif->pCreateParty',
        'ticksend': 'clif->pTickSend',
        'viewplayerequip': 'clif->pViewPlayerEquip',
        'hommovetomaster': 'clif->pHomMoveToMaster',
        'wisexin': 'clif->pPMIgnore',
        'storagepassword': 'clif->pStoragePassword',
        'npccloseclicked': 'clif->pNpcCloseClicked',
        'guildrequestinfo': 'clif->pGuildRequestInfo',
        'hommenu': 'clif->pHomMenu',
        'createchatroom': 'clif->pCreateChatRoom',
        'partychangeleader': 'clif->pPartyChangeLeader',
        'tradecancel': 'clif->pTradeCancel',
        'wanttoconnection': 'clif->pWantToConnection',
        'lesseffect': 'clif->pLessEffect',
        'gmhide': 'clif->pGMHide',
        'purchasereq2': 'clif->pPurchaseReq2',
        'stopattack': 'clif->pStopAttack',
        'walktoxy': 'clif->pWalkToXY',
        'npcclicked': 'clif->pNpcClicked',
        'bookingcanceljoinparty': 'clif->pDull',
        'recall2': 'clif->pGMRecall2',
        'changedir': 'clif->pChangeDir',
        'guildleave': 'clif->pGuildLeave',
        'searchstoreinfo': 'clif->pSearchStoreInfo',
        'bookingsearchreq': 'clif->pPartyBookingSearchReq',
        'partyinvite': 'clif->pPartyInvite',
        'auctionclose': 'clif->pAuction_close',
        'repairitem': 'clif->pRepairItem',
        'bookingignorereq': 'clif->pDull',
        'searchstoreinfonextpage': 'clif->pSearchStoreInfoNextPage',
        'solvecharname': 'clif->pSolveCharName',
        'guildreplyalliance': 'clif->pGuildReplyAlliance',
        'weaponrefine': 'clif->pWeaponRefine',
        'maildelete': 'clif->pMail_delete',
        'useskilltoid': 'clif->pUseSkillToId',
        'cashshopbuy': 'clif->pCashShopBuy',
        'traderequest': 'clif->pTradeRequest',
        'restart': 'clif->pRestart',
        'gmreqnochat': 'clif->pGMReqNoChat',
        'movefromkafra': 'clif->pMoveFromKafra',
        'replypartyinvite2': 'clif->pReplyPartyInvite2',
        'changechatowner': 'clif->pChangeChatOwner',
        'guildbreak': 'clif->pGuildBreak',
        'producemix': 'clif->pProduceMix',
        'auctionregister': 'clif->pAuction_register',
        'auctioncancel': 'clif->pAuction_cancel',
        'remove': 'clif->pGMShift',     # probably error
        'summon': 'clif->pGMRecall',    # probably error
        'openvending': 'clif->pOpenVending',
        'leaveparty': 'clif->pLeaveParty',
        'cashshopclose': 'clif->pCashShopClose',
        'guildchangenotice': 'clif->pGuildChangeNotice',
        'chatroomstatuschange': 'clif->pChatRoomStatusChange',
        'auctionsearch': 'clif->pAuction_search',
        'tradeack': 'clif->pTradeAck',
        'useitem': 'clif->pUseItem',
        'sndoridori': 'clif->pNoviceDoriDori',
        'guildreplyinvite': 'clif->pGuildReplyInvite',
        'selectarrow': 'clif->pSelectArrow',
        'feelsaveok': 'clif->pFeelSaveOk',
        'taekwon': 'clif->pTaekwon',
        'battlechat': 'clif->pBattleChat',
        'guilddelalliance': 'clif->pGuildDelAlliance',
        'cashshopreqtab': 'clif->pCashShopReqTab',
        'partyinvite2': 'clif->pPartyInvite2',
        'hommoveto': 'clif->pHomMoveTo',
        'useskilltoposmoreinfo': 'clif->pUseSkillToPosMoreInfo',
        'getcharnamerequest': 'clif->pGetCharNameRequest',
        'closesearchstoreinfo': 'clif->pCloseSearchStoreInfo',
        'localbroadcast': 'clif->pLocalBroadcast',
        'closekafra': 'clif->pCloseKafra',
        'putitemtocart': 'clif->pPutItemToCart',
        'actionrequest': 'clif->pActionRequest',
        'cashshopschedule': 'clif->pCashShopSchedule',
        'auctioncancelreg': 'clif->pAuction_cancelreg',
        'rc': 'clif->pGMRc',
        'guildexpulsion': 'clif->pGuildExpulsion',
        'partymessage': 'clif->pPartyMessage',
        'equiptickbox': 'clif->pEquipTick',
        'guildchangememberposition': 'clif->pGuildChangeMemberPosition',
        'adoptreply': 'clif->pAdopt_reply',
        'mailwinopen': 'clif->pMail_winopen',
        'hotkey': 'clif->pHotkey',
        'searchstoreinfolistitemclick': 'clif->pSearchStoreInfoListItemClick',
        'npcselllistsend': 'clif->pNpcSellListSend',
        'dropitem': 'clif->pDropItem',
        'takeitem': 'clif->pTakeItem',
        'npcselectmenu': 'clif->pNpcSelectMenu',
        'changehomunculusname': 'clif->pChangeHomunculusName',
        'shift': 'clif->pGMShift',
        'friendslistadd': 'clif->pFriendsListAdd',
        'sendemotion': 'clif->pSendEmotion',
        'progressbar': 'clif->pProgressbar',
        'bookingdelreq': 'clif->pPartyBookingDeleteReq',
        'howmanyconnections': 'clif->pHowManyConnections',
        'changemaptype': 'clif->pGMChangeMapType',
        'blacksmith': 'clif->pBlacksmith',
        'npcbuylistsend': 'clif->pNpcBuyListSend',
        'gmreqaccname': 'clif->pGMReqAccountName',
        'emotion': 'clif->pEmotion',
        'skillselectmenu': 'clif->pSkillSelectMenu',
        'reqtradebuyingstore': 'clif->pReqTradeBuyingStore',
        'pvpinfo': 'clif->pPVPInfo',
        'wisexlist': 'clif->pPMIgnoreList',
        'chataddmember': 'clif->pChatAddMember',
        'remove2': 'clif->pGMRemove2',
        'requestmemo': 'clif->pRequestMemo',
        'wis': 'clif->pWisMessage',
        'petmenu': 'clif->pPetMenu',
        'rankingpk': 'clif->pRankingPk',
        'mailgetattach': 'clif->pMail_getattach',
        'tradeadditem': 'clif->pTradeAddItem',
        'useskillmap': 'clif->pUseSkillMap',
        'auctionbuysell': 'clif->pAuction_buysell',
        'autorevive': 'clif->pAutoRevive',
        'movetokafrafromcart': 'clif->pMoveToKafraFromCart',
        'cashshopopen': 'clif->pCashShopOpen',
        'queststate': 'clif->pquestStateAck',
        'loadendack': 'clif->pLoadEndAck',
        'unequipitem': 'clif->pUnequipItem',
        'replypartyinvite': 'clif->pReplyPartyInvite',
        'guildrequestemblem': 'clif->pGuildRequestEmblem',
        'globalmessage': 'clif->pGlobalMessage',
        'reqclickbuyingstore': 'clif->pReqClickBuyingStore',
        'bookingsummonmember': 'clif->pDull',
        'friendslistreply': 'clif->pFriendsListReply',
        'npcstringinput': 'clif->pNpcStringInput',
        'closevending': 'clif->pCloseVending',
        'skillup': 'clif->pSkillUp',
        'broadcast': 'clif->pBroadcast',
        'guildcheckmaster': 'clif->pGuildCheckMaster',
        'guildchangeemblem': 'clif->pGuildChangeEmblem',
        'itemmonster': 'clif->pGM_Monster_Item',
        'vendinglistreq': 'clif->pVendingListReq',
        'guildrequestalliance': 'clif->pGuildRequestAlliance',
        'bookingupdatereq': 'clif->pPartyBookingUpdateReq',
        'removeoption': 'clif->pRemoveOption',
        'recall': 'clif->pGMRecall',
        'changepetname': 'clif->pChangePetName',
        'chatleave': 'clif->pChatLeave',
        'snexplosionspirits': 'clif->pNoviceExplosionSpirits',
        'mailread': 'clif->pMail_read',
        'mermenu': 'clif->pmercenary_action',
        'alchemist': 'clif->pAlchemist',
        'partychangeoption': 'clif->pPartyChangeOption',
        'tradeok': 'clif->pTradeOk',
        'kickfromchat': 'clif->pKickFromChat',
        'reqopenbuyingstore': 'clif->pReqOpenBuyingStore',
        'moveitem': 'clif->pMoveItem',
        'homattack': 'clif->pHomAttack',
        'ranking': 'clif->pRankingPk',
        'changecart': 'clif->pChangeCart',
        'reqclosebuyingstore': 'clif->pReqCloseBuyingStore',
        'removepartymember': 'clif->pRemovePartyMember',
        'catchpet': 'clif->pCatchPet',
        'selectegg': 'clif->pSelectEgg',
        'partybookingregisterreq': 'clif->pPartyBookingRegisterReq',
        'mailsend': 'clif->pMail_send',
        'itemlistwindowselected': 'clif->pItemListWindowSelected',
        'mailrefresh': 'clif->pMail_refreshinbox',
        'mapmove': 'clif->pMapMove',
        'check': 'clif->pCheck',
        'useskilltoposinfo': 'clif->pUseSkillToPosMoreInfo',
        'adoptrequest': 'clif->pAdopt_request',
        'npcamountinput': 'clif->pNpcAmountInput',
        'battlegroundreg': 'clif->pBGQueueRegister',
        'wisall': 'clif->pPMIgnoreAll',
        'npcnextclicked': 'clif->pNpcNextClicked',
        'resetchar': 'clif->pResetChar',
        'npcbuysellselected': 'clif->pNpcBuySellSelected',
        'killall': 'clif->pGMKickAll',
        'mailsetattach': 'clif->pMail_setattach',
        'insertcard': 'clif->pInsertCard',
        'purchasereq': 'clif->pPurchaseReq',
        'auctionbid': 'clif->pAuction_bid',
        'gmkick': 'clif->pGMKick',
        'auctionsetitem': 'clif->pAuction_setitem',
        'createparty2': 'clif->pCreateParty2',
        'statusup': 'clif->pStatusUp',
        'usecard': 'clif->pUseCard',
        'guildmessage': 'clif->pGuildMessage',
        'itemidentify': 'clif->pItemIdentify',
        'bookingjoinpartyreq': 'clif->pDull',
        'equipitem': 'clif->pEquipItem',
        'useskilltopos': 'clif->pUseSkillToPos',
        'autospell': 'clif->pAutoSpell',
        'cooking': 'clif->pCooking',
        'bookingregreq': 'clif->pPartyBookingRegisterReq',
        'movefromkafratocart': 'clif->pMoveFromKafraToCart',
        'mailreturn': 'clif->pMail_return',
        'tradecommit': 'clif->pTradeCommit',
        'quitgame': 'clif->pQuitGame',
        'movetokafra': 'clif->pMoveToKafra',
        'friendslistremove': 'clif->pFriendsListRemove',
        'getitemfromcart': 'clif->pGetItemFromCart',
        'guildopposition': 'clif->pGuildOpposition',
        'createguild': 'clif->pCreateGuild',
        'guildchangepositioninfo': 'clif->pGuildChangePositionInfo',
        'selectcart': 'clif->pSelectCart',

#rathena
        'partytick': 'clif->pPartyTick',
        'clientversion': 'in packet',
        'gmfullstrip': 'clif->pGMFullStrip',
        'guildinvite2': 'clif->pGuildInvite2',
        'mergeitem_req': 'clif->ackmergeitems',
        'mergeitem_cancel': 'clif->cancelmergeitem',
        'booking_playcancel': 'in packet',
        'cashshopitemlist': 'clif->pCashShopSchedule',
        'reqworldinfo': 'missing',
        'ranklist': 'clif->pRanklist',
        'bankdeposit': 'clif->pBankDeposit',
        'bankwithdrawal': 'clif->pBankWithdraw',
        'bankcheck': 'clif->pBankCheck',
        'bankopen': 'clif->pBankOpen',
        'bankclose': 'clif->pBankClose',
        'dull': 'clif->pDull',
        'npcshopclosed': 'clif->pNPCShopClosed',
        'npcmarketpurchase': 'clif->pNPCMarketPurchase',
        'npcmarketclosed': 'clif->pNPCMarketClosed',
        'hotkeyrowshift': 'clif->pHotkeyRowShift',
        'rouletteopen': 'clif->pRouletteOpen',
        'rouletteinfo': 'clif->pRouletteInfo',
        'rouletteclose': 'clif->pRouletteClose',
        'roulettegenerate': 'clif->pRouletteGenerate',
        'rouletterecvitem': 'clif->pRouletteRecvItem'
    }

    @staticmethod
    def getInPackets(dbName, packetVersion, server):
        with open(dbName, "r") as f:
            version = "00000000"
            for line in f:
                m = PacketDb.packetVersionRe.search(line)
                if m is not None:
                    version = m.group("v1") + m.group("v2") + m.group("v3")
                if version > packetVersion:
                    continue
                m = PacketDb.clientpacketre.search(line)
                if m is not None:
                    data = m.group("packet").lower()
                    while len(data) < 4:
                        data = "0" + data
                    func = m.group("function")
                    if func not in PacketDb.nameMap:
                        if func.find("_") < 0:
                            print "Cant find name for functions " + func
                    else:
                        func = PacketDb.nameMap[func]
                    if func.find("_") < 0 and func != "in packet":
                        server.functionToId[func] = data
                        server.inPackets[data] = \
                            (int(m.group("len")), func)
                    #print "{0}, {1}, {2}".format(m.group("packet"), m.group("len"), func)
                m = PacketDb.serverpacketre.search(line)
                if m is not None:
                    data = m.group("packet").lower()
                    while len(data) < 4:
                        data = "0" + data
                    server.knownLenPackets[data] = int(m.group("len"))
