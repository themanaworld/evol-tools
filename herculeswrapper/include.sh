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
    git_merge
    stash_pop "data"
    cd ../server-code
    stash_pop "code"
    cd src/evol
    stash_pop "plugin"
    cd ../../../tools
    stash_pop "tools"
    cd ../
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

function git_merge {
    if [ -f ../tools/herculeswrapper/herc-map-wrapper-config ]
    then
        # prevent interaction
        export GIT_EDITOR=:
        # force commits to have predictable hashes
        export GIT_AUTHOR_DATE='1970-01-01 00:00 +0000'
        export GIT_COMMITTER_DATE='1970-01-01 00:00 +0000'

        reset=$'\e[m'
        black_fg=$'\e[30m'
        red_fg=$'\e[31m'
        green_fg=$'\e[32m'
        yellow_fg=$'\e[33m'
        blue_fg=$'\e[34m'
        magenta_fg=$'\e[35m'
        cyan_fg=$'\e[36m'
        gray_fg=$'\e[37m'

        reset2='##0'
        black_fg2='##0'
        red_fg2='##1'
        green_fg2='##2'
        blue_fg2='##3'
        orange_fg2='##4'
        yellow_fg2='##5'
        pink_fg2='##6'
        purple_fg2='##7'
        gray_fg2='##8'
        brown_fg2='##9'


        now()
        {
            date -u +'%F %T'
        }

        good()
        {
            echo "$(now)$green_fg" "$@" "$reset" >&2
        }

        info()
        {
            echo "$(now)$cyan_fg" "$@" "$reset" >&2
        }

        warning()
        {
            echo "$(now)$yellow_fg" "$@" "$reset" >&2
        }

        error()
        {
            echo "$(now)$red_fg" "$@" "$reset" >&2
        }

        good2()
        {
            echo \""$green_fg2" "$@" "$reset2"\",
        }

        info2()
        {
            echo \""$brown_fg2" "$@" "$reset2"\",
        }

        warning2()
        {
            echo \""$yellow_fg2" "$@" "$reset2"\",
        }

        error2()
        {
            echo \""$red_fg2" "$@" "$reset2"\",
        }

        run()
        {
            info '$' "$@"
            "$@"
        }

        try_merge()
        {
            test -n "$1"
            local branch=$1 commit
            info 'commit=$(' git rev-parse --verify -q $branch ')'
            if ! commit=$(git rev-parse --verify -q $branch)
            then
                error2 bogus $branch >> $motd
                error bogus $branch
                return
            fi
            info commit=$commit
            if run bash -c 'set -o pipefail; git branch --contains '$commit' | grep -qw master'
            then
                warning2 already $branch $commit >> $motd
                warning already $branch
                return
            fi
            if run git merge --ff-only $branch $commit
            then
                good2 fast $branch $commit >> $motd
                good fast $branch $commit
                return
            fi
            if run git merge $branch $commit
            then
                good2 merge $branch $commit >> $motd
                good merge $branch $commit
                return
            fi
            git merge --abort
            error2 abort $branch $commit >> $motd
            error abort $branch $commit
            return
        }

        start_time=$(date +%s)
        source ../tools/herculeswrapper/herc-map-wrapper-config

        run test -f $motd
        echo -e 'function\tscript\tMOTD_debug_text\t{\n    setarray $Debug_Messages$,' > $motd
        run git fetch --all
        run git reset --hard $server_main_branch
        info 'commit=$(' git rev-parse --verify -q $server_main_branch ')'
        commit=$(git rev-parse --verify -q $server_main_branch)
        info2 server base $server_main_branch $commit >> $motd
        for branch in ${server_extra_branches[@]}
        do
            try_merge $branch
        done

        run cd $client_data

        # force new master and back up for future restoration
        run git fetch --all
        run git reset --hard $client_main_branch

        info 'commit=$(' git rev-parse --verify -q $client_main_branch ')'
        commit=$(git rev-parse --verify -q $client_main_branch)
        info2 client base $client_main_branch $commit >> $motd
        for branch in ${client_extra_branches[@]}
        do
            try_merge $branch
        done
        echo '"End of Commits";' >> $motd
        echo -e '    return;\n}' >> $motd

        # generate the transient updates
        run cd $tmw_tools/update/
        run ./createnew.sh
        run ./create_music.sh
        run cd ../../server-data/
    fi
}
