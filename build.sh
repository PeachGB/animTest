#!/bin/sh

set -xe

FILE="main.c"
CFLAGS="-Wall -Wextra "
LIBS="-lraylib"

gcc -o main $CFLAGS $FILE $LIBS
