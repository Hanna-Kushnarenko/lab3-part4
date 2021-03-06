#!/bin/bash

ml icc
echo "g++ compilation with 0 flag:"
g++ -O prog.cpp -o test0
time ./test0
echo -e "\n"

echo "g++ compilation with 01 flag:"
g++ -O1 prog.cpp -o test1
time ./test1
echo -e "\n"

echo "g++ compilation with 02 flag:"
g++ -O2 prog.cpp -o test2
time ./test2
echo -e "\n"

echo "g++ compilation with 03 flag:"
g++ -O3 prog.cpp -o test3
time ./test3
echo -e "\n"

echo "g++ compilation with 0fast flag:"
g++ -Ofast prog.cpp -o test4
time ./test4
echo -e "\n"

grep 'flags' /proc/cpuinfo | uniq
echo -e "\n"

extn=(sse2 ssse3 sse4.2 avx)
for flag in ${extn[@]}
do
icc -std=c++11 -x$flag -O2 prog.cpp -o nexttest
if [$? -eq 0]
then
echo "Extention is $flag"
time ./nexttest
echo -e "\n"
fi
done
