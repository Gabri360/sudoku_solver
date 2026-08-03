CFLAGS=-O3 -funroll-loops -flto -pedantic -std=c99

ifeq ($(OS),Windows_NT)
	TARGET = sudoku_solver.exe
else
	TARGET = sudoku_solver
endif

CC = $(CROSS)gcc

all: $(TARGET)

$(TARGET): sudoku_solver.o sudoku_lib.o
	$(CC) $(CFLAGS) sudoku_solver.o sudoku_lib.o -o $@ -lm

sudoku_solver.o: ../prg/sudoku_solver.c
	$(CC) $(CFLAGS) -c ../prg/sudoku_solver.c

sudoku_lib.o: ../lib/sudoku_lib.c ../head/sudoku_lib.h
	$(CC) $(CFLAGS) -c ../lib/sudoku_lib.c

clean:
	rm -f *.o $(TARGET)
