#!/bin/bash


while read -r num1 && read -r num2 && read -r op; do
    ./client_bignumber "$num1" "$num2" "$op" >> small_minus_positives.txt
done < small_minus_positives.in