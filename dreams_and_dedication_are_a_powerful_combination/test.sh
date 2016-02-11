#!/bin/bash
echo "Script started."
LINES=$(cat result.txt | sed 's/[^,]//g' | wc -c)
i=1
ERROR=0
while [ $i -le $LINES ]
do 
    VALUE=$(cat result.txt | cut -d, -f${i} | sed -e 's/^[[:space:]]*//')
    FIRST="$(echo "$VALUE" | cut -c 1-2)"
    SECOND="$(echo "$VALUE" | cut -c 4-5)"
    if [ "$(grep -F "${SECOND} ${FIRST}" result.txt)" != ""  ]
    then
	echo "Duplicate Found: $VALUE - ${SECOND} ${FIRST}"
	ERROR=$(($ERROR+1))
    fi
    i=$(($i+1))
done
echo "There were $ERROR duplicates found."
