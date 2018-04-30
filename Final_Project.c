//Parker Cormack
//CSCI1312
//Semester Projet - Tic-Tac-Toe

//Libraries
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

//Global Definitions
#define HORIZONTAL 3
#define VERTICAL 3

//Function Declartion
void gotoxy(int x, int y);
void draw_board();
void draw_x(int x, int y);
void draw_o(int x, int y);
void place_marker(int x, int p);
int tie(int count, int* board[HORIZONTAL][VERTICAL]);
void restart(int count);
int replay(int count);
int repeat(int n, int p, int* board[HORIZONTAL][VERTICAL]);
int check_for_win(int n, int p, int* board[HORIZONTAL][VERTICAL], int count);
void reset_index(int* board[HORIZONTAL][VERTICAL]);

//Main Function
int main()
{
	//Variable declaration
	int n; //space
	int* pn = &n;
	int p = 2; //player
	int turns = 0;
	int count = 0;
	int game;
	int repeated;
	int win = 0;

	draw_board();

	int board[HORIZONTAL][VERTICAL] = { 0 };

	while (true)
	{
		repeated = 0;

		if (turns == 9)
		{
			game = tie(count, board);
			if (game == 7) break;
			if (game == 2) count += game;
			turns = 0;
		}
		printf("Which square do you want: ");
		scanf("%d", &n);
		if (n == 10) break; //If user picks 10, break and exit game
		repeated = repeat(n, p, board);
		if (repeated > 0) count += 2;
		if (repeated == 0)
		{
			place_marker(n, p);
			turns++;
			count++;
			if (p == 1) p = 2;
			else if (p == 2) p = 1;
		}
		gotoxy(0, 39 + count);
		win = check_for_win(n, p, board, count);
		if (win > 1)
		{
			count += 2;
			turns = 0;
		}
	}
}


