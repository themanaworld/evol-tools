#!/bin/bash

export MANAPLUS="../../manaplus/src/manaplus"
if [ -f "$MANAPLUS" ]; then
    echo "Starting local manaplus"
else
    echo "Starting system manaplus"
    export MANAPLUS="manaplus"
fi

${MANAPLUS} -u -d ../../client-data evol.manaplus
