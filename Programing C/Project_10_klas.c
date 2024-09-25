#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7

enum bool{ False, True };

void print_board(char board[ROWS][COLS])
{
    puts(" 1   2   3   4   5   6   7");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        puts("|");
    }
}

enum bool is_valid_move(int position, char board[ROWS][COLS])
{
    for (int row = ROWS - 1; row >= 0; row--)
    {
        if (board[row][position] == ' ')
        {
            return True;
        }
    }
    return False;
}


enum bool check_vertical(char board[ROWS][COLS])
{
    for (int row = 0; row < ROWS - 3; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] == board[row + 1][col] && board[row][col] == board[row + 2][col] && board[row][col] == board[row + 3][col] && board[row][col] != ' ')
                return True;
        }
    }
    return False;
}

enum bool check_horizontal(char board[ROWS][COLS])
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS - 3; col++)
        {
            if (board[row][col] == board[row][col + 1] && board[row][col] == board[row][col + 2] && board[row][col] == board[row][col + 3] && board[row][col] != ' ')
                return True;
        }
    }
    return False;
}

enum bool check_left_diagonal(char board[ROWS][COLS])
{
    int index = ROWS - 1;
    for (int row = ROWS; 0 <= row - 3; row--)
    {
        for (int col = COLS; 0 <= col - 3; col--)
        {
            if (board[index][col] == board[index - 1][col - 1] && board[index][col] == board[index - 2][col - 2] && board[index][col] == board[index - 3][col - 3] && board[index][col] != ' ')
                return True;
        }
        index--;
    }
    return False;
}

enum bool check_right_diagonal(char board[ROWS][COLS])
{
    int index = ROWS - 1;
    for (int row = ROWS - 1; 0 <= row - 3; row--)
    {
        for (int col = 0; col < COLS - 3; col++)
        {
            if (board[index][col] == board[index - 1][col + 1] && board[index][col] == board[index - 2][col + 2] && board[index][col] == board[index - 3][col + 3] && board[index][col] != ' ')
                return True;
        }
        index--;
    }
    return False;
}



enum bool check_win(char board[ROWS][COLS])
{
    return (check_horizontal(board) || check_vertical(board) || check_right_diagonal(board) || check_left_diagonal(board));
}

int main()
{
    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    int mode = 1, turns = 0, flag = 1;
    if (mode)
    {
        while (ROWS * COLS > turns && !(check_win(board)))
        {
            if (flag)
            {
                print_board(board);
                int position = 0;
                do
                {
                    puts("Enter number of coloum you want to play:");
                    scanf("%d", &position);

                    if (!(position > 0 && position < COLS + 1) || !(is_valid_move(position - 1, board)))
                    {
                        puts("Move is not valid!");
                    }
                } while (!(position > 0 && position < COLS + 1) || !(is_valid_move(position - 1, board)));

                position = position - 1;

                for (int row = ROWS - 1; row >= 0; row--)
                {
                    if (board[row][position] == ' ')
                    {
                        board[row][position] = 'X';
                        break;
                    }
                }
                turns++;
                flag = 0;
            }
            else
            {
                print_board(board);
                int position = 0;
                do
                {
                    puts("Enter number of coloum you want to play:");
                    scanf("%d", &position);

                    if (!(position > 0 && position < COLS + 1) || !(is_valid_move(position - 1, board)))
                    {
                        puts("Move is not valid!");
                    }
                } while (!(position > 0 && position < COLS + 1) || !(is_valid_move(position - 1, board)));

                position = position - 1;

                for (int row = ROWS - 1; row >= 0; row--)
                {
                    if (board[row][position] == ' ')
                    {
                        board[row][position] = 'O';
                        break;
                    }
                }
                turns++;
                flag = 1;
            }
        }

        print_board(board);

        if (turns == 42)
        {
            puts("Tie!");
        }
        else
        {

            if (flag)
                printf("Player O wins in %d turns!", turns);
            else
                printf("Player X wins in %d turns!", turns);
        }
    }
    else
    {
        while (turns < ROWS * COLS && check_win(board))
        {
            if (flag)
            {
                print_board(board);
                int position = 0;
                do
                {
                    puts("Enter number of coloum you want to play:");
                    scanf("%d", &position);

                    if (!(position > 0 && position < COLS + 1) || !(is_valid_move(position - 1, board)))
                    {
                        puts("Move is not valid!");
                    }
                } while (!(position > 0 && position < COLS + 1) || !(is_valid_move(position - 1, board)));
                position = position - 1;

                for (int row = ROWS - 1; row >= 0; row--)
                {
                    if (board[row][position] == ' ')
                    {
                        board[row][position] = 'X';
                        break;
                    }
                }
                turns++;
                flag = 0;
            }
            else
            {
                //computer
                flag = 1;
            }
        }
    }

    return 0;
}