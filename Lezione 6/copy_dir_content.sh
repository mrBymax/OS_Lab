#!/bin/bash

# Copy dir1 content into dir2
cp -r dir1/* dir2

# Transform all the occurrences of the string "SP" into "SU"
sed -i '' 's/SP/SU/g' dir2/* # Mac OS X sed