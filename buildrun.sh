#!/bin/bash
if [ -z "$1" ]
  then
    echo "Usage: ./$(basename $0) <taskname>"
  else
    gcc -Wall -Wextra -o $1 $1.c
    ./$1
fi