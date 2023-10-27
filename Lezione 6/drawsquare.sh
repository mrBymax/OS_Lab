#!/bin/bash

# Draw a square of +, - and | characters of the given size in input
# Example: ./drawsquare.sh 5
# Output:
# +---+
# |   |
# |   |
# |   |
# +---+

# Check if the number of arguments is correct [2, 15]
if [ $# -ne 1 ] || [ $1 -lt 2 ] || [ $1 -gt 15 ]; then
    echo "Usage: $0 <size>"
    exit 1
fi

# Draw the square
for ((i=0; i<$1; i++)); do
   for (( j=0; j<$1; j++)); do
         if [ $i -eq 0 ] || [ $i -eq $(($1-1)) ]; then
              if [ $j -eq 0 ] || [ $j -eq $(($1-1)) ]; then
                echo -n "+"
              else
                echo -n "-"
              fi
         else
              if [ $j -eq 0 ] || [ $j -eq $(($1-1)) ]; then
                echo -n "|"
              else
                echo -n " "
              fi
         fi
    done
    echo ""
done

# Exit
exit 0