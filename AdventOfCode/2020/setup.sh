#!/bin/bash
./getProblem.py $1 && cp code.cc $1/$1.cc && cd $1 && nvim +6 -O $1.cc input
