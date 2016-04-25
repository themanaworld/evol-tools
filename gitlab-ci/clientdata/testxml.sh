#!/bin/bash

source ./tools/gitlab-ci/init.sh

clientdata_init

cd tools/testxml

./xsdcheck.sh
export RES=$(cat errors.txt)
if [[ -n "${RES}" ]]; then
    echo "xml check failed" >../../clientdata/shared/error.log
    echo ${RES} >>../../clientdata/shared/error.log
    cat ../../clientdata/shared/error.log
    exit 1
fi

echo >../../clientdata/shared/error.log
./testxml.py silent >../../clientdata/shared/error.log
if [ "$?" != 0 ]; then
    echo "test xml error"
    cat ../../clientdata/shared/error.log
    exit 1
fi

echo >../../clientdata/shared/error.log
