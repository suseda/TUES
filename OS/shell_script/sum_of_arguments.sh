#!/bin/bash

sum=0

for num in $@
do
	sum=$(($sum + $num))
done

echo $sum

read n

sum=$(($n * $sum))

echo $sum
