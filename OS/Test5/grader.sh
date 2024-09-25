#!/bin/bash

answers=$1
correct_answers=$2
results=$3

if ! [ -d "$answers" ]; then
    echo "$answers is not a directory"
    exit 1
elif ! [ $(find "$answers" -maxdepth 1 -type f | wc -l) -eq 25 ]; then
    echo "There are not 25 files in $answers"
    exit 2
else
    for file in $(echo "$(pwd)/"$answers"")/*
    do
        if ! [ -r $file ] && [ $( wc -l < $file) -eq 25 ]; then
            echo "File is not readable or its not 25 lines"
            exit 3
        else
            while read line;
            do
                 if echo "$line" | grep -qE '^[A-D]$'; then
                    continue
                 else
                    echo "Answer must be between A-D"
                    exit 4
                 fi
            done < $file
        fi
    done  
fi  


if ! [ -f "$correct_answers" ]; then
    echo "$correct_answers is not a file"
    exit 5
else
    if ! [ -r $correct_answers ] && [ $( wc -l < $file) -eq 25 ]; then
        echo "File is not readable or its not 25 lines"
        exit 6
    else
        while read line;
            do
                 if echo "$line" | grep -qE '^[A-D]$'; then
                    continue
                 else
                    echo "Answer must be between A-D"
                    exit 7
                 fi
            done < $correct_answers  
    fi    
fi


if ! [ -d "$results" ] ; then
    echo "$results is not a directory"
    exit 8
else
    if ! [ -n "$(find $(echo "$(pwd)/"$results"") -mindepth 1)" ]; then
        for file in $(echo "$(pwd)/"$answers"")/*
        do
            grade () {
                local points="${1}"
                if [ $points -le 25 ] && [ $points -ge 23 ]; then
                    echo '6'
                elif [ $points -le 22 ] && [ $points -ge 20 ]; then
                    echo '5'
                elif [ $points -le 19 ] && [ $points -ge 17 ]; then
                    echo '4'
                elif [ $points -le 16 ] && [ $points -ge 14 ]; then
                    echo '3'
                else
                    echo '2'
                fi
            }

            
            grade "$(comm -12 $file $correct_answers 2>/dev/null | wc -l)" > $(echo "$(pwd)/"$results"/$(basename "$file")")

        done   
    fi
fi

