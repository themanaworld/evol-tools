#!/bin/bash

export path="bot"
export server="irc.freenode.net"
export channel="#evol-dev"
export nick="evolbuildbot"
export buildid="$(cat clientdata/shared/buildid.log)"
export error="$(cat clientdata/shared/error.log)"

cd clientdata
export ghead=$(git log --pretty=oneline -n 1 | awk '{print $1}')
export gitcommit=$(echo ${ghead} | cut -c 1-7)
export msg="Build failed: ${gitcommit}. See https://gitlab.com/evol/clientdata/builds/${buildid}"

echo "${msg}"

mkdir ${path}

ii -s ${server} -i ${path} -n ${nick} -f ${nick} &
sleep 5s

echo "/j ${channel}" > "${path}/${server}/in"
sleep 10s

echo ${msg} >${path}/${server}/${channel}/in
if [[ -n "${error}" ]]; then
    sleep 2s
    export LINK=$(pastebinit -b http://paste.ubuntu.com/ shared/error.log)
    echo "Error log: ${LINK}" >${path}/${server}/${channel}/in
fi
sleep 3s

rm -rf shared/buildid.log
rm -rf shared/error.log

killall ii
