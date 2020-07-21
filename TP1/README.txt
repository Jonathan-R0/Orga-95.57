Compilación: gcc -Wall -g cachesim.c -lm -o test
valgrind ./test adpcm.xex 2048 2 64 a 2 3
valgrind ./test adpcm.xex 4096 1 128 a 2 3
