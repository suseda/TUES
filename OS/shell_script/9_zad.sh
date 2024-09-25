#!/bin/bash

rval=$(echo "$1" | rev)

delimiter=" "

if [ $# -gt 1 ]; then
    delimiter="$2"
fi

rval=$(echo $rval | sed "s/\(...\)/\1$delimiter/g" | rev)
echo $rval
