#!/bin/bash

function create_pipe {
    trap "rm -f $PIPE" EXIT
    if [[ ! -p $PIPE ]]; then
        echo "Making pipe $PIPE"
        rm -f $PIPE
        mkfifo $PIPE
    fi
}

# $1 - text
function send_all_pipes {
    echo $1 >$LOGIN_PIPE
    echo $1 >$CHAR_PIPE
}

# $1 - text
function send_char_pipe {
    echo $1 >$CHAR_PIPE
}

# $1 - server binary name
# $2 - sleep time
function server_logic {
    create_pipe
    $1

    while true
    do
        if read line <$PIPE; then
            echo pipe: $line
            if [[ "$line" == 'exit' ]]; then
                exit
            fi
            if [[ "$line" == 'restart' ]]; then
                sleep $2
                $1
            fi
        fi
    done
}
