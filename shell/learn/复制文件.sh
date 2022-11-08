#!/bin/bash
for i in "$@"
do
    if [ "$i" != "$1" ]; then
        cp -r "$i" "$1"
    fi
done