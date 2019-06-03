#include "sudoku.h"

void setBoard(int **board, int rows, int cols)
{

    FILE *file1 = fopen("board.txt", "r");


    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            char c;

            if (fscanf(file1, " %c", &c) != 1)
            {
                printf("Klaida skaitant faila\n");
                i=j=1000;
                break;
            }
                else if(isdigit((unsigned char)c))
                    board[i][j] = c - '0';
                    else
                        board[i][j] = 0;
        }
    }

    fclose(file1);
}

void printBoard(int **board)
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%d ", board[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

//current position and the number
int checkRow(int y, int num, int **board) //9x1 pass the column, 1-no match
{
    for(int i=0;i<ROWS;i++)
    {
        if(board[i][y] == num)
            return 0;
    }

    return 1;
}

int checkColumn(int x, int num, int **board)//1x9 pass the row, 1 no match
{

    for(int i=0;i<COLS;i++)
    {
        if(board[x][i]==num)
            return 0;
    }

    return 1;

}

int checkSquare(int x, int y, int num, int **board)//3x3 pass both
{
    //which square, set up for the loops

    if(x<3)
    {
        x=0;
    }
        else if(x<6)
        {
            x=3;
        }
            else
            {
                x=6;
            }

    if(y<3)
    {
        y=0;
    }
        else if(y<6)
        {
            y=3;
        }
            else
            {
                y=6;
            }

    for(int i=x;i<x+3;i++)
    {
        for(int j=y;j<y+3;j++)
        {
            if(board[i][j]==num)
                return 0;
        }

    }

    return 1;
}

int solveSudoku(int **board, int x, int y)
{
    int num = 1;
    int tx=0, ty=0;

    if(board[x][y]!=0)
    {
        if(x==8 && y==8)
        {
            return 1;
        }
            else
            {
                if(y<8)
                {
                    y++;
                }
                    else
                    {
                            y=0;
                            x++;
                    }
            }

        if(solveSudoku(board, x, y)==1)//?
        {
            return 1;
        }
            else
            {
                return 0;
            }
    }



    if(board[x][y]==0)
    {
        while(num<10)
        {
            if(checkRow(y, num, board)==1 && checkColumn(x, num, board)==1 && checkSquare(x, y, num, board)==1)
            {
                board[x][y]=num;
                if(x==8 && y==8)
                {
                    return 1;
                }

                if(y<8)
                {
                    ty++;
                }
                    else
                    {
                        if(x<8)
                        {
                            tx++;
                            ty=0;
                        }
                    }

                if(solveSudoku(board, tx, ty)==1)//backtracks if there is no further solution
                {
                    return 1;
                }


            }

            num++;

        }
        //backtrack no number is appliableeeee
        board[x][y] = 0;
        return 0;

    }
}
