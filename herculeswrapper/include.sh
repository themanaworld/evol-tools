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

function stash_save {
    STR=$(git diff --stat --color=always)
    if [[ -n "${STR}" ]]; then
        echo ${1}: git stash save "wrapper pull"
        git stash save "wrapper pull"
        export ${1}_saved="1"
    else
        export ${1}_saved="0"
    fi
}

function stash_pop {
    var="${1}_saved"
    eval var=\$$var
    if [[ "${var}" == "1" ]]; then
        echo ${1}: git stash pop
        git stash pop
    fi
}

function pull_all {
    stash_save "data"
    cd ../server-code
    stash_save "code"
    cd src/evol
    stash_save "plugin"
    cd ../../../tools
    stash_save "tools"
    cd ..
    ./pull.sh
    cd server-data
    stash_pop "data"
    cd ../server-code
    stash_pop "code"
    cd src/evol
    stash_pop "plugin"
    cd ../../../tools
    stash_pop "tools"
    cd ..
    ./status.sh
    cd server-data
}

function build_all {
    cd ../server-code
    ./build.sh 2>err.txt
    cat err.txt
    cd ../server-data
}

function build_clean {
    cd ../tools/localserver
    ./clean.sh
    cd ../../server-data
}

function build_plugin {
    cd ../server-plugin
    ./build.sh 2>err.txt
    cat err.txt
    cd ../server-data
}
