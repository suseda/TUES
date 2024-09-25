#!/bin/bash

num=$1
left=$2
right=$3


for i in "$@"
do
    if echo "$i" | grep -qE '^-?[0-9]+$' ; then
        continue;
    else
        exit 3;
    fi

done


if [ $left -gt $right ]; then
    exit 2;
elif [ $num -lt $left ] || [ $num -gt $right ]; then
    exit 1;
elif [ $num -gt $left ] && [ $right -gt $num ]; then
    exit 0;
else
    exit 4;
fi
