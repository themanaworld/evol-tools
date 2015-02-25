#!/bin/bash

export CMD="$*"

if [[ -z "${CMD}" ]]; then
    echo "Usage example: ./import_newsb.sh -u evol -pevol evol"
    exit
fi

cd newdb

function import {
echo Importing $1
mysql $CMD <$1
}

import acc_reg_num_db.sql
import char.sql
import char_reg_num_db.sql
import inventory.sql
import login.sql
import party.sql
import skill.sql
import storage.sql
