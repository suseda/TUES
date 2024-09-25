#!/bin/bash

if [[ $1 =~ ^[0-9a-zA-Z]+$ ]]; 
then
    echo "Match"
else
    echo "Not Match"
fi

