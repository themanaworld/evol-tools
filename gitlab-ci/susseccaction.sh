#!/bin/bash

export path="bot"
export server="irc.freenode.net"
export channel="#evol-dev"
export nick="evolbuildbot"
export buildid="$(cat clientdata/shared/buildid.log)"
export error="$(cat clientdata/shared/error.log)"
export C="\0003"
export R="\x0f"

cd clientdata
export ghead=$(git log --pretty=oneline -n 1 | awk '{print $1}')
export gitcommit=$(echo ${ghead} | cut -c 1-7)
export msg1="Build success: ${C}03${gitcommit}${R}. See https://gitlab.com/evol/clientdata/builds/${buildid}"
export msg2="Build failed: ${C}03${gitcommit}${R}. See https://gitlab.com/evol/clientdata/builds/${buildid}"

echo "${msg}"

mkdir ${path}

ii -s ${server} -i ${path} -n ${nick} -f ${nick} &
sleep 5s

echo "/j ${channel}" > "${path}/${server}/in"
sleep 10s

if [[ -n "${error}" ]]; then
    echo -e ${msg2} >${path}/${server}/${channel}/in
    sleep 2s
    export LINK=$(pastebinit -b http://paste.ubuntu.com/ shared/error.log)
    echo "Error log: ${LINK}" >${path}/${server}/${channel}/in
    rm -rf shared/buildid.log
    rm -rf shared/error.log
    exit 1
else
    echo -e ${msg1} >${path}/${server}/${channel}/in
fi

sleep 3s

rm -rf shared/buildid.log
rm -rf shared/error.log

killall ii
