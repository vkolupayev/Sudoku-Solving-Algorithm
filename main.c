#include "sudoku.h"

int main()
{
  int rows = ROWS, cols = COLS;
  int **board;

  /* obtain values for rows & cols */

  /* allocate the array */

  board = malloc(rows * sizeof *board);

  for (int i=0; i<rows; i++)
  {
    board[i] = malloc(cols * sizeof *board[i]);
  }


  setBoard(board, rows, cols);
  printBoard(board);
  solveSudoku(board,0,0);
  printBoard(board);

  /*deallocate the array*/
  for (int i=0; i<rows; i++)
  {
    free(board[i]);
  }
  free(board);
}
