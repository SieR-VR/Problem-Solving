#!/bin/bash

gcc -Wall -Wextra -Werror -o dist/$1 $1/$1.c -lm

dist/$1