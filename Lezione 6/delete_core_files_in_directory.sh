#!/bin/bash

# Given a directory name, delete all the files that contain "core" in the filename

# Check if the number of arguments is correct
if [ $# -ne 1 ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

# Check if the directory exists
if [ ! -d $1 ]; then
    echo "Error: $1 is not a directory"
    exit 2
fi

# =========== Create the files to test the script ================
ls $1 
for ((i=0; i<10; i++)); do
    if ((i % 2 == 0)); then
        touch $1/core$i.txt
    else
        touch $1/other$i.txt
    fi

    # sleep for 1 second
    sleep 1
done
# ================================================================


# Delete all the files that contain "core" in the filename
for file in $(ls $1); do
    if [ $(echo $file | grep -c "core") -eq 1 ]; then
        rm $1/$file
    fi
done

# =========== Delete the files created to test the script ========

sleep 5 # sleep for 5 seconds to see the files created and deleted
for file in $(ls $1); do
    rm $1/$file
done

# ================================================================

# Exit
exit 0