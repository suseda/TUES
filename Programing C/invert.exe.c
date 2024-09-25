#include <stdio.h>
void print_board(char board[HORIZONTAL][VERTICAL])
{
    int turn;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 'A'; j < 'A'+2; j++)
        {
            printf("%c", board[i][j]);
            if (j != 'A'+2)
                printf("|");
        }
        if (i != 2)
            printf("\n---------");
        printf("\n");
    }   
}

int main()
{
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("Player %c, make your move: ", turn);
    scanf(" %c %c", &i, &j);
}
