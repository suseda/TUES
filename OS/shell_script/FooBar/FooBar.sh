#!/bin/bash


for num in $(seq $1 $2)
do
    if [ $((num % 3)) -eq 0 ] && [ $((num % 5)) -eq 0 ]; then
        echo "$num : FooBar"
    elif [ $((num % 3)) -eq 0 ]; then
         echo "$num : Foo"
    elif [ $((num % 5)) -eq 0 ]; then
        echo "$num : Bar"
    else
        echo "$num : NA"
    fi 

done
