#!/bin/bash

FILENAME=$1
QUOTE='"'
TAB="\t"
FSLASH="\/"
REPLACEMENT_STRING="%c"

# Check if the file exists
if [ ! -f "$FILENAME" ]; then
    echo "File not found!"
    exit 1
fi

# Replace the character with the string and update the file
tr '\n' '"' <$FILENAME | sed "s/$QUOTE/$REPLACEMENT_STRING/g" | sed "s/$TAB/$REPLACEMENT_STRING/g"
echo

# Read the file character by character
echo -n "fprintf(file,s"
while IFS= read -r -n1 char
do
    # Get the ASCII value of the character
    ascii_value=$(printf "%d" "'$char")
    
    # Check for specific characters and print their ASCII values
    case "$char" in
        "")
            echo -n ",10"
            ;;
        $'\t')
            echo -n ",$ascii_value"
            ;;
        '"')
            echo -n ",$ascii_value"
            ;;
    esac
done < "$FILENAME"
echo ");"
