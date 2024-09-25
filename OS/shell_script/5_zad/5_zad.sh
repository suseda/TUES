#!/bin/bash

read -p "Enter file: " file
read -p "Enter string: " str

grep "^.*$str.*$" $file

echo $? 
