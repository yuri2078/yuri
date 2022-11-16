#!/usr/bin/bash
yuri=$(ls "$HOME")

for val in $yuri; 
do
    echo "${val}"
done
