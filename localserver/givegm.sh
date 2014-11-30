#!/bin/bash

ID="$1"
if [[ -z "${ID}" ]]; then
    mysql -u evol -pevol evol -e "update login set group_id=99 where account_id=2000000;"
else
    mysql -u evol -pevol evol -e "update login set group_id=99 where account_id=${ID} or userid='${ID}';"
fi
