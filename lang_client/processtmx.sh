#!/bin/bash

export name=$1
export name=${name##*/}

itstool -o pot/map${name}.pot -i its/tmx.xml $1
