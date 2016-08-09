#!/bin/bash

export PIPE=./log/charpipe.tmp

source ${dir}/include.sh

server_logic ./char-server 2s
