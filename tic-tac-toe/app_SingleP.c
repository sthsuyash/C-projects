/*
    Simple Tic Tac Toe game in CMD using C.
    Author : Suyash Shrestha
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

char board[3][3];                  // creating a 2D array board
const char PLAYER = 'X', AI = 'O'; // PLAYER is assigned 'X' symbol to play with while AI is assigned 'O'.

// declaring function prototypes
void reset_Board();
void print_Board();
int check_Free_Spaces();
void player_Move();
void AI_move();
char check_Winner();
void print_Winner(char);

// driver function
int main(void)
{
    system("color D");
    printf("\n\n\t\t\t-------------------------------------------------\n");
    printf("\t\t\t|\tWELCOME to the game of TIC-TAC-TOE\t|\n");
    printf("\t\t\t-------------------------------------------------\n\n\n");
    printf("\t\t------\tPlayer plays as 'X' and COMPUTER plays as 'O'\t------\n\n");
    char winner = ' ';
    char ans;

    do
    {
        reset_Board();
        winner = ' ';
        ans = ' ';
        while (check_Free_Spaces() != 0 && winner == ' ')
        {
            print_Board();

            player_Move();
            winner = check_Winner();
            if (winner != ' ' || check_Free_Spaces() == 0)
            {
                break;
            }

            AI_move();
            winner = check_Winner();
            if (winner != ' ' || check_Free_Spaces() == 0)
            {
                break;
            }
        }
        print_Board();
        print_Winner(winner);

        printf("\nDo you want to play again?? (y/n): ");
        scanf(" %c", &ans);

        ans = tolower(ans);

    } while (ans == 'y');

    printf("\nThanks for playing!!\n");

    system("pause");
    return 0;
}

// function to reset the board to empty every new game.
void reset_Board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// function to print the board everytime the user and AI places their options at specific value
void print_Board()
{
    printf("\n\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

// function to check the total number of free spaces left
int check_Free_Spaces()
{
    int free_spaces = 9; // declaring total number of free spaces that can be available. As there are total of 9 possible spaces, the total number of free spaces that can be available to us is 9.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                free_spaces--; // decreasing total number of free spaces if the space is already occupied by player or AI.
            }
        }
    }
    return free_spaces;
}

// function to check the free space available and place the player symbol at desired row and column
void player_Move()
{
    int row, column;

    do
    {
        printf("Enter row (1-3) where you want your move: ");
        scanf("%d", &row);
        row--;

        printf("Enter column (1-3) where you want your move: ");
        scanf("%d", &column);
        column--;

        if (board[row][column] != ' ')
        {
            printf("\t\aInvalid move!!!\n\n");
        }
        else
        {
            board[row][column] = PLAYER;
        }
    } while (board[row][column] == ' ');
}

// function to check the rows and columns for equality elements
char check_Winner()
{
    // checking equality condition for rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0]; // returns the character that is at the place of board[i][0] 'X' for PLAYER's character and 'O' for AI.
        }
    }

    // checking equality condition for columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j])
        {
            return board[0][j]; // returns the character that is at the place of board[0][j] 'X' for PLAYER's character and 'O' for AI.
        }
    }

    // checking equality condition for left diagonals
    if (board[0][0] == board[1][1] && board[2][2] == board[0][0])
    {
        return board[0][0]; // returns the character that is at the place of board[0][0] 'X' for PLAYER's character and 'O' for AI.
    }

    // checking equality condition for right diagonals
    if (board[0][2] == board[1][1] && board[2][0] == board[0][2])
    {
        return board[0][2]; // returns the character that is at the place of board[0][2] 'X' for PLAYER's character and 'O' for AI.
    }

    return ' '; // returns empty character or space if there is no winner
}

// function to fill the gaps by AI by generating random postions on the board using rand function
void AI_move()
{
    srand(time(NULL)); // creates a seed for generating random numbers
    int ran1, ran2;
    char none = ' ';
    if (check_Free_Spaces() > 0)
    {
        do
        {
            ran1 = rand() % 3;
            ran2 = rand() % 3;
        } while (board[ran1][ran2] != ' ');
        board[ran1][ran2] = AI;
    }
    else
    {
        print_Winner(none);
    }
}

// function to print the winner by taking parameter which is PLAYER, AI or nothing.
void print_Winner(char winner)
{
    if (winner == PLAYER)
    {
        printf("\n\t\t*************************\n");
        printf("\t\t*\tYou win!!!\t*\n");
        printf("\t\t*************************\n\n\n");
    }
    else if (winner == AI)
    {
        printf("\a\n\t\t*****************************************\n");
        printf("\t\t*\tComputer won!! TRY AGAIN\t*\n");
        printf("\t\t*****************************************\n\n\n");
    }
    else
    {
        printf("\n\t\t*************************\n");
        printf("\t\t*\tIt's a DRAW!!\t*\n");
        printf("\t\t*************************\n");
    }
}
