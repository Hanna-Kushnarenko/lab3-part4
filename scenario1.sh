#!/bin/bash

ml icc
echo "g++ compilation with 0 flag:"
g++ -O сircle.cpp -o test0
time ./test0
echo -e "\n"

echo "g++ compilation with 01 flag:"
g++ -O1 сircle.cpp -o test1
time ./test1
echo -e "\n"

echo "g++ compilation with 02 flag:"
g++ -O2 сircle.cpp -o test2
time ./test2
echo -e "\n"

echo "g++ compilation with 03 flag:"
g++ -O3 сircle.cpp -o test3
time ./test3
echo -e "\n"

echo "g++ compilation with 0fast flag:"
g++ -Ofast сircle.cpp -o test4
time ./test4
echo -e "\n"