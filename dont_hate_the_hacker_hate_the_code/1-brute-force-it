#!/bin/bash

STRINGS="$(strings a.out)"
for STRING in $STRINGS; do
    cp a.out b.out
    RESULT="$(./b.out $STRING)"
    if [[ $RESULT == *"Access granted \o/"* ]]
    then
	printf "%s" $STRING
	break;
    fi
done