void gotoxy(int x, int y)
{
	COORD coord = { 0,0 };
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw_board()
{
	//Game Board
	printf("\t--------------------------------------------------\n");
	printf("\t||\t 1 \t|\t 2 \t|\t 3 \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||----------------------------------------------||\n");
	printf("\t||\t 4 \t|\t 5 \t|\t 6 \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||----------------------------------------------||\n");
	printf("\t||\t 7 \t|\t 8 \t|\t 9 \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t--------------------------------------------------\n");
	printf("\t\t\tTIC - TAC - TOE\n");
	printf("\tEnter your chosen square #. Enter 10 to exit game.\n\n\n\n\n");
	printf("GAME CONTROLLER:\n\n");
}

void draw_x(int x, int y)
{
	//X Shape
	gotoxy(x, y); printf("X           X\n");
	gotoxy(x, y + 1); printf("  X       X\n");
	gotoxy(x, y + 2); printf("    X   X\n");
	gotoxy(x, y + 3); printf("      X\n");
	gotoxy(x, y + 4); printf("    X   X\n");
	gotoxy(x, y + 5); printf("  X       X\n");
	gotoxy(x, y + 6); printf("X           X\n");
}

void draw_o(int x, int y)
{
	//O Shape
	gotoxy(x, y); printf("      O\n");
	gotoxy(x, y + 1); printf(" O         O\n");
	gotoxy(x, y + 2); printf("O           O\n");
	gotoxy(x, y + 3); printf("O           O\n");
	gotoxy(x, y + 4); printf("O           O\n");
	gotoxy(x, y + 5); printf(" O         O\n");
	gotoxy(x, y + 6); printf("      O\n");
}

void place_marker(int x, int p)
{
	if (p == 1)
	{
		if (x == 1) draw_o(11, 2);
		else if (x == 2) draw_o(26, 2);
		else if (x == 3) draw_o(42, 2);
		else if (x == 4) draw_o(11, 12);
		else if (x == 5) draw_o(26, 12);
		else if (x == 6) draw_o(42, 12);
		else if (x == 7) draw_o(11, 22);
		else if (x == 8) draw_o(26, 22);
		else if (x == 9) draw_o(42, 22);
	}

	if (p == 2)
	{
		if (x == 1) draw_x(11, 2);
		else if (x == 2) draw_x(26, 2);
		else if (x == 3) draw_x(42, 2);
		else if (x == 4) draw_x(11, 12);
		else if (x == 5) draw_x(26, 12);
		else if (x == 6) draw_x(42, 12);
		else if (x == 7) draw_x(11, 22);
		else if (x == 8) draw_x(26, 22);
		else if (x == 9) draw_x(42, 22);
	}
}

int tie(int count, int* board[HORIZONTAL][VERTICAL])
{
	int game;
	printf("The game is a tie");
	game = replay(count);
	reset_index(board);
	return game;
}

void restart(int count)
{
	printf("\t--------------------------------------------------\n");
	printf("\t||\t 1 \t|\t 2 \t|\t 3 \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||----------------------------------------------||\n");
	printf("\t||\t 4 \t|\t 5 \t|\t 6 \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||----------------------------------------------||\n");
	printf("\t||\t 7 \t|\t 8 \t|\t 9 \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t||\t   \t|\t   \t|\t   \t||\n");
	printf("\t--------------------------------------------------\n");
	printf("\t\t\tTIC - TAC - TOE\n");
	printf("\tEnter your chosen square #. Enter 10 to exit game.\n\n\n\n\n");
	printf("GAME CONTROLLER:\n\n");
	gotoxy(0, 50 + count);
}

int replay(int count)
{
	int num = 0;
	do
	{
		char restart_game; //yes or no answer

		printf("\nWould you like to play again? (y/n): ");
		restart_game = getchar();
		scanf("%c", &restart_game);
		if (restart_game == 'Y' || restart_game == 'y')
		{
			gotoxy(0, 0);
			restart(count);
			return 2;
			num = 2;
		}
		else if (restart_game == 'N' || restart_game == 'n')
		{
			return 7;
			num = 2;
		}
	} while (num < 1);
}

int repeat(int n, int p, int* board[HORIZONTAL][VERTICAL])
{
	int repeated = 0;

	//If player 1's turn
	if (p == 1)
	{
		if (n == 1)
		{
			if (board[0][0] == 0) board[0][0] == 1;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 2)
		{
			if (board[0][1] == 0) board[0][1] == 1;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 3)
		{
			if (board[0][2] == 0) board[0][2] == 1;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 4)
		{
			if (board[1][0] == 0) board[1][0] == 1;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 5)
		{
			if (board[1][1] == 0) board[1][1] == 1;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 6)
		{
			if (board[1][2] == 0) board[1][2] == 1;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 7)
		{
			if (board[2][0] == 0) board[2][0] == 1;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 8)
		{
			if (board[2][1] == 0) board[2][1] == 1;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 9)
		{
			if (board[2][2] == 0) board[2][2] == 1;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
	}

	//If player 2's turn
	if (p == 2)
	{
		if (n == 1)
		{
			if (board[0][0] == 0) board[0][0] == 2;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 2)
		{
			if (board[0][1] == 0) board[0][1] == 2;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 3)
		{
			if (board[0][2] == 0) board[0][2] == 2;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 4)
		{
			if (board[1][0] == 0) board[1][0] == 2;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 5)
		{
			if (board[1][1] == 0) board[1][1] == 2;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 6)
		{
			if (board[1][2] == 0) board[1][2] == 2;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 7)
		{
			if (board[2][0] == 0) board[2][0] == 2;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 8)
		{
			if (board[2][1] == 0) board[2][1] == 2;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
		else if (n == 9)
		{
			if (board[2][2] == 0) board[2][2] == 2;
			else
			{
				repeated = 7;
				printf("There is already a character in that space, pick another.");
			}
		}
	}
	return repeated;
}

int check_for_win(int n, int p, int* board[HORIZONTAL][VERTICAL], int count)
{
	int out;
	int add = 0;

	//Place a 1 in places that Player 1 picks
	if (p == 1)
	{
		if (n == 1) board[0][0] = 1;
		else if (n == 2) board[0][1] = 1;
		else if (n == 3) board[0][2] = 1;
		else if (n == 4) board[1][0] = 1;
		else if (n == 5) board[1][1] = 1;
		else if (n == 6) board[1][2] = 1;
		else if (n == 7) board[2][0] = 1;
		else if (n == 8) board[2][1] = 1;
		else if (n == 9) board[2][2] = 1;
	}

	//Place a 2 in places that Player 2 picks
	if (p == 2)
	{
		if (n == 1) board[0][0] = 2;
		else if (n == 2) board[0][1] = 2;
		else if (n == 3) board[0][2] = 2;
		else if (n == 4) board[1][0] = 2;
		else if (n == 5) board[1][1] = 2;
		else if (n == 6) board[1][2] = 2;
		else if (n == 7) board[2][0] = 2;
		else if (n == 8) board[2][1] = 2;
		else if (n == 9) board[2][2] = 2;
	}

	//Checks for win
	for (int i = 0; i < 3; i++)
	{
		//Player 1 wins horizontally or vertically
		if (board[i][0] == 1 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) //The same number 1 for Player 1 is seen across on the first, second, or third row
		{
			printf("Player 1 is the winner!");
			out = replay(count); //checks if playing again
			if (out == 7) exit(-1); //if output from function is a 7, code quits
			else if (out == 2) //if output is a 2
			{
				reset_index(board); //resets table
				add = 2; //sends a number greater than 1 to main function
			}
		}
		if (board[0][i] == 1 && board[0][i] == board[1][i] && board[1][i] == board[2][i]) //The same number 1 for Player 1 is seen down the first, second, or third column
		{
			printf("Player 1 is the winner!");
			out = replay(count);
			if (out == 7) exit(-1);
			else if (out == 2)
			{
				reset_index(board);
				add = 2;
			}
		}

		//player 2 wins horizontally or vertically
		if (board[i][0] == 2 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) //The same number 2 for Player 2 is seen across on the first, second, or third row
		{
			printf("Player 2 is the winner!");
			out = replay(count);
			if (out == 7) exit(-1);
			else if (out == 2)
			{
				reset_index(board);
				add = 2;
			}
		}
		if (board[0][i] == 2 && board[0][i] == board[1][i] && board[1][i] == board[2][i]) //The same number 2 for Player 2 is seen down the first, second, or third column
		{
			printf("Player 2 is the winner!");
			out = replay(count);
			if (out == 7) exit(-1);
			else if (out == 2)
			{
				reset_index(board);
				add = 2;
			}
		}

		//Player 1 wins diagonally
		if (board[0][0] == 1 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		{
			printf("Player 1 is the winner!");
			out = replay(count);
			if (out == 7) exit(-1);
			else if (out == 2)
			{
				reset_index(board);
				add = 2;
			}
		}
		if (board[0][2] == 1 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		{
			printf("Player 1 is the winner!");
			out = replay(count);
			if (out == 7) exit(-1);
			else if (out == 2)
			{
				reset_index(board);
				add = 2;
			}
		}

		//Player 2 wins diagonally
		if (board[0][0] == 2 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		{
			printf("Player 2 is the winner!");
			out = replay(count);
			if (out == 7) exit(-1);
			else if (out == 2)
			{
				reset_index(board);
				add = 2;
			}
		}
		if (board[0][2] == 2 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		{
			printf("Player 2 is the winner!");
			out = replay(count);
			if (out == 7) exit(-1);
			else if (out == 2)
			{
				reset_index(board);
				add = 2;
			}
		}
	}

	return add;
}

void reset_index(int* board[HORIZONTAL][VERTICAL])
{
	//reset array to zeroes
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = 0;
		}
	}
}