#!/bin/sh

if [ -z "$1" ]; then
  PROBLEM_NUMBER=$(gum input --placeholder "Enter the problem number")
else
  PROBLEM_NUMBER=$1
fi

mkdir $PROBLEM_NUMBER && cp templates/.c $PROBLEM_NUMBER/$PROBLEM_NUMBER.c

code -v > /dev/null && code $PROBLEM_NUMBER/$PROBLEM_NUMBER.c
