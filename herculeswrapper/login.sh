#!/bin/bash

export PIPE=./log/loginpipe.tmp

source ${dir}/include.sh

server_logic ./login-server 0s
