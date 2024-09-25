#!/bin/bash

read -p "Enter a directory: " dir

if ![ -d "$dir" ]; then
    echo "$dir is not a directory"
    exit 1
fi
if ! grep -q "^/" <<< "$dir"; then
    echo "not an absolute path"
    exit 2
fi

echo "Objects count:"
find $dir -type f -o -type d | wc -l
