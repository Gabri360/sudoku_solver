CFLAGS=-O3 -march=native -ffast-math -funroll-loops -flto -pedantic -std=c99
#CFLAGS=-g -O3 -Wall -Wextra -Werror -pedantic -Wconversion -std=c99

#all: isto random gauss_MCMC ising
all: sudoku_solver

sudoku_solver: sudoku_solver.o sudoku_lib.o
	gcc $(CFLAGS) sudoku_solver.o sudoku_lib.o -o $@ -lm

sudoku_solver.o: ../prg/sudoku_solver.c 
	gcc $(CFLAGS) -c ../prg/sudoku_solver.c

sudoku_lib.o: ../lib/sudoku_lib.c ../head/sudoku_lib.h
	gcc $(CFLAGS) -c ../lib/sudoku_lib.c

c:
	find . -type f ! -name "Makefile" -delete

