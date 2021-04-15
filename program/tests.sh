#!/bin/bash

files="test_inputs/*"

for f in $files
do
printf "\nChecking file $f\n"
sha512sum="$(sha512sum $f)"
sha512calculator="$(./sha512calculator $f)"
echo "sha512calculator: " $sha512calculator
echo "sha512sum:        " $sha512sum
if [[ $sha512calculator == $sha512sum ]]; 
	then 
		echo "Pass"
	else
		echo "Fail"
	fi
done