
stacktest: main.o sudoku.o
	gcc main.o sudoku.o -o sudokutest

main.o: main.c
	gcc -c main.c

sudoku.o: sudoku.c sudoku.h
	gcc -c sudoku.c

clean:
	rm *.o sudokutest
