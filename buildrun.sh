#!/bin/bash

if [ -z "$1" ]; then
  echo -e "Usage: ./$(basename $0) <taskname>"
else
  if test -f "$1.c"; then
    gcc -Wall -Wextra -Werror -Wshadow -Wsign-conversion -o $1.cout $1.c
    ./$1.cout
  elif test -f "$1.cpp"; then
    g++ -Wall -Wextra -Werror -Wshadow -Wsign-conversion -pedantic -std=c++17 -o $1.cppout $1.cpp
    ./$1.cppout
  else
    echo -e "File '$1.c' doesn't exist.\nUsage: ./$(basename $0) <taskname>"
  fi
fi