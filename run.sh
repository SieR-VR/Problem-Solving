#!/bin/bash

gcc -Wall -Wextra -Werror -g -o dist/$1 $1/$1.c -lm

dist/$1