#!/bin/bash

export DIR="$(pwd)"
export VER=$(cat versions/sqlver 2>/dev/null)

cd ../../server-data/sql-files

echo Creating db and user...
echo Enter mysql root password:
mysql --force -u root -p <./init.sql
result=$?
if [ "$result" != 0 ]; then
    echo Password failed. Trying with sudo...
    sudo mysql --force -u root <./init.sql
fi

export CMD="mysql -u evol -pevol evol"

echo Creating tables...
$CMD <main.sql
$CMD <logs.sql

if [[ -z "${VER}" ]]; then
    mkdir ${DIR}/versions
    echo "2" >${DIR}/versions/sqlver
fi
