#!/bin/bash

# Set up files for testing.
files="test_inputs/*"

# Test the program with all the files against sha512sum.
for f in $files; do
  printf "\nChecking file $f\n"
  sha512sum="$(sha512sum $f)"
  sha512calculator="$(./sha512calculator $f)"
  echo "sha512calculator: " $sha512calculator
  echo "sha512sum:        " $sha512sum
  if [[ $sha512calculator == $sha512sum ]]; then
    printf "Pass\n"
  else
    printf "Fail\n"
  fi
done
