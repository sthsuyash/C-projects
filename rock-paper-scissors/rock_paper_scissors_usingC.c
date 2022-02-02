/*
    Author : Suyash Shrestha
    sthasuyash11@gmail.com

    Description: 
    User enters choice of rock scissors and paper as 0,1 or 2 respectively.
    User must win max times among 3 games to win the game.
    Computer generates random number from 0 to 2 and is matached with user's answer.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

int main()
{
    int compAns, userAns;
    char name[20];

    printf("\n\n\t---------Welcome to Game of Rock, Paper and Scissors-----------\n");
    printf("\t---------------Play three times to win the game----------------\n\n");
    printf("\t\tEnter 0 for Rock, 1 for Paper and 2 for Scissors.\n\n");

    printf("Enter your name : ");
    scanf("%s", name);

    while (true)
    {
        int userWin = 0, compWin = 0;
        printf("\n");
        for (int i = 0; i < 3; i++)
        {
            srand(time(NULL));
            compAns = rand() % 3;

            printf("Enter your choice : ");
            scanf("%d", &userAns);

            if (userAns > 2)
            {
                printf("Enter a valid number.\n");
                continue;
            }

            else if (userAns == compAns)
            {
                printf("Computer also chose the same.\n");
                continue;
            }
            else if (userAns == 0 && compAns == 2)
            {
                printf("Computer chose %d.\n", compAns);
                userWin++;
            }
            else if (userAns == 1 && compAns == 0)
            {
                printf("Computer chose %d.\n", compAns);
                userWin++;
            }
            else if (userAns == 2 && compAns == 1)
            {
                printf("Computer chose %d.\n", compAns);
                userWin++;
            }
            else
            {
                printf("Computer chose %d.\n", compAns);
                compWin++;
            }
        }

        printf("\nComputer Score: %d\t", compWin);
        printf("%s Score: %d\n", name, userWin);

        if (compWin == userWin)
        {
            printf("\nIt's a tie!! Good Game %s.\n\n", name);
        }
        else if (compWin < userWin)
        {
            printf("\nCONGRATULATIONS %s!! You Won.\n\n", name);
        }
        else
        {
            printf("\nComputer Wins!! Better luck next time %s.\n\n", name);
        }
        char ans;
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &ans);

        if (ans == 'n')
        {
            printf("Quitting");
            for (int i = 0; i <7; i++)
            {
                Sleep(120);
                printf(".");
            }
            printf("\nPlay Again Soon!!\n\n");
            break;
        }
    }
    system("pause");
    exit (0);
    return 0;
}
