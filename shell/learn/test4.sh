#!/bin/bash
for ((i = 0; i < 10; i++)); do
    for ((j = 0; j < i + 1; j++)); do
        echo -n "$(($i - $j))" " "
    done
    echo ''
done
