#!/bin/sh
PROBLEM_NUMBER=$(gum input --placeholder "Enter the problem number")

mkdir $PROBLEM_NUMBER && touch $PROBLEM_NUMBER/$PROBLEM_NUMBER.c

code -v > /dev/null && code $PROBLEM_NUMBER/$PROBLEM_NUMBER.c