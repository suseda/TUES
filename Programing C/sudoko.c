#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
char board[9][9];
enum bool{ false, true };
struct box
{
	int x, y;
};
enum bool solve_sudoku(struct box box)
{
	int num = 1;
	struct box auxiliary_structure = box;
	if (board[box.x][box.y] != 0)
	{
		if (box.x == 8 && box.y == 8)
			return true;
		if (box.x < 8)
			box.x = box.x + 1;
		else
		{
			if (box.y < 8)
			{
				box.x = 0;
				box.y = box.y + 1;
			}
		}

		if (solve_sudoku(box))
			return true;
		else
			return false;
	}
	if (board[box.x][box.y] == 0)
	{
		while (num < 10)
		{
			if (!same_box(box, num) && !same_row(box, num) && !same_column(box, num))
			{
				board[box.x][box.y] = num;
				if (box.x == 8 && box.y == 8)
					return true;
				if (box.x < 8)
					auxiliary_structure.x = box.x + 1;
				else
				{
					if (box.y < 8)
					{
						auxiliary_structure.x = 0;
						auxiliary_structure.y = box.y + 1;
					}
				}
				if (solve_sudoku(auxiliary_structure))
					return true;
			}
			num++;
		}
		board[box.x][box.y] = 0;
		return false;
	}

}

enum bool same_column(struct box box, int num)
{
	for (int i = 0; i < 8; i++)
	{
		if (board[box.x][i] == num)
			return true;
	}
	return false;
}

enum bool same_row(struct box box, int num)
{
	for (int i = 0; i < 8; i++)
	{
		if (board[i][box.y] == num)
			return true;
	}
	return false;
}

enum bool same_box(struct box box, int num)
{

	if (box.x < 3) {
		box.x = 0;
	}
	else if (box.x < 6) {
		box.x = 3;
	}
	else { box.x = 6; }

	if (box.y < 3) {
		box.y = 0;
	}
	else if (box.y < 6) {
		box.y = 3;
	}
	else { box.y = 6; }

	for (int i = box.x; i < box.x + 3; i++)
	{
		for (int j = box.y; j < box.y + 3; j++)
		{
			if (board[i][j] == num)
				return true;
		}
	}
	return false;
}

generate_sudoku(struct box box, int dificulty)
{
	int cnt;
	time_t t;
	srand((unsigned)time(&t));
	struct box a = { 0,0 };
	char first_board[9][9];
	do
	{
		cnt = dificulty * 2 + 20;
		for (int i = 0; i < 9; i++)
			for (int p = 0; p < 9; p++)
				board[p][i] = 0, first_board[p][i] = 0;
		while (cnt)
		{
			int num = rand() % 10;
			box.x = rand() % 9;
			box.y = rand() % 9;
			if (board[box.x][box.y] == 0)
				if (!same_box(box, num) && !same_row(box, num) && !same_column(box, num))
				{
					board[box.x][box.y] = num;
					cnt--;
				}
		}
		memcpy(first_board, board, sizeof board);
	} while (solve_sudoku(a) == false);
	memcpy(board, first_board, sizeof board);
	return 1;
}

void red()
{
	printf("\033[1;31m");
}
void green()
{
	printf("\033[0;32m");
}
void purple()
{
	printf("\033[0;35m");
}
void cyan() {
	printf("\033[0;36m");
}
void yellow()
{
	printf("\033[1;33m");
}

void reset()
{
	printf("\033[0m");
}

void print_board()
{
	printf("\n");
	printf("\t\t\t   SUDOKU\n");
	printf("\t  A    B    C    D    E    F    G    H    I\n");
	for (int a = 0; a < 9; a++)
	{
		struct box m = { 0,0 };
		printf("\t ");
		for (; m.x < 9; m.x++)
		{
			if (a % 3 == 0)
				printf(" ====");
			else
				printf(" ____");
		}

		printf("\n");
		printf("%d\t", a + 1);
		for (; m.y < 10; m.y++)
		{
			if (m.y % 3 == 0)
			{
				printf("#  ");
				yellow();
				printf("%c ", " 123456789"[board[m.y][a]]);
				reset();
			}
			else
			{
				printf("|  ");
				yellow();
				printf("%c ", " 123456789"[board[m.y][a]]);
				reset();
			}
		}
		printf("\n");
	}
	printf("\t  ==== ==== ==== ==== ==== ==== ==== ==== ====\n");
}
void check_validility(int x, int y, int num)
{
	struct box a = { x,y };
	red();
	if (same_column(a, num))
		printf("\ninvalid input, there is %d in the same column\n", num);
	else
		if (same_row(a, num))
			printf("\ninvalid input, there is %d in the same row\n", num);
		else
			if (same_box(a, num))
				printf("\ninvalid input, there is %d in the same box\n", num);
			else
				board[x][y] = num;
	reset();
	print_board();
}
int main(int argc, const char* argv)
{
	int mode;
	struct box b = { 0,0 };
	cyan();
	printf("If you want to enter sudoku to be solved press 1, if you want to solve sudoku press 2: ");
	scanf("%d", &mode);
	reset();
	if (mode == 1)
	{
		purple();
		printf("What to do:\n 1.enter unsolved sudoku\n 2.When you'r done enter 0,0,0\n 3.See the solved sudoku;)\n\n");
		reset();
		print_board();
		while (1)
		{
			int y = 0, num, x = 0;
			do
			{
				printf("Enter a number in a box 1st the column, then the row and then the number you want to be in there:\n");
				char x_char;
				while (3 != scanf("%c,%d,%d", &x_char, &y, &num));
				x = toupper(x_char) - 'A';
				y--;
				if (num == 0)
					break;
			} while (y > 9 && y < 1 || num > 9 && num < 1);

			if (num == 0)
				break;
			check_validility(x, y, num);
		}
		solve_sudoku(b);
		print_board();
	}
	else
	{
		int dificulity, n = 0;
		green();
		printf("Choose dificulty\n 1.hard\n 2.medium\n 3.easy\n");
		reset();
		scanf("%d", &dificulity);
		generate_sudoku(b, dificulity);
		char solution[9][9];
		memcpy(solution, board, sizeof board);
		print_board();
		while (n <= 81)
		{
			int y = 0, num, x = 0;
			do
			{
				printf("Enter a number in a box 1st the column, then the row and then the number you want to be in there:\n");
				char x_char;

				while (3 != scanf("%c,%d,%d", &x_char, &y, &num));
				x = toupper(x_char) - 'A';
				y--;
				if (num == 0)
					break;

			} while (y > 9 && y < 1 || num > 9 && num < 1);

			if (num == 0)
			{
				memcpy(board, solution, sizeof board);
				solve_sudoku(b);
				print_board();
				return;
			}
			check_validility(x, y, num);
		}
		cyan();
		printf("Congratulations, you succeded in solving the sudoku!");
		reset();
	}

}