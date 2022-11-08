#!/bin/bash
DIR='/home/yuri/miku/test'
for file in *.c; do
    cp "$file" "$DIR"
done
ALL_FILE=$(ls -S $DIR)
echo "$ALL_FILE"
exit 0