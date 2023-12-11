#!/bin/bash


while read -r num1 && read -r num2 && read -r op; do
    ./client_bignumber "$num1" "$num2" "$op" >> regular.txt
done < regular.in