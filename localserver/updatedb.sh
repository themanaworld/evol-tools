#!/bin/bash

export VER=$(cat versions/sqlver 2>/dev/null)
export SQLDIR="../../server-data/sql-files/upgrades"
export CMD="mysql -u evol -pevol evol"

function run {
    echo "Running $1"
    $CMD <${SQLDIR}/$1
}

if [[ -z "${VER}" ]]; then
    export VER="1"
    mkdir versions
fi

if [ "${VER}" -lt "2" ]; then
    run "2015-07-08--13-08.sql"
    run "2015-08-27--20-42.sql"
fi

if [ "${VER}" -lt "3" ]; then
    run "2015-12-16--12-57.sql"
    run "2015-12-17--15-58.sql"
fi

if [ "${VER}" -lt "3" ]; then
    echo "3" >versions/sqlver
fi
