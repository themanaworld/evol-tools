#! /usr/bin/env python2
# -*- coding: utf8 -*-
#
# Copyright (C) 2015-2016  Evol Online
# Author: Andrei Karas (4144)

class Reporter:
    def reportManaplus(self, hercules, manaplus):
        with open(self.packetDir + "/" + hercules.reportName + "_outpackets.txt", "w") as w:
            for packet in hercules.outPacketsSorted:
                data = packet
                while data[0] == "0":
                    data = data[1:]
                if packet in manaplus.inPackets:
                    clientName = manaplus.inPackets[packet][0]
    #                if clientName not in manaplus.manaplusUsedPacketsSet and clientName.find("_OUTDATED") <= 0:
    #                    w.write("UNIMPLIMENTED ")
                    w.write(data + " client name: " + clientName)
                else:
                    w.write(data)
                w.write("\n")

        funcDict = dict()
        for packet in hercules.inPacketsSorted:
            data = packet
            while data[0] == "0":
                data = data[1:]
            if packet in hercules.inPackets:
                funcDict[hercules.inPackets[packet][1]] = packet

        with open(self.packetDir + "/client_uselesspackets.txt", "w") as w:
            for packet in manaplus.outPackets:
                if packet not in hercules.inPackets:
                    w.write("Useless packet {0}.\n".format(packet))

    #    manaplusFunc = set()
        rev = []

        with open(self.packetDir + "/client_packets.txt", "w") as w:
            for packet in manaplus.outPackets:
                clientName = manaplus.outPackets[packet][0]
                if clientName not in manaplus.manaplusUsedPacketsSet and clientName.find("_OUTDATED") <= 0:
                    w.write("PSESENT BUT UNIMPLIMENTED {0}\n".format(clientName))

    #        for packet in manaplus.outPackets:
    #            if packet in hercules.inPackets:
    #                manaplusFunc.add(hercules.inPackets[packet][1])
    #        for func in funcDict:
    #            if func not in manaplusFunc:
    #                packet = funcDict[func]
    #                rev.append("{0:4} {1:>4} {2}".format(packet, hercules.inPackets[packet][0], hercules.inPackets[packet][1]))

            clientSet = set()
            for packet in hercules.inPackets:
                clientSet.add(hercules.inPackets[packet][1])
            for packet in manaplus.outPackets:
                if packet in hercules.inPackets and hercules.inPackets[packet][1] in clientSet:
                    if manaplus.outPackets[packet][2] == hercules.inPackets[packet][1]:
                        clientSet.remove(hercules.inPackets[packet][1])
                    else:
                        if manaplus.outPackets[packet][2] in clientSet:
                            clientSet.remove(manaplus.outPackets[packet][2])

            allPackets = set()
            for packet in hercules.inPackets:
                allPackets.add(packet)
            for packet in manaplus.outPackets:
                allPackets.add(packet)

            for packet in clientSet:
                rev.append("{0:4} {1:33} {2}".format("?", "UNIMPLIMENTED", packet))

            for packet in allPackets:
                if packet not in manaplus.outPackets:
                    continue
                data = "{0:4} {1:33} ".format(packet, manaplus.outPackets[packet][0])
                if packet in hercules.inPackets:
                    if manaplus.outPackets[packet][2] == hercules.inPackets[packet][1]:
                        data = data + hercules.inPackets[packet][1]
                        rev.append(data)
                else:
                    data = data + "?"
                    rev.append(data)

            rev.sort()

            for data in rev:
                w.write(data)
                w.write("\n")

        rev = []
        with open(self.packetDir + "/client_wrongoutpacketsizes.txt", "w") as w:
            for name in manaplus.outMsgNameToId:
                packet = manaplus.outMsgNameToId[name]
    #        for packet in manaplus.outPackets:
                if packet in hercules.inPackets and manaplus.outPackets[packet][1] != hercules.inPackets[packet][0]:
                    packet1 = manaplus.outPackets[packet]
                    packet2 = hercules.inPackets[packet]
                    if packet2[0] != 0:
                        rev.append("{0:4} {1:33} {2:35} {3:4} vs {4:4}".format(
                            packet,
                            packet1[0],
                            packet2[1],
                            packet1[1],
                            packet2[0]))
            rev.sort()

            for data in rev:
                w.write(data)
                w.write("\n")

        rev = []
        with open(self.packetDir + "/client_badpackets.txt", "w") as w:
            for name in manaplus.outMsgNameToId:
                packet = manaplus.outMsgNameToId[name]
    #        for packet in manaplus.outPackets:
                if packet in hercules.inPackets:
                    packet1 = manaplus.outPackets[packet]
                    packet2 = hercules.inPackets[packet]
                    if packet1[2] in hercules.functionToId:
                        data = hercules.functionToId[packet1[2]]
                        data2 = hercules.functionToId[packet2[1]]
                        if data2 == packet:
                            if packet1[2] != packet2[1]:
                                rev.append("{0:4} {1:33} client: {2:35} server: {3:35} Change id to {4}".format(packet,
                                    packet1[0],
                                    packet1[2],
                                    packet2[1],
                                    data))
                        else:
                            # here hidden or previous packet
                            pass
                    else:
                        data = "unknown"
                        if packet1[2] != packet2[1]:
                            rev.append("{0:4} {1:33} client: {2:35} server: {3:35} Change id to {4}".format(packet,
                                packet1[0],
                                packet1[2],
                                packet2[1],
                                data))

            rev.sort()

            for data in rev:
                w.write(data)
                w.write("\n")

        rev = []
        with open(self.packetDir + "/client_preferredpackets.txt", "w") as w:
            with open(self.packetDir + "/client_badpackets.txt", "a+") as w2:
                for name in manaplus.outMsgNameToId:
                    packet = manaplus.outMsgNameToId[name]
                    if packet in hercules.inPackets:
                        packet1 = manaplus.outPackets[packet]
                        packet2 = hercules.inPackets[packet]
                        if packet1[0] != name:
                            # skip if same id used for other packet already
                            #print("{0}, {1}, {2}, {3}".format(name, packet, packet1, packet2))
                            w2.write("{0:4} {1:33} hidden by {2}\n".format(packet,
                                name,
                                packet1[2]))
                            continue
                        if packet1[2] in hercules.functionToId:
                            data = hercules.functionToId[packet1[2]]
                            if packet1[2] == packet2[1] and hercules.functionToId[packet1[2]] != packet:
                                rev.append("{0:4} -> {1:4}  {2:33} {3}".format(packet,
                                    data,
                                    packet1[0],
                                    packet1[2]))
                        else:
                            data = "unknown"
                            if packet1[2] == packet2[1] and hercules.functionToId[packet1[2]] != packet:
                                rev.append("{0:4} -> {1:4}  {2:33} {3}".format(packet,
                                    data,
                                    packet1[0],
                                    packet1[2]))
                rev.sort()
                for data in rev:
                    w.write(data)
                    w.write("\n")

        with open(self.packetDir + "/client_wronginpacketsizes.txt", "w") as w:
            for packet in hercules.getLenPackets:
                if packet in manaplus.sizes:
                    if hercules.knownLenPackets[packet] != manaplus.sizes[packet]:
                        w.write("{0:4} client={1:4} vs server={2:4}\n".format(
                            packet,
                            manaplus.sizes[packet],
                            hercules.knownLenPackets[packet]))
                else:
                    if packet in hercules.knownLenPackets:
                        w.write("{0:4} client=missing vs server={1:4}\n".format(
                            packet,
                            hercules.knownLenPackets[packet]))
                    else:
                        w.write("{0:4} client=missing vs server=missing\n".format(
                            packet))

    def reportHercules(self, hercules):
        with open(self.packetDir + "/" + hercules.reportName + "_issues.txt", "w") as w:
            for name in hercules.functionToId:
                packet = hercules.functionToId[name]
                if name != hercules.inPackets[packet][1]:
                    found = False
                    oldId = ""
                    for packet in hercules.inPackets:
                        if name == hercules.inPackets[packet][1]:
                            found = True
                            if oldId == "":
                                oldId = str(packet)
                            else:
                                oldId = oldId + "," + str(packet)
                    if found is False:
                        w.write("Server code error: function {0} hidden in server code\n".format(
                            name))
                    else:
                        w.write("Server code warning: function {0} hidden in server code but can be used older packets definition {1}\n".format(
                            name,
                            oldId))
        with open(self.packetDir + "/" + hercules.reportName + "_missing_sizes.txt", "w") as w:
            for packet in hercules.getLenPackets:
                if packet not in hercules.knownLenPackets:
                    w.write("Missing length for packet {0}\n".format(
                        packet))


    def reportRathena(self, hercules, rathena):
        with open(self.packetDir + "/" + hercules.reportName + "_" + rathena.reportName + "_outpackets.txt", "w") as w:
            for packet in rathena.outPacketsSorted:
                if packet not in hercules.packetsSet:
                    w.write("Exists only in rAthena: " + packet + "\n")


    def reportHerculesFork(self, hercules, fork, name):
        with open(self.packetDir + "/" + hercules.reportName + "_" + fork.reportName + "_outpackets.txt", "w") as w:
            for packet in fork.outPacketsSorted:
                if packet not in hercules.packetsSet:
                    if packet in fork.getLenPackets and packet not in fork.knownLenPackets:
                        w.write("Exists only in " + name + ", but missing packet size: " + packet + "\n")
                    else:
                        w.write("Exists only in " + name + ": " + packet + "\n")
            for packet in fork.outPacketsSorted:
                if packet not in hercules.packetsSet:
                    # incomplete code?
                    if packet in fork.getLenPackets and packet in fork.knownLenPackets and \
                    packet in hercules.getLenPackets and packet in hercules.knownLenPackets:
                        w.write("Different packet size for packet {0}: {1} vs {2}\n".format(
                            packet,
                            hercules.knownLenPackets[packet],
                            fork.knownLenPackets[packet]))
        with open(self.packetDir + "/" + hercules.reportName + "_" + fork.reportName + "_inpackets.txt", "w") as w:
            for func in hercules.functionToId:
                packet = hercules.functionToId[func]
                if packet in hercules.inPackets:
                    if func not in fork.functionToId:
                        continue
                    forkPacket = fork.functionToId[func]
                    if packet != forkPacket and func != "clif->pDull":
                        w.write("Wrong preffered packet for function {0}: {1} vs {2}\n".format(
                            func,
                            packet,
                            forkPacket))
            for packet in fork.inPacketsSorted:
                if packet not in hercules.inPackets:
                    w.write("Exists only in " + name + ": " + packet + " " + fork.inPackets[packet][1] + "\n")
            for packet in fork.inPacketsSorted:
                if packet in hercules.inPackets:
                    herculesFunction = hercules.inPackets[packet][1]
                    herculesLen = hercules.inPackets[packet][0]
                    forkFunction = fork.inPackets[packet][1]
                    forkLen = fork.inPackets[packet][0]
                    if herculesFunction != forkFunction:
                        if hercules.functionToId[herculesFunction] == packet or fork.functionToId[forkFunction] == packet:
                            w.write("Wrong function name for packet {0}: {1} vs {2}\n".format(
                                packet,
                                herculesFunction,
                                forkFunction))
                    elif herculesLen != forkLen:
                        w.write("Different packet size for packet {0} {1}: {2} vs {3}\n".format(
                            packet,
                            herculesFunction,
                            herculesLen,
                            forkLen))


    def reportServer(self, hercules, server):
        with open(self.packetDir + "/" + hercules.reportName + "_" + server.dirName + "_outpackets.txt", "w") as w:
            for packet in server.outPacketsSorted:
                if packet not in hercules.outPacketsSorted:
                    w.write("Exists only in " + server.dirName + ": " + packet + "\n")
        with open(self.packetDir + "/" + hercules.reportName + "_" + server.dirName + "_inpackets.txt", "w") as w:
            for packet in server.inPacketsSorted:
                if packet not in hercules.inPacketsSorted:
                    w.write("Exists only in " + server.dirName + ": " + packet + "\n")
        with open(self.packetDir + "/" + server.dirName + "_" + hercules.reportName + "_outpackets.txt", "w") as w:
            fail = False
            for packet in hercules.outPacketsSorted:
                if packet not in server.outPackets:
                    fail = True
                    w.write("Exists only in Hercules: " + packet + "\n");
            if fail == False:
                w.write("Server include all hercules packets\n")
        with open(self.packetDir + "/" + server.dirName + "_" + hercules.reportName + "_inpackets.txt", "w") as w:
            fail = False
            for packet in hercules.inPacketsSorted:
                if packet not in server.inPackets:
                    fail = True
                    w.write("Exists only in Hercules: " + packet + "\n");
            if fail == False:
                w.write("Server include all hercules packets\n")


    def reportTables(self, hercules, tables):
        if len(tables.inPacketsSorted) == 0:
            return
        with open(self.packetDir + "/" + hercules.reportName + "_" + tables.dirName + "_inpackets.txt", "w") as w:
            for packet in tables.inPacketsSorted:
                if packet not in hercules.inPacketsSorted and packet not in hercules.outPacketsSorted:
                    w.write("Exists only in " + tables.dirName + ": " + packet + "\n")
            for packet in tables.inPacketsSorted:
                if packet in hercules.inPacketsSorted and packet in tables.inPackets and packet in hercules.knownLenPackets:
                    if hercules.knownLenPackets[packet] != tables.knownLenPackets[packet]:
                        w.write("Different packet size for packet {0}: {1} vs {2}\n".format(
                            packet,
                            hercules.knownLenPackets[packet],
                            tables.knownLenPackets[packet]))
        with open(self.packetDir + "/" + tables.dirName + "_" + hercules.reportName + "_inpackets.txt", "w") as w:
            fail = False
            for packet in hercules.inPacketsSorted:
                if packet not in tables.inPackets:
                    fail = True
                    w.write("Exists only in Hercules: " + packet + "\n");
            if fail == False:
                w.write("Table include all hercules packets\n")
        with open(self.packetDir + "/" + tables.dirName + "_" + hercules.reportName + "_outpackets.txt", "w") as w:
            fail = False
            for packet in hercules.outPacketsSorted:
                if packet not in tables.inPackets:
                    fail = True
                    w.write("Exists only in Hercules: " + packet + "\n");
            if fail == False:
                w.write("Server include all hercules packets\n")


    def reportPeek(self, hercules, peek):
        if len(peek.inPacketsSorted) == 0:
            return
        with open(self.packetDir + "/" + hercules.reportName + "_" + peek.dirName + "_inpackets.txt", "w") as w:
            for packet in peek.inPacketsSorted:
                if packet not in hercules.inPacketsSorted and packet not in hercules.outPacketsSorted:
                    w.write("Exists only in " + peek.dirName + ": " + packet + "\n")
            for packet in peek.inPacketsSorted:
                if packet in hercules.inPacketsSorted and packet in peek.inPackets and packet in hercules.knownLenPackets:
                    if hercules.knownLenPackets[packet] != peek.knownLenPackets[packet]:
                        w.write("Different packet size for packet {0}: {1} vs {2}\n".format(
                            packet,
                            hercules.knownLenPackets[packet],
                            peek.knownLenPackets[packet]))
        with open(self.packetDir + "/" + peek.dirName + "_" + hercules.reportName + "_inpackets.txt", "w") as w:
            fail = False
            for packet in hercules.inPacketsSorted:
                if packet not in peek.inPackets:
                    fail = True
                    w.write("Exists only in Hercules: " + packet + "\n");
            if fail == False:
                w.write("Table include all hercules packets\n")
            for packet in hercules.inMapPacketsSorted:
                if packet in peek.inPackets:
                    peekFunction = peek.inPackets[packet][1]
                    if peekFunction != "":
                        herculesFunction = hercules.inMapPackets[packet][1]
                        if peekFunction != herculesFunction:
                            w.write("Wrong function name for packet {0}: {1} vs {2}\n".format(
                                packet,
                                peekFunction,
                                herculesFunction))
        with open(self.packetDir + "/" + peek.dirName + "_" + hercules.reportName + "_outpackets.txt", "w") as w:
            fail = False
            for packet in hercules.outPacketsSorted:
                if packet not in peek.inPackets:
                    fail = True
                    w.write("Exists only in Hercules: " + packet + "\n");
            if fail == False:
                w.write("Server include all hercules packets\n")
