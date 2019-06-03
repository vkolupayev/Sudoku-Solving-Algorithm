#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ROWS 9
#define COLS 9

void setBoard(int **board, int rows, int cols);
void printBoard(int **board);
int checkRow(int y, int num, int **board);
int checkColumn(int x, int num, int **board);
int checkSquare(int x, int y, int num, int **board);
int solveSudoku(int **board, int x, int y);

#endif // SUDOKU_H_INCLUDED
