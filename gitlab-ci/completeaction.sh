#!/bin/bash

export path="bot"
export server="irc.freenode.net"
export channel="#evol-dev"
export nick="evolbuildbot"

echo "$1"

apt-get update
apt-get -y -qq install ii psmisc

mkdir ${path}

ii -s ${server} -i ${path} -n ${nick} -f ${nick} &
sleep 5s

echo "/j ${channel}" > "${path}/${server}/in"
sleep 10s

echo $1 >${path}/${server}/${channel}/in
sleep 3s

killall ii
