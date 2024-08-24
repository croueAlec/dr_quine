#!/bin/bash

FILENAME=$1

# Check if the file exists
if [ ! -f "$FILENAME" ]; then
    echo "File not found!"
    exit 1
fi

sed -i 's/"/%2$c/g' $FILENAME
tr '\n' '"' < $FILENAME
sed -i 's/"/%1$c/g' $FILENAME
