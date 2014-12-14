#!/bin/bash

cd ../../server-data/sql-files

echo Creating db and user...
echo Enter mysql root password:
mysql --force -u root -p <./init.sql

export CMD="mysql -u evol -pevol evol"

echo Creating tables...
$CMD <main.sql
$CMD <logs.sql
