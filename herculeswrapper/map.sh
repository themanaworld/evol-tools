#!/bin/bash

export PIPE=./log/mappipe.tmp
export LOGIN_PIPE=./log/loginpipe.tmp
export CHAR_PIPE=./log/charpipe.tmp

source ${dir}/include.sh

create_pipe

while [ 1 ] ; do
    ./map-server
    export ret=$?
    case "${ret}" in
    0)
        echo "Returned 0. Probably ctrl+c"
        break
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
    esac
done
