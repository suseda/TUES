// needed for windows scanf
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

board[3][3];     // -1 player X, 0 empty, 1 player O

//--------------- author1 ----------------
// x, y - position of the last played move
int evaluate_move(int x, int y) // -1 - player X, 0 - no winner, 1 player O wins
{
    return      board[y][0] == board[y][1] && board[y][1] == board[y][2] || // row
        board[0][x] == board[1][x] && board[1][x] == board[2][x] || // col
        x == y && board[0][0] == board[1][1] && board[1][1] == board[2][2] || // \ diag
        x == 2 - y && board[2][0] == board[1][1] && board[1][1] == board[0][2] ?  // / diag
        board[y][x] : 0; // result
}
//--------------- author2 ----------------
// x, y - contain the previous move on entry, contain the next move on exit
// start with x=-1, y=-1 to generate first position
// shuffle - value that reorders the board traversal
int find_empty(int* x, int* y, int shuffle)  // 0 no empty, 1 found
{
    do
    {
        int p; // linearized board id
        if (*x == -1) // if starting board empty field enumeration
            p = shuffle % 9; // start from random field
        else
        {
            p = (*x + 3 * *y + 1) % 9; // restore linear id and go to the next
            if (p == shuffle % 9) // if reached the starting point
                return 0; // signal end of iteration
        }
        *x = p % 3; // move from 1D to 2D ids
        *y = p / 3;
    } while (board[*y][*x]); // repeat while not empty
    return 1;
}
//--------------- author3 ----------------
// output in x, y the move, evaluation - the move value
// input: player is -1 for X, 1 for O, depth: how many moves to analyze
// return 0 for no move, 1 found move 
int find_best_move(int* out_x, int* out_y, int* out_eval, int player, int depth)
{
    int x = -1, y = -1, shuffle = rand(), best_x, best_y, best_eval = -2; // detect not found case
    while (find_empty(&x, &y, shuffle)) // for every empty field:
    {
        board[y][x] = player; // play the move
        int eval = evaluate_move(x, y); // see what happens
        if (eval == 0 && depth) // if not conclusive
            find_best_move(out_x, out_y, &eval, -player, depth - 1); // play opponent move
        board[y][x] = 0; // remove the move to restore the board for next move
        eval *= player; // make evaluation relative to player so 1 means win, -1 loss
        if (best_eval < eval) // maximize best move
        {
            best_eval = eval;
            best_x = x;
            best_y = y;
            if (best_eval == 1) // we won already: no need to continue
                break;
        }
    }
    if (best_eval < -1) // no empty field found?
        return 0;
    *out_x = best_x; // write the results
    *out_y = best_y;
    *out_eval = best_eval * player; // restore the evaluation to absolute player id
    return 1;
}
//--------------- author4 ----------------
// "c:\>tic-tac-toe 2 5" computer depth 2 vs. computer depth 5
// "c:\>tic-tac-toe -1 4" human vs computer depth 4
void print_board()
{
    printf("\n\t     A   B   C");
    for (int row = 0; row < 3; row++) // row loop
    {
        printf("\n\t    --- --- ---\n\t%d  |", row + 1);
        for (int col = 0; col < 3; col++) // column loop
            printf(" %c |", "X O"[board[row][col] + 1]); // fill the board fields
    }
    printf("\n\t    --- --- ---\n");
}
int main(int argc, const char* const argv[])
{
    if (argc != 3) // incorrect number of arguments?
        return printf("Usage: %s <player X depth> <player O depth>\n depth is 0-9, -1 for human.\n", argv[0]), -2;
    srand((unsigned)time(0)); // seed the random number generator with current time
    int eval = 0, forecast = 0; // game forecast counter
    for (int move = 0; move < 9; move++) // make max 9 moves
    {
        int player = (move & 1) * 2 - 1, depth = atoi(argv[1 + (move & 1)]), x, y;
        if (depth < 0 && move < 7) // if human autoplay last two moves as boring
        {
            if (eval && !forecast++) // if winner is known make game forecast
                printf("Player %c will win.\n", "X O"[eval + 1]);
            print_board();
            do
            {
                printf("Enter valid move for player %c: ", "XO"[move & 1]);
                char cx;
                while (2 != scanf("%c%d", &cx, &y));
                x = toupper(cx) - 'A'; // upcase the column char
                y--;
            } while (x < 0 || 2 < x || y < 0 || 2 < y || board[y][x]); // check input validity
        }
        else
            find_best_move(&x, &y, &eval, player, depth); // find computer move
        board[y][x] = player; // play
        if (evaluate_move(x, y)) // check for victory
        {
            print_board();
            printf("Player %c wins.\n", "XO"[move & 1]);
            return player;
        }
    }
    print_board(); // if no victory then draw
    printf("Draw.\n");
    return 0;
}