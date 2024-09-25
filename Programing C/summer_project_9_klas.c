#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
enum bool { false, true };
enum bool gameover;
int i, j, height = 20, width = 20;
int x, y, fruit_x, fruit_y, direction,score;
int tail_x[100], tail_y[100],tail_lenght;
void start()
{
    gameover = false;
    x = height / 2;
    y = width / 2;
    fruit_x = rand() % width;
    fruit_y = rand() % height;
    score = 0;
}

void draw()
{
    system("cls");
    for (int n = 0; n < width + 2; n++)
        printf("#");
    printf("\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) 
        {
            if (j==0) 
                printf("#");
            if (i == x && j == y)
                printf("O");
            else if (i == fruit_x && j == fruit_y)
                    printf("*");
            else
            {
                    enum bool print = false;
                    for (int k = 0; k < tail_lenght; k++)
                    {
                        if (tail_x[k] == i && tail_y[k] == j)
                        {
                            printf("o");
                            print = true;
                        }
                    }
                    if (!print)
                        printf(" ");
            }
            if (j == width - 1)
                printf("#");
        }
        printf("\n");
    }
    for (int n = 0; n < width + 2; n++)
        printf("#");
    printf("\n");
    printf("score = %d", score);
    printf("\n");
    printf("press X to quit the game");
}

void moves()
{
    if (_kbhit()) {
        switch (getch()) {
        case 'a':
            direction = 1;
            break;
        case 's':
            direction = 2;
            break;
        case 'd':
            direction = 3;
            break;
        case 'w':
            direction = 4;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}

void play()
{
    int prev_x = tail_x[0];
    int prev_y = tail_y[0];
    int prev_2x, prev_2y;
    tail_x[0] = x;
    tail_y[0] = y;
    for (int i = 1; i < tail_lenght; i++)
    {
        prev_2x = tail_x[i];
        prev_2y = tail_y[i];
        tail_x[i] = prev_x;
        tail_y[i] = prev_y;
        prev_x = prev_2x;
        prev_y = prev_2y;
    }
    switch (direction) {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }

    if (x < 0 || x > height || y < 0 || y > width)
        gameover = true;
    for (int i = 0; i < tail_lenght; i++)
    {
        if (tail_x[i] == x && tail_y[i] == y)
            gameover = true;
    }

    if (x == fruit_x && y == fruit_y) 
    {
        fruit_x = rand() % width;
        fruit_y = rand() % height;
        tail_lenght++;
        score += 10;
    }
}

void main()
{
    start();
    while (!gameover) 
    {
        draw();
        moves();
        play();
        Sleep(10);
        Sleep(10);
    }
}