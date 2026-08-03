all:
	cd build && make && mv sudoku_solver ..
start:
	cd build && make && mv sudoku_solver .. && cd .. && ./sudoku_solver
clean:
	cd build && make clean
