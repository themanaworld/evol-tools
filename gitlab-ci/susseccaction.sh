#!/bin/bash

export path="bot"
export server="irc.freenode.net"
export channel="#evol-dev"
export nick="evolbuildbot"
export buildid="$(cat clientdata/.shared/buildid.log)"
export error="$(cat clientdata/.shared/error.log)"

export msg1="Build success. See https://gitlab.com/evol/clientdata/builds/${buildid}"
export msg2="Build failed. See https://gitlab.com/evol/clientdata/builds/${buildid}"

echo "${msg}"

mkdir ${path}

ii -s ${server} -i ${path} -n ${nick} -f ${nick} &
sleep 5s

echo "/j ${channel}" > "${path}/${server}/in"
sleep 10s

if [[ -n "${error}" ]]; then
    echo ${msg2} >${path}/${server}/${channel}/in
    sleep 2s
    export LINK=$(pastebinit -b http://paste.ubuntu.com/ clientdata/.shared/error.log)
    echo "Error log: ${LINK}" >${path}/${server}/${channel}/in
else
    echo ${msg1} >${path}/${server}/${channel}/in
fi

sleep 3s

rm -rf clientdata/.shared/buildid.log
rm -rf clientdata/.shared/error.log

killall ii
