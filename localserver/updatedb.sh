#!/usr/bin/env bash

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

if [ "${VER}" -lt "4" ]; then
    run "2016-03-10--22-18.sql"
fi

if [ "${VER}" -lt "5" ]; then
    run "2016-07-08--02-42.sql"
    run "2016-07-08--02-51.sql"
fi

if [ "${VER}" -lt "6" ]; then
    run "2016-10-03--20-27.sql"
fi

if [ "${VER}" -lt "7" ]; then
    run "2016-10-26--10-29.sql"
fi

if [ "${VER}" -lt "8" ]; then
    run "2017-03-02--11-40.sql"
    run "2017-03-05--08-09.sql"
fi

if [ "${VER}" -lt "9" ]; then
    run "2017-03-15--14-29.sql"
fi

if [ "${VER}" -lt "10" ]; then
    run "2017-11-04--10-39.sql"
fi

if [ "${VER}" -lt "11" ]; then
    run "2017-06-04--15-04.sql"
    run "2017-06-04--15-05.sql"
fi

if [ "${VER}" -lt "12" ]; then
    run "2018-02-26--15-57.sql"
fi

if [ "${VER}" -lt "12" ]; then
    echo "12" >versions/sqlver
fi
