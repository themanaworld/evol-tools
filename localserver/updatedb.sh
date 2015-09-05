#!/bin/bash

export VER=$(cat versions/sqlver 2>/dev/null)
export SQLDIR="../../server-data/sql-files/"
export CMD="mysql -u evol -pevol evol"

function run {
    echo "Running $1"
    $CMD <$1
}

if [[ -z "${VER}" ]]; then
    export VER="1"
fi

if [ "${VER}" -lt "2" ]; then
    run "2015-07-02--18-14.sql"
    run "2015-07-08--13-08.sql"
    run "2015-08-27--20-42.sql"
fi

if [ "${VER}" -lt "2" ]; then
    echo "2" >versions/sqlver
fi
