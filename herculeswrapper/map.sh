#!/usr/bin/env bash

export PIPE=./log/mappipe.tmp
export LOGIN_PIPE=./log/loginpipe.tmp
export CHAR_PIPE=./log/charpipe.tmp

source ${dir}/include.sh

create_pipe

while [ 1 ] ; do
    $DEBUG_MAP ./map-server
    export ret=$?
    case "${ret}" in
    0)
        echo "Returned 0. Probably ctrl+c"
        break
        ;;
    1)
        echo "Returned 1. Probably error in server"
        [ ! -z "$DEBUG_MAP" ] || break
        ;;
    100)
        echo "Terminating server"
        send_all_pipes "exit"
        break
        ;;
    101)
        echo "Restarting all servers..."
        send_all_pipes "restart"
        sleep 5s
        ;;
    102)
        echo "Restarting chat and map servers..."
        send_char_pipe "restart"
        sleep 3s
        ;;
    103)
        echo "Restarting map server..."
        ;;
    104)
        echo "git pull..."
        pull_all
        echo "Restarting all servers..."
        send_all_pipes "restart"
        sleep 5s
        ;;
    105)
        echo "Build all servers"
        sleep 5s
        build_all
        echo "Restarting all servers..."
        send_all_pipes "restart"
        sleep 5s
        ;;
    106)
        echo "Rebuild all servers"
        sleep 5s
        build_clean
        build_all
        echo "Restarting all servers..."
        send_all_pipes "restart"
        sleep 5s
        ;;
    107)
        echo "git pull..."
        pull_all
        echo "Build all servers"
        build_all
        echo "Restarting all servers..."
        send_all_pipes "restart"
        sleep 5s
        ;;
    108)
        echo "git pull..."
        pull_all
        echo "Rebuild all servers"
        build_clean
        build_all
        echo "Restarting all servers..."
        send_all_pipes "restart"
        sleep 5s
        ;;
    109)
        echo "Build plugin"
        sleep 5s
        build_plugin
        echo "Restarting all servers..."
        send_all_pipes "restart"
        sleep 5s
        ;;
    110)
        echo "git pull..."
        pull_all
        echo "Build plugin"
        build_plugin
        echo "Restarting all servers..."
        send_all_pipes "restart"
        sleep 5s
        ;;
    esac
done
