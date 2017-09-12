#!/usr/bin/env bash

export DIR=`pwd`
./checktime.sh
source ./clean.sh
./build.sh old
