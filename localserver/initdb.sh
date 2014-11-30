#!/bin/bash

cd ../../server-data/sql-files

echo Creating db and user...
echo Enter mysql root password:
mysql --force -u root -p <./init.sql

export CMD="mysql -u evol -pevol evol"

echo Creating tables...
$CMD <main.sql
$CMD <mob_skill_db.sql
$CMD <mob_skill_db2.sql
$CMD <logs.sql
$CMD <item_db_re.sql
$CMD <mob_db_re.sql
$CMD <mob_skill_db_re.sql
