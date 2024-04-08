#!/bin/sh
echo "Choose a problem to run:" 
FILE=$(gum choose $(ls . | grep -E '[0-9]+'))

gcc -Wall -Wextra -o "dist/$FILE" "$FILE/$FILE.c" -lm

if [ $? -ne 0 ]; then
  gum log --time="TimeOnly" --structured --level error "Compilation failed for $FILE.c"
  exit 1
else
  gum style \
    --foreground 212 --border-foreground 212 --border double \
    --align center --width 40 \
    'Compiled successfully! 🎉' "Running $FILE.c"
  dist/$FILE
fi

