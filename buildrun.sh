#!/bin/bash

if [ -z "$1" ]; then
  for i in *.c; do
    gcc -Wall -Wextra -o ${i%.c}.out "$i"
    echo -e "\n${i%.c}:"
    ./${i%.c}.out
  done
else
  if test -f "$1.c"; then
    gcc -Wall -Wextra -o $1.out $1.c
    ./$1.out
  else
    echo -e "File '$1.c' doesn't exist.\nUsage: ./$(basename $0) <taskname>"
  fi
fi