#!/bin/bash

read -p "Enter first file: " f1
read -p "Enter second file: " f2
read -p "Enter third file: " f3

cat $f1 >> $f3  | cat $f2 >> $f3 | sort $f3


