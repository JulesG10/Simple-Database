@echo off
cd build && g++ -std=c++14 ../main.cpp -o main
gcc -g -O -c ../main.cpp
gcc -S ../main.cpp 
g++ -c ../main.cpp
g++ -shared -o ./main.dll ./main.o -Wl,--out-implib,./main.a
g++ -c -o ./main.o ../main.cpp
ranlib ./main.a
cd ..