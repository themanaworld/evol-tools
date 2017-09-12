#!/usr/bin/env bash

year=$(date "+%Y")

if [[ $year -lt 2017 ]]; then
    date
    echo "Error: Date time is wrong. Please fix time. See man date"
    exit 1
fi